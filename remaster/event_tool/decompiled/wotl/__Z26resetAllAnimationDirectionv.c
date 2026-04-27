// __Z26resetAllAnimationDirectionv @ 0x1555D8 (96 bytes)
// WotL iOS - debug symbols

void __fastcall resetAllAnimationDirection()
{
  int i; // r1
  __int16 v1; // r3

  for ( i = gStartAnimation; i; i = *(_DWORD *)i )
  {
    if ( (*(_WORD *)(i + 112) & 0xFFFu) < 0x200 )
      goto LABEL_9;
    if ( (*(_WORD *)(i + 112) & 0xFFFu) < 0x600 )
    {
      v1 = 1024;
      goto LABEL_10;
    }
    if ( (*(_WORD *)(i + 112) & 0xFFFu) < 0xA00 )
    {
      v1 = 2048;
      goto LABEL_10;
    }
    if ( (*(_WORD *)(i + 112) & 0xFFFu) >= 0xE00 )
LABEL_9:
      v1 = 0;
    else
      v1 = 3072;
LABEL_10:
    *(_WORD *)(i + 112) = v1;
  }
}

