// __Z23make_abilitycommandmainv @ 0x66E84 (676 bytes)
// WotL iOS - debug symbols

int __fastcall make_abilitycommandmain()
{
  int v0; // r10
  int bwp; // r0
  int i; // r0
  int j; // r4
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r3
  int v9; // r0
  int k; // r4
  int result; // r0
  _WORD *v12; // r2
  __int16 v13; // r3

  TRACE_Dummy("make_abilitycommandmain\n");
  lastchargetime = 0;
  abilitycommand[0] = 0;
  direct = get_actwindow_data(
             word_27B28E,
             (unsigned __int8 *)abilitycommand,
             (unsigned __int8 *)abilitycommandmask,
             abilitycommandtype);
  v0 = serchmessagepointer(20496);
  bwp = get_bwp(word_27B28E);
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
    (unsigned __int8)abilitycommand[0],
    (unsigned __int8)abilitycommandmask[0]);
  for ( j = 1; j != 6; ++j )
  {
    v4 = j;
    v5 = (unsigned __int8)abilitycommand[j];
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
  for ( k = 0; k != 6; ++k )
  {
    *(_BYTE *)(v9 + 3) = -6;
    if ( (unsigned __int8)abilitycommand[k] == 255 )
      break;
    if ( abilitycommandmask[k] )
    {
      *(_BYTE *)(v9 + 1) = 4;
      nextblock4[k] = 4099;
    }
    else
    {
      *(_BYTE *)(v9 + 1) = 0;
      nextblock4[k] = 3;
    }
    wordfield[k] = direct ? 45056 : (unsigned __int8)abilitycommand[k] + 45056;
    v9 += 5;
  }
  if ( read_eventflag(99) && k <= 5 )
  {
    *(_BYTE *)(5 * k + v0 + 1) = 0;
    nextblock4[k] = 22;
    abilitycommand[k] = -68;
    abilitycommand[k + 1] = -1;
    wordfield[k++] = 45244;
  }
  result = 5 * k + v0;
  *(_BYTE *)(result - 2) = -1;
  v12 = (_WORD *)(combase + 256);
  *(_WORD *)(combase + 286) = k - 1;
  v13 = 16 * (k + 1);
  v12[11] = v13;
  v12[7] = v13;
  v12[3] = v13;
  return result;
}

