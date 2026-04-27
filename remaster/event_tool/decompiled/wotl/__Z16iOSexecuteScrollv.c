// __Z16iOSexecuteScrollv @ 0x1D72A0 (288 bytes)
// WotL iOS - debug symbols

void __fastcall iOSexecuteScroll()
{
  float32x2_t v0; // d5
  float32x2_t v1; // d6
  int v2; // r6
  int v3; // r8
  unsigned __int64 v4; // r0
  float32x2_t v5; // d7
  float32x2_t v6; // d7
  int v7; // r3
  float32x2_t v8; // d7

  if ( sTchSlideFlag )
  {
    if ( sTchSlideSpeed <= 0.0 || iOS_getTouchTap() )
    {
      sTchSlideFlag = 0;
    }
    else
    {
      v2 = (((sTchSlideAngle + (((word_12B16DE & 0xFFF) + 1024) & 0xFFF)) & 0xFFF) - 1024) & 0xFFF;
      v3 = rcos(v2);
      v4 = __PAIR64__(&mapVector, rsin(v2));
      v0.f32[0] = sTchSlideSpeed;
      v5 = vadd_f32(v0, v0);
      v1.f32[0] = v5.f32[0] / 3.0;
      v5.f32[0] = (float)v3;
      v6 = vmul_f32(v5, v1);
      v7 = (int)v6.f32[0];
      v6.f32[0] = (float)(int)v4;
      mapVector += v7;
      v8 = vmul_f32(v1, v6);
      dword_12B16FC += (int)v8.f32[0];
      v8.f32[0] = sTchSlideSpeedDD;
      sTchSlideSpeed = vsub_f32(v0, v8).f32[0];
      if ( sTchSlideSpeed <= 0.0 )
        sTchSlideFlag = 0;
    }
  }
}

