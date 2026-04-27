// __ZL19hook_disp_itemmenu3v_0 @ 0x5E784 (248 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu3()
{
  int v0; // r4

  v0 = 32;
  localfadef = 0;
  asmTaskEntry();
  do
  {
    localfadef = v0;
    v0 += 32;
    asmTaskEntry();
  }
  while ( v0 != 256 );
  localfadef = 255;
  stoprequest = 1;
  send_taskparamater(8, 0, 0, 1);
  send_taskparamater(10, 0, 0, 1);
  send_taskparamater(11, 0, 0, 1);
  send_taskparamater(12, 0, 0, 1);
  send_taskparamater(13, 0, 0, 1);
  wait_allstatus();
  wait_overlay(2);
  mallocbytask(0x20000u);
  wait_overlay(10);
  task_wait(2);
  allstopf = 1;
  task_create(13, (void (__fastcall *)())hook_disp_itemmenu2);
  task_killmyself();
}

