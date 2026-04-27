// __Z17tutorial_hookfuncv @ 0x5D0E0 (152 bytes)
// WotL iOS - debug symbols

void __fastcall tutorial_hookfunc()
{
  int v0; // r3

  if ( tutorialstartf == 2 && asmtasknumber )
  {
    if ( !pad )
      pad_org = 0;
    if ( *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) != 1 )
    {
      v0 = pad_org;
      goto LABEL_10;
    }
    pad = pad_tutorial;
    if ( iOS_getV2Icon(153) )
    {
      v0 = 0;
LABEL_10:
      pad = v0;
    }
  }
}

