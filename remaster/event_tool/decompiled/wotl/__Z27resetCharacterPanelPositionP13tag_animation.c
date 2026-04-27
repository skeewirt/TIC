// __Z27resetCharacterPanelPositionP13tag_animation @ 0x13EA28 (88 bytes)
// WotL iOS - debug symbols

int __fastcall resetCharacterPanelPosition(int a1)
{
  int result; // r0

  *(_DWORD *)(a1 + 24) = (28 * *(unsigned __int8 *)(a1 + 124) + 14) << 12;
  *(_DWORD *)(a1 + 32) = (28 * *(unsigned __int8 *)(a1 + 125) + 14) << 12;
  result = (__int16)getOriginalAnimationHight() << 12;
  *(_DWORD *)(a1 + 28) = result;
  return result;
}

