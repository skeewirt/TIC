// __Z13Whook_jobmenuv @ 0x562E0 (284 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn Whook_jobmenu()
{
  TRACE_Dummy("hook_jobmenu\n");
  if ( wasmGetActiveTask(3) )
    Wtask_killmyself();
  if ( wasmGetActiveTask(1) )
    Wtask_killmyself();
  wmaskhelp = 1;
  wsoundf = 1;
  mallocbytask(0x20000u);
  TRACE_Dummy("wait_overlay(7);\n");
  Wwait_overlay(7);
  TRACE_Dummy("task_wait(2);\n");
  Wtask_wait(2);
  wexeoverlay = 3;
  TRACE_Dummy("hook_jobmenu loop\n");
  do
  {
    pad = 0;
    wasmTaskEntry();
  }
  while ( wexeoverlay );
  pad = 0;
  TRACE_Dummy("hook_jobmenu freebytask\n");
  freeForFile((void *)FileLoadAddress);
  TRACE_Dummy("hook_jobmenu task_wait(2);\n");
  Wtask_wait(2);
  wmaskhelp = 0;
  TRACE_Dummy("end hook_jobmenu\n");
  Wtask_killmyself();
}

