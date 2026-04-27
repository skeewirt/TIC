// set_event_table @ 0x1402F1E6C (1227 bytes)
// Decompiled by IDA Pro - Event System Phase 0

__int64 __fastcall sub_1402F1E4C(__int64 a1, int a2, int a3)
{
  int v4; // r13d
  int v5; // r14d
  __int64 v6; // rax
  __int64 v7; // rcx
  int *v8; // rax
  unsigned __int8 *v9; // rbx
  __int64 v10; // r15
  __int16 v11; // dx
  unsigned __int64 v12; // rcx
  __int64 v13; // r9
  unsigned int v14; // r10d
  __int64 v15; // r11
  unsigned __int16 v16; // di
  __int16 v17; // ax
  unsigned __int16 v18; // bp
  int v19; // r13d
  int v20; // eax
  int v21; // r15d
  int v22; // ebp
  int v23; // r15d
  int v24; // ebp
  unsigned __int16 v25; // r13
  unsigned __int8 v26; // dl
  int v27; // eax
  __int64 v28; // r8
  int v29; // eax
  __int64 v30; // rax
  __int64 v31; // rdx
  char v32; // r8
  int v33; // ecx
  int v34; // r8d
  __int16 v35; // r10
  __int64 v36; // rdx
  __int64 v37; // r9
  _WORD *v38; // rdx
  __int64 v39; // r12
  __int64 v40; // r8
  __int64 v41; // rax
  bool v42; // cc
  unsigned __int16 v44; // [rsp+20h] [rbp-78h]
  int v45; // [rsp+20h] [rbp-78h]
  unsigned int v46; // [rsp+24h] [rbp-74h]
  BOOL v48; // [rsp+2Ch] [rbp-6Ch]
  unsigned __int8 v49; // [rsp+30h] [rbp-68h]
  unsigned __int8 *v51; // [rsp+38h] [rbp-60h]
  char v52; // [rsp+40h] [rbp-58h]
  __int128 v53; // [rsp+41h] [rbp-57h]
  __int128 v54; // [rsp+51h] [rbp-47h]
  int v55; // [rsp+61h] [rbp-37h]
  __int16 v56; // [rsp+65h] [rbp-33h]
  char v57; // [rsp+67h] [rbp-31h]

  v4 = a2;
  v5 = 0;
  v48 = dword_14185C048 == 9;
  v6 = a1 + 2;
  v7 = 40;
  do
  {
    *(_DWORD *)(v6 - 2) = -1;
    v6 += 4;
    --v7;
  }
  while ( v7 );
  if ( a2 != 2 && a3 != 1 )
  {
    v8 = (int *)&unk_14184D890;
    while ( !*((_BYTE *)v8 + 440) )
    {
      v8 += 128;
      if ( (__int64)v8 >= (__int64)&dword_141850290 )
        goto LABEL_11;
    }
    if ( v8 )
      sub_1402F2318(*((unsigned __int8 *)v8 + 444), 0, 0, a1);
  }
LABEL_11:
  v9 = (unsigned __int8 *)&unk_14184D8FB;
  v46 = 0;
  v51 = (unsigned __int8 *)&unk_14184D8FB;
  v10 = 39;
  do
  {
    if ( (unsigned int)sub_1402F1CA0(v9 - 107) )
      goto LABEL_60;
    v16 = v15;
    v44 = v15;
    if ( (*(v9 - 7) & 2) != 0 )
    {
      v16 = v9[1];
      v44 = v16;
    }
    if ( (*(v9 - 6) & 0x10) != 0 )
    {
      if ( v9[6] > v16 )
        v16 = v9[6];
      v44 = v16;
    }
    v17 = v9[290];
    if ( (_BYTE)v17 == 0xFF )
      goto LABEL_31;
    if ( v4 != (_DWORD)v13 )
    {
      v18 = v16 + v17;
      if ( (_BYTE)v17 || v9[333] == (_BYTE)v15 || v4 != 3 )
        v18 += v11;
      v5 += sub_1402F2318(v14, 1, v18 << 8, a1);
      v13 = 1;
      if ( (*(v9 - 10) & 1) != 0 )
      {
        v19 = 0;
        v9[338] = *(_BYTE *)(sub_1402B6D2C((unsigned int)*(__int16 *)(v9 + 311)) + 12) & 0x7F;
        v13 = 1;
        do
        {
          v18 += v9[338];
          if ( v18 > 0xFFu )
            break;
          v20 = sub_1402F2318(v46, 1, v18 << 8, a1);
          v13 = 1;
          v5 += v20;
          ++v19;
        }
        while ( v19 < 39 );
        v16 = v44;
        v4 = a2;
      }
      v14 = v46;
      v12 = (unsigned __int64)(v9 - 107);
      v15 = 0;
LABEL_31:
      if ( v4 == 2 )
        goto LABEL_60;
    }
    v21 = v15;
    v22 = v15;
    if ( (*(_BYTE *)(v12 + 100) & 4) != 0 )
    {
      v23 = *v9;
      if ( (*(v9 - 17) & 4) != 0 )
        v23 = 512;
      v21 = v23 - v16;
      if ( v21 < 0 )
        v21 = v15;
    }
    if ( (*(_BYTE *)(v12 + 100) & 8) != 0 )
    {
      v24 = *(v9 - 1);
      if ( (*(v9 - 17) & 8) != 0 )
        v24 = 512;
      v22 = v24 - v16;
      if ( v22 < 0 )
        v22 = v15;
    }
    v25 = *(v9 - 42);
    v12 = *(v9 - 43);
    if ( !*(v9 - 43) )
      v12 = (unsigned int)v13;
    v45 = v15;
    v49 = v12;
    do
    {
      if ( v25 < 0x64u )
      {
        do
        {
          v16 += v13;
          v26 = v49;
          if ( v21 )
          {
            v21 -= v13;
            v26 = v13;
            v12 = v49 >> 1;
            v27 = v22 - 1;
            if ( v49 >> 1 )
              v26 = v49 >> 1;
            if ( !v22 )
              v27 = 0;
            v22 = v27;
          }
          else if ( v22 )
          {
            v22 -= v13;
            v26 = 3 * v49 / 2;
          }
          v25 += v26;
        }
        while ( v16 <= 0x1F4u && v25 < 0x64u );
      }
      if ( v16 > 0xFFu )
        break;
      v25 %= 0x64u;
      v28 = v16 << 8;
      LOWORD(v28) = (v16 << 8) - v25 + 100;
      v29 = sub_1402F2318(v46, 0, v28, a1);
      v15 = 0;
      v13 = 1;
      if ( !v29 )
        break;
      v5 += v29;
      ++v45;
    }
    while ( v45 < 40 );
    v9 = v51;
    v10 = 39;
    v14 = v46;
    v4 = a2;
LABEL_60:
    v46 = v13 + v14;
    v9 += 512;
    v51 = v9;
  }
  while ( (int)(v13 + v14) < 21 );
  if ( !v5 )
    return 0xFFFFFFFFLL;
  if ( v4 != 2 && a3 == (_DWORD)v13 )
  {
    v30 = sub_14024C670(v12, v48);
    if ( v30 )
    {
      v31 = *(_QWORD *)(v30 + 328);
      if ( v31 )
      {
        v32 = *(_BYTE *)(v31 + 444);
        v33 = *(unsigned __int8 *)(a1 + 1) + 256;
        if ( *(char *)a1 >= (char)v15 )
          v33 = *(unsigned __int8 *)(a1 + 1);
        if ( v32 != (*(_BYTE *)a1 & 0x1F)
          || ((*(_BYTE *)a1 & 0x40) != 0 || v33) && *(_WORD *)(a1 + 2) > (unsigned __int16)v15 )
        {
          do
          {
            *(_DWORD *)(a1 + 4 * v10) = *(_DWORD *)(a1 + 4 * v10 - 4);
            v10 -= v13;
          }
          while ( v10 > 0 );
          *(_WORD *)(a1 + 2) = v15;
          *(_BYTE *)a1 = v32;
          if ( !++v5 )
            return 0xFFFFFFFFLL;
        }
      }
    }
  }
  if ( v5 < 40 )
  {
    v52 = -1;
    v55 = 0;
    v34 = v15;
    v56 = 0;
    v35 = *(_WORD *)(a1 + 4LL * v5 - 2);
    v57 = 0;
    v53 = 0;
    v54 = 0;
    if ( v5 > 0 )
    {
      v36 = v15;
      v34 = v5;
      do
      {
        *(&v52 + v36) = *(_BYTE *)(a1 + 4 * v36) & 0x1F;
        v36 += v13;
      }
      while ( v36 < v5 );
    }
    if ( v5 < 40LL )
    {
      v37 = v34;
      v38 = (_WORD *)(a1 + 2 + 4LL * v5);
      v39 = 40LL - v5;
      v40 = v15;
      do
      {
        *((_BYTE *)v38 - 2) = *(&v52 + v40);
        v41 = v40 + 1;
        v42 = v40 + 1 < v37;
        *((_BYTE *)v38 - 1) = v15;
        v40 = v15;
        *v38 = v35;
        if ( v42 )
          v40 = v41;
        v38 += 2;
        --v39;
      }
      while ( v39 );
    }
  }
  return 0;
}

