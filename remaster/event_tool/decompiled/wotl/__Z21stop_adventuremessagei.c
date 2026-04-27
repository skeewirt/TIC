// __Z21stop_adventuremessagei @ 0xA5B1C (32 bytes)
// WotL iOS - debug symbols, no obfuscation

char *__fastcall stop_adventuremessage(int a1)
{
  char *result; // r0

  result = (char *)wasmtaskframeptr + 1024 * a1;
  *((_DWORD *)result + 19) = 3;
  return result;
}

