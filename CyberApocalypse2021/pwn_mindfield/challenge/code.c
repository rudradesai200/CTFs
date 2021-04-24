
void invalid(void)

{
  puts(&DAT_00400cb8);
  return;
}

void w(char *param_1)

{
  long lVar1;
  size_t __n;
  long in_FS_OFFSET;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __n = strlen(param_1);
  write(1, param_1, __n);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28))
  {
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

void r(void *param_1, void *param_2, int param_3, char *param_4, int param_5, int param_6)

{
  read(0, param_1, 9);
  return;
}

void _(void)

{
  long lVar1;
  size_t __n;
  long in_FS_OFFSET;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __n = strlen(&DAT_00400ccc);
  write(1, &DAT_00400ccc, __n);
  system("cat flag*");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28))
  {
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

void setup(void)

{
  setvbuf(stdin, (char *)0x0, 2, 0);
  setvbuf(stdout, (char *)0x0, 2, 0);
  alarm(0x7f);
  return;
}

void mission(undefined8 param_1, void *param_2, undefined8 param_3, char *param_4, int param_5,
             int param_6)

{
  unsigned long long *puVar1;
  unsigned long long uVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  void *pvVar3;
  char local_24[10];
  char local_1a[10];

  printf("Insert type of mine: ");
  r(local_24, param_2, extraout_EDX, param_4, param_5, param_6);
  pvVar3 = (void *)0x0;
  puVar1 = (unsigned long long *)strtoull(local_24, (char **)0x0, 0);
  printf("Insert location to plant: ");
  r(local_1a, pvVar3, extraout_EDX_00, param_4, param_5, param_6);
  puts("We need to get out of here as soon as possible. Run!");
  uVar2 = strtoull(local_1a, (char **)0x0, 0);
  *puVar1 = uVar2;

  return;
}

void choice(int param_1)

{

  if (param_1 == 1)
  {
    w("If you are not ready we cannot continue.\n");
    /* WARNING: Subroutine does not return */
    exit(0x22);
  }
  w("We are ready to proceed then!\n");
  mission();

  return;
}

void menu(void)

{
  int local_1c;
  char *local_18;

  local_18 = "Are you ready to plant the mine?\n1. No.\n2. Yes, I am ready.\n> ";
  w("Are you ready to plant the mine?\n1. No.\n2. Yes, I am ready.\n> ");
  __isoc99_scanf(&DAT_00400def, &local_1c);
  if ((local_1c == 1) || (local_1c == 2))
  {
    choice(local_1c);
  }
  else
  {
    invalid();
  }
  return;
}

undefined8 main(void)

{
  setup();
  menu();
  return 0;
}
