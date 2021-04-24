
void setup(void)

{
  setvbuf(stdin, (char *)0x0, 2, 0);
  setvbuf(stdout, (char *)0x0, 2, 0);
  alarm(0x7f);
  return;
}

void hidden_func(int param_1)

{
  size_t sVar1;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  int local_28;
  int local_24;
  char *local_20;
  int local_14;
  char *local_10;

  if (param_1 == 0)
  {
    /* WARNING: Subroutine does not return */
    exit(0x22);
  }
  local_10 = "Do you think this is the secret password?\n> ";
  sVar1 = strlen("Do you think this is the secret password?\n> ");
  local_14 = (int)sVar1;
  local_20 = "At least we tried...\n";
  sVar1 = strlen("At least we tried...\n");
  local_24 = (int)sVar1;
  local_28 = 0x464;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  write(1, local_10, (long)local_14);
  read(0, &local_48, (long)local_28);
  write(1, local_20, (long)local_24);
  if (check != 0)
  {
    fclose(stdout);
    fclose(stderr);
  }
  check = check + 1;
  return;
}

undefined8 main(void)

{
  size_t sVar1;
  int local_80;
  int local_7c;
  char *local_78;
  int local_6c;
  undefined *local_68;
  int local_5c;
  char *local_58;
  int local_4c;
  char *local_48;
  int local_3c;
  char *local_38;
  int local_2c;
  undefined *local_28;
  int local_1c;
  undefined *local_18;
  undefined4 local_c;

  setup();
  local_c = 0;
  local_18 = &DAT_00400bc0;
  sVar1 = strlen(&DAT_00400bc0);
  local_1c = (int)sVar1;
  local_28 = &DAT_00400be2;
  sVar1 = strlen(&DAT_00400be2);
  local_2c = (int)sVar1;
  local_38 = "You found nothing of interest..\n";
  sVar1 = strlen("You found nothing of interest..\n");
  local_3c = (int)sVar1;
  local_48 = "We are doomed!\n";
  sVar1 = strlen("We are doomed!\n");
  local_4c = (int)sVar1;
  local_58 = "Invalid option! Exiting..\n";
  sVar1 = strlen("Invalid option! Exiting..\n");
  local_5c = (int)sVar1;
  local_68 = &DAT_00400c48;
  sVar1 = strlen(&DAT_00400c48);
  local_6c = (int)sVar1;
  local_78 = "You found something interesting!\n";
  sVar1 = strlen("You found something interesting!\n");
  local_7c = (int)sVar1;
  write(1, local_68, (long)local_6c);
  read(0, companion, 0xf);
  write(1, local_18, (long)local_1c);
  write(1, local_28, (long)local_2c);
  __isoc99_scanf(&DAT_00400c92, &local_80);
  if (local_80 == 1)
  {
    write(1, local_38, (long)local_3c);
  }
  else
  {
    if (local_80 == 2)
    {
      write(1, local_48, (long)local_4c);
    }
    else
    {
      if (local_80 != 0x2a)
      {
        write(1, local_58, (long)local_5c);
        /* WARNING: Subroutine does not return */
        exit(0x16);
      }
      local_c = 1;
      write(1, local_78, (long)local_7c);
    }
  }
  hidden_func(local_c);
  return 0;
}
