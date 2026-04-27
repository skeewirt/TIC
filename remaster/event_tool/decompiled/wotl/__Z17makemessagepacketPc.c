// __Z17makemessagepacketPc @ 0x658A0 (92 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall makemessagepacket(char *a1)
{
  int result; // r0
  int i; // r2

  result = iOS_hook_common("makemessagepacket", 187);
  messagepacket[0] = (int)&a1[*(_DWORD *)a1 + 128];
  for ( i = 1; i != 32; ++i )
    messagepacket[i] = (int)&a1[*(_DWORD *)&a1[i * 4] + 128];
  return result;
}

