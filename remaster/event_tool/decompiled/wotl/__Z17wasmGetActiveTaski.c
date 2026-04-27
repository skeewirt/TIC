// __Z17wasmGetActiveTaski @ 0x2F65C (28 bytes)
// WotL iOS - debug symbols

int __fastcall wasmGetActiveTask(int a1)
{
  return *((_DWORD *)wasmtaskframeptr + 256 * a1 + 18);
}

