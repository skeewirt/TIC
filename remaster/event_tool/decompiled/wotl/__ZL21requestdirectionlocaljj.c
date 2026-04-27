// __ZL21requestdirectionlocaljj @ 0x642B4 (96 bytes)
// WotL iOS - debug symbols

int __fastcall requestdirectionlocal(unsigned int a1, unsigned int a2)
{
  int BattleWorkIDFromAnimation; // r0
  int v5; // r0
  unsigned int AnimationIDFormBattleWork; // r0

  if ( !read_eventflag(509) )
  {
    BattleWorkIDFromAnimation = getBattleWorkIDFromAnimation(a1);
    if ( BattleWorkIDFromAnimation >= 0 )
    {
      v5 = *(unsigned __int8 *)(get_bwp(BattleWorkIDFromAnimation) + 420);
      if ( v5 )
      {
        AnimationIDFormBattleWork = getAnimationIDFormBattleWork(v5 & 0x1F);
        setAnimationDirection16(AnimationIDFormBattleWork, a2);
      }
    }
  }
  return setAnimationDirection16(a1, a2);
}

