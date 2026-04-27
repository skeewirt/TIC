// __ZL15waitjoinmessagev @ 0x991A4 (152 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall waitjoinmessage()
{
  while ( *((_DWORD *)asmtaskframeptr + 1298) && record2 != -1 && record2 != 1 && record2 )
    asmTaskEntry();
  asmTaskEntry();
  *((_DWORD *)asmtaskframeptr + 1811) = 3;
  send_taskparamater(7, 0, 0, 2);
  wait_taskend(7);
  return wait_taskend(5);
}

