// __Z16executeMapScrollv @ 0x1552F0 (184 bytes)
// WotL iOS - debug symbols

void __fastcall executeMapScroll()
{
  if ( gScrollChangeStep )
  {
    gScrollTmp += gScrollChangeValue;
    dword_12B16A0 += dword_12B1718;
    dword_12B16A4 += dword_12B171C;
    gTheVec = gScrollTmp / 4096;
    dword_12B1680 = dword_12B16A0 / 4096;
    dword_12B1684 = dword_12B16A4 / 4096;
    --gScrollChangeStep;
  }
}

