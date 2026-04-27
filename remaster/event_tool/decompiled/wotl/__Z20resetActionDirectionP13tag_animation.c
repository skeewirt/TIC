// __Z20resetActionDirectionP13tag_animation @ 0x147BDC (212 bytes)
// WotL iOS - debug symbols

int __fastcall resetActionDirection(int result)
{
  int v1; // r4
  __int16 v2; // r3
  int v3; // r0
  unsigned __int8 v4; // r1
  unsigned __int8 v5; // r2

  v1 = result;
  if ( result )
  {
    if ( (*(_DWORD *)(result + 324) & 4) != 0 )
    {
      *(_WORD *)(result + 114) = -1;
    }
    else
    {
      v2 = *(_WORD *)(result + 114);
      if ( v2 != -1 )
      {
        *(_WORD *)(result + 112) = v2;
        result = set_unitcoord(
                   *(unsigned __int8 *)(*(_DWORD *)(result + 308) + 428),
                   *(_BYTE *)(result + 124),
                   *(_BYTE *)(result + 125),
                   *(_BYTE *)(result + 126),
                   v2 / 1024);
        *(_WORD *)(v1 + 114) = -1;
        if ( *(_BYTE *)(v1 + 304) )
        {
          v3 = searchAnimationByID(*(unsigned __int8 *)(v1 + 305));
          v4 = *(_BYTE *)(v1 + 124);
          v5 = *(_BYTE *)(v1 + 125);
          *(_WORD *)(v3 + 112) = *(_WORD *)(v1 + 112);
          return set_unitcoord(
                   *(unsigned __int8 *)(*(_DWORD *)(v1 + 308) + 428),
                   v4,
                   v5,
                   *(_BYTE *)(v1 + 126),
                   *(__int16 *)(v1 + 112) / 1024);
        }
      }
    }
  }
  return result;
}

