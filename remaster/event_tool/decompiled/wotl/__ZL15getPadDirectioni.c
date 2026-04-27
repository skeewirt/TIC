// __ZL15getPadDirectioni @ 0x142C40 (4536 bytes)
// WotL iOS - debug symbols

int __fastcall getPadDirection(int a1)
{
  int *v1; // r2
  int v2; // r5
  __int16 v3; // r0
  bool v4; // zf
  int v5; // r3
  int v6; // r4
  int v7; // r4
  int result; // r0

  if ( gCursorType < 0 )
    goto LABEL_63;
  if ( gCursorType > 1 )
  {
    if ( gCursorType == 2 )
    {
      if ( a1 != 1 )
      {
        if ( a1 == 2 )
        {
          LOWORD(v2) = untrg;
          goto LABEL_217;
        }
        if ( !a1 )
        {
          LOWORD(v2) = padold0 | pad;
          goto LABEL_217;
        }
        goto LABEL_63;
      }
      v3 = padold0 | pad;
      if ( (trg & 0x1000) != 0 )
      {
        if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x2000) == 0 )
        {
          if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x8000) == 0 )
          {
LABEL_54:
            LOWORD(v2) = 0;
            goto LABEL_58;
          }
LABEL_57:
          LOWORD(v2) = -28672;
          goto LABEL_58;
        }
LABEL_55:
        LOWORD(v2) = 12288;
        goto LABEL_58;
      }
      if ( (trg & 0x4000) != 0 )
      {
        if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x2000) == 0 )
        {
          v4 = (v3 & 0x8000) == 0;
LABEL_28:
          if ( v4 )
            goto LABEL_54;
          LOWORD(v2) = -16384;
LABEL_58:
          if ( gKeyRepeatCtr > 6 && gKeyRepeatCtr == 6 * (gKeyRepeatCtr / 6u) )
            LOWORD(v2) = padold0 | pad;
          goto LABEL_217;
        }
      }
      else
      {
        if ( (trg & 0x8000) != 0 )
        {
          if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x1000) != 0 )
            goto LABEL_57;
          v4 = (v3 & 0x4000) == 0;
          goto LABEL_28;
        }
        if ( (trg & 0x2000) == 0 )
        {
          if ( (trgold1 & 0x1000) != 0 )
          {
            if ( ((trg | trgold0) & 0x1000) != 0 || (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x1000) == 0 )
              goto LABEL_54;
            LOWORD(v2) = 4096;
          }
          else if ( (trgold1 & 0x4000) != 0 )
          {
            if ( ((trg | trgold0) & 0x4000) != 0 || (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x4000) == 0 )
              goto LABEL_54;
            LOWORD(v2) = 0x4000;
          }
          else if ( (trgold1 & 0x8000) != 0 )
          {
            if ( ((trg | trgold0) & 0x8000) != 0 || (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x8000) == 0 )
              goto LABEL_54;
            LOWORD(v2) = 0x8000;
          }
          else
          {
            if ( (trgold1 & 0x2000) == 0
              || ((trg | trgold0) & 0x2000) != 0
              || (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x2000) == 0 )
            {
              goto LABEL_54;
            }
            LOWORD(v2) = 0x2000;
          }
          goto LABEL_58;
        }
        if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x1000) != 0 )
          goto LABEL_55;
        if ( (((unsigned __int16)padold0 | (unsigned __int16)pad) & 0x4000) == 0 )
          goto LABEL_54;
      }
      LOWORD(v2) = 24576;
      goto LABEL_58;
    }
LABEL_63:
    LOWORD(v2) = 0;
    goto LABEL_64;
  }
  if ( a1 == 1 )
  {
    LOWORD(v2) = trg;
    if ( gKeyRepeatCtr <= 15
      || gKeyRepeatCtr != (((2863311531u * (unsigned __int64)(unsigned int)gKeyRepeatCtr) >> 32) & 0xFFFFFFFE)
                        + gKeyRepeatCtr / 3u )
    {
      goto LABEL_64;
    }
    v1 = &pad;
  }
  else if ( a1 == 2 )
  {
    v1 = &untrg;
  }
  else
  {
    if ( a1 )
      goto LABEL_63;
    v1 = &pad;
  }
  v2 = *v1;
LABEL_64:
  if ( gCursorType == 1 )
  {
    v6 = word_12B16DE & 0xC00;
    if ( v6 == 1024 )
    {
      if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
        goto LABEL_293;
      if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
        goto LABEL_299;
      if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
        goto LABEL_298;
      if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
        goto LABEL_297;
      if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
        goto LABEL_292;
      if ( (v2 & 0x4000) == 0 && siOS_TCurPosGet(4u, 0) != 2 )
      {
        if ( (v2 & 0x8000) == 0 && siOS_TCurPosGet(2u, 0) != 3 )
        {
          if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
            goto LABEL_291;
          goto LABEL_294;
        }
        goto LABEL_295;
      }
      goto LABEL_296;
    }
    if ( (word_12B16DE & 0xC00u) <= 0x400 )
    {
      if ( (word_12B16DE & 0xC00) != 0 )
        goto LABEL_291;
      if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, word_12B16DE & 0xC00) == 6 )
        goto LABEL_298;
      if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
        goto LABEL_293;
      if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
        goto LABEL_297;
      if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
        goto LABEL_299;
      if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
        goto LABEL_294;
      if ( (v2 & 0x4000) != 0 || siOS_TCurPosGet(4u, 0) == 2 )
        goto LABEL_295;
      if ( (v2 & 0x8000) != 0 || siOS_TCurPosGet(2u, 0) == 3 )
        goto LABEL_292;
      if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
        goto LABEL_291;
      goto LABEL_296;
    }
    if ( v6 == 2048 )
    {
      if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
        goto LABEL_299;
      if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
        goto LABEL_297;
      if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
        goto LABEL_293;
      if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
        goto LABEL_298;
      if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
        goto LABEL_295;
      if ( (v2 & 0x4000) != 0 || siOS_TCurPosGet(4u, 0) == 2 )
        goto LABEL_294;
      if ( (v2 & 0x8000) == 0 && siOS_TCurPosGet(2u, 0) != 3 )
      {
        if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
          goto LABEL_291;
        goto LABEL_292;
      }
      goto LABEL_296;
    }
    if ( v6 != 3072 )
      goto LABEL_291;
    if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
      goto LABEL_297;
    if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
      goto LABEL_298;
    if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
      goto LABEL_299;
    if ( (v2 & 0xC000) != 0xC000 && siOS_TCurPosGet(6u, 0) != 7 )
    {
      if ( (v2 & 0x1000) == 0 && siOS_TCurPosGet(8u, 0) != 1 )
      {
        if ( (v2 & 0x4000) == 0 && siOS_TCurPosGet(4u, 0) != 2 )
        {
          if ( (v2 & 0x8000) != 0 || siOS_TCurPosGet(2u, 0) == 3 )
            goto LABEL_294;
          if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
            goto LABEL_291;
          goto LABEL_295;
        }
        goto LABEL_292;
      }
      goto LABEL_296;
    }
    goto LABEL_293;
  }
  if ( gCursorType != 2 )
  {
    if ( gCursorType )
      goto LABEL_291;
    v5 = word_12B16DE & 0xC00;
    if ( v5 == 1024 )
    {
      if ( (v2 & 0x1000) != 0 || siOS_TCurSucCheck(9u) )
        goto LABEL_294;
      if ( (v2 & 0x4000) != 0 || siOS_TCurSucCheck(6u) )
        goto LABEL_295;
      if ( (v2 & 0x8000) != 0 || siOS_TCurSucCheck(0xAu) )
        goto LABEL_292;
      if ( (v2 & 0x2000) == 0 && !siOS_TCurSucCheck(5u) )
      {
        if ( (v2 & 0x3000) != 0x3000 && !siOS_TCurSucCheck(1u) )
        {
          if ( (v2 & 0x9000) == 0x9000 || siOS_TCurSucCheck(8u) )
            goto LABEL_293;
          if ( (v2 & 0x6000) != 0x6000 && !siOS_TCurSucCheck(4u) )
          {
            if ( (v2 & 0xC000) != 0xC000 && !siOS_TCurSucCheck(2u) )
              goto LABEL_291;
            goto LABEL_299;
          }
          goto LABEL_297;
        }
        goto LABEL_298;
      }
      goto LABEL_296;
    }
    if ( (word_12B16DE & 0xC00u) > 0x400 )
    {
      if ( v5 != 2048 )
      {
        if ( v5 == 3072 )
        {
          if ( (v2 & 0x1000) != 0 || siOS_TCurSucCheck(9u) )
            goto LABEL_295;
          if ( (v2 & 0x4000) != 0 || siOS_TCurSucCheck(6u) )
            goto LABEL_294;
          if ( (v2 & 0x8000) != 0 || siOS_TCurSucCheck(0xAu) )
            goto LABEL_296;
          if ( (v2 & 0x2000) != 0 || siOS_TCurSucCheck(5u) )
            goto LABEL_292;
          if ( (v2 & 0x3000) == 0x3000 || siOS_TCurSucCheck(1u) )
            goto LABEL_299;
          if ( (v2 & 0x9000) == 0x9000 || siOS_TCurSucCheck(8u) )
            goto LABEL_297;
          if ( (v2 & 0x6000) == 0x6000 || siOS_TCurSucCheck(4u) )
            goto LABEL_293;
          if ( (v2 & 0xC000) != 0xC000 && !siOS_TCurSucCheck(2u) )
            goto LABEL_291;
          goto LABEL_298;
        }
LABEL_291:
        result = -1;
        goto LABEL_300;
      }
      if ( (v2 & 0x1000) != 0 || siOS_TCurSucCheck(9u) )
        goto LABEL_292;
      if ( (v2 & 0x4000) != 0 || siOS_TCurSucCheck(6u) )
      {
LABEL_296:
        result = 2048;
        goto LABEL_300;
      }
      if ( (v2 & 0x8000) != 0 || siOS_TCurSucCheck(0xAu) )
        goto LABEL_295;
      if ( (v2 & 0x2000) != 0 || siOS_TCurSucCheck(5u) )
        goto LABEL_294;
      if ( (v2 & 0x3000) != 0x3000 && !siOS_TCurSucCheck(1u) )
      {
        if ( (v2 & 0x9000) == 0x9000 || siOS_TCurSucCheck(8u) )
          goto LABEL_299;
        if ( (v2 & 0x6000) != 0x6000 && !siOS_TCurSucCheck(4u) )
        {
          if ( (v2 & 0xC000) != 0xC000 && !siOS_TCurSucCheck(2u) )
            goto LABEL_291;
          goto LABEL_297;
        }
        goto LABEL_298;
      }
    }
    else
    {
      if ( (word_12B16DE & 0xC00) != 0 )
        goto LABEL_291;
      if ( (v2 & 0x1000) != 0 || siOS_TCurSucCheck(9u) )
        goto LABEL_296;
      if ( (v2 & 0x4000) != 0 || siOS_TCurSucCheck(6u) )
        goto LABEL_292;
      if ( (v2 & 0x8000) != 0 || siOS_TCurSucCheck(0xAu) )
        goto LABEL_294;
      if ( (v2 & 0x2000) != 0 || siOS_TCurSucCheck(5u) )
        goto LABEL_295;
      if ( (v2 & 0x3000) == 0x3000 || siOS_TCurSucCheck(1u) )
        goto LABEL_297;
      if ( (v2 & 0x9000) == 0x9000 || siOS_TCurSucCheck(8u) )
        goto LABEL_298;
      if ( (v2 & 0x6000) == 0x6000 || siOS_TCurSucCheck(4u) )
        goto LABEL_299;
      if ( (v2 & 0xC000) != 0xC000 && !siOS_TCurSucCheck(2u) )
        goto LABEL_291;
    }
LABEL_293:
    result = 512;
    goto LABEL_300;
  }
LABEL_217:
  v7 = word_12B16DE & 0xC00;
  if ( v7 == 1024 )
  {
    if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
      goto LABEL_294;
    if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
      goto LABEL_292;
    if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
      goto LABEL_296;
    if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
      goto LABEL_295;
    if ( (v2 & 0x1000) == 0 && siOS_TCurPosGet(8u, 0) != 1 )
    {
      if ( (v2 & 0x4000) != 0 || siOS_TCurPosGet(4u, 0) == 2 )
        goto LABEL_297;
      if ( (v2 & 0x8000) != 0 || siOS_TCurPosGet(2u, 0) == 3 )
        goto LABEL_299;
      if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
        goto LABEL_291;
      goto LABEL_298;
    }
    goto LABEL_293;
  }
  if ( (word_12B16DE & 0xC00u) > 0x400 )
  {
    if ( v7 != 2048 )
    {
      if ( v7 == 3072 )
      {
        if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
          goto LABEL_295;
        if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
          goto LABEL_296;
        if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
          goto LABEL_292;
        if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
          goto LABEL_294;
        if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
          goto LABEL_297;
        if ( (v2 & 0x4000) != 0 || siOS_TCurPosGet(4u, 0) == 2 )
          goto LABEL_293;
        if ( (v2 & 0x8000) == 0 && siOS_TCurPosGet(2u, 0) != 3 )
        {
          if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
            goto LABEL_291;
          goto LABEL_299;
        }
LABEL_298:
        result = 1536;
        goto LABEL_300;
      }
      goto LABEL_291;
    }
    if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, 0) == 6 )
      goto LABEL_292;
    if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
      goto LABEL_295;
    if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
      goto LABEL_294;
    if ( (v2 & 0xC000) != 0xC000 && siOS_TCurPosGet(6u, 0) != 7 )
    {
      if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
        goto LABEL_299;
      if ( (v2 & 0x4000) == 0 && siOS_TCurPosGet(4u, 0) != 2 )
      {
        if ( (v2 & 0x8000) == 0 && siOS_TCurPosGet(2u, 0) != 3 )
        {
          if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
            goto LABEL_291;
          goto LABEL_293;
        }
        goto LABEL_297;
      }
      goto LABEL_298;
    }
    goto LABEL_296;
  }
  if ( (word_12B16DE & 0xC00) != 0 )
    goto LABEL_291;
  if ( (v2 & 0x3000) == 0x3000 || siOS_TCurPosGet(9u, word_12B16DE & 0xC00) == 6 )
    goto LABEL_296;
  if ( (v2 & 0x9000) == 0x9000 || siOS_TCurPosGet(0xAu, 0) == 5 )
  {
LABEL_294:
    result = 1024;
    goto LABEL_300;
  }
  if ( (v2 & 0x6000) == 0x6000 || siOS_TCurPosGet(5u, 0) == 8 )
  {
LABEL_295:
    result = 3072;
    goto LABEL_300;
  }
  if ( (v2 & 0xC000) == 0xC000 || siOS_TCurPosGet(6u, 0) == 7 )
  {
LABEL_292:
    result = 0;
    goto LABEL_300;
  }
  if ( (v2 & 0x1000) != 0 || siOS_TCurPosGet(8u, 0) == 1 )
    goto LABEL_298;
  if ( (v2 & 0x4000) == 0 && siOS_TCurPosGet(4u, 0) != 2 )
  {
    if ( (v2 & 0x8000) != 0 || siOS_TCurPosGet(2u, 0) == 3 )
      goto LABEL_293;
    if ( (v2 & 0x2000) == 0 && siOS_TCurPosGet(1u, 0) != 4 )
      goto LABEL_291;
LABEL_297:
    result = 2560;
    goto LABEL_300;
  }
LABEL_299:
  result = 3584;
LABEL_300:
  if ( (trg & 0x9F0) != 0 )
    return -1;
  return result;
}

