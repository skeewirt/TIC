// __ZL12SetUACommandiii @ 0x1C1304 (1176 bytes)
// WotL iOS - debug symbols

int __fastcall SetUACommand(int a1, int a2, int a3)
{
  int ability; // r0
  int v5; // r11
  char *v6; // r3
  _BYTE *v7; // r2
  int v8; // r1
  __int16 v9; // r3
  int v10; // r1
  char *v11; // r3
  _BYTE *v12; // r2
  __int16 v13; // r3
  int v14; // r4
  char *v15; // r3
  _WORD *v16; // r3
  __int16 v17; // r0
  char *v18; // r3
  int v19; // r5
  char *v20; // r9
  int v21; // r4
  int v22; // r8
  int v23; // r6
  char *v24; // r12
  int v25; // r1
  char *v26; // r2
  bool v27; // zf
  char *v28; // r2
  char v29; // r3
  char *v30; // r3
  int v31; // r1
  int v32; // r3
  int v36; // [sp+Ch] [bp-24h]
  int v37; // [sp+10h] [bp-20h]
  int v38; // [sp+14h] [bp-1Ch]

  if ( !a2 )
    return a3;
  ability = get_ability(a2, 1);
  v5 = (unsigned __int8)spd_back[a1 + 6540];
  v36 = (unsigned __int8)comtype[a2];
  v38 = ability;
  if ( v36 == 2 )
  {
    if ( CheckAbilityGet(a1, a2, 0) )
    {
      v6 = &spd_back[136 * v5 + 3824 + 4 * a3];
      v6[2] = a2;
      *(_WORD *)v6 = ((_WORD)a1 << 10) + 122;
      v7 = v6 + 6;
      v8 = 1;
      do
      {
        v9 = ((_WORD)a1 << 10) + 122 + v8++;
        *v7 = a2;
        *((_WORD *)v7 - 1) = v9;
        v7 += 4;
      }
      while ( v8 != 3 );
      a3 += 3;
    }
    if ( CheckAbilityGet(a1, a2, 1) )
    {
      v10 = 1;
      v11 = &spd_back[136 * v5 + 3824 + 4 * a3];
      v11[2] = a2;
      *(_WORD *)v11 = ((_WORD)a1 << 10) + 125;
      v12 = v11 + 6;
      do
      {
        v13 = ((_WORD)a1 << 10) + 125 + v10++;
        *v12 = a2;
        *((_WORD *)v12 - 1) = v13;
        v12 += 4;
      }
      while ( v10 != 3 );
      a3 += 3;
    }
    v14 = 2;
    while ( !CheckAbilityGet(a1, a2, v14) )
    {
      if ( ++v14 == 12 )
        return a3;
    }
    v15 = &spd_back[136 * v5 + 4 * a3];
    v15[3826] = a2;
    v16 = v15 + 3824;
    v17 = (_WORD)a1 << 10;
    goto LABEL_18;
  }
  if ( v36 == 3 )
  {
    v18 = &spd_back[136 * v5 + 4 * a3];
    v18[3826] = a2;
    v16 = v18 + 3824;
    v17 = (_WORD)a1 << 10;
LABEL_18:
    ++a3;
    *v16 = v17;
    return a3;
  }
  if ( v36 == 10 && *(_BYTE *)(pspItemGetCommonData(*(unsigned __int16 *)&spd_back[8 * v5 + 6012]) + 5) == 10 )
    return a3;
  v19 = 0;
  v20 = nullptr;
  v37 = 0;
  do
  {
    v21 = *(unsigned __int16 *)(2 * v19 + v38);
    if ( !*(_WORD *)(2 * v19 + v38) )
      goto LABEL_47;
    v22 = 2 * v5;
    v23 = 32 * v5;
    v20 = &spd_back[136 * v5 + 3824 + 4 * a3];
    if ( (aco[8 * v21 + 7] & 0x80) == 0 )
      goto LABEL_47;
    if ( *(unsigned __int16 *)(2 * v19 + v38) >= 0x170u )
      goto LABEL_35;
    v24 = (char *)&aa + 14 * v21;
    v25 = (unsigned __int8)v24[13];
    v26 = (char *)&bwork + 486 * a1;
    if ( v26[153] < 0 )
      v25 = (unsigned int)v25 >> 1;
    if ( v25 > *((unsigned __int16 *)v26 + 27) || (byte_135720A & 4) != 0 && (v26[91] & 0x40) != 0 )
      goto LABEL_47;
    if ( (v24[6] & 8) != 0 )
    {
      v27 = (v26[422] & 8) == 0;
      goto LABEL_34;
    }
    if ( (v24[6] & 4) != 0 )
    {
      v27 = (v26[422] & 4) == 0;
LABEL_34:
      if ( v27 )
        goto LABEL_47;
    }
LABEL_35:
    v20 = &spd_back[136 * v5 + 3824 + 4 * a3];
    if ( !CheckAbilityGet(a1, a2, v19) )
      goto LABEL_47;
    if ( (unsigned int)(a2 - 176) <= 0x2F )
    {
      v28 = &spd_back[4 * v22 + 4 * v23 + 4 * a3];
      if ( v19 == 3 )
        v29 = v28[3827] | 8;
      else
        v29 = v28[3827] & 0xF7;
      v28[3827] = v29;
    }
    v30 = &spd_back[4 * v22 + 4 * v23 + 4 * a3];
    v30[3826] = a2;
    *((_WORD *)v30 + 1912) = v21;
    if ( v36 == 9 )
    {
      if ( v21 > 398 )
        goto LABEL_47;
      if ( v37 == 1 )
      {
        --a3;
        v31 = 4 * (v22 + v23 + a3);
        v20 = &spd_back[v31 + 3824];
        *(_WORD *)&spd_back[v31 + 3824] = v21;
      }
      else
      {
        v37 = 1;
      }
    }
    ++a3;
    *(_WORD *)v20 += (_WORD)a1 << 10;
LABEL_47:
    ++v19;
  }
  while ( v19 != 16 );
  if ( v36 == 9 )
    v32 = ((unsigned __int8)v37 ^ 1) & 1;
  else
    v32 = 0;
  if ( v32 )
  {
    v20[2] = 18;
    *(_WORD *)v20 = (_WORD)a1 << 10;
  }
  return a3;
}

