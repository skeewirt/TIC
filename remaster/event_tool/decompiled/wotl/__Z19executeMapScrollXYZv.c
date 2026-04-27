// __Z19executeMapScrollXYZv @ 0x15527C (104 bytes)
// WotL iOS - debug symbols

int __fastcall executeMapScrollXYZ()
{
  int result; // r0

  if ( gScrollChangeStepXYZ )
  {
    mapVector += gScrollChangeValue;
    dword_12B16F8 += dword_12B1718;
    dword_12B16FC += dword_12B171C;
    --gScrollChangeStepXYZ;
    return dword_12B1718;
  }
  return result;
}

