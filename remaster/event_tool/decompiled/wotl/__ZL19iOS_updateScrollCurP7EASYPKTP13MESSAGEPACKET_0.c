// __ZL19iOS_updateScrollCurP7EASYPKTP13MESSAGEPACKET_0 @ 0x59638 (260 bytes)
// WotL iOS - debug symbols

int __fastcall iOS_updateScrollCur(int result, int a2)
{
  int v2; // lr
  int v3; // r12
  int v4; // r3

  v2 = *(unsigned __int16 *)(result + 32);
  v3 = *(__int16 *)(result + 46);
  if ( v2 != v3 )
  {
    *(_DWORD *)(360 * globalframe + a2 + 36) = v2 - v3;
    *(_DWORD *)(360 * globalframe + a2 + 40) = *(unsigned __int16 *)(result + 34);
    *(_DWORD *)(360 * globalframe + a2 + 32) = 4;
    v4 = *(unsigned __int16 *)(result + 34);
    if ( *(_WORD *)(result + 34) )
    {
      *(_DWORD *)(360 * globalframe + a2 + 32) |= 1u;
      v4 = *(unsigned __int16 *)(result + 34);
    }
    result = *(unsigned __int16 *)(result + 32) - *(__int16 *)(result + 46);
    if ( v4 != result )
      *(_DWORD *)(360 * globalframe + a2 + 32) |= 2u;
  }
  return result;
}

