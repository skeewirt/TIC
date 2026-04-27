// __Z10Wtask_waitl @ 0xA52C4 (40 bytes)
// WotL iOS - debug symbols

int __fastcall Wtask_wait(int result)
{
  int v1; // r4
  int v2; // r5

  v1 = 0;
  v2 = result;
  while ( v1 < v2 )
  {
    result = wasmTaskEntry();
    ++v1;
  }
  return result;
}

