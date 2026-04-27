// __ZL25tgdirection_hitdataadjustv @ 0x1119CC (440 bytes)
// WotL iOS - debug symbols

int __fastcall tgdirection_hitdataadjust()
{
  int result; // r0
  int v1; // r12
  int v2; // r1
  unsigned int v3; // r2
  unsigned __int8 v4; // r3
  int v5; // r3
  int v6; // r1
  int v7; // r3
  bool v8; // zf
  int v9; // r3
  bool v10; // zf

  result = target_bwp;
  v1 = *(unsigned __int8 *)(target_bwp + 79) - *(unsigned __int8 *)(caster_bwp + 79);
  v2 = *(unsigned __int8 *)(target_bwp + 80) - *(unsigned __int8 *)(caster_bwp + 80);
  v3 = (unsigned __int8)abs32(v1);
  v4 = abs32(v2);
  if ( v3 > v4 )
  {
    if ( v1 > 0 )
    {
      v5 = *(_BYTE *)(target_bwp + 81) & 0xF;
      if ( v5 == 1 )
      {
        v6 = 0;
        goto LABEL_35;
      }
      if ( v5 == 3 )
      {
        v6 = 2;
        goto LABEL_35;
      }
      goto LABEL_15;
    }
    if ( v1 )
    {
      v7 = *(_BYTE *)(target_bwp + 81) & 0xF;
      if ( v7 != 3 )
      {
        v8 = v7 == 1;
        goto LABEL_19;
      }
      goto LABEL_41;
    }
    goto LABEL_42;
  }
  if ( v3 < v4 )
  {
    if ( v2 > 0 )
    {
      v6 = *(_BYTE *)(target_bwp + 81) & 0xF;
      if ( (*(_BYTE *)(target_bwp + 81) & 0xF) == 0 || v6 == 2 )
      {
LABEL_35:
        byte_12422BD = v6;
        if ( !v6 )
          return result;
        goto LABEL_36;
      }
LABEL_15:
      v6 = 1;
      goto LABEL_35;
    }
    if ( v2 )
    {
      v9 = *(_BYTE *)(target_bwp + 81) & 0xF;
      if ( v9 != 2 )
      {
        v8 = v9 == 0;
LABEL_19:
        if ( !v8 )
          goto LABEL_42;
        goto LABEL_39;
      }
LABEL_41:
      byte_12422BD = 0;
      return result;
    }
LABEL_42:
    byte_12422BD = 1;
    byte_12422BC = 0;
    return result;
  }
  if ( v1 <= 0 )
  {
    if ( !v1 )
      goto LABEL_27;
    v10 = (*(_BYTE *)(target_bwp + 81) & 0xF) == 3;
  }
  else
  {
    v10 = (*(_BYTE *)(target_bwp + 81) & 0xF) == 1;
  }
  if ( v10 )
    goto LABEL_41;
LABEL_27:
  if ( v2 <= 0 )
  {
    if ( v2 && (*(_BYTE *)(target_bwp + 81) & 0xF) == 2 )
      goto LABEL_41;
  }
  else if ( (*(_BYTE *)(target_bwp + 81) & 0xF) == 0 )
  {
    goto LABEL_41;
  }
  if ( !(v2 | v1) )
  {
LABEL_39:
    v6 = 2;
    goto LABEL_40;
  }
  v6 = 1;
LABEL_40:
  byte_12422BD = v6;
LABEL_36:
  byte_12422BC = 0;
  if ( v6 == 2 )
  {
    byte_12422BA = 0;
    byte_12422BB = 0;
  }
  return result;
}

