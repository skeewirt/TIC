// __ZL13set_event_oneiitP10TURN_TABLE @ 0x11DF64 (224 bytes)
// WotL iOS - debug symbols

int __fastcall set_event_one(int a1, int a2, unsigned __int16 a3, int a4)
{
  int v6; // r4
  int v7; // r5
  int v8; // r6
  int i; // r8
  char v10; // r1
  char *v11; // r0
  int v12; // r0

  v6 = a4;
  v7 = a4;
  v8 = 0;
  while ( *(unsigned __int16 *)(v6 + 2) <= (unsigned int)a3 )
  {
    ++v8;
    v6 += 4;
    if ( v8 == 40 )
      return 0;
  }
  for ( i = 39; ; --i )
  {
    v7 -= 4;
    if ( i <= v8 )
      break;
    memcpy((void *)(v7 + 160), (const void *)(v7 + 156), 4u);
  }
  *(_WORD *)(v6 + 2) = a3;
  v10 = a1;
  if ( a2 )
  {
    v10 = a1 + 64;
    v11 = (char *)&bwork + 486 * a1;
    if ( v11[401] == 18 )
    {
      v10 = a1 + 96;
    }
    else
    {
      v12 = *((__int16 *)v11 + 201);
      if ( v12 > 255 )
        v10 ^= 0x80u;
      *(_BYTE *)(v6 + 1) = v12;
    }
  }
  *(_BYTE *)v6 = v10;
  return 1;
}

