// __ZL13hook_debugchrv @ 0x55204 (148 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_debugchr()
{
  Wrequest_status(0, 255, 255);
  wmaskhelp = 1;
  wstoprequest = 1;
  Wwait_overlay(11);
  Wsend_taskparamater(8, 0, 0, 1);
  Wwait_taskend(8);
  wait_allstatus();
  wasmTaskEntry();
  wasmTaskEntry();
  debug_chrmenu();
  wstoprequest = 0;
  wmaskhelp = 0;
  wsound_mask = 0;
  pad = 0;
  Wtask_killmyself();
}

