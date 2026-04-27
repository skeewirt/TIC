// __ZL29directionChangeProcs_netmode2v @ 0x14BB40 (444 bytes)
// WotL iOS - debug symbols

int __fastcall directionChangeProcs_netmode2()
{
  int v0; // r4
  unsigned int *OTptrZ; // r0
  int v2; // r3
  int v3; // r1
  unsigned __int16 v4; // r3
  int v5; // r3
  int PadDirection; // r0
  int v7; // r5

  searchCurrentAnimation();
  if ( !pspNetCheckDuty() )
  {
    v0 = searchCurrentAnimation();
    getDisplayPosition();
    if ( gStopMode != 1 )
      ExecuteAnimations();
    if ( (*(_BYTE *)(v0 + 318) & 8) != 0 )
      displayDirection();
    DisplayAnimations();
    OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
    menu_call(OTptrZ, padd);
    if ( (*(_BYTE *)(v0 + 318) & 8) != 0 )
    {
      startTurn();
      startZoom();
      startFukan();
      if ( (sDirectChngYesNo & 0x20) == 0 || sScrollAreaOkFlag )
      {
        if ( (sDirectChngYesNo & 0x40) == 0 || sScrollAreaOkFlag )
        {
          PadDirection = getPadDirection(1);
          v7 = PadDirection;
          if ( PadDirection != -1 && PadDirection != oldDirection )
          {
            callSystemSound(3);
            oldDirection = v7;
            TRACE_Dummy("direction 0x%04x -> 0x%04x\n", v7, v7);
          }
          set_direction_sub(v0, v7);
        }
        else
        {
          TRACE_Dummy("CANCEL!\n");
          afterCommandInit();
        }
        goto LABEL_23;
      }
      TRACE_Dummy("OK!\n");
      v2 = *(_DWORD *)(v0 + 308);
      if ( v2 )
      {
        set_turn_end(*(unsigned __int8 *)(v2 + 428));
        directionChangeProcsSub(v0);
      }
      callSystemSound(1);
    }
    else
    {
      v3 = *(_DWORD *)(v0 + 360);
      if ( v3 <= 3 )
        set_direction_sub(v0, v3 << 10);
      v4 = *(_WORD *)(v0 + 8) + 6;
      *(_WORD *)(v0 + 8) = v4;
      if ( v4 <= 0x1Eu )
        goto LABEL_23;
      v5 = *(_DWORD *)(v0 + 308);
      if ( v5 )
      {
        set_turn_end(*(unsigned __int8 *)(v5 + 428));
        directionChangeProcsSub(v0);
      }
    }
    newTurn();
LABEL_23:
    iOSRotSlidCls();
  }
  return 0;
}

