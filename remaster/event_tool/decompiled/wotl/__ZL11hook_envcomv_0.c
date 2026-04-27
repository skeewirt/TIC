// __ZL11hook_envcomv_0 @ 0x75A58 (104 bytes)
// WotL iOS - debug symbols

int __fastcall hook_envcom()
{
  int v0; // r4

  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) = 66;
  while ( 1 )
  {
    if ( !checkScrolling() )
    {
      v0 = (unsigned __int16)addactiveturn;
      if ( !addactiveturn )
        break;
    }
    asmTaskEntry();
  }
  tutorial_syscall((int *)0xFE);
  statusmaskf = v0;
  return disp_selectwindow();
}

