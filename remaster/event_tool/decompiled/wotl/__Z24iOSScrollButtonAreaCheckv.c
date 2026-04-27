// __Z24iOSScrollButtonAreaCheckv @ 0x1D8A78 (148 bytes)
// WotL iOS - debug symbols

bool __fastcall iOSScrollButtonAreaCheck()
{
  int v0; // r0
  int v1; // r3
  int v2; // r0

  v0 = searchCurrentAnimation();
  if ( v0
    && (unsigned __int16)(*(_WORD *)(v0 + 288) - 213) <= 0x56u
    && (v1 = dword_12B16B0 * (charTypeTable[4 * *(unsigned __int8 *)(v0 + 6) + 3] >> 1),
        v2 = *(__int16 *)(v0 + 290),
        v2 - v1 / 4096 > 80) )
  {
    return v2 <= 159;
  }
  else
  {
    return 0;
  }
}

