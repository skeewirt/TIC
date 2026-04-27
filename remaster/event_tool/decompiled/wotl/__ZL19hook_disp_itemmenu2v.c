// __ZL19hook_disp_itemmenu2v @ 0x475B8 (288 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu2()
{
  int i; // r4
  int v1; // r0
  int v2; // r4

  waddactiveturn = 4;
  do
    wasmTaskEntry();
  while ( wasmGetActiveTask(6) );
  wexeoverlay = 2;
  wallstopf = 0;
  do
    Wtask_wait(1);
  while ( wexeoverlay );
  freeForFile((void *)FileLoadAddress);
  Wsend_taskparamater(2, 0, 0, 1);
  for ( i = 3; i != 15; ++i )
  {
    v1 = i;
    Wsend_taskparamater(v1, 0, 0, 1);
  }
  v2 = 239;
  wlocalfadef = 255;
  wasmTaskEntry();
  do
  {
    wlocalfadef = v2;
    v2 -= 16;
    wasmTaskEntry();
  }
  while ( v2 != -1 );
  wlocalfadef = 0;
  wmaskhelp = 0;
  wstoprequest = 0;
  waddactiveturn = 0;
  Wrequest_status(2, word_271BAE, 255);
  Wtask_killmyself();
}

