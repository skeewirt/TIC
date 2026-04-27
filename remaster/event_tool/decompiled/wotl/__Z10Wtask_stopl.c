// __Z10Wtask_stopl @ 0xA5338 (44 bytes)
// WotL iOS - debug symbols

int __fastcall Wtask_stop(int a1)
{
  *((_DWORD *)wasmtaskframeptr + 256 * a1 + 18) = 0;
  return TE_task_stop(a1);
}

