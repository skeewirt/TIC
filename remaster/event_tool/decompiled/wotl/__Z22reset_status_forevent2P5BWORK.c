// __Z22reset_status_forevent2P5BWORK @ 0x113D68 (304 bytes)
// WotL iOS - debug symbols, no obfuscation

_BYTE *__fastcall reset_status_forevent2(_BYTE *a1)
{
  int v2; // r10
  int i; // r0
  int v4; // r1
  char v5; // r3
  int v6; // r4
  int v7; // r5
  _BYTE *result; // r0
  int j; // r1
  int v10; // r3

  target_arp = (int)(a1 + 430);
  v2 = (unsigned __int8)a1[428];
  a1[464] &= a1[97];
  for ( i = 1; i != 5; ++i )
  {
    v4 = i + target_arp;
    v5 = a1[i + 97];
    *(_BYTE *)(v4 + 34) &= v5;
  }
  v6 = 0;
  do
  {
    if ( (*(unsigned __int8 *)(target_arp + v6 / 8 + 34) & (128 >> (v6 & 7))) != 0 )
    {
      set_status_counter(a1, v6, 0);
      v7 = v6 + 1;
      _changeAnimationStatus_(v6 + 1, 0, v2);
    }
    else
    {
      v7 = v6 + 1;
    }
    v6 = v7;
  }
  while ( v7 != 40 );
  result = a1;
  for ( j = 0; j != 5; ++j )
  {
    result[97] &= ~*(_BYTE *)(j + target_arp + 34);
    v10 = j + target_arp;
    result[87] &= ~*(_BYTE *)(v10 + 34);
    ++result;
  }
  return result;
}

