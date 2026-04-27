// __Z13appare_unit_fi @ 0x11C4AC (100 bytes)
// WotL iOS - debug symbols

int __fastcall appare_unit_f(int a1)
{
  unsigned __int8 v1; // r1
  unsigned __int8 *v2; // r0
  int v3; // r4
  unsigned __int8 v5; // r3

  v1 = a1;
  v2 = (unsigned __int8 *)&bwork + 486 * a1;
  if ( v2[1] != 255 )
    return 0;
  v3 = v2[421];
  if ( v2[421] )
    return -1;
  v2[421] = 1;
  v5 = v2[5];
  v2[1] = v1;
  if ( (v5 & 0x30) == 0 )
    return 0;
  add_level_total();
  return v3;
}

