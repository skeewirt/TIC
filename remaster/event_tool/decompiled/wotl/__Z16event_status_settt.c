// __Z16event_status_settt @ 0x62F80 (416 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall event_status_set(int result, unsigned __int16 a2)
{
  int v2; // r6
  int v3; // r4
  int v4; // r4
  int bwp; // r0
  unsigned __int16 v6[2]; // [sp+8h] [bp-1Ch] BYREF
  int v7; // [sp+Ch] [bp-18h] BYREF
  unsigned __int16 v8[2]; // [sp+10h] [bp-14h] BYREF
  int v9; // [sp+14h] [bp-10h] BYREF

  v6[0] = result;
  v2 = a2;
  evtstts = ablk + 1840;
  v3 = (unsigned __int16)tutorialstartf;
  if ( !tutorialstartf )
  {
    result = loadchrmask(v6, &v9);
    if ( result )
    {
      *(_WORD *)(evtstts + 1008) = v3;
      *(_DWORD *)v8 = v3;
      do
      {
        result = makechrmask(v6, v8, &v9);
        if ( result )
        {
          result = getBattleWorkIDFromAnimation(v6[0]);
          v4 = result;
          if ( result != -1 )
          {
            bwp = get_bwp(result);
            result = search_controlID(*(unsigned __int8 *)(bwp + 385), &v7);
            if ( v7 >= 0 )
            {
              if ( v2 )
              {
                result = rec_eventstatus(v4, v6[0]);
              }
              else
              {
                result = rsv_eventstatus(v4);
                if ( result )
                {
                  asmfunction = requestStatusResult;
                  result = asm_function(1u, v6[0], 0, 0, 0, 0);
                }
              }
            }
          }
          if ( !v9 )
            break;
        }
        ++*(_DWORD *)v8;
      }
      while ( *(int *)v8 <= 20 );
      if ( *(_WORD *)(evtstts + 1008) )
      {
        result = task_wait(40);
        if ( (*(_WORD *)(evtstts + 1008) & 1) != 0 )
          result = task_wait(40);
      }
      if ( !v2 )
      {
        asmfunction = checkJumpReset;
        return asm_function(1u, 0, 0, 0, 0, 0);
      }
    }
  }
  return result;
}

