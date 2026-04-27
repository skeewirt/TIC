// __Z19drawmessagepolygonsv @ 0x6C794 (1176 bytes)
// WotL iOS - debug symbols, no obfuscation

int *__fastcall drawmessagepolygons()
{
  int i; // r5
  int v1; // r4
  __int16 v2; // r11
  int v3; // r2
  __int16 v4; // r1
  __int16 v5; // r0
  __int16 v6; // r3
  __int16 v7; // r2
  __int16 v8; // r1
  __int16 v9; // r2
  int v10; // r3
  int v11; // r3
  bool v12; // zf
  __int16 v13; // r3
  __int16 v14; // r3
  int v15; // r6
  int v16; // r0
  int v17; // r6
  int v18; // r3
  char v19; // r2
  char v20; // r3
  __int16 TPage; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  char v25; // r2
  char v26; // r3
  char v27; // r3
  int v28; // r2
  int *result; // r0
  int v30; // [sp+4h] [bp-30h]
  int v31; // [sp+8h] [bp-2Ch]
  int v32; // [sp+Ch] [bp-28h]
  int v33; // [sp+10h] [bp-24h]
  int v34; // [sp+14h] [bp-20h]
  __int16 v35; // [sp+18h] [bp-1Ch]

  for ( i = 4; i != -2; i -= 2 )
  {
    if ( mespktptr[i] != -1 )
    {
      v1 = mespktptr[i + globalframe];
      if ( *(_DWORD *)v1 == 1 )
      {
        if ( *((_DWORD *)&asmtaskframe + 256 * *(_DWORD *)(v1 + 4) + 18) )
        {
          v30 = v1 + 60;
          const_ambset(v1 + 60, *(char *)(v1 + 316));
          v31 = v1 + 84;
          const_ambset(v1 + 84, *(char *)(v1 + 316));
          const_ambset(v1 + 108, *(char *)(v1 + 316));
          v32 = v1 + 132;
          const_ambset(v1 + 132, *(char *)(v1 + 316));
          v33 = v1 + 228;
          const_ambset(v1 + 228, *(char *)(v1 + 316));
          v34 = v1 + 272;
          const_ambset(v1 + 272, *(char *)(v1 + 316));
          v2 = *(_WORD *)(v1 + 240);
          v3 = *(__int16 *)(v1 + 248) - v2;
          if ( v3 % 8 == 4 )
            v4 = v3 - 15;
          else
            v4 = v3 - 13;
          v35 = v4;
          v5 = *(_WORD *)(v1 + 258) - *(_WORD *)(v1 + 242);
          v6 = *(_WORD *)(v1 + 242);
          v7 = v4 + v2;
          *(_WORD *)(v1 + 168) = v4 + v2;
          v8 = v6 + 8;
          *(_WORD *)(v1 + 192) = v7;
          v9 = v6 - 26 + v5;
          v10 = *(_DWORD *)(v1 + 24);
          *(_WORD *)(v1 + 170) = v8;
          *(_WORD *)(v1 + 194) = v9;
          if ( v10 == 16 )
          {
            v11 = *(_DWORD *)(v1 + 20);
            v12 = v11 == 1;
            if ( v11 == 1 )
              v13 = v8 - 4;
            else
              v13 = v8 + 4;
            *(_WORD *)(v1 + 170) = v13;
            if ( v12 )
              v14 = v9 - 4;
            else
              v14 = v9 + 4;
            *(_WORD *)(v1 + 194) = v14;
          }
          v15 = *(__int16 *)(v1 + 178) + *(__int16 *)(v1 + 170);
          v16 = *(_DWORD *)(mespktptr[i + globalframe] + 40)
              * (*(__int16 *)(v1 + 194) - v15 - 4)
              / *(_DWORD *)(mespktptr[i + globalframe] + 36);
          *(_WORD *)(v1 + 216) = v35 + v2;
          *(_WORD *)(v1 + 218) = v16 + v15;
          v17 = *(_DWORD *)(mespktptr[i + globalframe] + 32);
          if ( pspWorldCheckFlg(128) && *(_DWORD *)(mespktptr[i + globalframe] + 4) == 14 )
          {
            if ( (v17 & 1) != 0 )
              addlocalprim2(v1 + 156);
            if ( (v17 & 2) != 0 )
              addlocalprim2(v1 + 180);
            if ( (v17 & 4) != 0 )
              addlocalprim2(v1 + 204);
            addlocalprim2(v30);
            addlocalprim2(v31);
            addlocalprim2(v32);
            addlocalprim2(v1 + 44);
            addlocalprim2(v1 + 320);
            addlocalprim2(v1 + 344);
          }
          else
          {
            if ( (v17 & 1) != 0 )
              addlocalprim(v1 + 156);
            if ( (v17 & 2) != 0 )
              addlocalprim(v1 + 180);
            if ( (v17 & 4) != 0 )
              addlocalprim(v1 + 204);
            addlocalprim(v30);
            addlocalprim(v31);
            addlocalprim(v32);
            addlocalprim(v1 + 44);
            addlocalprim(v1 + 320);
            addlocalprim(v1 + 344);
          }
          v18 = *(_DWORD *)(v1 + 12);
          if ( v18 == -1 )
          {
            faceuvclut(v34, *(_DWORD *)(v1 + 16));
          }
          else
          {
            v19 = 32 * v18;
            *(_BYTE *)(v1 + 288) = 32 * v18;
            *(_BYTE *)(v1 + 289) = -50;
            v20 = 32 * v18 + 31;
            *(_BYTE *)(v1 + 297) = -50;
            *(_BYTE *)(v1 + 296) = v20;
            *(_BYTE *)(v1 + 304) = v19;
            *(_BYTE *)(v1 + 312) = v20;
            *(_BYTE *)(v1 + 305) = -2;
            *(_BYTE *)(v1 + 313) = -2;
            TPage = GetTPage(0, 0, 448, 0);
            v22 = *(_DWORD *)(v1 + 12);
            *(_WORD *)(v1 + 298) = TPage;
            *(_WORD *)(v1 + 290) = GetClut(16 * (v22 % 4) + 448, v22 / 4 + 254);
          }
          if ( *(int *)(v1 + 28) > 0 )
          {
            v23 = *(unsigned __int8 *)(v1 + 288);
            v24 = *(unsigned __int8 *)(v1 + 296);
            if ( v23 == v24 )
            {
              v26 = *(_BYTE *)(v1 + 297);
              *(_BYTE *)(v1 + 297) = *(_BYTE *)(v1 + 289);
              *(_BYTE *)(v1 + 289) = v26;
              v27 = *(_BYTE *)(v1 + 313);
              *(_BYTE *)(v1 + 313) = *(_BYTE *)(v1 + 305);
              *(_BYTE *)(v1 + 305) = v27;
            }
            else
            {
              *(_BYTE *)(v1 + 288) = v24;
              *(_BYTE *)(v1 + 296) = v23;
              v25 = *(_BYTE *)(v1 + 304);
              *(_BYTE *)(v1 + 304) = *(_BYTE *)(v1 + 312);
              *(_BYTE *)(v1 + 312) = v25;
            }
          }
          if ( pspWorldCheckFlg(128) && *(_DWORD *)(mespktptr[i + globalframe] + 4) == 14 )
          {
            addlocalprim2(v34);
            addlocalprim2(v33);
          }
          else
          {
            addlocalprim(v34);
            addlocalprim(v33);
          }
        }
      }
    }
  }
  v28 = 1;
  result = mespktptrBack;
  mespktptrBack[0] = mespktptr[0];
  do
  {
    mespktptrBack[v28] = mespktptr[v28];
    ++v28;
  }
  while ( v28 != 6 );
  return result;
}

