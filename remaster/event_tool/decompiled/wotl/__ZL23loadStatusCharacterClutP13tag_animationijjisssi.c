// __ZL23loadStatusCharacterClutP13tag_animationijjisssi @ 0x138F34 (332 bytes)
// WotL iOS - debug symbols

int __fastcall loadStatusCharacterClut(
        unsigned __int8 *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        __int16 a6,
        __int16 a7,
        __int16 a8,
        int a9)
{
  int v10; // r1
  int v11; // r12
  int v12; // r0
  unsigned __int16 *v13; // r1
  int v15; // [sp+0h] [bp-24h]
  __int16 v16; // [sp+4h] [bp-20h]
  __int16 v17; // [sp+8h] [bp-1Ch]
  __int16 v18; // [sp+Ch] [bp-18h]
  int v19; // [sp+10h] [bp-14h]

  v10 = a1[7];
  switch ( a1[6] )
  {
    case 0x9Bu:
      v11 = 32 * v10 + 320;
      v15 = a5;
      v16 = a6;
      v17 = a7;
      v18 = a8;
      v19 = a9;
      v12 = a2;
      goto LABEL_6;
    case 0x9Cu:
      v11 = 32 * v10;
      v15 = a5;
      v16 = a6;
      v17 = a7;
      v18 = a8;
      v19 = a9;
      v12 = a2;
      goto LABEL_6;
    case 0x9Du:
      v11 = 32 * v10 + 160;
      v15 = a5;
      v16 = a6;
      v17 = a7;
      v18 = a8;
      v19 = a9;
      v12 = a2;
      goto LABEL_6;
    case 0x9Eu:
      v11 = 32 * v10 + 512;
      v12 = a2;
      v15 = a5;
      v16 = a6;
      v17 = a7;
      v18 = a8;
      v19 = a9;
LABEL_6:
      v13 = (unsigned __int16 *)((char *)&gOtherPalette + v11);
      break;
    default:
      v15 = a5;
      v16 = a6;
      v13 = (unsigned __int16 *)&gFontWork[13014 * a1[5] + 12502 + 32 * v10];
      v12 = a2;
      v17 = a7;
      v18 = a8;
      v19 = a9;
      break;
  }
  return loadClutDataCalcPlus(v12, v13, a3, a4, v15, v16, v17, v18, v19);
}

