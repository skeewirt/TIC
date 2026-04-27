// Wdrawmessagepolygons @ 0x1402D3138 (966 bytes)
// Decompiled by IDA Pro - Event System Phase 0

void sub_1402D3118()
{
  char v0; // di
  __int128 *v1; // rbp
  unsigned int v2; // r10d
  __int64 v3; // r9
  unsigned int v4; // esi
  int v5; // r13d
  int v6; // r15d
  int v7; // r12d
  __int64 v8; // rbx
  __int16 v9; // ax
  int v10; // edx
  __int16 v11; // cx
  unsigned int v12; // eax
  __int16 v13; // r10
  __int16 v14; // ax
  __int16 v15; // r10
  __int16 v16; // dx
  bool v17; // zf
  int v18; // r9d
  __int64 v19; // r8
  __int16 v20; // ax
  __int64 v21; // rdx
  unsigned int v22; // eax
  __int64 v23; // rcx
  unsigned int v24; // eax
  unsigned int v25; // eax
  __int64 v26; // rcx
  unsigned int v27; // r8d
  unsigned int v28; // eax
  char v29; // [rsp+50h] [rbp+8h] BYREF

  v0 = dword_140783378;
  v1 = &xmmword_14377C060;
  v2 = 1;
  v3 = 0;
  v4 = 1;
  v5 = 0;
  v6 = 2;
  do
  {
    v7 = v3;
    if ( *(_QWORD *)v1 != v3 )
    {
      v8 = *((_QWORD *)&xmmword_14377C040[v6] + dword_141844DA8);
      if ( *(_DWORD *)v8 == v2 && *((_QWORD *)&unk_141845020 + 256 * (__int64)*(int *)(v8 + 4)) != v3 )
      {
        *(_BYTE *)(v8 + 92) = v0;
        *(_BYTE *)(v8 + 93) = v0;
        *(_BYTE *)(v8 + 94) = v0;
        *(_BYTE *)(v8 + 124) = v0;
        *(_BYTE *)(v8 + 125) = v0;
        *(_BYTE *)(v8 + 126) = v0;
        *(_BYTE *)(v8 + 156) = v0;
        *(_BYTE *)(v8 + 157) = v0;
        *(_BYTE *)(v8 + 158) = v0;
        *(_BYTE *)(v8 + 188) = v0;
        *(_BYTE *)(v8 + 189) = v0;
        *(_BYTE *)(v8 + 190) = v0;
        *(_BYTE *)(v8 + 316) = v0;
        *(_BYTE *)(v8 + 317) = v0;
        *(_BYTE *)(v8 + 318) = v0;
        *(_BYTE *)(v8 + 452) = v0;
        *(_BYTE *)(v8 + 453) = v0;
        *(_BYTE *)(v8 + 454) = v0;
        if ( *(_BYTE *)(v8 + 579) != (_BYTE)v3 )
        {
          if ( dword_14184444C == (_DWORD)v3 )
          {
            v9 = 31804;
          }
          else
          {
            v9 = 32060;
            *(_WORD *)(v8 + 452) = 20544;
            *(_BYTE *)(v8 + 454) = 112;
          }
          *(_WORD *)(v8 + 326) = v9;
        }
        v10 = *(__int16 *)(v8 + 320);
        v11 = *(_WORD *)(v8 + 328) - v10;
        v12 = (*(__int16 *)(v8 + 328) - v10) & 0x80000007;
        if ( *(__int16 *)(v8 + 328) - v10 < 0 )
          v12 = v2 + (((_BYTE)v12 - (_BYTE)v2) | 0xFFFFFFF8);
        v13 = -15;
        if ( v12 != 4 )
          v13 = -13;
        v14 = *(_WORD *)(v8 + 322) + 8;
        *(_WORD *)(v8 + 226) = v14;
        v15 = v10 + v11 + v13;
        v16 = *(_WORD *)(v8 + 338) - 26;
        *(_WORD *)(v8 + 224) = v15;
        v17 = *(_DWORD *)(v8 + 24) == 16;
        *(_WORD *)(v8 + 256) = v15;
        *(_WORD *)(v8 + 258) = v16;
        if ( v17 )
        {
          if ( *(_DWORD *)(v8 + 20) == 1 )
          {
            v14 -= 4;
            v16 -= 4;
          }
          else
          {
            v14 += 4;
            v16 += 4;
          }
          *(_WORD *)(v8 + 258) = v16;
          *(_WORD *)(v8 + 226) = v14;
        }
        v18 = v14 + *(__int16 *)(v8 + 234);
        v19 = *((_QWORD *)&xmmword_14377C040[v6] + dword_141844DA8);
        v20 = *(_DWORD *)(v19 + 40) * (v16 - v18 - 4) / *(_DWORD *)(v19 + 36);
        v21 = *(unsigned int *)(v8 + 12);
        *(_WORD *)(v8 + 288) = v15;
        *(_WORD *)(v8 + 290) = v20 + v18;
        if ( (_DWORD)v21 == -1 )
        {
          v2 = 1;
        }
        else
        {
          v22 = sub_1402DCE1C(v8 + 440, v21, 0, &v29);
          v24 = sub_14025FED8(v23, v22);
          sub_14024332C(v4, v24);
          v2 = 1;
          v5 = 1;
          v7 = 1;
        }
        if ( *(float *)&dword_142C7B104 < 2.0 )
        {
          v3 = 0;
LABEL_40:
          if ( v7 )
            v4 -= v2;
          goto LABEL_42;
        }
        v25 = sub_140243364(v4);
        v3 = 0;
        v27 = v25;
        if ( !dword_142FF3848 )
        {
          if ( !v5 )
            v27 = sub_14025FED8(v26, v25);
          if ( v27 == -1 )
            goto LABEL_40;
        }
        v28 = v27;
        if ( v27 > 0xCD )
        {
          v27 = -1;
          v28 = v3;
        }
        if ( v4 <= v2 )
        {
          if ( v27 == 176 )
          {
            v4 = 2;
LABEL_38:
            dword_142FF3854 = v27;
            *(_DWORD *)(v8 + 488) = v28 + 11624;
            dword_142E796B8 = v3;
            HIDWORD(xmmword_142E796D0) = v27;
            LODWORD(xmmword_142E796E0) = *(unsigned __int16 *)(v8 + 462);
            DWORD1(xmmword_142E796E0) = v2;
            goto LABEL_40;
          }
          if ( !v4 )
          {
            dword_142FF384C = v27;
            *(_DWORD *)(v8 + 488) = v28 + 11112;
            dword_142E796B8 = v3;
            dword_142E796BC = v27;
            LODWORD(xmmword_142E796C0) = *(unsigned __int16 *)(v8 + 462);
            DWORD1(xmmword_142E796C0) = v2;
            goto LABEL_40;
          }
          if ( v4 == v2 )
          {
            dword_142FF3850 = v27;
            v17 = dword_142FF381C == (_DWORD)v3;
            *(_DWORD *)(v8 + 488) = v28 + 11368;
            dword_142E796B8 = v3;
            HIDWORD(xmmword_142E796C0) = v27;
            LODWORD(xmmword_142E796D0) = *(unsigned __int16 *)(v8 + 462);
            DWORD1(xmmword_142E796D0) = v2;
            if ( !v17 )
              LODWORD(xmmword_142E796D0) = xmmword_142E796C0;
            goto LABEL_40;
          }
        }
        if ( v4 != 2 )
          goto LABEL_40;
        goto LABEL_38;
      }
    }
LABEL_42:
    --v6;
    --v1;
  }
  while ( (__int64)v1 >= (__int64)xmmword_14377C040 );
}

