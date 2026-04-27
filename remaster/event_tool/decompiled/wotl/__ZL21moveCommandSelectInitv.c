// __ZL21moveCommandSelectInitv @ 0x144FF0 (92 bytes)
// WotL iOS - debug symbols

int __fastcall moveCommandSelectInit()
{
  int v0; // r0

  scrolling = 0;
  gStatusMode = 12;
  v0 = searchCurrentAnimation();
  return ask_event(1, 0, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, *(_BYTE *)(v0 + 318) & 8);
}

