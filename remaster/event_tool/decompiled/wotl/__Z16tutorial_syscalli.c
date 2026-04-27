// __Z16tutorial_syscalli @ 0x602A4 (72 bytes)
// WotL iOS - debug symbols

int *__fastcall tutorial_syscall(int *result)
{
  if ( tutorialstartf == 2 )
  {
    write_eventflag(86, (int)result);
    write_eventflag(41, 0xFFFF);
    asmTaskEntry();
    return write_eventflag(86, 0);
  }
  return result;
}

