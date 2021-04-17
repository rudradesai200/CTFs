
void addcreature(void)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_28;
  char *local_20;
  char local_18[8];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  local_20 = (char *)malloc(0x10);
  puts("Enter creature name");
  gets(local_20);
  puts("Enter creature type");
  puts("(Enter 1 for male animal, 2 for male bird, 3 for female animal, or 4 for female bird");
  gets(local_18);
  iVar1 = atoi(local_18);
  do
  {
    if (local_28 == 10)
    {
    LAB_00401098:
      if (local_20 != (char *)0x0)
      {
        puts("Ark full... creature cannot be added");
      }
      if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
      {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (*(int *)(creatures + (long)local_28 * 0x10 + 8) == 0)
    {
      *(char **)(creatures + (long)local_28 * 0x10) = local_20;
      *(int *)(creatures + (long)local_28 * 0x10 + 8) = iVar1;
      local_20 = (char *)0x0;
      goto LAB_00401098;
    }
    local_28 = local_28 + 1;
  } while (true);
}

void printcreatures(void)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  int local_30;
  uint local_2c;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  local_2c = 1;
  local_30 = 0;
  do
  {
    if (9 < local_30)
    {
      if (lVar2 == *(long *)(in_FS_OFFSET + 0x28))
      {
        return;
      }
      /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    iVar1 = *(int *)(creatures + (long)local_30 * 0x10 + 8);
    if (iVar1 != 2)
    {
      if (iVar1 < 3)
      {
        if (iVar1 != 1)
        {
        LAB_00401185:
          *(undefined4 *)(creatures + (long)local_30 * 0x10 + 8) = 0;
        }
      }
      else
      {
        if ((iVar1 != 3) && (iVar1 != 4))
          goto LAB_00401185;
      }
    }
    if (*(int *)(creatures + (long)local_30 * 0x10 + 8) != 0)
    {
      printf("%d %s (%s) \n", (ulong)local_2c, *(undefined8 *)(creatures + (long)local_30 * 0x10));
      local_2c = local_2c + 1;
    }
    local_30 = local_30 + 1;
  } while (true);
}

void removecreature(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_18[8];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter creature number to remove : ");
  gets(local_18);
  iVar1 = atoi(local_18);
  iVar1 = iVar1 + -1;
  if (iVar1 < 10)
  {
    free(*(void **)(creatures + (long)iVar1 * 0x10));
    *(undefined4 *)(creatures + (long)iVar1 * 0x10 + 8) = 0;
  }
  else
  {
    puts("Invalid number");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
  {
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

char mainmenu(void)

{
  long in_FS_OFFSET;
  char local_12;
  char local_11;
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = '\0';
  do
  {
    while (true)
    {
      while (true)
      {
        if (local_11 != '\0')
        {
          if (local_10 == *(long *)(in_FS_OFFSET + 0x28))
          {
            return local_12;
          }
          /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        puts("....................");
        puts("[a]dd a creature");
        puts("[r]emove a creature");
        puts("[p]rint creatures in Ark");
        puts("e[x]it program");
        gets(&local_12);
        if (local_12 != 'p')
          break;
        printcreatures(&DAT_00404da4);
      }
      if ('p' < local_12)
        break;
      if (local_12 == 'a')
      {
        addcreature();
      }
      else
      {
      LAB_00401364:
        puts("Invalid option");
      }
    }
    if (local_12 == 'r')
    {
      removecreature();
    }
    else
    {
      if (local_12 != 'x')
        goto LAB_00401364;
      puts("That\'s all folks!");
      local_11 = '\x01';
    }
  } while (true);
}

void donkeyBrays(void)

{
  puts("Yay! You got the flag, Noah!");
  system("cat /home/nptel/CTF/challenge_4/flag.txt");
  return;
}

undefined8 main(void)

{
  long in_FS_OFFSET;
  char local_28[24];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("-----------------------------------");
  puts("   Hello Noah! Build your Ark! \n");
  puts("-----------------------------------");
  puts("Enter the name of your Ark");
  gets(local_28);
  mainmenu();
  sleep(2);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
  {
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
