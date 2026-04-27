// __Z16hakenunit_changeP7CTLINFO @ 0x19F42C (908 bytes)
// WotL iOS - debug symbols

int __fastcall hakenunit_change(_DWORD *a1)
{
  int v2; // r1
  int v3; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3
  char *v8; // r0
  char *v9; // r2
  int v10; // [sp+0h] [bp-10h] BYREF
  int v11; // [sp+4h] [bp-Ch] BYREF

  v11 = a1[10];
  v10 = 0;
  if ( iOS_CMenuTouch::exec((iOS_CMenuTouch *)&gMenuTouchWorld, &v10, &v11, nullptr) == 7 && a1[10] != v11 )
  {
    a1[10] = v11;
    sound_request(3);
  }
  dword_12FB460 = 0;
  if ( (win_pac[13 * a1[14]] & 0x100) == 0 )
  {
    v2 = mouke_unitno[a1[10]] & 0x7FF;
    if ( a1[22] != v2 )
    {
      a1[22] = v2;
      mouketeam_unitface((int)a1, v2);
    }
  }
  if ( (pad_trg & 0x40) != 0 )
  {
    sound_request(2);
LABEL_11:
    iwapad_mask = 480;
    v3 = a1[2];
    anm_pac[9 * a1[3] + 5] = 0;
    anm_pac[9 * v3 + 5] = 0;
    win_pac[13 * a1[13]] |= 0x10u;
    win_pac[13 * a1[14]] |= 0x10u;
    anm_pac[9 * a1[15]] |= 0x10u;
    anm_pac[9 * a1[6]] |= 0x10u;
    a1[8] = 0;
    dword_12FB460 = 1;
    return iOS_setDispMenuTouch(0);
  }
  if ( (pad_trg & 0x20) != 0 )
  {
    sound_request(1);
    mouke_unitno[a1[10]] = scritem[word_12FB45C] & 0x7FF;
    mouketeam_unitwin(a1);
    mouketeam_scrollset(a1);
    rewrite_worldscroll(12);
    goto LABEL_11;
  }
  if ( wldkey_rep(0x1000u) )
  {
    v5 = a1[10];
    if ( v5 )
      v6 = v5 - 1;
    else
      v6 = 2;
    goto LABEL_20;
  }
  if ( wldkey_rep(0x4000u) )
  {
    v7 = a1[10];
    if ( v7 == 2 )
    {
      a1[10] = 0;
LABEL_21:
      sound_request(3);
      v8 = (char *)&anm_pac[9 * a1[6]];
      v9 = (char *)&win_pac[13 * a1[1]];
      *((_DWORD *)v8 + 6) = *((_DWORD *)v9 + 6) + 6;
      *((_DWORD *)v8 + 7) = *((_DWORD *)v9 + 7) + 12 + 16 * a1[10];
      goto LABEL_22;
    }
    v6 = v7 + 1;
LABEL_20:
    a1[10] = v6;
    goto LABEL_21;
  }
LABEL_22:
  if ( word_12C49CA )
    anm_pac[9 * a1[6] + 7] = 1000;
  else
    anm_pac[9 * a1[6] + 7] = win_pac[13 * a1[1] + 7] + 12 + 16 * a1[10];
  return iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)&gMenuTouchWorld, a1[10]);
}

