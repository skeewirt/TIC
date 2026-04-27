// __Z21Wmakemessagestructurev @ 0x46494 (128 bytes)
// WotL iOS - debug symbols, no obfuscation

_UNKNOWN **__fastcall Wmakemessagestructure()
{
  _UNKNOWN **result; // r0
  int i; // r2

  TRACE_Dummy("%s %d\n", "Wmakemessagestructure", 5792);
  iOS_hook_common("Wmakemessagestructure", 5794);
  result = &messagebuffer;
  wmessagepacket[0] = (int)&messagebuffer + (_DWORD)messagebuffer + 128;
  for ( i = 1; i != 32; ++i )
    wmessagepacket[i] = (int)&messagebuffer + *(_DWORD *)((char *)&messagebuffer + i * 4) + 128;
  return result;
}

