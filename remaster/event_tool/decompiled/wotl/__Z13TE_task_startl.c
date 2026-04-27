// __Z13TE_task_startl @ 0x1D1E18 (36 bytes)
// WotL iOS - debug symbols

char *__fastcall TE_task_start(int a1)
{
  char *result; // r0

  result = (char *)&gTaskFrame + 144 * a1;
  *((_DWORD *)result + 30) = 1;
  return result;
}

