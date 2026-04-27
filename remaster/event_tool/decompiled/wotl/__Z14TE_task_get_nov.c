// __Z14TE_task_get_nov @ 0x1D1E90 (64 bytes)
// WotL iOS - debug symbols

int __fastcall TE_task_get_no()
{
  pthread_t v0; // r0
  _DWORD *v1; // r3
  pthread_t v2; // r1
  int result; // r0

  v0 = pthread_self();
  v1 = &gTaskFrame;
  v2 = v0;
  result = 0;
  while ( v2 != (pthread_t)v1[35] )
  {
    ++result;
    v1 += 36;
    if ( result == 17 )
      return -1;
  }
  return result;
}

