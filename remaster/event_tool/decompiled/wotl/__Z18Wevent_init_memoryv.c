// __Z18Wevent_init_memoryv @ 0x47944 (172 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall Wevent_init_memory()
{
  wasmtaskframeptr = &asmtaskframe;
  wfontbufptr = iOS_GetFontBuffer();
  wwindowbufptr = (int)&windowbuffer;
  wevtptr = (int)&eventbuffer;
  wevtworkptr = eventwork;
  wcombase = (int)&comtest;
  whelpbase = -1;
  wanmloadf = 0;
  endf = 0;
  wloadf = 0;
  return TRACE_Dummy("anmloadf %d\n", 0);
}

