// __Z15request_commandi @ 0x664A8 (600 bytes)
// WotL iOS - debug symbols

void __fastcall request_command(int a1)
{
  int AnimationIDFormBattleWork; // r0
  int v3; // r1
  _BOOL4 v4; // r12
  int v5; // r1
  int v6; // r6
  char *v7; // r8
  char *v8; // r4
  int v9; // r2
  int v10; // r3
  bool v11; // zf
  char v12; // r2
  __int16 v13[4]; // [sp+0h] [bp-18h] BYREF

  TRACE_Dummy("request_command %d\n", a1);
  hook_Debug("request_command");
  if ( tutorialstartf != 1 )
  {
    if ( !stoprequest && !allstopf && !helpafter && a1 != -1 )
    {
      lastcommandno = a1;
      combase = (int)&comtest;
      AnimationIDFormBattleWork = getAnimationIDFormBattleWork(word_27B28E);
      getanimpos2d(AnimationIDFormBattleWork, v13);
      TRACE_Dummy("    svec.vx %d\n", v13[0]);
      v3 = 0;
      v4 = v13[0] > 256;
      do
      {
        if ( possw[v4 + v3] )
          *(_WORD *)(32 * v3 + combase + 8) = possw[v3 + v4] + 128;
        v3 += 2;
      }
      while ( v3 != 104 );
      v5 = 0;
      while ( a1 != comnolist[4 * v5] )
      {
        if ( ++v5 == 12 )
          goto LABEL_23;
      }
      v6 = 0;
      v7 = (char *)&cursv + 17 * word_27B28E;
      TRACE_Dummy("COMMAND:%d %d\n", v5, a1);
      v8 = (char *)&setrsvcursorposdat;
      do
      {
        if ( a1 == *v8 )
        {
          v9 = v8[2];
          v10 = *v7;
          v11 = v9 == v10;
          if ( v9 != v10 )
            v11 = v8[3] == v10;
          if ( v11 || v8[4] == v10 )
          {
            v12 = v8[1];
            *v7 = v12;
            TRACE_Dummy("    setrsvcursorposdat[%d][1:%d\n]", v6, v12);
          }
        }
        ++v6;
        v8 += 5;
      }
      while ( v6 != 8 );
      *(_WORD *)((a1 << 6) + combase + 56) = *v7;
LABEL_23:
      *(_WORD *)(combase + 568) = 0;
      word_27C868 = 0;
      clear_menu();
      task_create(3, (void (__fastcall *)())recovercanceledwindow);
      send_taskparamater(3, a1, 0, 0);
    }
    helpafter = 0;
  }
}

