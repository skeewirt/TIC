// __ZL18scrollLandscapeSubs @ 0x142144 (880 bytes)
// WotL iOS - debug symbols

int __fastcall scrollLandscapeSub(__int16 a1)
{
  int v1; // r5
  int result; // r0
  int v3; // r1
  int v4; // r0
  int v5; // r12
  int v6; // r3
  int v7; // r1
  int v8; // r12
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r1
  int v15; // r12
  int v16; // r3
  int v17; // r1
  int v18; // r12
  int v19; // r3

  v1 = a1;
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
  result = iOSIsCurMode();
  if ( result )
    return result;
  if ( gMoveVector >= 0 )
  {
    v7 = mapVector;
    v4 = gActivePanelX;
    v8 = 28 * gActivePanelX + 14;
    if ( v8 > mapVector / 4096 )
    {
      ++sScrollAreaOkFlag;
      v9 = mapVector + gMoveVector;
      mapVector += gMoveVector;
      if ( v7 + gMoveVector < 0 )
        v9 = v7 + gMoveVector + 4095;
      if ( v8 < v9 >> 12 )
        goto LABEL_13;
    }
  }
  else
  {
    v3 = mapVector;
    v4 = gActivePanelX;
    v5 = 28 * gActivePanelX + 14;
    if ( v5 < mapVector / 4096 )
    {
      ++sScrollAreaOkFlag;
      v6 = mapVector + gMoveVector;
      mapVector += gMoveVector;
      if ( v3 + gMoveVector < 0 )
        v6 = v3 + gMoveVector + 4095;
      if ( v5 > v6 >> 12 )
LABEL_13:
        mapVector = 114688 * v4 + 57344;
    }
  }
  if ( dword_12B1728 >= 0 )
  {
    if ( v1 <= dword_12B16F8 / 4096 )
      goto LABEL_25;
    v12 = dword_12B16F8 + dword_12B1728;
    v13 = dword_12B16F8 + dword_12B1728 + 4095;
    dword_12B16F8 = v12;
    if ( v12 < 0 )
      v12 = v13;
    if ( v1 >= v12 >> 12 )
      goto LABEL_25;
  }
  else
  {
    if ( v1 >= dword_12B16F8 / 4096 )
      goto LABEL_25;
    v10 = dword_12B16F8 + dword_12B1728;
    v11 = dword_12B16F8 + dword_12B1728 + 4095;
    dword_12B16F8 = v10;
    if ( v10 < 0 )
      v10 = v11;
    if ( v1 <= v10 >> 12 )
      goto LABEL_25;
  }
  dword_12B16F8 = v1 << 12;
LABEL_25:
  if ( dword_12B172C < 0 )
  {
    v14 = dword_12B16FC;
    result = gActivePanelZ;
    v15 = 28 * gActivePanelZ + 14;
    if ( v15 >= dword_12B16FC / 4096 )
      return result;
    ++sScrollAreaOkFlag;
    v16 = dword_12B16FC + dword_12B172C;
    dword_12B16FC += dword_12B172C;
    if ( v14 + dword_12B172C < 0 )
      v16 = v14 + dword_12B172C + 4095;
    if ( v15 <= v16 >> 12 )
      return result;
LABEL_35:
    dword_12B16FC = 114688 * result + 57344;
    return result;
  }
  v17 = dword_12B16FC;
  result = gActivePanelZ;
  v18 = 28 * gActivePanelZ + 14;
  if ( v18 > dword_12B16FC / 4096 )
  {
    ++sScrollAreaOkFlag;
    v19 = dword_12B16FC + dword_12B172C;
    dword_12B16FC += dword_12B172C;
    if ( v17 + dword_12B172C < 0 )
      v19 = v17 + dword_12B172C + 4095;
    if ( v18 < v19 >> 12 )
      goto LABEL_35;
  }
  return result;
}

