// __Z15iosAsmKanjiCopyPcS_P10tCOPYFIELDi @ 0x1D0D7C (244 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall iosAsmKanjiCopy(char *a1, int a2, __int16 *a3, int a4)
{
  unsigned int v6; // r6
  unsigned int v7; // r8
  unsigned int result; // r0
  char v9; // lr
  int v10; // r3
  unsigned int v11; // r10
  int i; // r4
  unsigned int v13; // r1
  int j; // r9
  char v15; // t1
  int v16; // r12
  char v17; // r2
  char v18; // r2
  unsigned int v19; // [sp+0h] [bp-20h]
  unsigned int v20; // [sp+4h] [bp-1Ch]

  v6 = 0;
  v7 = kanjiclipstart;
  v19 = kanjiclipend;
  v20 = *a3;
  result = *((_DWORD *)a3 + 2);
  v9 = *a1;
  v10 = 4;
  v11 = result >> 1;
  for ( i = a2 + (result >> 1) * a3[1]; ; i += v11 )
  {
    if ( v6 < v19 )
    {
      v13 = v20;
      for ( j = 0; j != 10; ++j )
      {
        if ( (unsigned __int8)(v9 & 0xC0) >> 6 && v6 >= v7 )
        {
          v16 = ((unsigned __int8)(v9 & 0xC0) >> 6) + a4;
          result = (v13 >> 1) + i;
          v17 = *(_BYTE *)result;
          if ( (v13 & 1) != 0 )
          {
            LOBYTE(v16) = 16 * v16;
            v18 = v17 & 0xF;
          }
          else
          {
            v18 = v17 & 0xF0;
          }
          *(_BYTE *)result = v18 | v16;
        }
        if ( --v10 )
        {
          v9 *= 4;
        }
        else
        {
          v15 = *++a1;
          v9 = v15;
          v10 = 4;
        }
        ++v13;
      }
    }
    if ( ++v6 == 14 )
      break;
  }
  return result;
}

