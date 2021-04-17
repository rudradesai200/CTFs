
void ignore_me_init_buffering(void)

{
  setvbuf(stdout, (char *)0x0, 2, 0);
  setvbuf(stdin, (char *)0x0, 2, 0);
  setvbuf(stderr, (char *)0x0, 2, 0);
  return;
}

void kill_on_timeout(int param_1)

{
  if (param_1 == 0xe)
  {
    printf("[!] Anti DoS Signal. Patch me out for testing.");
    /* WARNING: Subroutine does not return */
    _exit(0);
  }
  return;
}

void ignore_me_init_signal(void)

{
  signal(14, kill_on_timeout);
  alarm(60);
  return;
}

void WINgardium_leviosa(void)

{
  puts(&DAT_00400ab8);
  puts(&DAT_00400b04);
  puts(&DAT_00400b28);
  system("cat flag.txt");
  return;
}

void welcome(void)

{
  char local_108[256];

  puts("Enter your witch name:");
  gets(local_108);
  puts(&DAT_00400ab8);
  puts(&DAT_00400b98);
  puts(&DAT_00400b28);
  printf(local_108);
  return;
}

void AAAAAAAA(void)

{
  int iVar1;
  char local_108[256];

  puts(" enter your magic spell:");
  gets(local_108);
  iVar1 = strcmp(local_108, "Expelliarmus");
  if (iVar1 == 0)
  {
    puts("~ Protego!");
    return;
  }
  puts("-10 Points for Hufflepuff!");
  /* WARNING: Subroutine does not return */
  _exit(0);
}

void main(void)

{
  ignore_me_init_buffering();
  ignore_me_init_signal();
  welcome();
  AAAAAAAA();
  return;
}
