// __Z13Wwait_taskendl @ 0xA528C (52 bytes)
// WotL iOS - debug symbols

int __fastcall Wwait_taskend(int a1)
{
  int v1; // r5
  int result; // r0

  v1 = a1 << 10;
  do
    result = wasmTaskEntry();
  while ( *(_DWORD *)((char *)wasmtaskframeptr + v1 + 72) );
  return result;
}

