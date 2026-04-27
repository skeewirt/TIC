// __Z29doMetaschedulePtclCommandOncetP10_EffectTCB @ 0x163B6C (584 bytes)
// WotL iOS - debug symbols

__int16 *__fastcall doMetaschedulePtclCommandOnce(__int16 *result, int a2)
{
  int v2; // r8
  char v3; // r10
  unsigned int v4; // r11
  int v5; // r5
  __int16 *v6; // r4
  int v7; // r5
  __int16 *v8; // r4
  int v9; // r5
  __int16 *v10; // r4
  int v11; // r5
  __int16 *v12; // r4
  int v14; // [sp+4h] [bp-20h]
  int v15; // [sp+8h] [bp-1Ch]

  v2 = (unsigned __int8)result & 8;
  v3 = (char)result;
  v4 = (unsigned __int16)((unsigned __int16)result & 0xFF00) >> 8;
  v14 = (unsigned __int8)result & 7;
  if ( ((unsigned __int8)result & 8) != 0 )
  {
    result = gEffectOrder;
    if ( word_12BBD80 )
      v15 = -1;
    else
      result = (__int16 *)(unsigned __int8)byte_12BBD82;
    if ( !word_12BBD80 )
      v15 = (int)result;
  }
  else
  {
    v15 = 0;
  }
  if ( (v3 & 0x10) != 0 )
  {
    if ( v2 )
    {
      if ( v15 != -1 )
        result = (__int16 *)requestDamageNumber(v15);
    }
    else
    {
      v5 = 0;
      v6 = gEffectOrder;
      while ( v5 < (unsigned __int16)gEffectOrder[0] )
      {
        if ( !v6[2] )
          result = (__int16 *)requestDamageNumber(*((unsigned __int8 *)v6 + 6));
        ++v5;
        v6 += 5;
      }
    }
  }
  if ( (v3 & 0x20) != 0 )
  {
    if ( v2 )
    {
      if ( v15 != -1 )
        result = (__int16 *)requestDamageResult(v15);
    }
    else
    {
      v7 = 0;
      v8 = gEffectOrder;
      while ( v7 < (unsigned __int16)gEffectOrder[0] )
      {
        if ( !v8[2] )
          result = (__int16 *)requestDamageResult(*((unsigned __int8 *)v8 + 6));
        ++v7;
        v8 += 5;
      }
    }
  }
  if ( (v3 & 0x40) != 0 )
  {
    if ( v2 )
    {
      if ( v15 != -1 )
        result = (__int16 *)requestTargetAnimation(v15);
    }
    else
    {
      v9 = 0;
      v10 = gEffectOrder;
      while ( v9 < (unsigned __int16)gEffectOrder[0] )
      {
        if ( !v10[2] )
          result = (__int16 *)requestTargetAnimation(*((unsigned __int8 *)v10 + 6));
        ++v9;
        v10 += 5;
      }
    }
  }
  if ( v4 )
  {
    if ( v2 )
    {
      if ( v15 != -1 )
        result = (__int16 *)requestAnimation(v15, v4);
    }
    else
    {
      v11 = 0;
      v12 = gEffectOrder;
      while ( v11 < (unsigned __int16)gEffectOrder[0] )
      {
        if ( !v12[2] )
          result = (__int16 *)requestAnimation(*((unsigned __int8 *)v12 + 6), v4);
        ++v11;
        v12 += 5;
      }
    }
  }
  if ( v14 )
  {
    *(_BYTE *)((unsigned __int16)(v14 - 1) + a2 + 34) = 1;
    result = (__int16 *)pEntryPlug[(unsigned __int16)(v14 - 1)];
    *(_DWORD *)(4 * (unsigned __int16)(v14 - 1) + a2 + 212) = result;
  }
  return result;
}

