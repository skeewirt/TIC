// __Z14TE_task_createiPFvvEi @ 0x1D1DD8 (56 bytes)
// WotL iOS - debug symbols

_DWORD *__fastcall TE_task_create(int a1, void (__fastcall *a2)(), int a3)
{
  _DWORD *result; // r0

  result = (_DWORD *)((char *)&gTaskFrame + 144 * a1);
  result[30] = 1;
  result[33] = 1;
  result[1] = a2;
  result[34] = a3;
  gExecuteTaskType = a3;
  return result;
}

