

undefined8 parse_input(long param_1, void **param_2)

{
  int iVar1;
  void *pvVar2;
  int local_14;
  int local_10;
  int local_c;

  if (*param_2 != (void *)0x0)
  {
    free(*param_2);
    *param_2 = (void *)0x0;
  }
  if (param_2[1] != (void *)0x0)
  {
    free(param_2[1]);
    param_2[1] = (void *)0x0;
  }
  local_10 = -1;
  local_14 = 0;
  do
  {
    if (*(char *)(param_1 + local_14) == '\0')
    {
    LAB_001017cf:
      local_14 = 0;
      while (*(char *)(param_1 + local_14) != '\0')
      {
        local_14 = local_14 + 1;
      }
      local_c = local_14;
      while ((*(char *)(param_1 + (long)local_c + -1) == ' ' ||
              (*(char *)(param_1 + (long)local_c + -1) == '\n')))
      {
        local_c = local_c + -1;
      }
      if (local_10 < 0)
      {
        pvVar2 = malloc((long)(local_c + 1));
        *param_2 = pvVar2;
        if (*param_2 == (void *)0x0)
        {
          return 0xffffffff;
        }
        local_14 = 0;
        while (local_14 < local_c)
        {
          iVar1 = tolower((int)*(char *)(param_1 + local_14));
          *(char *)((long)local_14 + (long)*param_2) = (char)iVar1;
          local_14 = local_14 + 1;
        }
        *(undefined *)((long)local_c + (long)*param_2) = 0;
      }
      else
      {
        pvVar2 = malloc((long)(local_10 + 1));
        *param_2 = pvVar2;
        if (*param_2 == (void *)0x0)
        {
          return 0xffffffff;
        }
        local_14 = 0;
        while (local_14 < local_10)
        {
          iVar1 = tolower((int)*(char *)(param_1 + local_14));
          *(char *)((long)local_14 + (long)*param_2) = (char)iVar1;
          local_14 = local_14 + 1;
        }
        *(undefined *)((long)local_10 + (long)*param_2) = 0;
        pvVar2 = malloc((long)((local_c - (local_10 + 1)) + 1));
        param_2[1] = pvVar2;
        if (param_2[1] == (void *)0x0)
        {
          return 0xffffffff;
        }
        local_14 = 0;
        while (local_14 < local_c - (local_10 + 1))
        {
          iVar1 = tolower((int)*(char *)(param_1 + (long)(local_10 + local_14) + 1));
          *(char *)((long)local_14 + (long)param_2[1]) = (char)iVar1;
          local_14 = local_14 + 1;
        }
        *(undefined *)((long)(local_c - (local_10 + 1)) + (long)param_2[1]) = 0;
      }
      return 0;
    }
    if (*(char *)(param_1 + local_14) == ' ')
    {
      local_10 = local_14;
      goto LAB_001017cf;
    }
    local_14 = local_14 + 1;
  } while (true);
}

undefined8 initialize_rooms(char **output)

{
  char *pcVar1;
  undefined8 uVar2;
  uint i;

  i = 0;
  while (true)
  {
    if (7 < i)
    {
      *(char **)*output = "Dangeresque\'s Office";
      *(char **)(*output + 8) = "This is where the magic happens!";
      *(char **)output[1] = "Agency Lobby";
      *(char **)(output[1] + 8) = "It\'s late, the receptionist is out.";
      *(char **)output[2] = "Chief\'s Office";
      *(char **)(output[2] + 8) = "Geez, maybe I should leave. He looks pissed.";
      *(char **)output[3] = "Alleyway";
      *(char **)(output[3] + 8) = "It\'s late. Standing in a dark alleyway is never a good idea.";
      *(char **)output[4] = "Warehaus";
      *(char **)(output[4] + 8) = "Whoa, still smells like blood and sweat!";
      *(char **)output[5] = "Street";
      *(char **)(output[5] + 8) = "It\'s late, no one\'s out. At least there are street lights.";
      *(char **)output[6] = "\"Rong Cheng\"";
      *(char **)(output[6] + 8) = "Make sure you use a card at this place. Never cash.";
      *(char **)output[7] = "\"Cup of Mud Coffee\"";
      *(char **)(output[7] + 8) = "This place serves the worst coffee!";
      *(char **)(*output + 0x38) = output[1];
      *(char **)(output[1] + 0x30) = *output;
      *(char **)(output[1] + 0x20) = output[2];
      *(char **)(output[1] + 0x38) = output[3];
      *(char **)(output[2] + 0x28) = output[1];
      *(char **)(output[3] + 0x30) = output[1];
      *(char **)(output[3] + 0x38) = output[4];
      *(char **)(output[4] + 0x30) = output[3];
      *(char **)(output[4] + 0x38) = output[5];
      *(char **)(output[5] + 0x30) = output[4];
      *(char **)(output[5] + 0x20) = output[6];
      *(char **)(output[5] + 0x28) = output[7];
      uVar2 = cons_item("the swissblonkel scenario", "Hey, this is the case I\'m supposed to solve!",
                        0);
      uVar2 = cons_item("month-old chinese food", &DAT_0010325f, uVar2);
      pcVar1 = *output;
      uVar2 = cons_item("room-temperature coffee", &DAT_0010325f, uVar2);
      *(undefined8 *)(pcVar1 + 0x18) = uVar2;
      pcVar1 = output[2];
      uVar2 = cons_item("solved stamp", "This might come in handy...", 0);
      *(undefined8 *)(pcVar1 + 0x18) = uVar2;
      return 0;
    }
    pcVar1 = (char *)calloc(0x50, 1);
    output[i] = pcVar1;
    if (output[i] == (char *)0x0)
      break;
    i = i + 1;
  }
  return 0xffffffff;
}

undefined8 main(void)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long in_FS_OFFSET;
  int k;
  char *command;
  char *local_180;
  long local_178;
  undefined8 local_170;
  int ret_check;
  long local_158[8];
  char local_118[264];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = initialize_rooms(local_158);
  if (iVar1 == -1)
  {
    fwrite("Failed to initialize rooms!\n", 1, 0x1c, stderr);
    uVar2 = 1;
  }
  else
  {
    command = (char *)0x0;
    local_180 = (char *)0x0;
    local_178 = local_158[0];
    local_170 = 0;
    ret_check = 0;
    puts(
        "Welcome to Strong Bad\'s Cool Game for Attractive People Episode 6 - Dangeresque 4: TheCriminally-Dull Projective!");
    puts("Okay, you\'re Dangeresque. Nobody do anything... Dangeresque!");
    putchar(10);
    puts("\"Man. That warehaus was full of action and suspense.\"");
    puts("\"Dangeresque! You\'re outta line!\"");
    puts("\"Oh crap! It\'s the chief! I was supposed to solve a case for him months ago.\"");
    puts("\"Better try and \'solve\' his case quick.\"\n");
    describe_room(local_178);
    do
    {
      printf("a> ");
      fflush(stdout);
      fgets(local_118, 0x100, stdin);
      iVar1 = parse_input(local_118, &command, &command);
      if (iVar1 != 0)
      {
        /* WARNING: Subroutine does not return */
        exit(1);
      }
      iVar1 = strcmp(command, "look");
      if (iVar1 == 0)
      {
        describe_room();
      }
      else
      {
        iVar1 = strcmp(command, "inventory");
        if (iVar1 == 0)
        {
          describe_inventory();
        }
        else
        {
          iVar1 = strcmp(command, "go");
          if (iVar1 == 0)
          {
            if (local_180 == (char *)0x0)
            {
              puts("Gotta be more specific than that, bud!");
            }
            else
            {
              iVar1 = strcmp(local_180, "north");
              if (iVar1 == 0)
              {
                if (*(long *)(local_178 + 0x20) == 0)
                {
                  puts("Can\'t go that way!");
                }
                else
                {
                  local_178 = *(long *)(local_178 + 0x20);
                  describe_room();
                }
              }
              else
              {
                iVar1 = strcmp(local_180, "south");
                if (iVar1 == 0)
                {
                  if (*(long *)(local_178 + 0x28) == 0)
                  {
                    puts("Can\'t go that way!");
                  }
                  else
                  {
                    local_178 = *(long *)(local_178 + 0x28);
                    describe_room();
                  }
                }
                else
                {
                  iVar1 = strcmp(local_180, "east");
                  if (iVar1 == 0)
                  {
                    if (*(long *)(local_178 + 0x30) == 0)
                    {
                      puts("Can\'t go that way!");
                    }
                    else
                    {
                      local_178 = *(long *)(local_178 + 0x30);
                      describe_room();
                    }
                  }
                  else
                  {
                    iVar1 = strcmp(local_180, "west");
                    if (iVar1 == 0)
                    {
                      if (*(long *)(local_178 + 0x38) == 0)
                      {
                        puts("Can\'t go that way!");
                      }
                      else
                      {
                        local_178 = *(long *)(local_178 + 0x38);
                        describe_room();
                      }
                    }
                    else
                    {
                      iVar1 = strcmp(local_180, "up");
                      if (iVar1 == 0)
                      {
                        if (*(long *)(local_178 + 0x40) == 0)
                        {
                          puts("Can\'t go that way!");
                        }
                        else
                        {
                          local_178 = *(long *)(local_178 + 0x40);
                          describe_room();
                        }
                      }
                      else
                      {
                        iVar1 = strcmp(local_180, "down");
                        if (iVar1 == 0)
                        {
                          if (*(long *)(local_178 + 0x48) == 0)
                          {
                            puts("Can\'t go that way!");
                          }
                          else
                          {
                            local_178 = *(long *)(local_178 + 0x48);
                            describe_room();
                          }
                        }
                        else
                        {
                          printf("Where the hell is a \"%s\"?\n", local_180);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else
          {
            iVar1 = strcmp(command, "take");
            if (iVar1 == 0)
            {
              lVar3 = take_item(local_178, local_180, local_180);
              if (lVar3 == 0)
              {
                printf("There\'s no \"%s\" here!\n", local_180);
              }
              else
              {
                printf("Got the %s!\n", local_180);
                add_to_inventory(&local_178, lVar3, lVar3);
              }
            }
            else
            {
              iVar1 = strcmp(command, "drop");
              if (iVar1 == 0)
              {
                lVar3 = remove_from_inventory(&local_178, local_180, local_180);
                if (lVar3 == 0)
                {
                  printf("I ain\'t got no \"%s\"!\n", local_180);
                }
                else
                {
                  printf("Dropped the %s!\n", local_180);
                  insert_item(local_178, lVar3, lVar3);
                }
              }
              else
              {
                iVar1 = strcmp(command, "use");
                if (iVar1 == 0)
                {
                  use_item(&local_178, local_180, local_180);
                }
                else
                {
                  iVar1 = strcmp(command, "jhiezetfmvirlnjfbobk");
                  if (iVar1 == 0)
                  {
                    JHIEZETFMVIRLNJFBOBK = 1;
                  }
                  else
                  {
                    printf("I don\'t know how to \"%s\"\n", command);
                  }
                }
              }
            }
          }
        }
      }
    } while (ret_check == 0);
    if (JHIEZETFMVIRLNJFBOBK != 0)
    {
      k = 0;
      while (k < 0x23)
      {
        putchar((int)(char)(LHEIBZNXEKQSAPHHUWTQ[k] ^ COJASZQHPZXKLAPHRHOK[k]));
        k = k + 1;
      }
      putchar(10);
    }
    if (command != (char *)0x0)
    {
      free(command);
    }
    if (local_180 != (char *)0x0)
    {
      free(local_180);
    }
    free_rooms(local_158);
    uVar2 = 0;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
  {
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}
