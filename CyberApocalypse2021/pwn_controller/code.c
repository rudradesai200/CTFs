
void reset(void)

{
  printf("\x1b[0m");
  return;
}

void rainbow(char *param_1)

{
  size_t sVar1;
  char *local_f0;
  int imp0;
  int str_dec;
  uint local_b0;

  str_dec = 0;
  sVar1 = strlen(param_1);
  imp0 = 0;
  local_f0 = param_1;
  while (imp0 < (int)sVar1)
  {
    if (str_dec < 6)
    {
      if (check == 0)
      {
        printf("\x1b[1;%s%c", *(int *)(color_arr + (long)str_dec * 8),
               (ulong)(uint)(int)*local_f0);
      }
      else
      {
        printf("\x1b[1;%d;%s%c", (ulong)local_b0, *(int *)(color_arr + (long)str_dec * 8),
               (ulong)(uint)(int)*local_f0);
      }
    }
    else
    {
      str_dec = 0;
      if (check == 0)
      {
        printf("\x1b[1;%s%c", color_arr._0_8_, (ulong)(uint)(int)*local_f0);
      }
      else
      {
        printf("\x1b[1;%d;%s%c", (ulong)local_b0, color_arr._0_8_, (ulong)(uint)(int)*local_f0);
      }
    }
    str_dec = str_dec + 1;
    local_f0 = local_f0 + 1;
    imp0 = imp0 + 1;
  }
  reset();
  return;
}

/* WARNING: Removing unreachable block (ram,0x00400acf) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff58 : 0x00400ae1 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void color(int param_1, char *param_2)

{
  int str_cmp;
  char *clr_str;
  uint str_dec;
  char *local_a8;

  str_cmp = strcmp(param_2, "red");
  if (str_cmp == 0)
  {
    clr_str = "31m";
  }
  else
  {
    str_cmp = strcmp(param_2, "green");
    if (str_cmp == 0)
    {
      clr_str = "32m";
    }
    else
    {
      str_cmp = strcmp(param_2, "yellow");
      if (str_cmp == 0)
      {
        clr_str = "33m";
      }
      else
      {
        str_cmp = strcmp(param_2, "blue");
        if (str_cmp == 0)
        {
          clr_str = "34m";
        }
        else
        {
          str_cmp = strcmp(param_2, "magenta");
          if (str_cmp == 0)
          {
            clr_str = "35m";
          }
          else
          {
            str_cmp = strcmp(param_2, "cyan");
            if (str_cmp == 0)
            {
              clr_str = "36m";
            }
            else
            {
              str_cmp = strcmp(param_2, "rainbow");
              clr_str = param_2;
              if (str_cmp == 0)
              {
                check = 1;
              }
              else
              {
                puts("Unknown color!");
              }
            }
          }
        }
      }
    }
  }
  if (local_a8 == (char *)0x0)
  {
    if (check == 0)
    {
      printf("\x1b[1;%s%s", clr_str, param_1);
    }
    else
    {
      rainbow(param_1, str_dec, str_dec);
    }
  }
  else
  {
    str_cmp = strcmp(local_a8, "underline");
    if (str_cmp == 0)
    {
      str_dec = 4;
    }
    else
    {
      str_cmp = strcmp(local_a8, "blink");
      if (str_cmp == 0)
      {
        str_dec = 5;
      }
      else
      {
        str_cmp = strcmp(local_a8, "bold");
        if (str_cmp == 0)
        {
          str_dec = 6;
        }
        else
        {
          str_cmp = strcmp(local_a8, "background");
          if (str_cmp == 0)
          {
            str_dec = 7;
          }
          else
          {
            str_cmp = strcmp(local_a8, "hidden");
            if (str_cmp == 0)
            {
              str_dec = 8;
            }
            else
            {
              str_cmp = strcmp(local_a8, "deleted");
              if (str_cmp == 0)
              {
                str_dec = 9;
              }
            }
          }
        }
      }
    }
    if (check == 0)
    {
      printf("\x1b[1;%d;%s%s", (ulong)str_dec, clr_str, param_1);
    }
    else
    {
      rainbow(param_1, str_dec, str_dec);
    }
  }
  reset();
  check = 0;
  return;
}

void printstr(char *param_1)

{
  size_t sVar1;
  ulong local_10;

  local_10 = 0;
  while (true)
  {
    sVar1 = strlen(param_1);
    if (sVar1 <= local_10)
      break;
    putchar((int)param_1[local_10]);
    usleep(30000);
    local_10 = local_10 + 1;
  }
  return;
}

int add(int param_1, int param_2)

{
  return param_2 + param_1;
}

undefined4 menu(void)

{
  undefined4 imp;

  printstr("Choose operation:\n\n");
  puts(&DAT_004012da);
  puts(&DAT_004012e2);
  puts(&DAT_004012ea);
  puts(&DAT_004012f2);
  printf("> ");
  __isoc99_scanf(&DAT_004012fd, &imp);
  return imp;
}

uint calc(void)

{
  ushort uVar1;
  float fVar2;
  uint local_18;
  uint local_14;
  int local_10;
  uint imp;

  printstr("Insert the amount of 2 different types of recources: ");
  __isoc99_scanf("%d %d", &local_14, &local_18);
  local_10 = menu();
  if ((0x45 < (int)local_14) || (0x45 < (int)local_18))
  {
    printstr("We cannot use these many resources at once!\n");
    /* WARNING: Subroutine does not return */
    exit(0x69);
  }
  if (local_10 == 2)
  {
    imp = sub(local_14, local_18, local_18);
    printf("%d - %d = %d\n", (ulong)local_14, (ulong)local_18, (ulong)imp);
    return imp;
  }
  if (local_10 < 3)
  {
    if (local_10 == 1)
    {
      imp = add(local_14, local_18, local_18);
      printf("%d + %d = %d\n", (ulong)local_14, (ulong)local_18, (ulong)imp);
      return imp;
    }
  }
  else
  {
    if (local_10 == 3)
    {
      uVar1 = mult(local_14, local_18, local_18);
      imp = (uint)uVar1;
      printf("%d * %d = %d\n", (ulong)local_14, (ulong)local_18, (ulong)imp);
      return imp;
    }
    if (local_10 == 4)
    {
      fVar2 = (float)divi(local_14, local_18, local_18);
      imp = (uint)(long)fVar2;
      printf("%d / %d = %d\n", (ulong)local_14, (ulong)local_18, (long)fVar2 & 0xffffffff);
      return imp;
    }
  }
  printstr("Invalid operation, exiting..\n");
  return imp;
}

void calculator(void)

{
  char local_28[28];
  int imp;

  imp = calc();
  if (imp == 0xff3a)
  {
    printstr("Something odd happened!\nDo you want to report the problem?\n> ");
    __isoc99_scanf(&DAT_004013e6, local_28);
    if ((local_28[0] == 'y') || (local_28[0] == 'Y'))
    {
      printstr("Problem reported!\n");
    }
    else
    {
      printstr("Problem ingored\n");
    }
  }
  else
  {
    calculator();
  }
  return;
}

void calculator(void)

{
  char local_28[28];
  int imp;

  imp = calc();
  if (imp == 0xff3a)
  {
    printstr("Something odd happened!\nDo you want to report the problem?\n> ");
    __isoc99_scanf(&DAT_004013e6, local_28);
    if ((local_28[0] == 'y') || (local_28[0] == 'Y'))
    {
      printstr("Problem reported!\n");
    }
    else
    {
      printstr("Problem ingored\n");
    }
  }
  else
  {
    calculator();
  }
  return;
}

void welcome(void)

{
  color(&DAT_00401411, &DAT_0040122a, &DAT_00401274);
  return;
}

int main(void)

{
  setvbuf(stdout, (char *)0x0, 2, 0);
  welcome();
  calculator();
  return 0;
}
