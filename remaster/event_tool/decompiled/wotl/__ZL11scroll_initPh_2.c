// __ZL11scroll_initPh_2 @ 0x10D390 (880 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall scroll_init(unsigned __int8 *result)
{
  int v1; // r3
  bool v2; // zf
  int v3; // r4
  int v4; // r0
  __int16 v5; // r3
  __int16 v6; // r2
  int v7; // r12
  int v8; // r0
  int i; // r1
  int v10; // r2
  _BYTE v11[40]; // [sp+4h] [bp-3Ch] BYREF
  __int16 v12; // [sp+2Ch] [bp-14h] BYREF
  __int16 v13; // [sp+2Eh] [bp-12h]
  __int16 v14; // [sp+30h] [bp-10h]
  __int16 v15; // [sp+32h] [bp-Eh]
  _WORD vars0[10]; // [sp+34h] [bp-Ch] BYREF

  while ( 1 )
  {
    v1 = *result;
    v2 = v1 == 16;
    if ( v1 != 16 )
      v2 = v1 == 30;
    if ( v2 )
      break;
    if ( v1 == 33 )
      return result;
    result += result[1];
  }
  RetuTotal = result[4];
  Space = result[5];
  v3 = result[6];
  MaxLine = result[6];
  moji_space = result[9];
  v4 = result[10];
  moji_total = v4;
  length = ((unsigned __int8)moji_space * v4) >> 2;
  result = (unsigned __int8 *)&RefLine;
  if ( RefPos >= LineTotal )
    RefPos = LineTotal - 1;
  if ( RefPos - RefLine >= v3 || RefPos < RefLine )
    RefLine = RefPos;
  if ( (__int16)v3 <= LineTotal )
  {
    if ( (__int16)v3 > LineTotal - RefLine )
      RefLine = LineTotal - v3;
  }
  else
  {
    RefLine = 0;
  }
  if ( LineTotal <= RefPos )
    RefPos = LineTotal - 1;
  v5 = RefPos;
  if ( RefPos < 0 )
  {
    result = (unsigned __int8 *)TRACE_Dummy(
                                  "%s:%d RefPos:%d->0\n",
                                  "/Users/share/Desktop/title/veron/FFT_iOS/Classes/fftpsp/src/ku/unitlist/ios_window_unitlist.cpp",
                                  1284,
                                  RefPos);
    RefPos = 0;
    v5 = 0;
  }
  v6 = LineTotal;
  if ( v5 >= LineTotal )
  {
    result = (unsigned __int8 *)TRACE_Dummy(
                                  "%s:%d RefPos:%d->%d\n",
                                  "/Users/share/Desktop/title/veron/FFT_iOS/Classes/fftpsp/src/ku/unitlist/ios_window_unitlist.cpp",
                                  1288,
                                  v5,
                                  LineTotal - 1);
    v6 = LineTotal;
    RefPos = LineTotal - 1;
  }
  if ( RefLine < 0 )
  {
    result = (unsigned __int8 *)TRACE_Dummy(
                                  "%s:%d RefLine:%d->0\n",
                                  "/Users/share/Desktop/title/veron/FFT_iOS/Classes/fftpsp/src/ku/unitlist/ios_window_unitlist.cpp",
                                  1292,
                                  RefLine);
    v6 = LineTotal;
    RefLine = 0;
  }
  if ( v6 >= MaxLine && RefLine > v6 - MaxLine )
  {
    result = (unsigned __int8 *)TRACE_Dummy(
                                  "%s:%d RefLine:%d->0\n",
                                  "/Users/share/Desktop/title/veron/FFT_iOS/Classes/fftpsp/src/ku/unitlist/ios_window_unitlist.cpp",
                                  1298,
                                  RefLine);
    RefLine = LineTotal - MaxLine;
  }
  if ( pmes )
  {
    v13 = 304;
    v12 = 576;
    v14 = length;
    v15 = 16 * MaxLine;
    ClearImage(&v12, 0, 0, 0);
    v7 = MaxLine;
    v8 = 0;
    for ( i = 2 * RefLine + mes; ; *(_WORD *)&v11[v10] = *(_WORD *)(i - 2) )
    {
      i += 2;
      if ( v8 >= v7 )
        break;
      v10 = 2 * v8++;
    }
    vars0[v8 - 24] = -1;
    v13 = 304;
    v12 = 576;
    v14 = length;
    v15 = Space;
    result = (unsigned __int8 *)MakeTextureMessage(pmes, v11, &v12, 0);
  }
  scroll_type = 0;
  WinFlag = 0;
  return result;
}

