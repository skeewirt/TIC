// __Z11iosAsmMUL64lll @ 0x1D093C (296 bytes)
// WotL iOS - debug symbols

int __fastcall iosAsmMUL64(int a1, int a2, int a3)
{
  int v3; // r12
  unsigned int v6; // r6
  int v7; // r3
  unsigned int v8; // r4
  int v9; // r1
  int v10; // r0
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r6
  unsigned int v14; // r1
  int v15; // r4
  unsigned int v16; // r5
  unsigned int v17; // r2
  int v18; // lr
  int v19; // r9
  bool v20; // cc

  if ( a1 < 0 )
    v6 = (unsigned __int64)-(__int64)(unsigned int)-a1 >> 32;
  else
    v6 = 0;
  if ( a2 < 0 )
  {
    v9 = -a2;
    v7 = -v9;
    v8 = (unsigned __int64)-(__int64)(unsigned int)v9 >> 32;
  }
  else
  {
    v7 = a2;
    v8 = 0;
  }
  v10 = v7 * a1;
  v11 = (__PAIR64__(v6, a1) * __PAIR64__(v8, v7)) >> 32;
  v12 = v11;
  v13 = (unsigned int)v11 >> 31;
  v14 = false;
  if ( v11 < 0 )
  {
    v10 = -v10;
    v12 = ~v11;
    if ( !v10 )
      v14 = true;
  }
  v15 = 0;
  if ( a3 < 0 )
    ++v10;
  v16 = (unsigned int)a3 >> 31;
  if ( a3 < 0 )
    v17 = ~a3;
  else
    v17 = a3;
  v18 = 0;
  v19 = 0;
  while ( 1 )
  {
    v14 *= 2;
    if ( v12 < 0 )
      v14 |= 1u;
    v12 *= 2;
    if ( v10 < 0 )
      v12 |= 1u;
    v20 = v17 > v14;
    if ( v17 > v14 )
      v3 = 0;
    else
      v14 -= v17;
    if ( !v20 )
      v3 = 1;
    v19 *= 2;
    ++v18;
    if ( v15 < 0 )
      v19 |= 1u;
    v15 = v3 | (2 * v15);
    if ( v18 == 64 )
      break;
    v10 *= 2;
  }
  if ( v13 != v16 )
  {
    if ( v19 && v19 != -1 )
      asmoverflowf = 1;
    return -v15;
  }
  return v15;
}

