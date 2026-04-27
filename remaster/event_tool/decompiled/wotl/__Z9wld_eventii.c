// __Z9wld_eventii @ 0x194C00 (228 bytes)
// WotL iOS - debug symbols, no obfuscation

unsigned int __fastcall wld_event(int a1, int a2)
{
  unsigned __int16 v3; // r8
  int v4; // r1
  unsigned int result; // r0
  int v6; // r3

  v3 = 0;
  dword_12FB708 = event_buf + 2 * (*(unsigned __int16 *)(2 * a1 + event_buf) >> 1);
  while ( 1 )
  {
    v6 = 2 * v3;
    result = *(unsigned __int16 *)(v6 + dword_12FB708);
    if ( !*(_WORD *)(v6 + dword_12FB708) )
      break;
    dword_12FB70C = 2 * (result >> 1) + event_buf;
    word_12FB710 = 0;
    event_inf = 0;
    do
    {
      v4 = *(unsigned __int16 *)(2 * (unsigned __int16)word_12FB710++ + dword_12FB70C);
      EVT_func[v4]();
    }
    while ( (event_inf & 3) == 0 );
    if ( (event_inf & 1) != 0 && (event_inf & a2) != 0 )
      return 1;
    ++v3;
  }
  return result;
}

