// __ZL11ListCommandv_0 @ 0xFAC08 (1908 bytes)
// WotL iOS - debug symbols

int __fastcall ListCommand()
{
  int v0; // r5
  int MesAdr; // r0
  int v2; // r4
  int v3; // r0
  int v4; // t1
  __int16 v5; // r2
  int v6; // t1
  bool v7; // zf
  __int16 v8; // r2
  int result; // r0
  int TotalItem; // r0
  int v11; // r1
  int v12; // r12
  __int16 *i; // r2
  int v14; // r10
  char v15; // r5
  char v16; // r2
  int v17; // r8
  int j; // r4
  int v19; // r4
  signed __int8 v20; // r2
  int v21; // r0
  int v22; // [sp+14h] [bp-24h] BYREF
  int v23; // [sp+18h] [bp-20h] BYREF
  __int16 v24; // [sp+1Ch] [bp-1Ch] BYREF
  __int16 v25; // [sp+1Eh] [bp-1Ah] BYREF

  v0 = init_h;
  if ( init_h )
    goto LABEL_23;
  pad_stop = 0;
  HelpMessageNo = 0;
  unitans_init();
  dword_2DCDB0 = v0;
  MesAdr = GetMesAdr(mesunit, 3, 2);
  v2 = MesAdr;
  if ( LineTotal )
  {
    v3 = ItemChg(UnitMesList[RefPos], v0);
    if ( v3 )
    {
      *(_BYTE *)(v2 + 1) = v0;
      list_block[0] = 1;
      word_2DB79A = v3;
      goto LABEL_8;
    }
    *(_BYTE *)(v2 + 1) = 4;
  }
  else
  {
    *(_BYTE *)(MesAdr + 1) = LineTotal + 4;
  }
  list_block[0] = 5330;
  do
LABEL_8:
    v4 = *(unsigned __int8 *)++v2;
  while ( v4 != 227 );
  if ( LineTotal )
  {
    if ( GetTotalEquipItem(UnitMesList[RefPos]) )
    {
      *(_BYTE *)(v2 + 1) = 0;
      v5 = 4;
      goto LABEL_15;
    }
    *(_BYTE *)(v2 + 1) = 4;
  }
  else
  {
    *(_BYTE *)(v2 + 1) = LineTotal + 4;
  }
  v5 = 5330;
LABEL_15:
  word_2DB792 = v5;
  do
    v6 = *(unsigned __int8 *)++v2;
  while ( v6 != 227 );
  v7 = UnitMesList[0] == -1;
  if ( UnitMesList[0] != -1 )
    v7 = word_1241F9E == -1;
  if ( v7 )
  {
    *(_BYTE *)(v2 + 1) = 4;
    v8 = 5330;
  }
  else
  {
    *(_BYTE *)(v2 + 1) = 0;
    v8 = -1;
  }
  word_2DB794 = v8;
  myrefleshflg = 1;
  init_h = 1;
  iOS_CMenuTouch::init((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, 3, 3, 0, 240, 90, 50, 16, 0);
  xpLibGetOffset(&v23, &v22);
  iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, -v23 - 44, -v22);
LABEL_23:
  result = DrawMessage(6, &list_commanddata);
  if ( result || (init_h = 0, word_1241F7E != -1) )
  {
    if ( list_block[word_2DB5C8] >= 4096 && (PadData & 0x20) != 0 )
      SysSnd = 5;
    if ( word_1241F7E == -1 )
    {
      if ( Wtask_status(5) )
        return 2;
      v19 = MenuSelSideWithSnd(5u, 7u, PadData, 6);
      if ( v19 == list_category )
        return 2;
      pad_stop = 1;
      SetWindowPosition(list_category, RefPos, RefLine, UnitMesList);
      list_category = v19;
      if ( (char)v19 == 4 )
        v20 = 7;
      else
        v20 = v19 + 1;
      GetItemList(CurChr, (char)v19 + 1, v20, UnitMesList, 0xB4u, 0);
      GetWindowPosition(list_category, &v25, &v24, UnitMesList);
      WindowInit2(UnitMesList, v25, v24, (unsigned __int8 *)dword_1200A18);
      SetWindowCount(10);
      v21 = LineTotal;
      if ( LineTotal )
        v21 = UnitMesList[RefPos];
      GetItemParameter(v21, &wstatusainfo, &wstatuscinfo2, 0);
      dword_2DCD20 = 1;
      dword_2DCDAC = 1;
      goto LABEL_68;
    }
    if ( !word_1241F7E )
    {
      dword_2DCDB0 = 1;
      if ( !Wtask_status(5) )
      {
        if ( !word_1241F82 )
        {
          ItemChg(UnitMesList[RefPos], -word_1241F80);
          TotalItem = GetTotalItem(UnitMesList[RefPos]);
          if ( !TotalItem )
          {
            v11 = RefPos;
            v12 = LineTotal;
            for ( i = &UnitMesList[RefPos + 1]; ; *(i - 2) = *(i - 1) )
            {
              ++i;
              if ( v12 <= TotalItem + v11 )
                break;
              ++TotalItem;
            }
            ScrollWindowInit(UnitMesList, v11, (unsigned __int8 *)dword_1200A18, ListList);
            SetWindowCount(10);
            RefleshItemUserSort(list_category);
            GetItemParameter(UnitMesList[RefPos], &wstatusainfo, &wstatuscinfo2, 0);
            dword_2DCDAC = 1;
          }
        }
        init_h = 0;
        unitans_init();
        dword_2DCDB0 = 0;
        word_2DB688 = 0;
      }
      return 2;
    }
    if ( word_1241F7E != 1 )
    {
      if ( !result )
        return 5;
      return 2;
    }
    dword_2DCDB0 = 1;
    v14 = UnitMesList[RefPos];
    v15 = init_h;
    if ( init_h != 1 )
    {
LABEL_47:
      if ( Wtask_status(5) )
        return 2;
      v17 = word_1241F82;
      if ( !word_1241F82 )
      {
        while ( v17 < (unsigned __int8)TotalChr )
        {
          for ( j = 0; j != 5; ++j )
          {
            if ( *(unsigned __int16 *)(2 * j + ChrList[v17] + 84) == v14 )
              ItemEquip(v17, j, 0);
          }
          ++v17;
        }
      }
      wsound_mask = 0;
      unitans_init();
      dword_2DCDB0 = 0;
      word_2DB708 = 0;
LABEL_68:
      init_h = 0;
      return 2;
    }
    wsound_mask = 1;
    TRACE_Dummy("unitans[%d]:%d\n", 5, word_1241F82);
    if ( word_1241F82 )
    {
      v16 = word_1241F82;
      if ( word_1241F82 != 1 )
      {
        if ( !SysSnd )
        {
LABEL_46:
          init_h = v15;
          goto LABEL_47;
        }
LABEL_45:
        v15 = 100;
        goto LABEL_46;
      }
    }
    else
    {
      v16 = 7;
    }
    SysSnd = v16;
    goto LABEL_45;
  }
  return result;
}

