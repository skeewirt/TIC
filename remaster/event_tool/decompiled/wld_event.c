// wld_event @ 0x14033EDEC (1346 bytes)
// Decompiled by IDA Pro - Event System Phase 0

__int64 __fastcall sub_14033EDCC(unsigned int a1, int a2)
{
  __int64 v2; // rax
  __int64 *v4; // rax
  __int64 *v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rbp
  unsigned int v8; // eax
  signed __int64 v9; // r11
  unsigned int v10; // r15d
  int v11; // r10d
  unsigned __int16 v12; // di
  __int64 v13; // rcx
  unsigned __int64 v14; // rax
  unsigned int v15; // eax
  unsigned int v16; // r13d
  unsigned int v17; // r14d
  __int64 v18; // rax
  __int64 v19; // r8
  __int16 *v20; // rax
  int v21; // r10d
  _DWORD *v22; // rax
  int v23; // r9d
  _DWORD *v24; // rax
  int v25; // ecx
  _WORD *v26; // r9
  unsigned __int16 v27; // di
  _DWORD *v28; // rax
  int v29; // ecx
  _DWORD *v30; // rax
  char *v31; // r8
  int *v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rax
  signed __int64 v35; // r9
  signed __int64 v36; // r10
  char *v37; // r8
  char *v38; // r8
  _DWORD *v39; // rax
  bool v40; // zf
  _DWORD *v42; // rax
  __int64 v43; // rdx
  unsigned __int16 v44; // cx
  __int64 v45; // rax
  unsigned int v47; // [rsp+28h] [rbp-30h]

  v2 = qword_143CD4310;
  if ( qword_143CD4310 || qword_143CD36C0 && (v2 = sub_1403CE590(qword_143CD36C0, 199), (qword_143CD4310 = v2) != 0) )
  {
    v4 = (__int64 *)sub_1403CEE1C(v2, a1);
    v5 = v4;
    if ( v4 )
    {
      if ( *v4 < 0 || sub_1403CE30C(v4) )
      {
        v6 = qword_143CD4310;
        v7 = qword_143CD36C0;
        if ( !qword_143CD4310 && qword_143CD36C0 )
        {
          v6 = sub_1403CE590(qword_143CD36C0, 199);
          qword_143CD4310 = v6;
        }
        v8 = sub_1403CED68(v6, a1);
        v9 = 0;
        v47 = v8;
        v10 = 0;
        if ( v8 )
        {
          v11 = 1;
          while ( 1 )
          {
            v12 = v9;
            v13 = (unsigned int)v9;
            v14 = v9;
            do
            {
              if ( v14 >= 0x200 )
                _report_rangecheckfailure(v13, word_140D49820);
              *(_WORD *)((char *)word_140D49820 + v14) = v9;
              v13 = (unsigned int)(v11 + v13);
              v14 += 2LL;
            }
            while ( (unsigned int)v13 < 0x100 );
            if ( !v6 && v7 )
            {
              v6 = sub_1403CE590(v7, 199);
              qword_143CD4310 = v6;
            }
            v15 = sub_1403CEDB8(v6, a1, v10);
            v9 = 0;
            v16 = v15;
            v17 = 0;
            if ( v15 )
              break;
            v11 = 1;
LABEL_100:
            v10 += v11;
            if ( v10 >= v47 )
              return 0;
          }
          while ( 1 )
          {
            if ( v6 || v7 && (v18 = sub_1403CE590(v7, 199), v9 = 0, qword_143CD4310 = v18, (v6 = v18) != 0) )
            {
              v5 = (__int64 *)sub_1403CEEE0(v6, a1, v10, v17);
              v9 = 0;
            }
            if ( !v5 )
              return 0;
            v19 = *v5;
            if ( *v5 < 0 )
            {
              v20 = (__int16 *)&unk_1406F0E60;
            }
            else
            {
              if ( !sub_1403CE30C(v5) )
                return 0;
              v20 = (__int16 *)sub_1403CE30C(v5);
            }
            v21 = v20[2];
            if ( v21 > 34 )
              break;
            if ( v21 == 34 )
              goto LABEL_84;
            if ( !v20[2] )
              goto LABEL_88;
            if ( v21 == 1 )
            {
              if ( v19 < 0 )
                v28 = &unk_1406F0E60;
              else
                v28 = (_DWORD *)sub_1403CE30C(v5);
              v29 = v28[4];
              if ( !v29 )
                return 0;
              v26 = word_140D49820;
              word_140D49820[v12] = v21;
              v11 = 1;
              word_140D49820[++v12] = v29;
              goto LABEL_50;
            }
            if ( v21 == 4 )
            {
              v26 = word_140D49820;
              word_140D49820[v12] = 4;
              v11 = 1;
LABEL_50:
              v27 = v12 + 1;
              if ( *v5 < v9 )
                v30 = &unk_1406F0E60;
              else
                v30 = (_DWORD *)sub_1403CE30C(v5);
              if ( v30[3] == (_DWORD)v9 )
                return 0;
              if ( *v5 < v9 )
                v31 = (char *)&unk_1406F0E60;
              else
                v31 = (char *)sub_1403CE30C(v5);
              v26[v27] = *(_WORD *)&v31[*((int *)v31 + 2)];
              goto LABEL_58;
            }
            if ( (unsigned int)(v21 - 32) > 1 )
              goto LABEL_64;
            if ( v19 < 0 )
              v22 = &unk_1406F0E60;
            else
              v22 = (_DWORD *)sub_1403CE30C(v5);
            v23 = v22[5];
            if ( v19 < 0 )
              v24 = &unk_1406F0E60;
            else
              v24 = (_DWORD *)sub_1403CE30C(v5);
            if ( v23 == 47 )
              return 0;
            v25 = v24[6];
            if ( v25 == 47 )
              return 0;
            word_140D49820[v12] = v21;
            v11 = 1;
            word_140D49820[++v12] = v23;
            v26 = word_140D49820;
LABEL_43:
            v27 = v12 + 1;
            word_140D49820[v27] = v25;
LABEL_58:
            v12 = v11 + v27;
LABEL_90:
            v17 += v11;
            if ( v17 >= v16 )
            {
              if ( !v12 )
                goto LABEL_100;
              v43 = (__int64)v26;
              dword_140D42F50 = v9;
              v44 = v9;
              qword_140D42F60 = (__int64)v26;
              word_140D42F68 = v9;
              while ( *(_WORD *)(v43 + 2LL * v44) < 0x2Cu )
              {
                v45 = *(unsigned __int16 *)(v43 + 2LL * v44);
                word_140D42F68 = v11 + v44;
                funcs_14033F2A6[v45]();
                v11 = 1;
                if ( (dword_140D42F50 & 3) != 0 )
                {
                  if ( (dword_140D42F50 & 1) == 0 || (dword_140D42F50 & a2) == 0 )
                  {
                    v6 = qword_143CD4310;
                    v9 = 0;
                    v7 = qword_143CD36C0;
                    goto LABEL_100;
                  }
                  return 1;
                }
                v44 = word_140D42F68;
                v43 = qword_140D42F60;
              }
              return 0;
            }
          }
          if ( v21 != 35 && v21 != 36 )
          {
            if ( v21 == 41 )
            {
              if ( v19 < 0 )
                v39 = &unk_1406F0E60;
              else
                v39 = (_DWORD *)sub_1403CE30C(v5);
              v25 = v39[7];
              v40 = v25 == 0;
LABEL_82:
              if ( v40 )
                return 0;
LABEL_77:
              v26 = word_140D49820;
              word_140D49820[v12] = v21;
              v11 = 1;
              goto LABEL_43;
            }
            if ( v21 != 42 )
            {
              if ( v21 != 43 )
              {
LABEL_64:
                if ( v19 < 0 )
                  v32 = (int *)&unk_1406F0E60;
                else
                  v32 = (int *)sub_1403CE30C(v5);
                v33 = v32[3];
                v34 = v12;
                v35 = v9;
                ++v12;
                word_140D49820[v34] = v21;
                v36 = v33;
                if ( (int)v33 <= 0 )
                {
LABEL_88:
                  v11 = 1;
                }
                else
                {
                  do
                  {
                    if ( *v5 < v9 )
                      v37 = (char *)&unk_1406F0E60;
                    else
                      v37 = (char *)sub_1403CE30C(v5);
                    word_140D49820[v12++] = *(_WORD *)&v37[2 * v35++ + *((int *)v37 + 2)];
                  }
                  while ( v35 < v36 );
                  v11 = 1;
                }
                v26 = word_140D49820;
                goto LABEL_90;
              }
              if ( v19 < 0 )
                v38 = (char *)&unk_1406F0E60;
              else
                v38 = (char *)sub_1403CE30C(v5);
              LOWORD(v25) = *(_WORD *)&v38[*((int *)v38 + 2)];
              if ( (__int16)v25 <= 0 )
                return 0;
              goto LABEL_77;
            }
          }
LABEL_84:
          if ( v19 < 0 )
            v42 = &unk_1406F0E60;
          else
            v42 = (_DWORD *)sub_1403CE30C(v5);
          v25 = v42[5];
          v40 = v25 == 47;
          goto LABEL_82;
        }
      }
    }
  }
  return 0;
}

