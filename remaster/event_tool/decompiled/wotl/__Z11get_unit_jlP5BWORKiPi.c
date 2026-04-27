// __Z11get_unit_jlP5BWORKiPi @ 0x12A020 (56 bytes)
// WotL iOS - debug symbols

int __fastcall get_unit_jl(int a1, __int16 a2, _DWORD *a3)
{
  int LocalJobNumber; // r0
  int v6; // r3

  LocalJobNumber = GetLocalJobNumber(a2);
  *a3 = LocalJobNumber;
  v6 = *(unsigned __int8 *)(a1 + LocalJobNumber / 2 + 228);
  if ( (LocalJobNumber & 1) != 0 )
    return v6 & 0xF;
  else
    return v6 >> 4;
}

