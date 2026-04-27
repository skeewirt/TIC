// ask_event @ 0x14022470C (793 bytes)
// Decompiled by IDA Pro - Event System Phase 0

__int64 __fastcall sub_140224420(__int64 a1, int a2, int a3)
{
  __int64 v4; // rbp
  __int64 v5; // r13
  __int64 v6; // r12
  __int64 v7; // r9
  __int64 v8; // r10
  __int64 v9; // r8
  unsigned __int8 v10; // dl
  _BYTE *v11; // r15
  int v12; // r14d
  char v13; // al
  _BYTE *v14; // rcx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  unsigned __int64 v18; // rdx
  char v19; // cl
  __int64 v20; // rcx
  __int16 v21; // di
  __int64 v23; // rax
  __int64 v24; // [rsp+30h] [rbp-58h]
  __int64 v25; // [rsp+38h] [rbp-50h]
  __int64 v26; // [rsp+40h] [rbp-48h] BYREF
  _QWORD v27[8]; // [rsp+48h] [rbp-40h] BYREF
  __int64 v28; // [rsp+90h] [rbp+8h]
  __int64 v30; // [rsp+A8h] [rbp+20h]

  v4 = a2;
  sub_140271B48(*(_WORD *)(a1 + 2) & 0x1FF, v27, &v26);
  if ( (unsigned int)v4 > 0x14 )
  {
    v5 = 99;
    v25 = 508;
    v24 = 101;
    v30 = 98;
    v28 = 97;
    v6 = 3;
    v7 = 81;
    v8 = 19;
    v9 = 18;
  }
  else
  {
    v25 = (__int64)&unk_14184DA8C + 512 * v4;
    v24 = (__int64)&unk_14184D8F5 + 512 * v4;
    v30 = (__int64)&unk_14184D8F2 + 512 * v4;
    v28 = (__int64)&unk_14184D8F1 + 512 * v4;
    v5 = (__int64)&unk_14184D8F3 + 512 * v4;
    v6 = (__int64)&unk_14184D893 + 512 * v4;
    v7 = (__int64)&byte_14184D8E1[512 * v4];
    v8 = (__int64)&unk_14184D8A3 + 512 * v4;
    v9 = (__int64)&unk_14184D8A2 + 512 * v4;
  }
  v10 = *(_BYTE *)(a1 + 1);
  v11 = &unk_14066D0B0;
  if ( v10 )
  {
    v12 = 0;
    v13 = 1;
    v14 = &unk_14066D0B0;
    while ( v13 != v10 )
    {
      v13 = *++v14;
      if ( *v14 == 0xFF )
        goto LABEL_10;
    }
  }
  v12 = 1;
LABEL_10:
  if ( v10 == *(_BYTE *)v9 && (*(_BYTE *)v7 & 0x20) != 0 && v10 != 123 && v10 != 124 && (unsigned int)v10 - 125 >= 2 )
    v12 = 1;
  if ( v10 == *(_BYTE *)v8 && (*(_BYTE *)v7 & 0x10) != 0 && v10 != 123 && v10 != 124 && (unsigned int)v10 - 125 >= 2 )
    v12 = 1;
  v15 = dword_142E7957C;
  if ( dword_142E7957C == -1 )
    v15 = ((unsigned __int8)sub_14021F310(0x21u) & 0xFu) <= 3;
  if ( v12
    || dword_142FCAF48 == (*(_WORD *)(a1 + 2) & 0x1FF)
    || *(_BYTE *)v6 == 90
    || *(_BYTE *)v6 == 93
    || *(__int16 *)(a1 + 2) >= 368
    || (*(_BYTE *)(v26 + 5) & 2) == 0
    || (*(_BYTE *)v5 & 0x12) != 0 )
  {
    goto LABEL_39;
  }
  v16 = dword_14077CA24;
  if ( (dword_14077CA24 & 0x60000) != 0
    || !v15
    || (*(_BYTE *)v28 & 0x10) != 0
    || (*(_BYTE *)v5 & 4) != 0
    || (*(_BYTE *)v30 & 0x1C) != 0
    || (*(_BYTE *)v24 & 0x30) != 0 )
  {
    goto LABEL_40;
  }
  if ( !(unsigned __int8)sub_1400F77B0(*(unsigned int *)v25, *(unsigned __int8 *)v6, v9, v7) )
  {
LABEL_39:
    v16 = dword_14077CA24;
LABEL_40:
    v18 = *(unsigned __int8 *)(a1 + 1);
    if ( !(_BYTE)v18 )
      goto LABEL_48;
    v9 = 0;
    v19 = 1;
    while ( v19 != (_BYTE)v18 )
    {
      v19 = *++v11;
      if ( *v11 == 0xFF )
        goto LABEL_46;
    }
    v9 = 1;
LABEL_46:
    if ( !(_DWORD)v9 )
    {
LABEL_48:
      if ( (*(_BYTE *)(v27[0] + 3LL) & 0x40) != 0 && (v16 & 0x60000) == 0 )
        goto LABEL_55;
    }
    if ( (unsigned __int8)v18 <= 0x39u && (v20 = 0x300000000100040LL, _bittest64(&v20, v18))
      || (v21 = *(_WORD *)(a1 + 2) & 0x1FF, v21 == 436)
      || v21 == 442
      || (unsigned __int16)(v21 - 355) <= 1u )
    {
LABEL_55:
      if ( *(_WORD *)(a1 + 2) != 439 )
      {
        v17 = 7;
        return sub_14022473C(v17, 0, v4, 0, a3, a1);
      }
      v23 = sub_14024C96C((unsigned __int16)v4, v18, v9, v7);
      if ( v23 )
        *(_BYTE *)(v23 + 965) |= 1u;
    }
    return sub_14022473C(7, 0, v4, 0, 0, a1);
  }
  v17 = 5;
  dword_142FCAF48 = *(_WORD *)(a1 + 2) & 0x1FF;
  return sub_14022473C(v17, 0, v4, 0, a3, a1);
}

