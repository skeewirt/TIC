// __Z12wait_taskendl @ 0x1D05CC (52 bytes)
// WotL iOS - debug symbols

int __fastcall wait_taskend(int a1)
{
  int v1; // r5
  int result; // r0

  v1 = a1 << 10;
  do
    result = asmTaskEntry();
  while ( *(_DWORD *)((char *)asmtaskframeptr + v1 + 72) );
  return result;
}

