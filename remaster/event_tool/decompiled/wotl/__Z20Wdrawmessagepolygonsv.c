// __Z20Wdrawmessagepolygonsv @ 0x49A40 (992 bytes)
// WotL iOS - debug symbols, no obfuscation

int *__fastcall Wdrawmessagepolygons()
{
  int i; // r5
  int v1; // r4
  bool v2; // zf
  __int16 v3; // r3
  int v4; // r2
  __int16 v5; // r1
  __int16 v6; // r0
  __int16 v7; // r3
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
  int v18; // r2
  int *result; // r0
  __int16 v20; // [sp+0h] [bp-34h]
  int v21; // [sp+4h] [bp-30h]
  int v22; // [sp+8h] [bp-2Ch]
  int v23; // [sp+Ch] [bp-28h]
  int v24; // [sp+10h] [bp-24h]
  int v25; // [sp+14h] [bp-20h]
  __int16 v26; // [sp+18h] [bp-1Ch]

  for ( i = 4; i != -2; i -= 2 )
  {
    if ( mespktptr[i] != -1 )
    {
      v1 = mespktptr[i + wglobalframe];
      if ( *(_DWORD *)v1 == 1 )
      {
        if ( *((_DWORD *)&asmtaskframe + 256 * *(_DWORD *)(v1 + 4) + 18) )
        {
          v21 = v1 + 60;
          const_ambset(v1 + 60, floatr);
          v22 = v1 + 84;
          const_ambset(v1 + 84, floatr);
          const_ambset(v1 + 108, floatr);
          v23 = v1 + 132;
          const_ambset(v1 + 132, floatr);
          v24 = v1 + 228;
          const_ambset(v1 + 228, floatr);
          v25 = v1 + 272;
          const_ambset(v1 + 272, floatr);
          if ( *(_BYTE *)(v1 + 319) )
          {
            v2 = wallgrayf == 0;
            if ( wallgrayf )
            {
              *(_WORD *)(v1 + 246) = 32060;
              *(_BYTE *)(v1 + 280) = 64;
              v3 = 80;
            }
            else
            {
              v3 = 31804;
            }
            if ( v2 )
              *(_WORD *)(v1 + 246) = v3;
            else
              *(_BYTE *)(v1 + 281) = v3;
            if ( !v2 )
              *(_BYTE *)(v1 + 282) = v3 + 32;
          }
          v20 = *(_WORD *)(v1 + 240);
          v4 = *(__int16 *)(v1 + 248) - v20;
          if ( v4 % 8 == 4 )
            v5 = v4 - 15;
          else
            v5 = v4 - 13;
          v26 = v5;
          v6 = *(_WORD *)(v1 + 258) - *(_WORD *)(v1 + 242);
          v7 = *(_WORD *)(v1 + 242);
          *(_WORD *)(v1 + 168) = v5 + v20;
          *(_WORD *)(v1 + 192) = v5 + v20;
          v8 = v7 + 8;
          v9 = v7 - 26 + v6;
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
          v16 = *(_DWORD *)(mespktptr[i + wglobalframe] + 40)
              * (*(__int16 *)(v1 + 194) - v15 - 4)
              / *(_DWORD *)(mespktptr[i + wglobalframe] + 36);
          *(_WORD *)(v1 + 216) = v26 + v20;
          *(_WORD *)(v1 + 218) = v16 + v15;
          v17 = *(_DWORD *)(mespktptr[i + wglobalframe] + 32);
          if ( pspWorldCheckFlg(128) && *(_DWORD *)(mespktptr[i + wglobalframe] + 4) == 14 )
          {
            if ( (v17 & 1) != 0 )
              Waddlocalprim2(v1 + 156);
            if ( (v17 & 2) != 0 )
              Waddlocalprim2(v1 + 180);
            if ( (v17 & 4) != 0 )
              Waddlocalprim2(v1 + 204);
            Waddlocalprim2(v21);
            Waddlocalprim2(v22);
            Waddlocalprim2(v23);
            Waddlocalprim2(v1 + 44);
            Waddlocalprim2(v1 + 320);
            Waddlocalprim2(v1 + 344);
          }
          else
          {
            if ( (v17 & 1) != 0 )
              Waddlocalprim(v1 + 156);
            if ( (v17 & 2) != 0 )
              Waddlocalprim(v1 + 180);
            if ( (v17 & 4) != 0 )
              Waddlocalprim(v1 + 204);
            Waddlocalprim(v21);
            Waddlocalprim(v22);
            Waddlocalprim(v23);
            Waddlocalprim(v1 + 44);
            Waddlocalprim(v1 + 320);
            Waddlocalprim(v1 + 344);
          }
          if ( *(_DWORD *)(v1 + 12) != -1 )
            Wfaceuvclut(v25);
          if ( pspWorldCheckFlg(128) && *(_DWORD *)(mespktptr[i + wglobalframe] + 4) == 14 )
          {
            Waddlocalprim2(v25);
            Waddlocalprim2(v24);
          }
          else
          {
            Waddlocalprim(v25);
            Waddlocalprim(v24);
          }
        }
      }
    }
  }
  v18 = 1;
  result = mespktptrBack;
  mespktptrBack[0] = mespktptr[0];
  do
  {
    mespktptrBack[v18] = mespktptr[v18];
    ++v18;
  }
  while ( v18 != 6 );
  return result;
}

