// __Z15get_unit_heighti @ 0x128F60 (480 bytes)
// WotL iOS - debug symbols

_BYTE *__fastcall get_unit_height(_BYTE *a1, unsigned int a2)
{
  unsigned __int8 *v3; // r4
  int v4; // r0
  int v5; // lr
  unsigned __int8 v6; // r3
  char v7; // r6
  int v8; // r9
  unsigned int v9; // r2
  int v10; // r3
  unsigned int v11; // r8
  char *v12; // r2
  bool v13; // zf
  char v14; // r2
  char v15; // r3
  unsigned __int8 v16; // r6
  char *v17; // r0
  char v18; // r3
  unsigned int v19; // r0
  unsigned int v20; // r1
  char v21; // r2
  char v22; // r3
  char v23; // r3
  char v24; // r3

  v3 = (unsigned __int8 *)&bwork + 486 * a2;
  if ( a2 > 0x14 )
    goto LABEL_35;
  if ( v3[1] == 255 )
    goto LABEL_35;
  if ( (v3[97] & 0x40) != 0 )
    goto LABEL_35;
  v4 = v3[98] & 1;
  if ( (v3[98] & 1) != 0 )
    goto LABEL_35;
  v5 = v3[79];
  v6 = v3[3];
  v7 = a2;
  *a1 = v5;
  v8 = v3[80];
  a1[1] = v8;
  v9 = v3[81];
  if ( (unsigned __int8)(v6 - 94) > 2u )
    v7 = a2 | 0x20;
  v10 = a1[2] & 0x80 | (v9 >> 7);
  v11 = v9 >> 7;
  v12 = &byte_1242397;
  a1[2] = v10;
  while ( 1 )
  {
    v13 = v4 == a2;
    if ( v4 != a2 )
      v13 = (unsigned __int8)*v12 == 255;
    if ( !v13
      && (unsigned __int8)v12[78] == v5
      && (unsigned __int8)v12[79] == v8
      && v11 == *((unsigned __int8 *)&bwork + 486 * v4 + 81) >> 7 )
    {
      break;
    }
    ++v4;
    v12 += 486;
    if ( v4 == 21 )
    {
      v14 = 0;
      goto LABEL_19;
    }
  }
  v13 = (v7 & 0x20) == 0;
  v7 |= 0x40u;
  if ( !v13 )
    v3 = (unsigned __int8 *)&bwork + 486 * v4;
  v14 = 2;
LABEL_19:
  a1[3] = v7;
  if ( (v3[99] & 6) != 0 )
    v15 = v14 + 4;
  else
    v15 = v14 + 6;
  a1[4] = v15;
  v16 = v3[158];
  v17 = (char *)&block + 12 * get_coord_address(v3);
  v18 = v17[5];
  v19 = (unsigned __int8)v17[6];
  v20 = v19 >> 5;
  v21 = 2 * v18 + (v19 & 0x1F);
  if ( !(v19 >> 5) )
  {
    if ( (v3[99] & 0x40) == 0 )
      goto LABEL_34;
    v23 = v21 + 2;
    goto LABEL_33;
  }
  if ( (v3[99] & 0x40) != 0 )
  {
    v22 = 2 * (v20 + 1);
LABEL_27:
    v23 = v21 + v22;
LABEL_33:
    v21 = v23;
    goto LABEL_34;
  }
  if ( (v16 & 0x80) != 0 )
  {
    v22 = 2 * v20;
    goto LABEL_27;
  }
  if ( (v16 & 0x40) != 0 )
  {
    v23 = v21 + 2 * v20 - 2;
    goto LABEL_33;
  }
LABEL_34:
  v24 = a1[4];
  a1[5] = v21;
  a1[6] = v21 + v24;
  if ( (v3[97] & 0x20) != 0 )
LABEL_35:
    a1[3] = 0x80;
  return a1;
}

