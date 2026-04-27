// __ZL22initCommandMenuDisplayv @ 0x144774 (264 bytes)
// WotL iOS - debug symbols

int __fastcall initCommandMenuDisplay()
{
  int v0; // r0
  int v1; // r2
  int v2; // r4
  int v3; // r3

  return_actionstructure();
  v0 = searchAnimationByPositionBattle(gActivePanelX, gActivePanelZ, gActivePanelY);
  if ( v0 )
  {
    v1 = *(unsigned __int8 *)(v0 + 4);
    gActiveAnimation = v1;
    if ( gInterventionMode || v1 != gCurrentAnimation )
    {
      unitCommandInitOther();
    }
    else if ( (*(_BYTE *)(v0 + 318) & 8) != 0 )
    {
      unitCommandInitCurrent();
    }
    else
    {
      scrolling = 0;
      gStatusMode = 5;
      v2 = searchCurrentAnimation();
      *(_WORD *)(v2 + 8) = 0;
      *(_BYTE *)(v2 + 442) = 0;
      ASHURA_set_Mesh(0, 0);
      v3 = *(_DWORD *)(v2 + 308);
      if ( v3 )
        request_status(3, *(unsigned __int8 *)(v3 + 428), 0);
    }
  }
  pspNetCheckDuty();
  return pspNetSetControlChar(gStatusMode != 4);
}

