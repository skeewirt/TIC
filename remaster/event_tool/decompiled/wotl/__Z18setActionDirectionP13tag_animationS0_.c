// __Z18setActionDirectionP13tag_animationS0_ @ 0x149E24 (380 bytes)
// WotL iOS - debug symbols

int __fastcall setActionDirection(int result, int a2)
{
  int v2; // r6
  int v3; // r4
  int v4; // r3
  int v5; // r5
  int v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // r3
  bool v10; // zf
  __int16 v11; // r0
  int v12; // r3
  unsigned __int8 v13; // r1
  unsigned __int8 v14; // r2
  unsigned int v15; // r0
  int v16; // r0
  unsigned __int8 v17; // r1
  unsigned __int8 v18; // r2

  v3 = result;
  if ( result )
  {
    if ( a2 )
    {
      v4 = *(__int16 *)(result + 64);
      result = *(__int16 *)(result + 68);
      v2 = *(__int16 *)(a2 + 64) - v4;
      v5 = *(__int16 *)(a2 + 68) - result;
    }
    else
    {
      v6 = *(_DWORD *)(result + 308);
      if ( *(_BYTE *)(v6 + 410) == 5 )
      {
        v2 = 28 * *(__int16 *)(v6 + 412) - *(__int16 *)(result + 64) + 14;
        result = 28 * *(__int16 *)(v6 + 416) - *(__int16 *)(result + 68);
        v5 = result + 14;
      }
      else
      {
        result = searchAnimationByBattleID(*(unsigned __int8 *)(v6 + 411));
        v10 = result == 0;
        if ( result )
        {
          v8 = *(__int16 *)(result + 64);
          v9 = *(__int16 *)(result + 68);
          v7 = *(__int16 *)(v3 + 64);
          result = *(__int16 *)(v3 + 68);
        }
        else
        {
          v2 = 0;
        }
        if ( v10 )
        {
          v5 = v2;
        }
        else
        {
          v2 = v8 - v7;
          v5 = v9 - result;
        }
      }
    }
    if ( (*(_DWORD *)(v3 + 324) & 0x80074) == 0 && *(_WORD *)(v3 + 434) != 440 && (v2 || v5) )
    {
      reserveActionDirection(v3);
      v11 = ratan2(-v5, v2);
      v12 = *(_DWORD *)(v3 + 308);
      v13 = *(_BYTE *)(v3 + 124);
      v14 = *(_BYTE *)(v3 + 125);
      v15 = (v11 - 512) & 0xC00;
      *(_WORD *)(v3 + 112) = v15;
      result = set_unitcoord(*(unsigned __int8 *)(v12 + 428), v13, v14, *(_BYTE *)(v3 + 126), v15 >> 10);
      if ( *(_BYTE *)(v3 + 304) )
      {
        v16 = searchAnimationByID(*(unsigned __int8 *)(v3 + 305));
        v17 = *(_BYTE *)(v3 + 124);
        v18 = *(_BYTE *)(v3 + 125);
        *(_WORD *)(v16 + 112) = *(_WORD *)(v3 + 112);
        return set_unitcoord(
                 *(unsigned __int8 *)(*(_DWORD *)(v3 + 308) + 428),
                 v17,
                 v18,
                 *(_BYTE *)(v3 + 126),
                 *(__int16 *)(v3 + 112) / 1024);
      }
    }
  }
  return result;
}

