// __Z15set_event_tableP10TURN_TABLEi @ 0x11E19C (884 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall set_event_table(int a1, int a2)
{
  int v3; // r1
  int v4; // r3
  int active_unit; // r0
  unsigned int v6; // r5
  int v7; // r3
  bool v8; // zf
  unsigned int v9; // r4
  _BOOL4 v10; // r3
  int i; // r6
  int v12; // r12
  int v13; // r2
  int v14; // r10
  int v15; // r3
  int v16; // r8
  unsigned int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r3
  int v20; // r0
  int v22; // [sp+0h] [bp-38h]
  int v24; // [sp+Ch] [bp-2Ch]
  int v25; // [sp+10h] [bp-28h]
  _BOOL2 v26; // [sp+14h] [bp-24h]
  unsigned __int8 *v27; // [sp+18h] [bp-20h]

  v3 = 4;
  v26 = TF_stack_phase == 9;
  *(_BYTE *)a1 = -1;
  *(_BYTE *)(a1 + 1) = -1;
  *(_WORD *)(a1 + 2) = -1;
  do
  {
    v4 = a1 + v3;
    *(_BYTE *)(v3 + a1) = -1;
    v3 += 4;
    *(_BYTE *)(v4 + 1) = -1;
    *(_WORD *)(v4 + 2) = -1;
  }
  while ( v3 != 160 );
  if ( a2 != 2 )
  {
    active_unit = get_active_unit();
    if ( active_unit )
      set_event_one(*(unsigned __int8 *)(active_unit + 428), 0, 0, a1);
  }
  v25 = 0;
  v24 = 0;
  v27 = (unsigned __int8 *)&bwork;
  do
  {
    if ( !check_turn_frozen((char *)&bwork + 486 * v24) )
    {
      v6 = v27[100] & 2;
      if ( (v27[100] & 2) != 0 )
        v6 = v27[108];
      if ( (v27[101] & 0x10) != 0 && v6 < v27[113] )
        v6 = v27[113];
      v7 = v27[381];
      v8 = v7 == 255;
      if ( v7 != 255 )
        v8 = a2 == 1;
      if ( !v8 )
      {
        LOWORD(v9) = v6 + v7;
        if ( v27[381] )
          goto LABEL_20;
        v10 = a2 != 3;
        if ( !v27[424] )
          v10 = 1;
        if ( v10 )
LABEL_20:
          LOWORD(v9) = v9 + v26;
        v25 += set_event_one(v24, 1, (unsigned __int16)((_WORD)v9 << 8), a1);
        if ( (v27[97] & 1) != 0 )
        {
          set_cco_SD((char *)&bwork + 486 * v24);
          for ( i = 0; i != 39; ++i )
          {
            v9 = (unsigned __int16)(v9 + v27[429]);
            if ( v9 > 0xFF )
              break;
            v25 += set_event_one(v24, 1, (unsigned __int16)((_WORD)v9 << 8), a1);
          }
        }
      }
      if ( a2 != 2 )
      {
        if ( (v27[100] & 4) != 0 )
        {
          v13 = v27[107];
          if ( (v27[90] & 4) != 0 )
            v13 = 512;
          v12 = (v13 - v6) & ~((int)(v13 - v6) >> 31);
        }
        else
        {
          v12 = 0;
        }
        if ( (v27[100] & 8) != 0 )
        {
          v15 = v27[106];
          if ( (v27[90] & 8) != 0 )
            v15 = 512;
          v14 = (v15 - v6) & ~((int)(v15 - v6) >> 31);
        }
        else
        {
          v14 = 0;
        }
        v16 = 0;
        v17 = v27[64];
        v18 = v27[65];
        if ( !v27[64] )
          v17 = 1;
        while ( 1 )
        {
          while ( v18 > 0x63 )
          {
            if ( v6 <= 0xFF )
            {
              v22 = v12;
              v18 %= 0x64u;
              v20 = set_event_one(v24, 0, (unsigned __int16)(100 - v18 + ((_WORD)v6 << 8)), a1);
              v12 = v22;
              if ( v20 )
              {
                ++v16;
                v25 += v20;
                if ( v16 <= 39 )
                  continue;
              }
            }
            goto LABEL_54;
          }
          v6 = (unsigned __int16)(v6 + 1);
          if ( v12 )
          {
            v19 = v17 >> 1;
            --v12;
            if ( !(v17 >> 1) )
              LOWORD(v19) = 1;
            if ( v14 )
              --v14;
          }
          else if ( v14 )
          {
            --v14;
            LOWORD(v19) = (unsigned __int8)((int)(3 * v17) / 2);
          }
          else
          {
            LOWORD(v19) = v17;
          }
          if ( v6 > 0x1F4 )
            break;
          v18 = (unsigned __int16)(v18 + v19);
        }
      }
    }
LABEL_54:
    v8 = v24++ == 20;
    v27 += 486;
  }
  while ( !v8 );
  if ( v25 )
    return 0;
  else
    return -1;
}

