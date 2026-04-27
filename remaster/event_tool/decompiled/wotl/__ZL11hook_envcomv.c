// __ZL11hook_envcomv @ 0x51120 (104 bytes)
// WotL iOS - debug symbols

int __fastcall hook_envcom()
{
  int v0; // r4

  *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber + 19) = 66;
  while ( 1 )
  {
    if ( !checkScrolling() )
    {
      v0 = (unsigned __int16)waddactiveturn;
      if ( !waddactiveturn )
        break;
    }
    wasmTaskEntry();
  }
  Wtutorial_syscall((int *)0xFE);
  wstatusmaskf = v0;
  return Wdisp_selectwindow();
}

