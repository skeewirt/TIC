// __ZL13hook_debugchrv_0 @ 0x76098 (148 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_debugchr()
{
  request_status(0, 255, 255);
  maskhelp = 1;
  stoprequest = 1;
  wait_overlay(11);
  send_taskparamater(8, 0, 0, 1);
  wait_taskend(8);
  wait_allstatus();
  asmTaskEntry();
  asmTaskEntry();
  debug_chrmenu();
  stoprequest = 0;
  maskhelp = 0;
  sound_mask = 0;
  pad = 0;
  task_killmyself();
}

