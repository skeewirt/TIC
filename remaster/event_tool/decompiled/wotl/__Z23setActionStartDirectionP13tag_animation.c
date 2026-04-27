// __Z23setActionStartDirectionP13tag_animation @ 0x14A550 (124 bytes)
// WotL iOS - debug symbols

int __fastcall setActionStartDirection(int result)
{
  int v1; // r4
  int v2; // r1
  int v3; // r3

  v1 = result;
  if ( result )
  {
    v2 = 28 * gActivePanelX + 14 - *(__int16 *)(result + 64);
    v3 = 28 * gActivePanelZ + 14;
    result = v3 - *(__int16 *)(result + 68);
    if ( v2 || result )
    {
      result = ((unsigned __int16)ratan2(*(__int16 *)(v1 + 68) - v3, v2) - 512) & 0xC00;
      *(_WORD *)(v1 + 112) = result;
    }
  }
  return result;
}

