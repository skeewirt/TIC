// __Z20GetDirectionForPanelPaS_ @ 0x1B7494 (140 bytes)
// WotL iOS - debug symbols

int __fastcall GetDirectionForPanel(signed __int8 *a1, signed __int8 *a2)
{
  int v2; // lr
  int v3; // r12
  int v4; // r0
  int v5; // r2
  int v6; // r1
  int v7; // r2
  unsigned int v8; // r3
  _BOOL4 v10; // r3
  bool v11; // cc

  v2 = a1[2];
  v3 = *a1;
  v4 = *a2;
  v5 = a2[2];
  v6 = v4 + v2 - v3 - v5;
  v7 = v2 + v3 - v4 - v5;
  if ( v6 <= 0 )
    v8 = (unsigned int)v7 >> 31;
  else
    v8 = 0;
  if ( v8 )
    return 0;
  v10 = v6 > 0;
  if ( v7 > 0 )
    v10 = 0;
  if ( v10 )
    return 1;
  v11 = v6 <= 0;
  if ( v6 >= 0 )
    v11 = v7 <= 0;
  if ( !v11 )
    return 2;
  if ( (v6 & ~v7) < 0 )
    return 3;
  return 4;
}

