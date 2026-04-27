// __ZL18configCommandProcsv @ 0x148C74 (276 bytes)
// WotL iOS - debug symbols

int __fastcall configCommandProcs()
{
  int v0; // r0
  int v1; // r4
  unsigned int *OTptrZ; // r0

  v0 = recieve_statusinfo();
  v1 = v0;
  if ( (trg & 0x100) != 0 )
  {
    scrolling = 0;
    gStatusMode = 9;
    gHelpMode = 1;
    request_help();
    goto LABEL_12;
  }
  if ( !v0 )
  {
    gCursorType = 0;
    TRACE_Dummy("iOS_gSelectWindowRecord %d\n", iOS_gSelectWindowRecord);
    iOS_setV2Icon(71, v1);
    if ( iOS_gSelectWindowRecord == 1 )
    {
      iOS_setV2Icon(59, 1);
    }
    else
    {
      if ( iOS_gSelectWindowRecord != 2 )
      {
LABEL_9:
        freeCursorInit();
        goto LABEL_12;
      }
      iOS_setV2Icon(56, 1);
    }
    iOS_setV2Icon(71, 1);
    goto LABEL_9;
  }
  if ( v0 > 99 )
    activeTurnInit(v0 - 100);
LABEL_12:
  standerdExecution();
  OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
  return menu_call(OTptrZ, padd);
}

