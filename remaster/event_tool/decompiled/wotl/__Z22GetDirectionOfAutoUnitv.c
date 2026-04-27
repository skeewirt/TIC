// __Z22GetDirectionOfAutoUnitv @ 0x1C0F48 (540 bytes)
// WotL iOS - debug symbols

int __fastcall GetDirectionOfAutoUnit()
{
  int result; // r0
  char v1; // r5
  unsigned int v2; // r12
  char v3; // r6
  unsigned int v4; // r9
  int v5; // r0
  int v6; // r11
  int v7; // r10
  _BYTE *v8; // r1
  char v9; // r3
  unsigned __int8 v10; // r3
  char *v11; // r2
  int v12; // r1
  char *v13; // r3
  int v14; // r4
  int NearestUnit; // r5
  int v16; // r4
  int v17; // [sp+0h] [bp-20h] BYREF
  unsigned __int8 v18[4]; // [sp+4h] [bp-1Ch] BYREF

  result = (unsigned __int8)byte_13589FB;
  if ( byte_13589FB == 5 )
  {
    GetPanelUnderUnit((unsigned __int8)byte_135802A, (unsigned __int8 *)&dword_135802C);
    v1 = BYTE2(dword_135802C);
    v2 = (unsigned __int8)byte_1358036;
    v3 = dword_135802C;
    v4 = (unsigned __int8)byte_1358037;
    v5 = 0;
    v6 = 0;
    v7 = (BYTE1(dword_135802C) << 8)
       + (unsigned __int8)byte_1358036 * BYTE2(dword_135802C)
       + (unsigned __int8)dword_135802C;
    v8 = &np_data;
    do
    {
      v9 = v8[1];
      v18[0] = v3 + *v8;
      v10 = v1 + v9;
      v18[2] = v10;
      if ( v18[0] >= v2
        || v10 >= v4
        || (v11 = (char *)&block + 12 * v18[0] + 12 * v10 * v2, (v11[9] & 1) != 0)
        || (unsigned __int8)v11[5] - *((unsigned __int8 *)&block + 12 * v7 + 5) > 2 )
      {
        v18[v5 - 4] = 0;
      }
      else
      {
        v6 = v5;
        v18[v5 - 4] = 1;
      }
      ++v5;
      v8 += 2;
    }
    while ( v5 != 4 );
    v18[1] = 0;
    v12 = 1;
    if ( !v17 )
      v17 = 16843009;
    byte_1357E89 = 1;
    do
    {
      v13 = &spd_back[v12++];
      v13[3213] = 1;
    }
    while ( v12 != 21 );
    while ( 1 )
    {
      v14 = (unsigned __int8)byte_135802A;
      NearestUnit = GetNearestUnit(1);
      if ( v14 == NearestUnit )
      {
        v16 = 1;
        NearestUnit = GetNearestUnit(2);
      }
      else
      {
        v16 = 0;
      }
      GetPanelUnderUnit(NearestUnit, v18);
      result = GetDirectionForPanel((signed __int8 *)v18, (signed __int8 *)&dword_135802C);
      if ( v18[result - 4] )
        break;
      if ( v16 )
      {
        result = *(_BYTE *)(dword_13589F4 + 81) & 0xF;
        if ( !v18[result - 4] )
          return v6;
        return result;
      }
      spd_back[NearestUnit + 3213] = 0;
    }
  }
  return result;
}

