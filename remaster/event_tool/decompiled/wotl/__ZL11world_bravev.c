// __ZL11world_bravev @ 0xA5F7C (48 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn world_brave()
{
  bravef = 1;
  _pad_buf = 0;
  Wexport_localpad(&_pad_buf);
  Wtask_killmyself();
}

