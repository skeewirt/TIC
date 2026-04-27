// __Z16hakenunit_statusi @ 0x19E868 (216 bytes)
// WotL iOS - debug symbols

int __fastcall hakenunit_status(int a1)
{
  int result; // r0

  ctlworkingst_dataset(a1);
  dword_2EB4F0 = 0;
  dword_2EB4DC = 0;
  dword_2EB4C8 = 0;
  personaltest1 = 0;
  Wtask_create(8, (void (__fastcall *)())Wdisp_personalwindow);
  Wsend_taskparamater(8, (int)&personaltest1, 0, 0);
  Wtask_create(12, (void (__fastcall *)())Wdisp_parawindow);
  Wsend_taskparamater(12, (int)&personaltest3, 0, 0);
  Wtask_create(9, (void (__fastcall *)())Wdisp_bothwindow);
  Wsend_taskparamater(9, (int)&personaltest4, 0, 0);
  wld_flg |= 0x20000u;
  result = pspWorldEnableFlg(16);
  sSwypeCnt = 0;
  return result;
}

