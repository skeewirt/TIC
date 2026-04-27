// __ZL11hook_finishv @ 0x5FD64 (24 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_finish()
{
  asmTaskEntry();
  finishAttackTeamSelect();
  asmTaskEntry();
  task_killmyself();
}

