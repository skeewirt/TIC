// __Z20Wserchmessagepointeri @ 0x49F94 (80 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall Wserchmessagepointer(__int16 a1)
{
  bool v1; // zf
  int v3; // r1
  char *v4; // r0
  unsigned int v5; // r0

  v1 = (a1 & 0xF800) == 28672;
  v3 = (a1 & 0xF800) >> 11;
  v4 = *(char **)((char *)wmessagepacket + ((unsigned __int16)(a1 & 0xF800) >> 9));
  if ( v1 )
  {
    v5 = 2;
  }
  else
  {
    if ( v3 != 22 )
      return wasmSerchMessagePointer(v4, a1 & 0x7FF);
    v5 = 0;
  }
  v4 = (char *)pspMsgGet(v5);
  return wasmSerchMessagePointer(v4, a1 & 0x7FF);
}

