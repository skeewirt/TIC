// __Z17Wtutorial_syscalli @ 0x485B8 (72 bytes)
// WotL iOS - debug symbols

int *__fastcall Wtutorial_syscall(int *result)
{
  if ( wtutorialstartf == 2 )
  {
    Wwrite_eventflag(86, (int)result);
    Wwrite_eventflag(41, 0xFFFF);
    wasmTaskEntry();
    return Wwrite_eventflag(86, 0);
  }
  return result;
}

