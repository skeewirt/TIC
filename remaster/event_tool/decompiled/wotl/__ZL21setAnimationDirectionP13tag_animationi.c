// __ZL21setAnimationDirectionP13tag_animationi @ 0x140B98 (136 bytes)
// WotL iOS - debug symbols

int __fastcall setAnimationDirection(int result, int a2)
{
  if ( a2 == 1024 )
  {
    if ( *(_WORD *)(result + 112) == 1024 )
      return result;
    goto LABEL_13;
  }
  if ( a2 > 1024 )
  {
    if ( a2 == 2048 )
    {
      if ( *(_WORD *)(result + 112) != 2048 )
      {
LABEL_13:
        *(_WORD *)(result + 112) = a2;
        return requestDefaultAnimation();
      }
    }
    else if ( a2 == 3072 && *(_WORD *)(result + 112) != 3072 )
    {
      *(_WORD *)(result + 112) = 3072;
      return requestDefaultAnimation();
    }
  }
  else if ( !a2 && *(_WORD *)(result + 112) )
  {
    goto LABEL_13;
  }
  return result;
}

