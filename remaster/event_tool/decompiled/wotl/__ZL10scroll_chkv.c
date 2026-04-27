// __ZL10scroll_chkv @ 0xC4FE4 (120 bytes)
// WotL iOS - debug symbols

bool __fastcall scroll_chk()
{
  int v0; // r0

  if ( scroll )
    return 1;
  v0 = bCurChr / 5 - (__int16)((topy >> 15) - ((int)((unsigned __int64)(2290649225LL * topy) >> 32) >> 5));
  return v0 < 0 || v0 > 2;
}

