// __Z17event_init_systemv @ 0x5F2D8 (44 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall event_init_system()
{
  randomvalue = VSync(-1);
  allocatewindowinit();
  allocatetextureinit();
  allocatememoryinit();
  return task_init();
}

