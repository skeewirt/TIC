// __Z13iosAsmMUL3232llll @ 0x1D0A68 (284 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall iosAsmMUL3232(int a1, int a2, int a3, int a4)
{
  __int64 v5; // r4
  int v6; // r2
  int v7; // r1
  bool v8; // cf
  unsigned __int64 v9; // r8
  unsigned int v10; // r10
  unsigned int v11; // r6
  int v12; // r4
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r3
  int v16; // r0
  int v17; // r12

  if ( a1 < 0 )
    v5 = -(__int64)(unsigned int)-a1;
  else
    v5 = (unsigned int)a1;
  if ( a2 < 0 )
  {
    v7 = -a2;
    v8 = v7 == 0;
    a2 = -v7;
    v6 = -!v8;
  }
  else
  {
    v6 = 0;
  }
  v9 = v5 * __PAIR64__(v6, a2);
  v10 = a2 * v5;
  if ( a3 < 0 )
    v11 = (unsigned __int64)-(__int64)(unsigned int)a3 >> 32;
  else
    v11 = 0;
  if ( a4 < 0 )
  {
    v13 = -a4;
    v8 = v13 == 0;
    a4 = -v13;
    v12 = -!v8;
  }
  else
  {
    v12 = 0;
  }
  v14 = (__PAIR64__(v11, a3) * __PAIR64__(v12, a4)) >> 32;
  v15 = a4 * a3;
  v16 = HIDWORD(v9) - v14;
  if ( v10 < v15 )
    --v16;
  if ( v16 >= 0 )
    v17 = v16 >> 12;
  else
    v17 = v16 + 0xFFFF;
  if ( v16 < 0 )
    v17 >>= 16;
  if ( v17 && v17 != -1 )
    asmoverflowf = 1;
  return (v16 << 20) | ((v10 - v15) >> 12);
}

