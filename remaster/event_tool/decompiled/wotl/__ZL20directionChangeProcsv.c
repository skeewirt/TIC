// __ZL20directionChangeProcsv @ 0x14BD20 (1328 bytes)
// WotL iOS - debug symbols

int __fastcall directionChangeProcs()
{
  int v0; // r5
  unsigned int *OTptrZ; // r0
  int result; // r0
  int V2Icon; // r0
  int TouchBeginX; // r0
  int TouchBeginY; // r0
  int v6; // r11
  int TouchNowX; // r10
  int TouchNowY; // r0
  int v9; // kr00_4
  int v10; // r6
  int v11; // r8
  int v12; // r4
  int v13; // r2
  int IsLeftHand; // r0
  int v15; // r4
  int v16; // r6
  int TouchTap; // r4
  int TapedDirection; // r4
  int v19; // r2
  int v20; // r6
  int v21; // r0
  int PadDirection; // r0
  int v23; // r4
  int v24; // r1
  unsigned __int16 v25; // r3
  int v26; // r3
  int v27; // [sp+0h] [bp-1Ch]

  v0 = searchCurrentAnimation();
  getDisplayPosition();
  if ( gStopMode != 1 )
    ExecuteAnimations();
  if ( (*(_BYTE *)(v0 + 318) & 8) != 0 )
    displayDirection();
  DisplayAnimations();
  OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
  result = menu_call(OTptrZ, padd);
  if ( (*(_BYTE *)(v0 + 318) & 8) != 0 )
  {
    iOS_setV2Icon(5, 1);
    iOS_setV2Icon(4, 1);
    iOS_setV2Icon(9, 1);
    iOS_setV2Icon(12, 1);
    iOS_setV2Icon(9, 0);
    startZoom();
    iOS_getV2Icon(101);
    V2Icon = iOS_getV2Icon(101);
    if ( !V2Icon )
    {
      if ( iOS_isInGameArea() )
      {
        iOS_setV2Icon(101, 1);
        TouchBeginX = iOS_getTouchBeginX();
        iOS_setV2Icon(102, TouchBeginX);
        TouchBeginY = iOS_getTouchBeginY();
        iOS_setV2Icon(103, TouchBeginY);
      }
LABEL_35:
      TouchTap = iOS_getTouchTap();
      if ( iOSTutoCheck() && (read_eventflag(41) & 0x20) != 0 )
        TouchTap = 0;
      if ( (trg & 0x40) != 0 )
      {
        iOS_soundDirect(2);
LABEL_56:
        if ( (trg & 0x20) != 0 )
        {
          result = TRACE_Dummy("directionChangeProcs OK\n");
          sDirectChngYesNo = trg;
LABEL_60:
          gStatusMode = 72;
          return result;
        }
        if ( (trg & 0x40) != 0 )
        {
          result = TRACE_Dummy("CANCEL!\n");
          sDirectChngYesNo = trg;
          goto LABEL_60;
        }
        goto LABEL_61;
      }
      if ( !TouchTap && (trg & 0x20) == 0 )
      {
LABEL_61:
        PadDirection = getPadDirection(1);
        v23 = PadDirection;
        if ( PadDirection != -1 && PadDirection != oldDirection )
        {
          callSystemSound(3);
          oldDirection = v23;
          TRACE_Dummy("direction 0x%04x -> 0x%04x\n", v23, v23);
        }
        return set_direction_sub(v0, v23);
      }
      TapedDirection = getTapedDirection();
      TRACE_Dummy("no:%d\n", TapedDirection);
      if ( TapedDirection == -1 )
      {
        if ( (byte_29EB13 & 8) != 0 )
        {
          TRACE_Dummy("gTouchTap no:%d 0x%04x\n", -1, -1);
LABEL_55:
          iOSBtlStsButtonCheck();
          goto LABEL_56;
        }
        TapedDirection = ((((unsigned int)(v19 >> 31) >> 30) + *(__int16 *)(v0 + 112) / 1024) & 3)
                       - ((unsigned int)(v19 >> 31) >> 30);
      }
      switch ( TapedDirection )
      {
        case 0:
          v20 = 0;
          goto LABEL_73;
        case 1:
          v20 = 1024;
          goto LABEL_73;
        case 2:
          v20 = 2048;
          goto LABEL_73;
        case 3:
          v20 = 3072;
LABEL_73:
          TRACE_Dummy("gTouchTap no:%d 0x%04x\n", TapedDirection, v20);
          break;
        default:
          TRACE_Dummy("gTouchTap no:%d 0x%04x\n", TapedDirection, -1);
          if ( TapedDirection == -1 )
            goto LABEL_55;
          v20 = -1;
          break;
      }
      set_direction_sub(v0, v20);
      if ( TapedDirection == iOS_getDirectionTapDir() )
      {
        v21 = -1;
        trg |= 0x20u;
      }
      else
      {
        iOS_soundDirect(1);
        v21 = TapedDirection;
      }
      iOS_setDirectionTapDir(v21);
      goto LABEL_56;
    }
    if ( V2Icon != 1 )
      goto LABEL_35;
    v6 = iOS_getV2Icon(102);
    v27 = iOS_getV2Icon(103);
    TouchNowX = iOS_getTouchNowX();
    TouchNowY = iOS_getTouchNowY();
    v9 = *(__int16 *)(v0 + 112);
    v10 = (v9 / 1024) & 3;
    v11 = TouchNowY;
    if ( (~TouchNowX & ~TouchNowY) >= 0 || (int)iOS_getTouchCount() <= 10 )
    {
      LOBYTE(v12) = (v9 / 1024) & 3;
    }
    else
    {
      if ( TouchNowX < v6 - 16 )
      {
        LOBYTE(v12) = v10 + 1;
        v13 = 1;
      }
      else
      {
        v12 = (v9 / 1024) & 3;
        v13 = 0;
      }
      if ( TouchNowX > v6 + 16 )
      {
        LOBYTE(v12) = v12 - 1;
        v13 = 1;
      }
      if ( v11 < v27 - 16 )
      {
        IsLeftHand = Settings_IsLeftHand();
        v13 = 1;
        if ( IsLeftHand )
          LOBYTE(v12) = v12 + 1;
        else
          LOBYTE(v12) = v12 - 1;
      }
      if ( v11 <= v27 + 16 )
      {
        if ( !v13 )
          goto LABEL_28;
      }
      else if ( Settings_IsLeftHand() )
      {
        LOBYTE(v12) = v12 - 1;
      }
      else
      {
        LOBYTE(v12) = v12 + 1;
      }
      iOS_setV2Icon(102, TouchNowX);
      iOS_setV2Icon(103, v11);
      TRACE_Dummy("CHG %d %d\n", TouchNowX, v11);
    }
LABEL_28:
    v15 = v12 & 3;
    if ( v15 != v10 )
    {
      switch ( v15 )
      {
        case 0:
          v16 = 0;
          break;
        case 1:
          v16 = 1024;
          break;
        case 2:
          v16 = 2048;
          break;
        case 3:
          v16 = 3072;
          break;
      }
      set_direction_sub(v0, v16);
      iOS_setDirectionTapDir(v15);
      callSystemSound(3);
    }
    goto LABEL_35;
  }
  v24 = *(_DWORD *)(v0 + 360);
  if ( v24 <= 3 )
    result = set_direction_sub(v0, v24 << 10);
  v25 = *(_WORD *)(v0 + 8) + 6;
  *(_WORD *)(v0 + 8) = v25;
  if ( v25 > 0x1Eu )
  {
    v26 = *(_DWORD *)(v0 + 308);
    if ( v26 )
    {
      set_turn_end(*(unsigned __int8 *)(v26 + 428));
      directionChangeProcsSub(v0);
    }
    return newTurn();
  }
  return result;
}

