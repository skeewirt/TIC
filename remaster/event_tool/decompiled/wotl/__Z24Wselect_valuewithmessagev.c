// __Z24Wselect_valuewithmessagev @ 0x82C7C (2372 bytes)
// WotL iOS - debug symbols, no obfuscation

void __fastcall __noreturn Wselect_valuewithmessage()
{
  int v0; // r6
  _DWORD *v1; // r10
  _DWORD *v2; // r8
  __int16 TPage; // r0
  _DWORD *v4; // r4
  __int16 v5; // r0
  int v6; // r3
  char *v7; // r0
  __int16 v8; // r3
  __int16 v9; // r2
  int v10; // r3
  int v11; // r8
  int v12; // r1
  int TouchSwype; // r0
  int v14; // r5
  int v15; // r0
  int v16; // r1
  int v17; // r3
  __int16 *v18; // r2
  int v19; // r3
  bool v20; // zf
  int v21; // r2
  int v22; // r12
  int v23; // r0
  int v24; // r1
  int v25; // r3
  bool v26; // cc
  int v27; // r1
  unsigned __int16 v28; // r0
  char *v29; // r0
  int v30; // r4
  int v31; // r8
  int v32; // r5
  _DWORD *v33; // r11
  _DWORD *v34; // r10
  int v35; // r1
  int v36; // r1
  int v37; // r1
  int v38; // r1
  __int16 *v39; // r2
  __int16 v40; // r3
  int v41; // [sp+24h] [bp-2F0h]
  __int16 *v42; // [sp+38h] [bp-2DCh]
  char *v43; // [sp+3Ch] [bp-2D8h]
  int v44; // [sp+40h] [bp-2D4h]
  int v45; // [sp+44h] [bp-2D0h]
  int v46; // [sp+48h] [bp-2CCh]
  int v47; // [sp+4Ch] [bp-2C8h]
  int v48; // [sp+50h] [bp-2C4h]
  int v49; // [sp+54h] [bp-2C0h]
  char *v50; // [sp+58h] [bp-2BCh]
  int v51; // [sp+5Ch] [bp-2B8h]
  int v52; // [sp+60h] [bp-2B4h]
  int v53; // [sp+64h] [bp-2B0h]
  int i; // [sp+68h] [bp-2ACh]
  _BYTE v55[112]; // [sp+6Ch] [bp-2A8h] BYREF
  __int16 v56; // [sp+DCh] [bp-238h]
  __int16 v57; // [sp+DEh] [bp-236h]
  __int16 v58; // [sp+F6h] [bp-21Eh]
  _BYTE v59[32]; // [sp+154h] [bp-1C0h] BYREF
  char v60[140]; // [sp+174h] [bp-1A0h] BYREF
  _DWORD v61[22]; // [sp+238h] [bp-DCh] BYREF
  _DWORD v62[22]; // [sp+290h] [bp-84h] BYREF
  _BYTE v63[8]; // [sp+2E8h] [bp-2Ch] BYREF
  int v64; // [sp+2F0h] [bp-24h] BYREF
  int v65; // [sp+2F4h] [bp-20h] BYREF
  __int16 v66; // [sp+2F8h] [bp-1Ch] BYREF
  __int16 _2FA[17]; // [sp+2FAh] [bp-1Ah] BYREF

  padptr = Wimport_localpad(0);
  v50 = (char *)wasmtaskframeptr + 1024 * wasmtasknumber;
  v0 = *(_DWORD *)v50;
  v42 = *(__int16 **)(*(_DWORD *)v50 + 48);
  v49 = Wgetvaluelength(v42[1]);
  v45 = **(unsigned __int16 **)(v0 + 52);
  v44 = (unsigned __int16)*v42;
  v41 = *v42;
  if ( (__int16)v45 >= v41 && v42[1] >= (__int16)v45 )
  {
    v44 = (unsigned __int16)v45;
    v41 = (__int16)v45;
  }
  v1 = v62;
  v2 = v61;
  Wmultiwindow_packetinit(v63, v0, v59);
  for ( i = 0; i != 2; ++i )
  {
    Winitpolyft4(&v62[11 * i]);
    SetSemiTrans(&v62[11 * i], 0);
    TPage = GetTPage(0, 0, 960, 256);
    *((_BYTE *)v1 + 17) = 0;
    *((_BYTE *)v1 + 16) = -72;
    *((_BYTE *)v1 + 24) = -72;
    *((_BYTE *)v1 + 33) = 0;
    *((_WORD *)v1 + 9) = 32124;
    *((_BYTE *)v1 + 32) = -88;
    *((_BYTE *)v1 + 40) = -88;
    *((_BYTE *)v1 + 25) = 16;
    *((_BYTE *)v1 + 41) = 16;
    *((_WORD *)v1 + 13) = TPage;
    v1 += 11;
    v4 = &v61[11 * i];
    Winitpolyft4(v4);
    SetSemiTrans(v4, 1);
    v5 = GetTPage(0, 2, 960, 256);
    *((_BYTE *)v2 + 17) = 0;
    *((_BYTE *)v2 + 33) = 0;
    *((_WORD *)v2 + 9) = 32188;
    *((_BYTE *)v2 + 32) = -72;
    *((_BYTE *)v2 + 40) = -72;
    *((_BYTE *)v2 + 16) = -56;
    *((_BYTE *)v2 + 24) = -56;
    *((_BYTE *)v2 + 25) = 16;
    *((_BYTE *)v2 + 41) = 16;
    *((_WORD *)v2 + 13) = v5;
    v2 += 11;
    v6 = i + 1;
  }
  v43 = (char *)Wextend_systemframe(*(__int16 *)(v0 + 4), *(__int16 *)(v0 + 6), v63, v6 - 1);
  dword_26C8F8 = *(__int16 *)(v0 + 4);
  v7 = (char *)Wserchmessagepointer(*(_WORD *)(v0 + 28));
  Wcount_words2(_2FA, &v66, v7);
  Wloadcdst(8, 9);
  Wstatuskanjiprint(*(__int16 *)(v0 + 28), (unsigned int)v43, (unsigned int)&wcdst);
  Wloadcdst((unsigned __int16)_2FA[0] + 8, 9);
  Wloadcdst(*(__int16 *)(v0 + 4) - 6 * v49 - 16, 9);
  Wstatusfigprint0(v41, v49, v43, &wcdst);
  PSX_LoadImage(v63, v43);
  xpLibGetOffset(&v65, &v64);
  v8 = *(_WORD *)(v0 + 8);
  if ( v65 == -128 )
    v9 = v8 - 82;
  else
    v9 = v8 + v65;
  v10 = (__int16)(*(_WORD *)(v0 + 10) + v64 + 8);
  iOS_CMenuTouchNum::init(
    (iOS_CMenuTouchNum *)v55,
    2,
    v9,
    v10,
    *(_WORD *)(v0 + 12) - 10,
    16,
    v42[1],
    *v42,
    v9 + (__int16)(*(_WORD *)(v0 + 12) - 10),
    v10 - 8);
  if ( v65 == -128 )
    iOS_CMenuTouchNum::setDispOffset((iOS_CMenuTouchNum *)v55, 96, -v64);
  iOS_setV2Icon(92, 1);
  v46 = 0;
  v47 = 1;
  v48 = 0;
  while ( 1 )
  {
    if ( wonoflag )
      **(_WORD **)(v0 + 52) = v44;
    Wtask_wait(1);
    if ( v47 == 1 )
    {
      Wdisposememory(v43);
      v47 = 0;
    }
    if ( wasmGetActiveF() || wallgrayf )
    {
      v11 = 0;
    }
    else
    {
      v64 = (__int16)v44;
      switch ( iOS_CMenuTouchNum::exec((iOS_CMenuTouchNum *)v55, &v64) )
      {
        case 1:
          v12 = 0x4000;
          goto LABEL_22;
        case 2:
          v48 = 1;
          goto LABEL_26;
        case 3:
          v11 = 0;
          v48 = 0;
          break;
        case 4:
          v12 = 0x2000;
LABEL_22:
          iOS_setV2Icon(87, v12);
          goto LABEL_26;
        case 5:
          if ( *((_DWORD *)v50 - 238) )
            goto LABEL_26;
          v11 = 1;
          v47 = 1;
          v44 = (unsigned __int16)v64;
          break;
        default:
LABEL_26:
          v11 = 0;
          break;
      }
      TouchSwype = iOS_getTouchSwype();
      if ( TouchSwype == -1 )
      {
        v48 = 1;
        goto LABEL_34;
      }
      if ( TouchSwype == 1 )
        goto LABEL_32;
    }
    if ( !v48 )
    {
LABEL_32:
      iOS_CMenuTouchNum::setAddNum((iOS_CMenuTouchNum *)v55, 1);
      v48 = 0;
      goto LABEL_35;
    }
LABEL_34:
    iOS_CMenuTouchNum::setAddNum((iOS_CMenuTouchNum *)v55, 10);
LABEL_35:
    if ( Wmultiwindow_break((unsigned int *)padptr) )
    {
      iOS_setV2Icon(92, 0);
      wasmTaskEntry();
      Wtask_killmyself();
    }
    v14 = *(_DWORD *)padptr;
    Wmultiwindow_keydown(v0);
    v15 = Wmultiwindow_keyright(v0, 0);
    if ( *(_DWORD *)padptr == v14 )
      v17 = v11;
    else
      v17 = v11 | 1;
    if ( v17 )
    {
      v18 = *(__int16 **)(v0 + 52);
      v19 = *v18;
      v20 = v19 == -1;
      if ( v19 == -1 )
        v16 = v45;
      else
        v19 = v44;
      if ( v20 )
      {
        *v18 = v16;
      }
      else
      {
        *v18 = v19;
        v19 = *(_DWORD *)(v0 + 48);
      }
      if ( !v20 )
        (*(void (__fastcall **)(int, int))(v19 + 8))(v15, v16);
    }
    if ( !*((_DWORD *)v50 - 238) )
    {
      v21 = *(_DWORD *)padptr;
      if ( ((v48 > 0) & (*(_DWORD *)padptr >> 13)) != 0 )
        --v48;
      if ( (v21 & 0x8000) != 0 && v48 < v49 - 1 )
        ++v48;
      if ( (v21 & 0x1000) != 0 )
      {
        v22 = (unsigned __int16)v42[1];
        v23 = decvaluetbl[v48];
        v24 = (__int16)v44;
        v25 = (__int16)v22 - v23;
        v26 = (__int16)v44 <= v25;
        if ( (__int16)v44 <= v25 )
          v24 = v44;
        else
          v22 = (unsigned __int16)v22;
        if ( (__int16)v44 <= v25 )
        {
          v25 = 1;
          v23 += v24;
        }
        else
        {
          v44 = v22;
        }
        if ( v26 )
          v23 = (unsigned __int16)v23;
        else
          v22 = 1;
        if ( v26 )
        {
          v44 = v23;
          v47 = v25;
        }
        else
        {
          v47 = v22;
        }
      }
      if ( (v21 & 0x4000) != 0 )
      {
        v27 = decvaluetbl[v48];
        v28 = *v42;
        if ( (__int16)v44 >= v27 + *v42 )
          v28 = v44 - v27;
        v44 = v28;
LABEL_72:
        v43 = (char *)Wextend_systemframe(*(__int16 *)(v0 + 4), *(__int16 *)(v0 + 6), v63, 1);
        dword_26C8F8 = *(__int16 *)(v0 + 4);
        v29 = (char *)Wserchmessagepointer(*(_WORD *)(v0 + 28));
        Wcount_words(_2FA, &v66, v29);
        Wloadcdst(8, 9);
        Wstatuskanjiprint(*(__int16 *)(v0 + 28), (unsigned int)v43, (unsigned int)&wcdst);
        Wloadcdst(6 * (unsigned __int16)_2FA[0] + 8, 9);
        Wloadcdst(*(__int16 *)(v0 + 4) - 6 * v49 - 16, 9);
        Wstatusfigprint0((__int16)v44, v49, v43, &wcdst);
        PSX_LoadImage(v63, v43);
        v47 = 1;
        goto LABEL_73;
      }
    }
    if ( v47 == 1 )
      goto LABEL_72;
LABEL_73:
    v30 = v46 & 1;
    v31 = 4 * v30;
    v32 = 16 * v30;
    v33 = &v61[11 * v30];
    v34 = &v62[11 * v30];
    multiwindow_packetanmflip(v0, v34, v33, v46, v48);
    if ( !wasmGetActiveF() && !wallgrayf && !wasmGetActiveF() )
    {
      v51 = v56 + 16;
      v52 = v57;
      v53 = v58;
      v35 = v51 * iOSPosW(340);
      iOSTgaIconSetX(6, v35 / 4096);
      v36 = v52 * iOSPosH(240);
      iOSTgaIconSetY(6, v36 / 4096);
      iOSTgaIconSetFlag(6, 1);
      v37 = v51 * iOSPosW(340);
      iOSTgaIconSetX(7, v37 / 4096);
      v38 = v53 * iOSPosH(240);
      iOSTgaIconSetY(7, v38 / 4096);
      iOSTgaIconSetFlag(7, 1);
    }
    Wmultiwindow_loadcolor(v34);
    Wmultiwindow_loadcolor(v33);
    if ( wasmGetActiveF() )
    {
      v39 = &_2FA[2 * (v32 - v31 - v30) + 1];
      v40 = 32252;
    }
    else
    {
      v39 = &_2FA[2 * (v32 - v31 - v30) + 1];
      v40 = 32124;
    }
    *(v39 - 45) = v40;
    *(v39 - 89) = v40 + 64;
    Wmultiwindow_packetanm(v0, v59, v46, -1);
    Wmultiwindow_packetcolor(v59);
    Waddlocalprim(v34);
    Waddlocalprim(v33);
    Waddlocalprim(v60);
    Waddlocalprim(v59);
    ++v46;
  }
}

