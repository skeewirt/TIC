// __ZL9wait_naviv_0 @ 0x64ED0 (40 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn wait_navi()
{
  int Input1; // r0

  Input1 = asmGetInput1();
  nextblock6 = -2;
  word_27C82C = -2;
  autokeyright(Input1);
  task_killmyself();
}

