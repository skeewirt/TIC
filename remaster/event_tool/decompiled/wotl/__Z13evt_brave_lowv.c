// __Z13evt_brave_lowv @ 0x19518C (72 bytes)
// WotL iOS - debug symbols

int __fastcall evt_brave_low()
{
  int ramza_savework; // r0
  int result; // r0
  int v2; // r12

  ramza_savework = get_ramza_savework();
  result = get_unitwork_add_wld(ramza_savework);
  v2 = *(unsigned __int16 *)(2 * (unsigned __int16)word_12FB710++ + dword_12FB70C);
  if ( v2 < *(unsigned __int8 *)(result + 30) )
    event_inf |= 2u;
  return result;
}

