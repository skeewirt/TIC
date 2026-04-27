// __ZL21scrollLandscapeActionv @ 0x142504 (364 bytes)
// WotL iOS - debug symbols

void __fastcall scrollLandscapeAction()
{
  int v0; // r0
  __int16 MoveVectorForPanelUltra; // r0

  if ( !zooming && !fukaning && !turning && !scrolling )
  {
    v0 = searchAnimationByPositionBattle(gActivePanelX, gActivePanelZ, gActivePanelY);
    if ( v0 )
      v0 = dword_12B16B0 * (charTypeTable[4 * *(unsigned __int8 *)(v0 + 6) + 3] >> 1) / 4096;
    if ( (unsigned __int16)(gCursorX0 - 135) > 0xF2u || gCursorY0 - v0 <= 80 || gCursorY0 > 159 )
    {
      if ( (unsigned __int16)(gCursorX0 - 119) > 0x112u || gCursorY0 - v0 <= 64 || gCursorY0 > 175 )
        MoveVectorForPanelUltra = getMoveVectorForPanelUltra();
      else
        MoveVectorForPanelUltra = getMoveVectorForPanelFast();
      scrollLandscapeSub(MoveVectorForPanelUltra);
    }
    else
    {
      setLongVector(&gMoveVector, 0, 0, 0);
    }
  }
}

