// __Z16asmGetActiveTaski @ 0x2F2E4 (28 bytes)
// WotL iOS - debug symbols

int __fastcall asmGetActiveTask(int a1)
{
  return *((_DWORD *)asmtaskframeptr + 256 * a1 + 18);
}

