// __Z11event_startv @ 0x5DC10 (72 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall event_start()
{
  int result; // r0

  TRACE_Dummy("event_start\n");
  directioninit();
  result = asmGetActiveTask(1);
  if ( !result )
  {
    recieve_scroll();
    result = event_init_light();
    cameraoperateflg = 0;
    linkf = 0;
  }
  return result;
}

