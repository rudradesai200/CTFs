#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

void main(void)

{
  int iVar1;
  char *pcVar2;
  size_t pipe_name_len;
  ulong uVar4;
  long in_FS_OFFSET;
  undefined4 local_2ba0;
  socklen_t local_2b9c;
  int i;
  int local_2b94;
  undefined4 local_2b90;
  int new_socket;
  char *buffer;
  char *pipe_name;
  char *query_start;
  char *local_2b70;
  FILE *_pipe_;
  char *local_2b60;
  struct sockaddr_in address[4];
  undefined4 local_2b54;
  sockaddr local_2b48;
  char cmd_result[1023];
  undefined local_2739;
  char output[10008];
  undefined8 local_20;

  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_2ba0 = 1;
  local_2b9c = 0x10;
  local_2b94 = socket(2, 1, 0);
  if (local_2b94 < 0)
  {
    err(1, "can\'t open socket");
  }
  setsockopt(local_2b94, 1, 2, &local_2ba0, 4);
  local_2b90 = 0x1f90;
  address._0_2_ = 2;
  local_2b54 = 0;
  address._2_2_ = htons(0x1f90);
  iVar1 = bind(local_2b94, (struct sockaddr *)address, 0x10);
  if (iVar1 == -1)
  {
    close(local_2b94);
    err(1, "Can\'t bind");
  }
  listen(local_2b94, 5);
  do
  {
    while (new_socket = accept(local_2b94, &local_2b48, &local_2b9c), new_socket == -1)
    {
      perror("Can\'t accept");
    }
    buffer = (char *)malloc(0x400);
    read(new_socket, buffer, 1023);
    buffer[0x3ff] = '\0';
    pcVar2 = strstr(buffer, "GET / HTTP/1.1");
    if (pcVar2 == (char *)0x0)
    {
      pipe_name = strchr(buffer, '/');
      pipe_name = pipe_name + 1;
      query_start = strchr(buffer, '?');
      local_2b70 = strstr(buffer, " HTTP/1.1");
      if ((pipe_name == (char *)0x0) || (local_2b70 == (char *)0x0))
      {
        write(new_socket, &response, 0xa8);
      }
      else
      {
        if ((query_start == (char *)0x0) || (local_2b70 <= query_start))
        {
          write(new_socket, &response, 0xa8);
        }
        else
        {
          *local_2b70 = '\0';
          *query_start = ' ';
          i = 0;
          while (uVar4 = SEXT48(i), pipe_name_len = strlen(pipe_name), uVar4 < pipe_name_len)
          {
            if ((((pipe_name[i] == '&') || (pipe_name[i] == '|')) ||
                 (pipe_name[i] == '>')) ||
                ((pipe_name[i] == '$' || (pipe_name[i] == '<'))))
            {
              pipe_name[i] = ' ';
            }
            i = i + 1;
          }
          _pipe_ = popen(pipe_name, "r");
          puts(pipe_name);
          if (_pipe_ == (FILE *)0x0)
          {
            write(new_socket, &response, 0xa8);
          }
          else
          {
            fgets(cmd_result, 1020, _pipe_);
            local_2739 = 0;
            output[0] = '\0';
            local_2b60 = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n";
            strcat(output, "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n");
            strcat(output, cmd_result);
            pipe_name_len = strlen(output);
            write(new_socket, output, pipe_name_len - 1);
            puts("1");
            close((int)_pipe_);
          }
        }
      }
    }
    else
    {
      write(new_socket, &response, 0xa8);
    }
    close(new_socket);
  } while (true);
}
