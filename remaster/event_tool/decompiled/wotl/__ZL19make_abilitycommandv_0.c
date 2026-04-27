// __ZL19make_abilitycommandv_0 @ 0x7DE00 (872 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn make_abilitycommand()
{
  int bwp; // r0
  bool v1; // cc
  int v2; // r0
  int v3; // r6
  int v4; // r2
  int v5; // r3
  bool v6; // zf
  int v7; // r8
  int v8; // r8
  _BYTE *v9; // r4

  TRACE_Dummy("make_abilitycommand\n");
  bwp = get_bwp(word_27B28E);
  v1 = (unsigned int)lastcommandno > 0x30;
  if ( lastcommandno != 48 )
    v1 = (unsigned int)(lastcommandno - 19) > 1;
  if ( v1 && lastcommandno != 49 )
  {
    if ( (*(_BYTE *)(bwp + 97) & 8) != 0 )
    {
      v4 = *(unsigned __int8 *)(bwp + 401);
      if ( comtype[v4] == 10 )
        wordfield[0] = v4 + 45056;
      else
        wordfield[0] = *(__int16 *)(bwp + 402) + 28672;
      v3 = 32769;
      goto LABEL_20;
    }
    if ( (*(_BYTE *)(bwp + 97) & 1) != 0 )
    {
      v3 = 32770;
      goto LABEL_20;
    }
  }
  else
  {
    v2 = check_act_ok(bwp);
    switch ( v2 )
    {
      case 0:
        soundf = 5;
        task_killmyself();
      case 1:
        v3 = 4098;
        goto LABEL_20;
      case 2:
        v3 = 4099;
LABEL_20:
        v5 = byte_29EB11 & 0x30;
        v6 = v5 == 16;
        if ( v5 == 16 )
          v6 = (v3 & 0xFF00) == 0x8000;
        if ( v6 )
        {
          if ( !cancelok )
            soundf = 1;
        }
        else
        {
          v7 = cancelok;
          if ( !cancelok )
          {
            soundf = 5;
            *(_WORD *)(combase + 2268) = v3;
            task_create(asmtasknumber - 1, (void (__fastcall *)())disp_waitwindow);
            send_taskparamater(asmtasknumber - 1, combase + 2240, v7, v7);
            wait_taskend(asmtasknumber - 1);
          }
        }
        if ( (unsigned int)(v3 - 4098) <= 1 )
          task_killmyself();
        goto LABEL_32;
    }
  }
  if ( !cancelok )
    soundf = 1;
LABEL_32:
  TRACE_Dummy("    (combase+3)->roll 0x%08x\n", *(_DWORD *)(combase + 240));
  asmfunction = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))make_abilitycommandmain;
  asm_function(1u, 0, 0, 0, 0, 0);
  if ( direct )
  {
    *(_WORD *)(combase + 312) = 0;
    v8 = cancelok;
    if ( cancelok )
    {
      task_wait(2);
    }
    else
    {
      task_create(asmtasknumber - 1, (void (__fastcall *)())make_abilitylist);
      TRACE_Dummy("    (combase+3)->roll 0x%08x\n", *(_DWORD *)(combase + 240));
      send_taskparamater(asmtasknumber - 1, combase + 192, v8, v8);
    }
    do
      asmTaskEntry();
    while ( asmGetActiveTask(asmtasknumber - 1) );
    task_killmyself();
  }
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 1) = 1;
  v9 = &cursv[17 * word_27B28E];
  *(_WORD *)(combase + 312) = (char)v9[2];
  menudepth = 1;
  tutorial_syscall((int *)0xFC);
  disp_selectwindow();
  v9[2] = *(_WORD *)(combase + 312);
  task_killmyself();
}

