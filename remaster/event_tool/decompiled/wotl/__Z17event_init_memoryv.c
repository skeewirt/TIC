// __Z17event_init_memoryv @ 0x59B50 (152 bytes)
// WotL iOS - debug symbols, no obfuscation

void __fastcall event_init_memory()
{
  asmtaskframeptr = &asmtaskframe;
  fontbufptr = (int)&fontbuffer;
  windowbufptr = (int)&windowbuffer;
  evtptr = (int)&eventbuffer;
  evtworkptr = eventwork;
  combase = (int)&comtest;
  helpbase = -1;
  anmloadf = 0;
  endf = 0;
  loadf = 0;
}

