// __ZL18get_unit_hpos_easyP5BWORK @ 0x1293A4 (208 bytes)
// WotL iOS - debug symbols

int __fastcall get_unit_hpos_easy(char *a1)
{
  char *v1; // r4
  char *v2; // r0
  unsigned int v3; // r2
  int v4; // r1
  int v5; // r12
  int v6; // r2

  v1 = a1;
  v2 = (char *)&block + 12 * get_coord_address(a1);
  v3 = (unsigned __int8)v2[6];
  v4 = (unsigned __int8)(2 * v2[5] + (v3 & 0x1F));
  v5 = 2 * (v3 >> 5);
  if ( v1[420] < 0 )
  {
    v1 = (char *)&bwork + 486 * (v1[420] & 0x1F);
    v4 = (unsigned __int8)(v4 + 2);
  }
  if ( (v1[158] & 8) != 0 || (v6 = v1[99] & 0x40, (v1[99] & 0x40) != 0) )
  {
    v6 = 1;
    v4 = (unsigned __int8)(v4 + 2);
  }
  if ( v5 )
  {
    if ( v6 || v1[158] < 0 )
      return (unsigned __int8)(v4 + v5);
    if ( (v1[158] & 0x40) != 0 )
      return (unsigned __int8)(v4 + v5 - 2);
  }
  return v4;
}

