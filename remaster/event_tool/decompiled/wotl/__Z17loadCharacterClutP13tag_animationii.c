// __Z17loadCharacterClutP13tag_animationii @ 0x13C6AC (800 bytes)
// WotL iOS - debug symbols

int __fastcall loadCharacterClut(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r10
  __int16 v9; // r6
  __int16 v10; // r11
  __int16 v11; // r2
  int eventflag; // r5
  int v13; // r0
  __int16 AnimationHight; // r0
  __int16 v15; // r2
  int v16; // r1
  unsigned __int16 *v18; // r0
  __int16 v19; // [sp+0h] [bp-38h]
  __int16 v20; // [sp+4h] [bp-34h]
  __int16 v21; // [sp+8h] [bp-30h]
  int v22; // [sp+Ch] [bp-2Ch]
  __int16 v23; // [sp+10h] [bp-28h]
  __int16 v24; // [sp+10h] [bp-28h]
  int v26; // [sp+18h] [bp-20h]
  unsigned int v27; // [sp+1Ch] [bp-1Ch]

  v26 = *(unsigned __int8 *)(a1 + 5);
  v5 = *(unsigned __int8 *)(a1 + 7);
  v27 = *(unsigned __int8 *)(a1 + 4);
  v6 = 13014 * v26;
  v7 = (unsigned __int8)gFontWork[13014 * v26 + 1];
  if ( (unsigned __int8)(v7 - 96) > 0x3Au && (unsigned int)(v7 - 159) > 3 )
  {
    loadClutData((unsigned __int16 *)&gFontWork[v6 + 12758], 0xAu, v27, 0);
    v8 = 32 * v5;
  }
  else
  {
    v8 = 32 * v5;
    loadClutData((unsigned __int16 *)&gFontWork[32 * v5 + 12758 + v6], 0xAu, v27, 0);
  }
  switch ( a2 )
  {
    case 2:
      v9 = -8;
      break;
    case 3:
      v9 = -12;
      break;
    case 1:
      v9 = -4;
      break;
    default:
      v9 = 0;
      v10 = 0;
      v11 = 0;
      goto LABEL_13;
  }
  v10 = v9;
  v11 = v9;
LABEL_13:
  if ( (gMapInfo & 2) == 0 )
  {
    v23 = v11;
    eventflag = read_eventflag(35);
    v13 = read_eventflag(36);
    v11 = v23;
    if ( v13 )
    {
      if ( eventflag >= 0 )
      {
        if ( eventflag <= 1 )
        {
          v10 -= 3;
          goto LABEL_25;
        }
        if ( eventflag == 2 )
        {
          v10 -= 4;
          --v9;
          v11 = v23 + 3;
          goto LABEL_27;
        }
      }
      v10 -= 4;
      v9 -= 2;
      v11 = v23 + 4;
      goto LABEL_27;
    }
    if ( eventflag < 0 )
    {
LABEL_19:
      v10 -= 2;
LABEL_25:
      --v9;
      v11 = v23 + 2;
      goto LABEL_27;
    }
    if ( eventflag > 1 )
    {
      if ( eventflag == 2 )
      {
        --v10;
        v11 = v23 + 1;
        goto LABEL_27;
      }
      goto LABEL_19;
    }
  }
LABEL_27:
  v24 = v11;
  AnimationHight = getAnimationHight(a1);
  v15 = v24;
  if ( (gMapInfo & 2) == 0 && AnimationHight - 48 > *(__int16 *)(a1 + 66) )
  {
    v9 = 0;
    v10 = 0;
    v15 = 0;
  }
  switch ( *(_BYTE *)(a1 + 6) )
  {
    case 0x9B:
      v19 = v10;
      v20 = v9;
      v16 = v8 + 320;
      v21 = v15;
      v22 = a3;
      goto LABEL_35;
    case 0x9C:
      return loadClutDataCalc((unsigned __int16 *)((char *)&gOtherPalette + v8), 3u, v27, 0, v10, v9, v15, a3);
    case 0x9D:
      v19 = v10;
      v20 = v9;
      v16 = v8 + 160;
      v21 = v15;
      v22 = a3;
      goto LABEL_35;
    case 0x9E:
      v19 = v10;
      v20 = v9;
      v21 = v15;
      v16 = v8 + 512;
      v22 = a3;
LABEL_35:
      v18 = (unsigned __int16 *)((char *)&gOtherPalette + v16);
      break;
    default:
      v19 = v10;
      v20 = v9;
      v18 = (unsigned __int16 *)&gFontWork[13014 * v26 + 12502 + v8];
      v21 = v15;
      v22 = a3;
      break;
  }
  return loadClutDataCalc(v18, 3u, v27, 0, v19, v20, v21, v22);
}

