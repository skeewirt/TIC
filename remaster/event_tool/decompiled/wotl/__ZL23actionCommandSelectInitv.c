// __ZL23actionCommandSelectInitv @ 0x144EC4 (184 bytes)
// WotL iOS - debug symbols

int __fastcall actionCommandSelectInit()
{
  int v0; // r0
  int v1; // r4
  int result; // r0
  int v3; // r2

  scrolling = 0;
  gStatusMode = 22;
  v0 = searchCurrentAnimation();
  v1 = v0;
  if ( *(_DWORD *)(v0 + 376) == 3 )
    ask_event(1, 1, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, *(_BYTE *)(v0 + 318) & 8);
  else
    ask_event(1, 0, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, *(_BYTE *)(v0 + 318) & 8);
  result = *(unsigned __int8 *)(v1 + 318);
  v3 = result & 8;
  if ( (result & 8) != 0 )
    v3 = 1;
  gCursorDisplay = v3;
  return result;
}

