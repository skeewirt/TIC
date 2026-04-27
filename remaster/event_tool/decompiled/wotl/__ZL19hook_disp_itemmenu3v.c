// __ZL19hook_disp_itemmenu3v @ 0x4736C (248 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu3()
{
  int v0; // r4

  v0 = 32;
  wlocalfadef = 0;
  wasmTaskEntry();
  do
  {
    wlocalfadef = v0;
    v0 += 32;
    wasmTaskEntry();
  }
  while ( v0 != 256 );
  wlocalfadef = 255;
  wstoprequest = 1;
  Wsend_taskparamater(8, 0, 0, 1);
  Wsend_taskparamater(10, 0, 0, 1);
  Wsend_taskparamater(11, 0, 0, 1);
  Wsend_taskparamater(12, 0, 0, 1);
  Wsend_taskparamater(13, 0, 0, 1);
  wait_allstatus();
  Wwait_overlay(2);
  mallocbytask(0x20000u);
  Wwait_overlay(10);
  Wtask_wait(2);
  wallstopf = 1;
  Wtask_create(13, (void (__fastcall *)())hook_disp_itemmenu2);
  Wtask_killmyself();
}

