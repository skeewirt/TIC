// __ZL13executeScrollv @ 0x148E1C (656 bytes)
// WotL iOS - debug symbols

void __fastcall executeScroll()
{
  int PadDirection; // r0
  int v1; // r3
  int v2; // r3
  int v3; // r3
  int v4; // r3

  if ( iOSTutoCheck() )
  {
    if ( !scrolling )
      return;
    PadDirection = getPadDirection(0);
    if ( PadDirection == 1536 )
    {
      v2 = dword_12B16FC + 0x4000;
      goto LABEL_37;
    }
    if ( PadDirection <= 1536 )
    {
      if ( PadDirection != 512 )
      {
        if ( PadDirection != 1024 )
        {
          if ( PadDirection )
            goto LABEL_40;
          v1 = dword_12B16FC - 0x4000;
          goto LABEL_29;
        }
        goto LABEL_38;
      }
      v2 = dword_12B16FC - 0x4000;
LABEL_37:
      dword_12B16FC = v2;
LABEL_38:
      v4 = mapVector - 0x4000;
      goto LABEL_39;
    }
    if ( PadDirection == 2560 )
    {
      v3 = dword_12B16FC + 0x4000;
    }
    else
    {
      if ( PadDirection <= 2560 )
      {
        if ( PadDirection == 2048 )
        {
          v1 = dword_12B16FC + 0x4000;
LABEL_29:
          dword_12B16FC = v1;
        }
LABEL_40:
        if ( mapVector > 114688 * (unsigned __int8)gMapX + 458752 )
          mapVector = 114688 * (unsigned __int8)gMapX + 458752;
        if ( mapVector < -458752 )
          mapVector = -458752;
        if ( dword_12B16FC > 114688 * (unsigned __int8)gMapY + 458752 )
          dword_12B16FC = 114688 * (unsigned __int8)gMapY + 458752;
        goto LABEL_46;
      }
      if ( PadDirection == 3072 )
      {
LABEL_35:
        v4 = mapVector + 0x4000;
LABEL_39:
        mapVector = v4;
        goto LABEL_40;
      }
      if ( PadDirection != 3584 )
        goto LABEL_40;
      v3 = dword_12B16FC - 0x4000;
    }
    dword_12B16FC = v3;
    goto LABEL_35;
  }
  if ( !g_isRayPickLock && iOSTchInputCheck() && !iOS_getV2Icon(10) && scrolling && iOSSlideDirecChgMode() )
  {
    iOSexecuteScroll();
    if ( mapVector > 114688 * (unsigned __int8)gMapX + 458752 )
      mapVector = 114688 * (unsigned __int8)gMapX + 458752;
    if ( mapVector < -458752 )
      mapVector = -458752;
    if ( dword_12B16FC > 114688 * (unsigned __int8)gMapY + 458752 )
      dword_12B16FC = 114688 * (unsigned __int8)gMapY + 458752;
LABEL_46:
    if ( dword_12B16FC < -458752 )
      dword_12B16FC = -458752;
    return;
  }
  if ( iOSSlidOkCheck() )
    sTchSlideFlag = 0;
}

