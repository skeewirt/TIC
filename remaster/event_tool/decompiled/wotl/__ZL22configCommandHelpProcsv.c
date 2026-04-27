// __ZL22configCommandHelpProcsv @ 0x1488C0 (72 bytes)
// WotL iOS - debug symbols

int __fastcall configCommandHelpProcs()
{
  unsigned int *OTptrZ; // r0

  if ( recieve_statusinfo() != 2 )
  {
    gHelpMode = 0;
    configCommandInit();
  }
  standerdExecution();
  OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
  return menu_call(OTptrZ, padd);
}

