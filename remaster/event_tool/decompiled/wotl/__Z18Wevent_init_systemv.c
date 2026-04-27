// __Z18Wevent_init_systemv @ 0x47914 (44 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall Wevent_init_system()
{
  randomvalue = VSync(-1);
  Wallocatewindowinit();
  Wallocatetextureinit();
  Wallocatememoryinit();
  return Wtask_init();
}

