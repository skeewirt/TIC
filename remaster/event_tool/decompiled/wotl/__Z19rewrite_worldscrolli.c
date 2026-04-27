// __Z19rewrite_worldscrolli @ 0xA5DB0 (32 bytes)
// WotL iOS - debug symbols

char *__fastcall rewrite_worldscroll(int a1)
{
  char *result; // r0

  result = (char *)wasmtaskframeptr + 1024 * a1;
  *((_DWORD *)result + 24) = 1;
  return result;
}

