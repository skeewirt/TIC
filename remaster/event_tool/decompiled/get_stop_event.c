// get_stop_event @ 0x14025DA78 (397 bytes)
// Decompiled by IDA Pro - Event System Phase 0

__int64 __fastcall sub_14025D970(unsigned __int8 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // rdx
  __int64 v6; // rcx
  int v7; // ebx
  __int64 v8; // r8
  char v9; // al
  int v10; // ebx
  unsigned __int8 *v11; // rdi
  __int64 v12; // rbp
  __int64 v13; // rdx
  __int64 v14; // r8
  _BYTE *v15; // rcx
  unsigned __int8 v16; // al
  int v17; // ebp
  _BYTE *v18; // rax
  char v19; // r8
  char v20; // al
  int v21; // edx
  int v22; // ecx
  int v23; // eax

  LOBYTE(a4) = 65;
  v7 = sub_14027E9C0(a1[79], a1[80], a1[81] >> 7, a4);
  v9 = a1[436];
  v10 = v7 >= 0;
  if ( v9 >= 0 )
  {
    v11 = a1;
  }
  else
  {
    v11 = (unsigned __int8 *)&unk_14184D890 + 512 * (unsigned __int64)(v9 & 0x1F);
    qword_141864090 = (__int64)v11;
    qword_141864080 = (__int64)(v11 + 446);
    sub_140301070();
    v12 = qword_141864080;
    v13 = 0;
    v14 = qword_141864080 - ((_QWORD)&xmmword_1411A0650 + 13);
    do
    {
      v15 = (char *)&xmmword_1411A0650 + v13 + 13;
      ++v13;
      v15[v14 + 34] = *v15;
    }
    while ( v13 < 5 );
    if ( (unsigned int)sub_1402FBF40(0) )
    {
      *(_BYTE *)(v12 + 39) = 8;
      sub_1403034DC(v11[444], 0);
      v10 |= 0x400u;
    }
  }
  if ( v11 )
    v16 = v11[158] & 1;
  else
    v16 = 0;
  v17 = v16;
  if ( dword_1407CE518 && (unsigned __int8)sub_14025CB08(v11) )
    v17 = 1;
  LOBYTE(v5) = a1[80];
  LOBYTE(v6) = a1[79];
  LOBYTE(v8) = a1[81] >> 7;
  v18 = (_BYTE *)sub_14025DC30(v6, v5, v8);
  if ( v17 && (*v18 & 1) != 0 )
  {
    v10 |= 4u;
  }
  else if ( (*v18 & 2) != 0 )
  {
    v10 |= 8u;
  }
  if ( (unsigned int)sub_14025DB00(a1, 0) )
    v10 |= 0x10u;
  v19 = a1[157];
  v20 = a1[156] & 1;
  v21 = (v20 != 0 ? 0x20 : 0) | 0x42;
  if ( v19 >= 0 )
    v21 = v20 != 0 ? 0x22 : 0;
  v22 = v21 | 0x82;
  if ( (v19 & 0x40) == 0 )
    v22 = v21;
  v23 = v22 | 0x102;
  if ( (v19 & 0x20) == 0 )
    v23 = v22;
  return v10 | (unsigned int)v23;
}

