// __ZL19scrollLandscapeSub2P13tag_animation @ 0x141E18 (748 bytes)
// WotL iOS - debug symbols

int __fastcall scrollLandscapeSub2(__int16 *a1)
{
  int result; // r0
  int v3; // r1
  int v4; // r3
  int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r1
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2

  result = iOSTchHoseiControl();
  if ( result )
  {
    if ( mapVector > 114688 * (unsigned __int8)gMapX + 458752 )
      mapVector = 114688 * (unsigned __int8)gMapX + 458752;
    if ( mapVector < -458752 )
      mapVector = -458752;
    if ( dword_12B16FC > 114688 * (unsigned __int8)gMapY + 458752 )
      dword_12B16FC = 114688 * (unsigned __int8)gMapY + 458752;
    if ( dword_12B16FC < -458752 )
      dword_12B16FC = -458752;
    return result;
  }
  sScrollAreaOkFlag = 0;
  if ( gMoveVector >= 0 )
  {
    v3 = a1[32];
    if ( v3 > mapVector / 4096 )
    {
      sScrollAreaOkFlag = 1;
      v6 = mapVector + gMoveVector;
      v7 = mapVector + gMoveVector + 4095;
      mapVector = v6;
      if ( v6 < 0 )
        v6 = v7;
      if ( v3 < v6 >> 12 )
        goto LABEL_12;
    }
  }
  else
  {
    v3 = a1[32];
    if ( v3 < mapVector / 4096 )
    {
      sScrollAreaOkFlag = 1;
      v4 = mapVector + gMoveVector;
      v5 = mapVector + gMoveVector + 4095;
      mapVector = v4;
      if ( v4 < 0 )
        v4 = v5;
      if ( v3 > v4 >> 12 )
LABEL_12:
        mapVector = v3 << 12;
    }
  }
  if ( dword_12B1728 >= 0 )
  {
    v8 = a1[33];
    if ( v8 <= dword_12B16F8 / 4096 )
      goto LABEL_24;
    v11 = dword_12B16F8 + dword_12B1728;
    v12 = dword_12B16F8 + dword_12B1728 + 4095;
    dword_12B16F8 = v11;
    if ( v11 < 0 )
      v11 = v12;
    if ( v8 >= v11 >> 12 )
      goto LABEL_24;
  }
  else
  {
    v8 = a1[33];
    if ( v8 >= dword_12B16F8 / 4096 )
      goto LABEL_24;
    v9 = dword_12B16F8 + dword_12B1728;
    v10 = dword_12B16F8 + dword_12B1728 + 4095;
    dword_12B16F8 = v9;
    if ( v9 < 0 )
      v9 = v10;
    if ( v8 <= v9 >> 12 )
      goto LABEL_24;
  }
  dword_12B16F8 = v8 << 12;
LABEL_24:
  if ( dword_12B172C < 0 )
  {
    result = a1[34];
    if ( result >= dword_12B16FC / 4096 )
      return result;
    ++sScrollAreaOkFlag;
    v13 = dword_12B16FC + dword_12B172C;
    v14 = dword_12B16FC + dword_12B172C + 4095;
    dword_12B16FC = v13;
    if ( v13 < 0 )
      v13 = v14;
    if ( result <= v13 >> 12 )
      return result;
LABEL_34:
    result <<= 12;
    dword_12B16FC = result;
    return result;
  }
  result = a1[34];
  if ( result > dword_12B16FC / 4096 )
  {
    ++sScrollAreaOkFlag;
    v15 = dword_12B16FC + dword_12B172C;
    v16 = dword_12B16FC + dword_12B172C + 4095;
    dword_12B16FC = v15;
    if ( v15 < 0 )
      v15 = v16;
    if ( result < v15 >> 12 )
      goto LABEL_34;
  }
  return result;
}

