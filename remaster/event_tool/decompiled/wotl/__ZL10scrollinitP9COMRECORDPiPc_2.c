// __ZL10scrollinitP9COMRECORDPiPc_2 @ 0xA6434 (388 bytes)
// WotL iOS - debug symbols

int __fastcall scrollinit(int result, _DWORD *a2, unsigned int a3)
{
  int v3; // r6
  __int16 *v4; // r10
  int i; // r11
  __int16 *v6; // r4
  __int16 *v7; // r5
  int v8; // r8
  int v9; // r3
  bool v10; // zf
  int v11; // r2
  int v14; // [sp+8h] [bp-20h]

  v14 = result;
  v4 = *(__int16 **)(result + 48);
  for ( i = 0; i < *v4; ++i )
  {
    v6 = v4;
    v7 = v4;
    v8 = 0;
    dword_26C8F8 = *(__int16 *)(v14 + 4);
    do
    {
      v9 = v7[5];
      v10 = v9 == 2;
      if ( v9 != 2 )
      {
        v3 = 2 * (i + *a2);
        v10 = (*(_WORD *)(*((_DWORD *)v6 + 4) + v3) & 0x7FF) == 2047;
      }
      if ( !v10 )
      {
        result = Wloadcdst(v7[2], 16 * i);
        if ( v7[5] != 2 )
          wkanjicolor = *(__int16 *)(v3 + *((_DWORD *)v6 + 7));
        dword_26C8FC = 0;
        if ( wkanjicolor == 4 )
          dword_26C8FC = 1145324612;
        v11 = (unsigned __int16)v7[5];
        if ( v7[5] )
        {
          if ( v11 == 1 )
          {
            result = Wstatusfigprint10(*(__int16 *)(v3 + *((_DWORD *)v6 + 4)), 2, a3, &wcdst);
          }
          else if ( (__int16)v11 == 3 )
          {
            result = Wstatusfigprint16(*(__int16 *)(v3 + *((_DWORD *)v6 + 4)), 2, a3, &wcdst);
          }
        }
        else
        {
          result = Wstatuskanjiprint(*(__int16 *)(v3 + *((_DWORD *)v6 + 4)), a3, (unsigned int)&wcdst);
        }
        wkanjicolor = 0;
        dword_26C8FC = 0;
      }
      ++v8;
      ++v7;
      v6 += 2;
    }
    while ( v8 != 3 );
  }
  return result;
}

