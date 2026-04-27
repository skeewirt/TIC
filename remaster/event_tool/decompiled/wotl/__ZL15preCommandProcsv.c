// __ZL15preCommandProcsv @ 0x148910 (164 bytes)
// WotL iOS - debug symbols

int __fastcall preCommandProcs()
{
  unsigned int *OTptrZ; // r0
  int result; // r0

  standerdExecution();
  OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
  menu_call(OTptrZ, padd);
  result = *(_DWORD *)return_actionstructure();
  if ( result >= 7 && (result <= 8 || result == 255) )
    gActionCode = 1;
  if ( !(dword_12B1728 | gMoveVector | dword_12B172C) && !turning )
  {
    if ( gActionCode )
      return initCommandMenuDisplay();
  }
  return result;
}

