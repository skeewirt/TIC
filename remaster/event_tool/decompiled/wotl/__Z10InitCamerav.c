// __Z10InitCamerav @ 0x161F5C (64 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall InitCamera()
{
  gCameraWorkAngNow = 0;
  gCameraWorkTransNow = 0;
  gCameraWorkScaleNow = 0;
  gCameraOrderLast = 0;
  gCameraOrderTop = 0;
  return SetDefaultCamera();
}

