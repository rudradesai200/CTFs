
uint key_generator(void)

{
  next_in_seq = next_in_seq * 0x303577d + 0x145a;
  return next_in_seq % 0xff;
}

undefined4 main(int param_1, int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int aiStack596[100];
  byte abStack196[52];
  undefined4 local_90;
  undefined4 uStack140;
  undefined4 uStack136;
  undefined4 uStack132;
  undefined4 local_80;
  undefined4 uStack124;
  undefined4 uStack120;
  undefined4 uStack116;
  undefined4 local_70;
  undefined4 uStack108;
  undefined4 uStack104;
  undefined4 uStack100;
  undefined2 local_60;
  termios local_5c;
  ssize_t local_20;
  int local_1c;
  int local_18;
  int local_14;

  local_90 = 0x42485443;
  uStack140 = 0x4141417b;
  uStack136 = 0x41414141;
  uStack132 = 0x41414141;
  local_80 = 0x41414141;
  uStack124 = 0x41414141;
  uStack120 = 0x41414141;
  uStack116 = 0x41414141;
  local_70 = 0x41414141;
  uStack108 = 0x41414141;
  uStack104 = 0x41414141;
  uStack100 = 0x41414141;
  local_60 = 0x7d41;
  local_14 = 0;
  while (local_14 < 0x32)
  {
    bVar1 = *(byte *)((int)&local_90 + local_14);
    bVar2 = key_generator();
    abStack196[local_14] = bVar2 ^ bVar1;
    local_14 = local_14 + 1;
  }
  if (param_1 == 1)
  {
    uVar4 = 0xffffffff;
  }
  else
  {
    printf("[!] sending data to %s\n", *(undefined4 *)(param_2 + 4));
    local_1c = open(*(char **)(param_2 + 4), 0x902);
    if (local_1c == -1)
    {
      perror(*(char **)(param_2 + 4));
      uVar4 = 0xffffffff;
    }
    else
    {
      iVar3 = tcgetattr(local_1c, &local_5c);
      if (iVar3 < 0)
      {
        perror("[x] configuration error");
        uVar4 = 0xffffffff;
      }
      else
      {
        local_5c.c_iflag = 0;
        local_5c.c_oflag = 0;
        local_5c.c_lflag = 0;
        local_5c.c_cc[6] = '\0';
        local_5c.c_cc[5] = '\0';
        local_5c.c_cflag = 0x1141;
        tcsetattr(local_1c, 0, &local_5c);
        local_18 = 0;
        local_14 = 0;
        while (local_14 < 0x32)
        {
          aiStack596[local_18] = (abStack196[local_14] >> 4) + 1;
          aiStack596[local_18 + 1] = (abStack196[local_14] & 0xf) + 1;
          local_18 = local_18 + 2;
          local_14 = local_14 + 1;
        }
        local_14 = 0;
        while (local_14 < 1)
        {
          local_20 = write(local_1c, aiStack596, 400);
          if (local_20 < 0)
          {
            perror("[x] write error");
            return 0xffffffff;
          }
          local_14 = local_14 + 1;
        }
        close(local_1c);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}
