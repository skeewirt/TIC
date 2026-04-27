// __Z18Wmake_statusscrollv @ 0x5643C (452 bytes)
// WotL iOS - debug symbols

int __fastcall Wmake_statusscroll()
{
  int v0; // r2
  int v1; // r0
  int v2; // r12
  __int16 v3; // r1
  int bwp; // r0
  int i; // r3
  unsigned int j; // r12
  int v7; // r1
  __int16 v8; // lr
  int v10; // r5
  unsigned int v11; // r4
  int v12; // r9

  TRACE_Dummy("make_statusscroll\n");
  v0 = 0;
  v1 = (unsigned __int16)word_2740A6;
  v2 = (unsigned __int16)word_273EF0;
  do
  {
    if ( v1 || v2 == 1 )
      v3 = 2000;
    else
      v3 = 4117;
    *(_WORD *)((char *)&nextblock8 + v0) = v3;
    v0 += 2;
  }
  while ( v0 != 16 );
  bwp = get_bwp(word_271BAE);
  item3[0] = 28672;
  item4[0] = 28672;
  scrollcolor[0] = 0;
  for ( i = 1; i != 20; ++i )
  {
    item3[i] = 28672;
    item4[i] = 28672;
    scrollcolor[i] = 0;
  }
  v10 = bwp;
  v11 = 0;
  LOWORD(bwp) = -30720;
  do
  {
    v12 = *(unsigned __int8 *)(v10 + 97);
    v8 = bwp;
    LOWORD(v7) = 0;
    for ( j = 128; ; j >>= 1 )
    {
      if ( (j & v12) != 0 )
      {
        item3[v11] = v8;
        v11 = (unsigned __int16)(v11 + 1);
      }
      v7 = (unsigned __int16)(v7 + 1);
      ++v8;
      if ( v7 == 8 )
        break;
    }
    ++v10;
    bwp = (unsigned __int16)(bwp + 8);
  }
  while ( bwp != 34856 );
  TRACE_Dummy("ix:%d\n", 8);
  wsoundf = 1;
  if ( !v11 )
    Whook_jobmenu();
  if ( v11 <= 7 )
  {
    tes2 = v11;
    word_272CDA = 0;
  }
  else
  {
    tes2 = 7;
    word_272CDA = v11 - 7;
  }
  return Wdisp_scrollwindow();
}

