// __ZL8setbraveii @ 0x9B544 (152 bytes)
// WotL iOS - debug symbols

int *__fastcall setbrave(int *result, int a2)
{
  int *v2; // r5
  int v4; // r0
  const __int16 *v5; // r4
  int *v6; // r3
  bool v7; // zf

  v2 = result;
  if ( result == (int *)162 )
  {
    v4 = 1013;
    return write_eventflag(v4, a2);
  }
  if ( result == (int *)163 )
  {
    v4 = 1012;
    return write_eventflag(v4, a2);
  }
  v5 = warningcnvtbl2;
  do
  {
    v6 = (int *)*(unsigned __int16 *)v5;
    v7 = v6 == v2;
    if ( v6 != v2 )
      v7 = *((unsigned __int16 *)v5 + 1) == (_DWORD)v2;
    if ( v7 || (int *)*((unsigned __int16 *)v5 + 2) == v2 )
      result = write_eventflag(*((unsigned __int16 *)v5 + 3), a2);
    v5 += 4;
  }
  while ( v5 != windowdiv );
  return result;
}

