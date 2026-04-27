// __Z19get_command_abilityii @ 0x12105C (340 bytes)
// WotL iOS - debug symbols

int __fastcall get_command_ability(int a1, int a2)
{
  unsigned __int8 *v2; // lr
  int v3; // r0
  int v4; // r12
  bool v6; // cc
  int v7; // r12

  if ( a1 > 175 )
  {
    if ( a1 > 223 )
    {
      v6 = a1 <= 226;
      if ( a1 <= 226 )
        v6 = a2 <= 21;
      if ( v6 )
      {
        a1 -= 224;
        v2 = (unsigned __int8 *)&command_abilityA2;
        goto LABEL_14;
      }
    }
    else if ( a2 <= 3 )
    {
      v3 = 5 * (a1 - 176);
      v4 = *((unsigned __int8 *)&command_abilityB + v3 + a2 + 1);
      if ( v4 == 225 )
        return (unsigned __int16)(((*((unsigned __int8 *)&command_abilityB + v3 + a2 / 8) << (a2 % 8 + 1)) & 0x100) + 225);
      else
        return ((*((unsigned __int8 *)&command_abilityB + v3 + a2 / 8) << (a2 % 8 + 1)) & 0x100) + v4;
    }
    return 0;
  }
  if ( a2 > 21 )
    return 0;
  v2 = (unsigned __int8 *)&command_abilityA;
LABEL_14:
  if ( a2 >= 0 )
    v7 = a2;
  else
    v7 = a2 + 7;
  return ((v2[25 * a1 + (v7 >> 3)] << (a2 % 8 + 1)) & 0x100) + v2[25 * a1 + 3 + a2];
}

