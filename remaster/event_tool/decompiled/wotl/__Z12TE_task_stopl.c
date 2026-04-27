// __Z12TE_task_stopl @ 0x1D1E40 (72 bytes)
// WotL iOS - debug symbols

char *__fastcall TE_task_stop(int a1)
{
  char *result; // r0

  if ( !a1 )
  {
    TRACE_Dummy("TASK ERROR line %d\n", 642);
    while ( 1 )
      ;
  }
  result = (char *)&gTaskFrame + 144 * a1;
  *((_DWORD *)result + 30) = 0;
  return result;
}

