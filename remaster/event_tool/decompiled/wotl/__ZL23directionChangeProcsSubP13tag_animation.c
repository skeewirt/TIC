// __ZL23directionChangeProcsSubP13tag_animation @ 0x147EE8 (236 bytes)
// WotL iOS - debug symbols

_WORD *__fastcall directionChangeProcsSub(int a1)
{
  _WORD *result; // r0
  _WORD *v3; // r5
  __int16 v4; // r1
  __int16 v5; // r3

  set_unitcoord(
    *(unsigned __int8 *)(*(_DWORD *)(a1 + 308) + 428),
    *(_BYTE *)(a1 + 124),
    *(_BYTE *)(a1 + 125),
    *(_BYTE *)(a1 + 126),
    *(__int16 *)(a1 + 112) / 1024);
  result = (_WORD *)forceChangeAnimation(*(unsigned __int16 *)(a1 + 484) >> 1, *(__int16 *)(a1 + 112), a1);
  if ( *(_BYTE *)(a1 + 304) )
  {
    result = (_WORD *)searchAnimationByID(*(unsigned __int8 *)(a1 + 305));
    v3 = result;
    if ( result )
    {
      v4 = *(_WORD *)(a1 + 112);
      result[54] = *(_WORD *)(a1 + 108);
      v5 = *(_WORD *)(a1 + 110);
      result[56] = v4;
      result[55] = v5;
      forceChangeAnimation((unsigned __int16)result[242] >> 1, v4, result);
      return (_WORD *)set_unitcoord(
                        *(unsigned __int8 *)(*((_DWORD *)v3 + 77) + 428),
                        *(_BYTE *)(a1 + 124),
                        *(_BYTE *)(a1 + 125),
                        *(_BYTE *)(a1 + 126),
                        *(__int16 *)(a1 + 112) / 1024);
    }
  }
  return result;
}

