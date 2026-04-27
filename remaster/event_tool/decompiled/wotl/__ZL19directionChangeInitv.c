// __ZL19directionChangeInitv @ 0x1480A0 (292 bytes)
// WotL iOS - debug symbols

int __fastcall directionChangeInit()
{
  int v0; // r0
  int v1; // r2
  int v2; // r4
  int v3; // r5
  int v4; // r6
  int v5; // r3
  int result; // r0

  scrolling = 0;
  v0 = searchCurrentAnimation();
  gStatusMode = 19;
  v1 = *(__int16 *)(v0 + 112);
  *(_WORD *)(v0 + 8) = 0;
  v2 = v0;
  oldDirection = v1;
  iOS_setDirectionTapDir(-1);
  v3 = (*(_WORD *)(v2 + 112) & 0xC00) >> 10;
  if ( *(_BYTE *)(v2 + 304) == 1 )
  {
    v4 = searchAnimationByID(*(unsigned __int8 *)(v2 + 305));
    if ( v4 )
    {
      setAnimationDirection(v2, *(__int16 *)(v4 + 112));
      v5 = *(_DWORD *)(v2 + 308);
      if ( v5 )
      {
        set_unitcoord(
          *(unsigned __int8 *)(v5 + 428),
          *(_BYTE *)(v2 + 124),
          *(_BYTE *)(v2 + 125),
          *(_BYTE *)(v2 + 126),
          *(__int16 *)(v4 + 112) / 1024);
        v3 = *(__int16 *)(v4 + 112) / 1024;
      }
    }
  }
  iOS_setDirectionTapDir(v3);
  iOS_setV2Icon(101, 0);
  iOS_setV2Icon(102, -1);
  result = iOS_setV2Icon(103, -1);
  if ( (*(_BYTE *)(v2 + 318) & 8) == 0 )
  {
    result = GetDirectionOfAutoUnit();
    *(_DWORD *)(v2 + 360) = result;
  }
  return result;
}

