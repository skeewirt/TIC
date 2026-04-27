// __Z25doSchedulePtclCommandOncethP10_EffectTCB @ 0x16431C (280 bytes)
// WotL iOS - debug symbols

__int16 *__fastcall doSchedulePtclCommandOnce(__int16 a1, unsigned __int8 a2, int a3)
{
  char v4; // r5
  unsigned int v5; // r8
  int v6; // r6
  __int16 *result; // r0
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r2

  v4 = a1;
  v5 = (unsigned __int16)(a1 & 0xFF00) >> 8;
  v6 = a1 & 7;
  if ( (a1 & 8) == 0 )
  {
    result = &gEffectOrder[5 * a2 + 2];
    if ( !*result )
    {
      v8 = LOBYTE(gEffectOrder[5 * a2 + 3]);
      goto LABEL_8;
    }
LABEL_7:
    v8 = -1;
    goto LABEL_8;
  }
  result = gEffectOrder;
  if ( word_12BBD80 )
    goto LABEL_7;
  v8 = (unsigned __int8)byte_12BBD82;
LABEL_8:
  if ( (v4 & 0x10) != 0 && v8 != -1 )
    result = (__int16 *)requestDamageNumber(v8);
  if ( (v4 & 0x20) != 0 && v8 != -1 )
    result = (__int16 *)requestDamageResult(v8);
  if ( (v4 & 0x40) != 0 && v8 != -1 )
    result = (__int16 *)requestTargetAnimation(v8);
  if ( v5 && v8 != -1 )
    result = (__int16 *)requestAnimation(v8, v5);
  if ( v6 )
  {
    v9 = (unsigned __int16)(v6 - 1);
    *(_BYTE *)(v9 + a3 + 34) = 1;
    v10 = 4 * v9 + a3;
    result = (__int16 *)pEntryPlug[v9];
    *(_DWORD *)(v10 + 212) = result;
  }
  return result;
}

