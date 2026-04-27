// __Z21hakenunit_status_mainP7CTLINFO @ 0x19E960 (1764 bytes)
// WotL iOS - debug symbols

int __fastcall hakenunit_status_main(int result)
{
  int v1; // r3
  _DWORD *v2; // r5
  int v3; // r3
  int TouchSwype; // r0
  _DWORD *v5; // r3
  int v6; // r1
  _DWORD *v7; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r3
  int v10; // r2
  int v11; // r3
  bool v12; // cc
  int v13; // r2
  _DWORD *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r3

  v1 = *(_DWORD *)(result + 32);
  v2 = (_DWORD *)result;
  if ( v1 != 3 )
  {
    if ( v1 != 4 )
    {
      if ( v1 != 5 )
        return result;
      if ( !Wtask_status(8) && !Wtask_status(12) && !Wtask_status(9) )
      {
        v2[8] = 0;
        wld_flg &= 0xFFFDF7FF;
        Wtask_create(14, (void (__fastcall *)())Wdisp_floateventwindow);
        Wsend_taskparamater(14, 25, 47122, 0);
        dword_12FB460 = 1;
        Wtask_create(12, (void (__fastcall *)())world_scrollwindow);
        Wsend_taskparamater(12, (int)&comrec, 0, 0);
        anm_pac[9 * *v2] ^= 0x10u;
        win_pac[13 * v2[1]] ^= 0x10u;
        anm_pac[9 * v2[2]] ^= 0x10u;
        anm_pac[9 * v2[3]] ^= 0x10u;
        win_pac[13 * v2[4]] ^= 0x10u;
        win_pac[13 * v2[5]] ^= 0x10u;
      }
      return iOS_ClearRectHitAll();
    }
    if ( sSwypeCnt )
      --sSwypeCnt;
    iOSUnitListLRCurWrite(nullptr, nullptr);
    if ( sSwypeCnt )
    {
LABEL_21:
      if ( (pad_trg & 0x60) != 0 )
      {
        anm_pac[9 * v2[16]] |= 0x10u;
        anm_pac[9 * v2[17]] |= 0x10u;
        v2[8] = 5;
        Wsend_taskparamater(8, 0, 0, 1);
        Wsend_taskparamater(12, 0, 0, 1);
        Wsend_taskparamater(9, 0, 0, 1);
        pspWorldDisableFlg(16);
        return iOS_ClearRectHitAll();
      }
      if ( (pad_trg & 0x100) != 0 )
      {
        v5 = &anm_pac[9 * v2[16]];
        anm_pac[9 * v2[17] + 5] = 10;
        v5[5] = 10;
        sound_request(1);
        ctlsthelp_init();
        return iOS_ClearRectHitAll();
      }
      if ( (pad_dt & 0xC) == 0 )
      {
        anm_pac[9 * v2[16] + 1] = 102;
        anm_pac[9 * v2[17] + 1] = 104;
        v6 = v2[16];
        v7 = &anm_pac[9 * v2[17]];
        v7[4] = 0;
        v7[3] = 0;
        v8 = &anm_pac[9 * v6];
        v8[4] = 0;
        v8[3] = 0;
      }
      if ( !wldkey_rep(8u) || anm_pac[9 * v2[16] + 1] == 103 )
      {
        result = wldkey_rep(4u);
        if ( !result || anm_pac[9 * v2[17] + 1] == 105 )
          return result;
        anm_pac[9 * v2[16] + 1] = 103;
        v14 = &anm_pac[9 * v2[16]];
        v14[4] = 0;
        v14[3] = 0;
        v15 = v2[12];
        if ( v15 == 1 )
          goto LABEL_40;
        v16 = v2[10];
        if ( v16 )
          v17 = v16 - 1;
        else
          v17 = v15 - 1;
        v2[10] = v17;
        v13 = 2;
      }
      else
      {
        anm_pac[9 * v2[17] + 1] = 105;
        v9 = &anm_pac[9 * v2[17]];
        v9[4] = 0;
        v9[3] = 0;
        v10 = v2[12];
        if ( v10 == 1 )
        {
LABEL_40:
          sound_request(6);
          return iOS_ClearRectHitAll();
        }
        v11 = v2[10] + 1;
        v12 = v10 <= v11;
        v13 = 1;
        if ( v12 )
          v11 = 0;
        v2[10] = v11;
      }
      dword_2EB4D0 = v13;
      ctlworkingst_dataset(scritem[v2[10]] & 0x7FF);
      dword_2EB4E4 = 1;
      dword_2EB4F8 = 1;
      goto LABEL_40;
    }
    iOS_SetRectHit(2, 12, 32, 40, 40, 0);
    iOS_SetRectHit(3, 292, 32, 40, 40, 0);
    iOS_SetRectHit(5, 52, 20, 240, 200, 0);
    iOS_SetRectHit(6, 0, 0, 340, 240, 0);
    switch ( iOS_GetRectHitNoTap() )
    {
      case 2:
        v3 = pad_trg | 4;
        goto LABEL_14;
      case 3:
        v3 = pad_trg | 8;
        goto LABEL_14;
      case 5:
        v3 = pad_trg | 0x20;
        goto LABEL_14;
      case 6:
        v3 = pad_trg | 0x40;
LABEL_14:
        pad_trg = v3;
        break;
      default:
        break;
    }
    TouchSwype = iOS_getTouchSwype();
    if ( TouchSwype == -1 )
    {
      pad_trg = pad_trg & 0xFFFFFF9B | 4;
    }
    else
    {
      if ( TouchSwype != 1 )
      {
LABEL_20:
        iOSWldEffectLR(pad_trg);
        goto LABEL_21;
      }
      pad_trg = pad_trg & 0xFFFFFF97 | 8;
    }
    sSwypeCnt = 4;
    goto LABEL_20;
  }
  result = Wtask_status(12);
  if ( !result )
  {
    result = Wtask_status(14);
    if ( !result )
    {
      anm_pac[9 * v2[16]] ^= 0x10u;
      anm_pac[9 * v2[17]] ^= 0x10u;
      v2[8] = 4;
      result = hakenunit_status(scritem[word_12FB45C] & 0x7FF);
      v2[10] = word_12FB45C;
    }
  }
  return result;
}

