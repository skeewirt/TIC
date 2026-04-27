// __ZL25resetCharacterPositionSubP13tag_animation @ 0x147FD4 (164 bytes)
// WotL iOS - debug symbols

int __fastcall resetCharacterPositionSub(int a1)
{
  *(_BYTE *)(a1 + 124) = *(_BYTE *)(a1 + 132);
  *(_BYTE *)(a1 + 125) = *(_BYTE *)(a1 + 133);
  *(_BYTE *)(a1 + 126) = *(_BYTE *)(a1 + 134);
  *(_WORD *)(a1 + 112) = *(_WORD *)(a1 + 148);
  *(_BYTE *)(a1 + 304) = *(_BYTE *)(a1 + 306);
  *(_BYTE *)(a1 + 305) = *(_BYTE *)(a1 + 307);
  *(_BYTE *)(a1 + 286) = *(_BYTE *)(a1 + 287);
  getPositionFromPanel();
  set_unitcoord(
    *(unsigned __int8 *)(*(_DWORD *)(a1 + 308) + 428),
    *(_BYTE *)(a1 + 124),
    *(_BYTE *)(a1 + 125),
    *(_BYTE *)(a1 + 126),
    *(__int16 *)(a1 + 112) / 1024);
  return forceChangeAnimation(*(unsigned __int16 *)(a1 + 484) >> 1, *(__int16 *)(a1 + 112), a1);
}

