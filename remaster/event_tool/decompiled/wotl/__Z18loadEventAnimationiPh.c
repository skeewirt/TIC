// __Z18loadEventAnimationiPh @ 0x1557CC (556 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall loadEventAnimation(int a1, unsigned __int8 *a2)
{
  int *v3; // r5
  int *v5; // r0
  unsigned __int8 *v6; // r9
  unsigned __int8 *v7; // r2
  int *v8; // lr
  int v9; // r12
  int v10; // t1
  int v11; // r3
  char *v12; // r2
  int v13; // r12
  unsigned __int8 v14; // r3
  int v15; // lr
  int *v16; // r12
  int v17; // r5
  char *v18; // r4
  int v19; // r2
  int v20; // r3
  int v21; // r3
  _BYTE *v22; // r2
  int v23; // r12
  unsigned __int8 v24; // r3
  int v25; // r3
  unsigned __int8 *v26; // r12
  int i; // r2
  unsigned __int8 v28; // r3
  int v29; // r3
  unsigned __int8 *v30; // r12
  int j; // r2
  unsigned __int8 v32; // r3
  int *v33; // r0

  v3 = &gExtractArea[7513 * a1];
  if ( v3[1] )
    return 0;
  v5 = &gExtractArea[7513 * a1 + 71];
  v6 = a2;
  v7 = a2;
  v8 = v3;
  do
  {
    v9 = ((((v7[3] << 8) + v7[2]) << 8) + v7[1]) << 8;
    v10 = *v7;
    v7 += 4;
    v11 = v9 + v10;
    if ( v9 + v10 == -1 )
      v11 = 0;
    v8[7] = (int)v5 + v11;
    ++v8;
  }
  while ( v7 != a2 + 256 );
  v12 = (char *)v3 + 1;
  v13 = 257;
  *((_BYTE *)v3 + 284) = a2[256];
  do
  {
    v14 = a2[v13++];
    v12[284] = v14;
    ++v12;
  }
  while ( v13 != 1280 );
  v15 = 0;
  v16 = &gExtractArea[7513 * a1 + 329];
  v17 = 30052 * a1 + 2980;
  v18 = (char *)gExtractArea + v17;
  do
  {
    ++v15;
    v19 = ((((v6[1283] << 8) + v6[1282]) << 8) + v6[1281]) << 8;
    v20 = v6[1280];
    v6 += 4;
    v21 = v19 + v20;
    if ( v21 == -1 )
      v21 = 0;
    *v16 = (int)&v18[v21];
    v16[208] = (int)&gExtractArea[7513 * a1 + 865] + v21;
    ++v16;
  }
  while ( v15 != 40 );
  v22 = v18 + 1;
  v23 = 1441;
  *((_BYTE *)gExtractArea + v17) = a2[1440];
  v18[480] = a2[1440];
  do
  {
    *v22 = a2[v23];
    v24 = a2[v23++];
    v22[480] = v24;
    ++v22;
  }
  while ( v23 != 1920 );
  v25 = 30052 * a1 + 3940;
  v26 = (unsigned __int8 *)gExtractArea + v25 + 1;
  *((_BYTE *)gExtractArea + v25) = a2[1920];
  for ( i = 1921; i != 2432; ++i )
  {
    v28 = a2[i];
    *v26++ = v28;
  }
  v29 = 30052 * a1 + 4452;
  v30 = (unsigned __int8 *)gExtractArea + v29 + 1;
  *((_BYTE *)gExtractArea + v29) = a2[2432];
  for ( j = 2433; j != 28032; ++j )
  {
    v32 = a2[j];
    *v30++ = v32;
  }
  v33 = &gExtractArea[7513 * a1];
  v33[1] = 254;
  v33[2] = 3;
  return 1;
}

