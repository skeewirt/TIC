// __Z10task_startl @ 0x1D06A8 (44 bytes)
// WotL iOS - debug symbols

int __fastcall task_start(int a1)
{
  *((_DWORD *)asmtaskframeptr + 256 * a1 + 18) = 1;
  return TE_task_start(a1);
}

