// __Z18WmakemessagepacketPc @ 0x49F00 (92 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall Wmakemessagepacket(char *a1)
{
  int result; // r0
  int i; // r2

  result = iOS_hook_common("Wmakemessagepacket", 187);
  wmessagepacket[0] = (int)&a1[*(_DWORD *)a1 + 128];
  for ( i = 1; i != 32; ++i )
    wmessagepacket[i] = (int)&a1[*(_DWORD *)&a1[i * 4] + 128];
  return result;
}

