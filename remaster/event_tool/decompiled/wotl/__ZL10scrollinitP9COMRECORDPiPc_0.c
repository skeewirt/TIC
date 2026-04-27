// __ZL10scrollinitP9COMRECORDPiPc_0 @ 0x5BB10 (728 bytes)
// WotL iOS - debug symbols

int __fastcall scrollinit(int result, _DWORD *a2, unsigned int a3)
{
  int v3; // r3
  __int16 *v4; // r5
  int v5; // r10
  __int16 *v6; // r4
  int v7; // r8
  int v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  bool v11; // zf
  int v12; // r0
  int v13; // r2
  int v16; // [sp+8h] [bp-2Ch]
  int v17; // [sp+Ch] [bp-28h]
  int v18; // [sp+10h] [bp-24h]
  __int16 *v19; // [sp+14h] [bp-20h]

  v16 = result;
  v3 = 0;
  v19 = *(__int16 **)(result + 48);
LABEL_31:
  v18 = v3;
  if ( v3 < *v19 )
  {
    v4 = v19;
    v5 = 0;
    v6 = v19;
    dword_274E78 = *(__int16 *)(v16 + 4) - 8;
    v17 = 16 * v3;
    while ( v6[5] == 2 )
    {
LABEL_29:
      ++v5;
      ++v6;
      v4 += 2;
      if ( v5 == 3 )
      {
        v3 = v18 + 1;
        goto LABEL_31;
      }
    }
    v7 = v18 + *a2;
    result = loadcdst(v6[2], v17);
    if ( v6[5] != 2 )
    {
      result = 2 * v7;
      kanjicolor = *(__int16 *)(2 * v7 + *((_DWORD *)v4 + 7));
    }
    dword_274E7C = 0;
    if ( kanjicolor == 4 )
      dword_274E7C = 1145324612;
    v8 = (unsigned __int16)v6[5];
    if ( !v6[5] )
    {
      result = statuskanjiprint(*(__int16 *)(*((_DWORD *)v4 + 4) + 2 * v7), a3, (unsigned int)&cdst);
      if ( !*((_DWORD *)asmtaskframeptr + 256 * asmtasknumber + 3) || (*(_BYTE *)(v7 + ablk + 656) & 1) == 0 )
        goto LABEL_28;
      kanjicolor = *(__int16 *)(2 * v7 + *((_DWORD *)v4 + 7));
      loadcdst(v6[2] + 80, v17);
      v9 = a3;
      v10 = 20616;
LABEL_26:
      result = statuskanjiprint(v10, v9, (unsigned int)&cdst);
      goto LABEL_28;
    }
    if ( v8 == 1 )
    {
      result = statusfigprint10(*(__int16 *)(2 * v7 + *((_DWORD *)v4 + 4)), 2, a3, &cdst);
    }
    else if ( (__int16)v8 == 3 )
    {
      if ( v5 == 2 )
        goto LABEL_20;
      v11 = v5 == 1;
      if ( v5 == 1 )
        v11 = v19[7] == 2;
      if ( v11 )
      {
LABEL_20:
        v13 = *((_DWORD *)v4 + 4);
        v12 = 2 * v7;
        if ( *(unsigned __int16 *)(2 * v7 + v13) <= 1u && (unsigned __int8)(*(_BYTE *)(v7 + ablk + 820) - 1) > 0xFDu )
        {
          word_274E72 += 2;
          result = statusnowprint(a3, &cdst);
          goto LABEL_28;
        }
      }
      else
      {
        v12 = 2 * v7;
        v13 = *((_DWORD *)v4 + 4);
      }
      result = *(unsigned __int16 *)(v12 + v13);
      if ( (result & 0x7FF) != 0 )
      {
        if ( (result & 0x7FFu) <= 0x63 )
        {
          result = statusfigprint16((__int16)result, 2, a3, &cdst);
          goto LABEL_28;
        }
        v9 = a3;
        kanjicolor = 0;
        v10 = 20637;
        cdst += 3;
        goto LABEL_26;
      }
    }
LABEL_28:
    kanjicolor = 0;
    dword_274E7C = 0;
    goto LABEL_29;
  }
  return result;
}

