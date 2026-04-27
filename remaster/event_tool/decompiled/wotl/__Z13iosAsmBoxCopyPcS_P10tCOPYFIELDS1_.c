// __Z13iosAsmBoxCopyPcS_P10tCOPYFIELDS1_ @ 0x1D0B88 (500 bytes)
// WotL iOS - debug symbols

int __fastcall iosAsmBoxCopy(int result, int a2, __int16 *a3, __int16 *a4)
{
  int v4; // r5
  __int16 v6; // lr
  __int16 v7; // r2
  unsigned int v8; // r12
  unsigned int v9; // r8
  unsigned int v10; // r0
  int v11; // r1
  int v12; // r3
  int v13; // r12
  unsigned int v14; // r2
  int v15; // r9
  int *v16; // r8
  int v17; // r5
  _DWORD *v18; // r6
  unsigned int v19; // r11
  unsigned int v20; // r10
  int v21; // r1
  unsigned int v22; // r4
  unsigned int i; // lr
  int v24; // t1
  int v25; // t1
  unsigned int v26; // r3
  char v27; // r12
  unsigned int v28; // r3
  int v29; // t1
  int v30; // t1
  char v31; // r5
  char v32; // lr
  unsigned int v33; // r12
  bool v34; // zf
  int v35; // [sp+0h] [bp-34h]
  int v36; // [sp+4h] [bp-30h]
  int v37; // [sp+8h] [bp-2Ch]
  int v38; // [sp+Ch] [bp-28h]
  unsigned int v39; // [sp+10h] [bp-24h]
  unsigned int v40; // [sp+14h] [bp-20h]
  int v41; // [sp+18h] [bp-1Ch]

  v4 = *a4;
  v6 = a3[1];
  v7 = *a3;
  v8 = *((_DWORD *)a3 + 2);
  if ( v4 > 255 )
    return result;
  v9 = *((_DWORD *)a4 + 2);
  v37 = *((_DWORD *)a4 + 3);
  v35 = 4 * v8;
  v10 = result + ((unsigned int)v7 >> 1) + (v8 >> 1) * v6;
  v40 = a3[2];
  v41 = 4 * v9;
  v11 = a2 + ((unsigned int)v4 >> 1) + (v9 >> 1) * a4[1];
  v38 = 8 * (v10 & 3) + 4 * (v7 & 1);
  v12 = 8 * (v11 & 3);
  v13 = 4 * (v4 & 1);
  v14 = v12 + v13;
  v39 = v12 + v13;
  v15 = 15 << v38;
  v16 = (int *)(v10 & 0xFFFFFFFC);
  v17 = 15 << (v12 + v13);
  v18 = (_DWORD *)(v11 & 0xFFFFFFFC);
  v36 = a3[3];
  v19 = v10 & 0xFFFFFFFC;
  v20 = v11 & 0xFFFFFFFC;
  result = *(_DWORD *)(v10 & 0xFFFFFFFC);
  v21 = *(_DWORD *)(v11 & 0xFFFFFFFC);
  v22 = v38;
  while ( 2 )
  {
    for ( i = v40; i; --i )
    {
      if ( result || i <= 7 )
      {
        if ( (result & v15) != 0 )
        {
          v26 = ((result & v15) + v37) & v15;
          if ( v22 < v14 )
            v27 = v14 - v22;
          else
            v27 = v22 - v14;
          if ( v22 < v14 )
            v28 = v26 << v27;
          else
            v28 = v26 >> v27;
          v21 = v28 | ~v17 & v21;
        }
        v15 *= 16;
        if ( v15 )
        {
          v22 += 4;
        }
        else
        {
          v29 = v16[1];
          ++v16;
          result = v29;
          v15 = 15;
          v22 = 0;
        }
        v17 *= 16;
        if ( v17 )
        {
          v14 += 4;
        }
        else
        {
          *v18 = v21;
          v30 = v18[1];
          ++v18;
          v21 = v30;
        }
        if ( !v17 )
        {
          v17 = 15;
          v14 = 0;
        }
        continue;
      }
      if ( i == 8 )
        break;
      *v18 = v21;
      v24 = v18[1];
      ++v18;
      v21 = v24;
      v25 = v16[1];
      ++v16;
      result = v25;
      i -= 7;
    }
    *v18 = v21;
    v31 = v39 + v41;
    v32 = v38 + v35;
    v33 = 4 * ((v39 + v41) >> 5);
    v21 = *(_DWORD *)(v33 + v20);
    v18 = (_DWORD *)(v33 + v20);
    v34 = v36 == 1;
    v16 = (int *)(4 * ((unsigned int)(v38 + v35) >> 5) + v19);
    result = *v16;
    --v36;
    if ( !v34 )
    {
      v14 = v31 & 0x1F;
      v22 = v32 & 0x1F;
      v17 = 15 << (v31 & 0x1F);
      v15 = 15 << (v32 & 0x1F);
      v39 = v14;
      v38 = v22;
      v20 += v33;
      v19 = (unsigned int)v16;
      continue;
    }
    break;
  }
  return result;
}

