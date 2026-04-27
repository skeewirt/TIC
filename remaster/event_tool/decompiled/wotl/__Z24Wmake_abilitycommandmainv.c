// __Z24Wmake_abilitycommandmainv @ 0x57604 (684 bytes)
// WotL iOS - debug symbols

int __fastcall Wmake_abilitycommandmain()
{
  int v0; // r10
  int bwp; // r0
  int i; // r2
  int j; // r4
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r3
  int v9; // r0
  int v10; // r4
  int v11; // lr
  int result; // r0
  _WORD *v13; // r2
  __int16 v14; // r3

  TRACE_Dummy("make_abilitycommandmain\n");
  lastchargetime = 0;
  wabilitycommand[0] = 0;
  direct = get_actwindow_data(
             word_271BAE,
             (unsigned __int8 *)wabilitycommand,
             (unsigned __int8 *)abilitycommandmask,
             abilitycommandtype);
  v0 = Wserchmessagepointer(20496);
  bwp = get_bwp(word_271BAE);
  if ( check_act_ok(bwp) == 2 )
  {
    for ( i = 0; i != 6; ++i )
    {
      abilitycommandmask[i] = 1;
      if ( abilitycommandtype[i] == 13 )
        abilitycommandmask[i] = 0;
    }
  }
  TRACE_Dummy(
    "    abilitycommand[%d]=0x%x;(mask:%d)\n",
    0,
    (unsigned __int8)wabilitycommand[0],
    (unsigned __int8)abilitycommandmask[0]);
  for ( j = 1; j != 6; ++j )
  {
    v4 = j;
    v5 = (unsigned __int8)wabilitycommand[j];
    v6 = (unsigned __int8)abilitycommandmask[j];
    TRACE_Dummy("    abilitycommand[%d]=0x%x;(mask:%d)\n", v4, v5, v6);
  }
  v7 = 5;
  *(_BYTE *)(v0 + 3) = -6;
  do
  {
    v8 = v0 + v7;
    v7 += 5;
    *(_BYTE *)(v8 + 3) = -6;
  }
  while ( v7 != 30 );
  v9 = v0;
  v10 = 0;
  v11 = direct;
  do
  {
    *(_BYTE *)(v9 + 3) = -6;
    if ( (unsigned __int8)wabilitycommand[v10] == 255 )
      break;
    if ( abilitycommandmask[v10] )
    {
      *(_BYTE *)(v9 + 1) = 4;
      nextblock4[v10] = 4099;
    }
    else
    {
      *(_BYTE *)(v9 + 1) = 0;
      nextblock4[v10] = 3;
    }
    wwordfield[v10] = v11 ? 45056 : (unsigned __int8)wabilitycommand[v10] + 45056;
    ++v10;
    v9 += 5;
  }
  while ( v10 != 6 );
  if ( Wread_eventflag(99) && v10 <= 5 )
  {
    *(_BYTE *)(5 * v10 + v0 + 1) = 0;
    nextblock4[v10] = 22;
    wabilitycommand[v10] = -68;
    wabilitycommand[v10 + 1] = -1;
    wwordfield[v10++] = 45244;
  }
  result = 5 * v10 + v0;
  *(_BYTE *)(result - 2) = -1;
  v13 = (_WORD *)(wcombase + 256);
  *(_WORD *)(wcombase + 286) = v10 - 1;
  v14 = 16 * (v10 + 1);
  v13[11] = v14;
  v13[7] = v14;
  v13[3] = v14;
  return result;
}

