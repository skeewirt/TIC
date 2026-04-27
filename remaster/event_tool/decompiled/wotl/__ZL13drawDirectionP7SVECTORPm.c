// __ZL13drawDirectionP7SVECTORPm @ 0x134274 (1720 bytes)
// WotL iOS - debug symbols

int __fastcall drawDirection(__int16 *a1)
{
  _DWORD *v2; // r6
  int v3; // r5
  int v4; // r3
  int v5; // r2
  int v6; // r12
  int v7; // lr
  int v8; // r8
  int v9; // r4
  int v10; // kr04_4
  int v11; // r10
  __int16 v12; // r5
  int v13; // r3
  int v14; // r2
  int v15; // r6
  int v16; // r3
  int v17; // r2
  char v18; // r1
  int v19; // r2
  char v20; // r3
  char v21; // r12
  char v22; // r3
  char v23; // r3
  char v24; // r0
  char v25; // r3
  char v26; // r3
  char v27; // r2
  char v28; // r3
  char v29; // r3
  char v30; // r3
  char v31; // r3
  char v32; // r3
  char v33; // r3
  char v34; // r3
  char v35; // r3
  char v36; // r3
  int OTptrZ; // r0
  int result; // r0
  bool v39; // zf
  int v40; // [sp+28h] [bp-E0h]
  int v41; // [sp+2Ch] [bp-DCh]
  int v42; // [sp+30h] [bp-D8h]
  int v43; // [sp+34h] [bp-D4h]
  int v44; // [sp+38h] [bp-D0h]
  int v45; // [sp+3Ch] [bp-CCh]
  int v46; // [sp+40h] [bp-C8h]
  int v47; // [sp+44h] [bp-C4h]
  int v48; // [sp+48h] [bp-C0h]
  int v49; // [sp+4Ch] [bp-BCh]
  int v50; // [sp+50h] [bp-B8h]
  int *v51; // [sp+54h] [bp-B4h]
  _DWORD v52[16]; // [sp+58h] [bp-B0h] BYREF
  _DWORD v53[4]; // [sp+98h] [bp-70h] BYREF
  _DWORD v54[4]; // [sp+A8h] [bp-60h] BYREF
  _DWORD v55[4]; // [sp+B8h] [bp-50h] BYREF
  _DWORD v56[4]; // [sp+C8h] [bp-40h] BYREF
  _DWORD v57[4]; // [sp+D8h] [bp-30h] BYREF
  __int16 v58; // [sp+E8h] [bp-20h] BYREF
  __int16 v59; // [sp+EAh] [bp-1Eh]
  __int16 v60; // [sp+ECh] [bp-1Ch]

  v2 = v52;
  v3 = 0;
  v48 = searchCurrentAnimation();
  directionTimer += iOS_GetFrameRate();
  v57[0] = -28;
  v57[1] = 28;
  v57[2] = -28;
  v57[3] = 28;
  v56[0] = -28;
  v56[1] = -28;
  v56[2] = 28;
  v56[3] = 28;
  do
  {
    setShortVector(&v58, *a1 + v57[v3], a1[1] - 48, a1[2] + v56[v3]);
    ++v3;
    v4 = gTheMatrix * v58 + word_12B1736 * v59 + word_12B1738 * v60;
    v5 = dword_12B1748;
    v2[1] = dword_12B174C + (v58 * word_12B173A + v59 * word_12B173C + v60 * word_12B173E) / 4096;
    *v2 = v5 + v4 / 4096;
    v2 += 4;
  }
  while ( v3 != 4 );
  setShortVector(&v58, *a1, a1[1] - 48, a1[2]);
  v6 = dword_12B1748 + (gTheMatrix * v58 + word_12B1736 * v59 + word_12B1738 * v60) / 4096;
  v7 = dword_12B174C + (v58 * word_12B173A + v59 * word_12B173C + v60 * word_12B173E) / 4096;
  v55[0] = 0;
  v55[1] = -56;
  v55[2] = 0;
  v55[3] = 56;
  v54[0] = -56;
  v54[1] = 0;
  v54[2] = 56;
  v54[3] = 0;
  v53[0] = 2;
  v53[1] = 0;
  v53[2] = 3;
  v53[3] = 1;
  v8 = gTheScale;
  v40 = (v52[0] - v6) << 12;
  v41 = (v52[4] - v6) << 12;
  v42 = (v52[8] - v6) << 12;
  v43 = (v52[12] - v6) << 12;
  v44 = (v52[1] - v7) << 12;
  v45 = (v52[5] - v7) << 12;
  v46 = (v52[9] - v7) << 12;
  v51 = (int *)&theVecDirection;
  v47 = (v52[13] - v7) << 12;
  v49 = 0;
  v50 = 0;
  do
  {
    v9 = 44 * (__int16)myGetShapePrim() + shapePrim;
    *(_BYTE *)(v9 + 4) = 9;
    *(_BYTE *)(v9 + 5) = 0;
    *(_BYTE *)(v9 + 6) = 0;
    *(_BYTE *)(v9 + 7) = 0;
    *(_BYTE *)(v9 + 11) = 46;
    *(_WORD *)(v9 + 26) = 160;
    setShortVector(&v58, (v55[v50] << 12) / v8 + *a1, a1[1] - 48, (v54[v50] << 12) / v8 + a1[2]);
    v10 = gTheMatrix * v58 + word_12B1736 * v59 + word_12B1738 * v60;
    v11 = dword_12B1748 + v10 / 4096;
    v12 = dword_12B1748 + v10 / 4096;
    v13 = v58 * word_12B173A + v59 * word_12B173C + v60 * word_12B173E;
    v14 = v13 + 4095;
    if ( v13 >= 0 )
      v14 = v58 * word_12B173A + v59 * word_12B173C + v60 * word_12B173E;
    v15 = dword_12B174C + (v14 >> 12);
    *(_WORD *)(v9 + 12) = v12 + v40 / v8;
    *(_WORD *)(v9 + 20) = v12 + v41 / v8;
    *(_WORD *)(v9 + 28) = v12 + v42 / v8;
    *(_WORD *)(v9 + 36) = v12 + v43 / v8;
    *(_WORD *)(v9 + 14) = v15 + v44 / v8;
    *(_WORD *)(v9 + 22) = v15 + v45 / v8;
    *(_WORD *)(v9 + 30) = v15 + v46 / v8;
    *(_WORD *)(v9 + 38) = v15 + v47 / v8;
    *v51 = v11;
    v51[1] = v15;
    *(_WORD *)(v9 + 18) = GetClut(0, 256);
    if ( iOS_getDirectionTapDir() == -1 )
    {
      LOBYTE(v16) = 96;
    }
    else if ( v49 == (unsigned __int16)(*(_WORD *)(v48 + 112) & 0xC00) >> 10 && v49 == iOS_getDirectionTapDir() )
    {
      if ( (directionTimer & 0x10) != 0 )
        v16 = ((int)((unsigned __int64)(2290649225LL * ((unsigned __int8)(directionTimer & 0xF) << 6)) >> 32) >> 3) + 64;
      else
        v16 = -128
            - ((int)((unsigned __int64)(2290649225LL * ((unsigned __int8)(directionTimer & 0xF) << 6)) >> 32) >> 3);
    }
    else
    {
      LOBYTE(v16) = 48;
    }
    *(_BYTE *)(v9 + 10) = v16;
    *(_BYTE *)(v9 + 9) = v16;
    *(_BYTE *)(v9 + 8) = v16;
    v17 = v53[v50];
    *(_BYTE *)(v9 + 24) = 0;
    *(_BYTE *)(v9 + 32) = 0;
    *(_BYTE *)(v9 + 40) = 0;
    *(_BYTE *)(v9 + 16) = 0;
    v18 = drawDirection(SVECTOR *,unsigned long *)::uvconv[4 * v17];
    v19 = 4 * v17;
    if ( (v18 & 1) != 0 )
      v20 = 55;
    else
      v20 = 1;
    *(_BYTE *)(v9 + 16) = v20;
    v21 = drawDirection(SVECTOR *,unsigned long *)::uvconv[v19 + 1];
    v22 = *(_BYTE *)(v9 + 24);
    if ( (v21 & 1) != 0 )
      v23 = v22 + 55;
    else
      v23 = v22 + 1;
    *(_BYTE *)(v9 + 24) = v23;
    v24 = drawDirection(SVECTOR *,unsigned long *)::uvconv[v19 + 2];
    v25 = *(_BYTE *)(v9 + 32);
    if ( (v24 & 1) != 0 )
      v26 = v25 + 55;
    else
      v26 = v25 + 1;
    *(_BYTE *)(v9 + 32) = v26;
    v27 = drawDirection(SVECTOR *,unsigned long *)::uvconv[v19 + 3];
    v28 = *(_BYTE *)(v9 + 40);
    if ( (v27 & 1) != 0 )
      v29 = v28 + 55;
    else
      v29 = v28 + 1;
    *(_BYTE *)(v9 + 40) = v29;
    *(_BYTE *)(v9 + 17) = 40;
    *(_BYTE *)(v9 + 25) = 40;
    *(_BYTE *)(v9 + 33) = 40;
    *(_BYTE *)(v9 + 41) = 40;
    if ( (v18 & 2) != 0 )
      v30 = 95;
    else
      v30 = 41;
    *(_BYTE *)(v9 + 17) = v30;
    v31 = *(_BYTE *)(v9 + 25);
    if ( (v21 & 2) != 0 )
      v32 = v31 + 55;
    else
      v32 = v31 + 1;
    *(_BYTE *)(v9 + 25) = v32;
    v33 = *(_BYTE *)(v9 + 33);
    if ( (v24 & 2) != 0 )
      v34 = v33 + 55;
    else
      v34 = v33 + 1;
    *(_BYTE *)(v9 + 33) = v34;
    v35 = *(_BYTE *)(v9 + 41);
    if ( (v27 & 2) != 0 )
      v36 = v35 + 55;
    else
      v36 = v35 + 1;
    *(_BYTE *)(v9 + 41) = v36;
    OTptrZ = ASHURA_getOTptrZ(1);
    AddPrim(OTptrZ, v9);
    result = v49 + 1;
    v39 = v49++ == 3;
    ++v50;
    v51 += 4;
  }
  while ( !v39 );
  return result;
}

