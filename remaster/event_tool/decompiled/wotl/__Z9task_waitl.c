// __Z9task_waitl @ 0x1D0604 (40 bytes)
// WotL iOS - debug symbols

int __fastcall task_wait(int result)
{
  int v1; // r4
  int v2; // r5

  v1 = 0;
  v2 = result;
  while ( v1 < v2 )
  {
    result = asmTaskEntry();
    ++v1;
  }
  return result;
}

