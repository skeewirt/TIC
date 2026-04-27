// __Z18TE_task_killmyselfv @ 0x1D2134 (92 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn TE_task_killmyself()
{
  int no; // r0
  char *v1; // r3

  no = TE_task_get_no();
  if ( !no )
  {
    TRACE_Dummy("TASK ERROR line %d\n", 678);
    while ( 1 )
      ;
  }
  v1 = (char *)&gTaskFrame + 144 * no;
  *((_DWORD *)v1 + 30) = 0;
  *((_DWORD *)v1 + 1) = 0;
  longjmp((int *)&gTaskFrame + 36 * no + 2, 1);
}

