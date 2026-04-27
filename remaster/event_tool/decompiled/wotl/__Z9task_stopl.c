// __Z9task_stopl @ 0x1D0678 (44 bytes)
// WotL iOS - debug symbols

char *__fastcall task_stop(int a1)
{
  *((_DWORD *)asmtaskframeptr + 256 * a1 + 18) = 0;
  return TE_task_stop(a1);
}

