// __ZL19make_abilitycommandv @ 0x57138 (872 bytes)
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
  bwp = get_bwp(word_271BAE);
  v1 = (unsigned int)wlastcommandno > 0x30;
  if ( wlastcommandno != 48 )
    v1 = (unsigned int)(wlastcommandno - 19) > 1;
  if ( v1 && wlastcommandno != 49 )
  {
    if ( (*(_BYTE *)(bwp + 97) & 8) != 0 )
    {
      v4 = *(unsigned __int8 *)(bwp + 401);
      if ( comtype[v4] == 10 )
        wwordfield[0] = v4 + 45056;
      else
        wwordfield[0] = *(__int16 *)(bwp + 402) + 28672;
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
        wsoundf = 5;
        Wtask_killmyself();
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
            wsoundf = 1;
        }
        else
        {
          v7 = cancelok;
          if ( !cancelok )
          {
            wsoundf = 5;
            *(_WORD *)(wcombase + 2268) = v3;
            Wtask_create(wasmtasknumber - 1, (void (__fastcall *)())Wdisp_waitwindow);
            Wsend_taskparamater(wasmtasknumber - 1, wcombase + 2240, v7, v7);
            Wwait_taskend(wasmtasknumber - 1);
          }
        }
        if ( (unsigned int)(v3 - 4098) <= 1 )
          Wtask_killmyself();
        goto LABEL_32;
    }
  }
  if ( !cancelok )
    wsoundf = 1;
LABEL_32:
  TRACE_Dummy("    (combase+3)->roll 0x%08x\n", *(_DWORD *)(wcombase + 240));
  wasmfunction = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))Wmake_abilitycommandmain;
  wasm_function(1u, 0, 0, 0, 0, 0);
  if ( direct )
  {
    *(_WORD *)(wcombase + 312) = 0;
    v8 = cancelok;
    if ( cancelok )
    {
      Wtask_wait(2);
    }
    else
    {
      Wtask_create(wasmtasknumber - 1, (void (__fastcall *)())make_abilitylist);
      TRACE_Dummy("    (combase+3)->roll 0x%08x\n", *(_DWORD *)(wcombase + 240));
      Wsend_taskparamater(wasmtasknumber - 1, wcombase + 192, v8, v8);
    }
    do
      wasmTaskEntry();
    while ( wasmGetActiveTask(wasmtasknumber - 1) );
    Wtask_killmyself();
  }
  *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber + 1) = 1;
  v9 = &cursv[17 * word_271BAE];
  *(_WORD *)(wcombase + 312) = (char)v9[2];
  menudepth = 1;
  Wtutorial_syscall((int *)0xFC);
  Wdisp_selectwindow();
  v9[2] = *(_WORD *)(wcombase + 312);
  Wtask_killmyself();
}

