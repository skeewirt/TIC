// __Z12hook_jobmenuv @ 0x7AE08 (284 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_jobmenu()
{
  TRACE_Dummy("hook_jobmenu\n");
  if ( asmGetActiveTask(3) )
    task_killmyself();
  if ( asmGetActiveTask(1) )
    task_killmyself();
  maskhelp = 1;
  soundf = 1;
  mallocbytask(0x20000u);
  TRACE_Dummy("wait_overlay(7);\n");
  wait_overlay(7);
  TRACE_Dummy("task_wait(2);\n");
  task_wait(2);
  exeoverlay = 3;
  TRACE_Dummy("hook_jobmenu loop\n");
  do
  {
    pad = 0;
    asmTaskEntry();
  }
  while ( exeoverlay );
  pad = 0;
  TRACE_Dummy("hook_jobmenu freebytask\n");
  freeForFile((void *)FileLoadAddress);
  TRACE_Dummy("hook_jobmenu task_wait(2);\n");
  task_wait(2);
  maskhelp = 0;
  TRACE_Dummy("end hook_jobmenu\n");
  task_killmyself();
}

