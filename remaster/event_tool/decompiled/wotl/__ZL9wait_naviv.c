// __ZL9wait_naviv @ 0x491B4 (40 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn wait_navi()
{
  int Input1; // r0

  Input1 = wasmGetInput1();
  nextblock6 = -2;
  word_272CC4 = -2;
  autokeyright(Input1);
  Wtask_killmyself();
}

