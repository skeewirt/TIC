// __Z14ForAutoCommandv @ 0x1B8918 (888 bytes)
// WotL iOS - debug symbols

int __fastcall ForAutoCommand()
{
  int result; // r0
  int NearestUnit; // r5
  char *v2; // r2
  char v3; // r3
  int v4; // r1
  int v5; // r0
  char *v6; // r3
  char *v7; // r1
  char v8; // r2

  switch ( byte_1358BB2 )
  {
    case 12:
      NearestUnit = *(unsigned __int8 *)(dword_13589F4 + 477);
      if ( byte_1358BB3 )
      {
        switch ( byte_1357E6A )
        {
          case 0:
            goto LABEL_22;
          case 1:
            goto LABEL_24;
          case 2:
            goto LABEL_27;
          case 3:
            goto LABEL_32;
          default:
            goto LABEL_36;
        }
      }
      if ( !IsAlmostNullUnit(NearestUnit) && spd_back[16 * NearestUnit + 6196] )
        goto LABEL_21;
      *(_BYTE *)(dword_1358030 + 4) &= ~8u;
      v2 = (char *)&bwork + 486 * NearestUnit;
      v3 = v2[420];
      if ( (v3 & 0x40) != 0 )
      {
        if ( (v2[99] & 0x10) != 0 )
        {
          v5 = v3 & 0x1F;
          if ( (*((_BYTE *)&bwork + 486 * v5 + 99) & 0x10) != 0 )
            goto LABEL_21;
        }
        else
        {
          v5 = v3 & 0x1F;
        }
        goto LABEL_19;
      }
      v4 = 1;
      byte_1357E89 = 1;
      do
      {
        v6 = &spd_back[v4++];
        v6[3213] = 1;
      }
      while ( v4 != 21 );
      NearestUnit = GetNearestUnit(4);
      if ( NearestUnit == (unsigned __int8)byte_135802A )
      {
        v5 = 0;
        v7 = &byte_1242397;
        while ( (unsigned __int8)*v7 == 255 || !spd_back[16 * v5 + 6196] || (v7[98] & 0x10) == 0 )
        {
          ++v5;
          v7 += 486;
          if ( v5 == 21 )
            goto LABEL_21;
        }
LABEL_19:
        NearestUnit = v5;
      }
LABEL_21:
      *(_BYTE *)(dword_13589F4 + 477) = NearestUnit;
      SetDestUnit(NearestUnit);
      byte_1358029 = 0;
LABEL_22:
      result = MakeMapChantedAction();
      if ( result == -1 )
      {
        v8 = 0;
LABEL_38:
        byte_1357E6A = v8;
        return result;
      }
LABEL_24:
      result = SetMoveAreaForTarget();
      if ( result == -1 )
      {
        v8 = 1;
        goto LABEL_38;
      }
      byte_1358029 = 2;
      SetThresholdDoNothing();
      byte_1358029 = 0;
LABEL_27:
      result = ForChantedAction();
      if ( result == -1 )
      {
        v8 = 2;
        goto LABEL_38;
      }
      if ( result == 1 )
        return 1;
      byte_1358029 = 0;
      if ( SetBaseTargetGroup(3, NearestUnit) )
      {
LABEL_32:
        result = EvaluateAllUnitAction();
        if ( result == -1 )
        {
          v8 = 3;
          goto LABEL_38;
        }
        if ( SetMove() )
          return 1;
      }
      byte_1358029 = 1;
      if ( SetBaseTargetGroup(0, 0) )
      {
LABEL_36:
        result = EvaluateAllUnitAction();
        if ( result == -1 )
        {
          v8 = 4;
          goto LABEL_38;
        }
        if ( SetMove() )
          return 1;
      }
      byte_1358029 = 2;
      StayAtSafePanel();
      return 1;
    case 14:
      goto LABEL_41;
    case 16:
      if ( byte_1358BB3 )
        goto LABEL_48;
      if ( SetTargetNeedCure() )
      {
        byte_1358BB2 = 14;
LABEL_41:
        result = NakamaWoEnngoSeyoRoutine();
        if ( result != -1 )
        {
          if ( result == -2 )
          {
LABEL_50:
            result = DattoNoGotokuNigeyoRoutine();
            if ( result == -1 )
              return result;
          }
          return 1;
        }
      }
      else
      {
        SetDestUnit(*(unsigned __int8 *)(dword_13589F4 + 477));
LABEL_48:
        result = MainBattleRoutine();
        if ( result != -1 )
          return 1;
      }
      return result;
    case 17:
      goto LABEL_50;
    default:
      return 0;
  }
}

