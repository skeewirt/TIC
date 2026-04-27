// __Z11Wtask_startl @ 0xA5368 (44 bytes)
// WotL iOS - debug symbols

int __fastcall Wtask_start(int a1)
{
  *((_DWORD *)wasmtaskframeptr + 256 * a1 + 18) = 1;
  return TE_task_start(a1);
}

