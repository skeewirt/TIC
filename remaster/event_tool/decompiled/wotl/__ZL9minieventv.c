// __ZL9minieventv @ 0x602F0 (528 bytes)
// WotL iOS - debug symbols, no obfuscation

void __fastcall __noreturn minievent()
{
  int v0; // r4
  __int16 *v1; // r1
  char **v2; // r4

  minieventcounter = 1;
  makemessagestructure();
  v0 = *((_DWORD *)&asmtaskframe + 256 * asmtasknumber);
  if ( (byte_29EB11 & 0x30) != 0 )
    v0 = phaserec[10 * v0 + 8];
  if ( !tutorialstartf )
  {
    while ( asmGetActiveTask(1) )
    {
      if ( dword_CF38A0 == 68 )
        task_killmyself();
      asmTaskEntry();
    }
  }
  waitscrolling();
  TRACE_Dummy("minievent ix:%d navi:%d\n", v0, ((unsigned __int8)byte_29EB11 >> 4) & 3);
  hook_Debug2("minievent");
  wait_taskend(8);
  v1 = &phaserec[10 * v0];
  lastcommandno = *v1;
  *(_WORD *)((v1[2] << 6) + combase + 28) = v1[1];
  nextblock28 = v1[3];
  *(_WORD *)((v1[2] << 6) + combase + 32) = v1[4];
  if ( (unsigned int)(v0 - 31) <= 8 && ((1 << (v0 - 31)) & 0x181) != 0 )
    hook_fix_bugno_931(v0);
  if ( v0 == 31 )
  {
    task_create(8, (char *)hook_disp_suc);
    send_taskparamater(8, 0, whois31, 0);
    task_killmyself();
  }
  if ( v0 != 8 )
    tutorial_syscall(v0);
  v2 = (char **)&phaserec[10 * v0];
  task_create(8, v2[3]);
  send_taskparamater4(8, (*((__int16 *)v2 + 2) << 6) + combase, 0, 0, 0);
  minieventcounter = 0;
  task_killmyself();
}

