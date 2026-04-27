// __ZL11ListCommandv @ 0xD646C (648 bytes)
// WotL iOS - debug symbols

int __fastcall ListCommand()
{
  int v0; // r4
  int *Ot_equip; // r0
  int v3; // [sp+14h] [bp-20h] BYREF
  int v4; // [sp+18h] [bp-1Ch] BYREF
  int v5; // [sp+1Ch] [bp-18h] BYREF
  int v6; // [sp+20h] [bp-14h] BYREF

  v6 = 0;
  v5 = 0;
  v0 = ListCommand(void)::init;
  if ( !ListCommand(void)::init )
  {
    if ( !eLineTotal )
      return 0;
    word_2D8F6C = ListCommand(void)::init;
    dword_2D8F70 = 1;
    word_2D8FAC = ListCommand(void)::init;
    dword_2D8FB0 = 1;
    eHelpMessageNo = ListCommand(void)::init;
    equans_init();
    dword_2D9244 = v0;
    if ( word_1241912 == -1 )
    {
      ListCommand(void)::sort = v0;
      ListCommand(void)::p = (int)&list_commanddata2;
    }
    else
    {
      ListCommand(void)::sort = 1;
      ListCommand(void)::p = (int)&list_commanddata;
    }
    ListCommand(void)::init = 1;
    iOS_CMenuTouch::init((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, 3, 3, 0, 236, 90, 52, 16, v6);
    xpLibGetOffset(&v4, &v3);
    iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, -v4, -v3);
  }
  eHelpMessageNo = *(__int16 *)(ListCommand(void)::p + 56) + 4143;
  ListCommand(void)::init = eDrawMessage(3);
  if ( !ListCommand(void)::init )
    return 0;
  v6 = word_2D8F6C;
  if ( iOS_CMenuTouch::exec((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, &v5, &v6, nullptr) == 7
    && word_2D8F6C != v6 )
  {
    word_2D8F6C = v6;
  }
  if ( (ePadData & 0x20) != 0 )
  {
    if ( word_2D8F6C == 2 )
    {
      ListCommand(void)::init = 0;
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, 0);
      eDrawMessageKill(3);
      return 5;
    }
    eSysSnd = 5;
  }
  iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, word_2D8F6C);
  if ( !allgrayf )
  {
    Ot_equip = (int *)iOS_getOt_equip(50);
    iOS_CMenuTouch::drawMenuAssist((iOS_CMenuTouch *)&ListCommand(void)::menuTouchListCommand, word_2D8F6C, Ot_equip);
  }
  return 2;
}

