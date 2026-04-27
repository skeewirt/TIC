// __ZL17make_maincommand2v @ 0x4EA60 (244 bytes)
// WotL iOS - debug symbols

int __fastcall make_maincommand2()
{
  __int16 *Input1; // r4

  TRACE_Dummy("make_maincommand2\n");
  Input1 = (__int16 *)wasmGetInput1();
  TRACE_Dummy("  SRC{%3d,%3d,%3d,%3d}\n", *Input1, Input1[1], Input1[2], Input1[3]);
  TRACE_Dummy("  DST{%3d,%3d,%3d,%3d}\n", Input1[4], Input1[5], Input1[6], Input1[7]);
  TRACE_Dummy("  BG{%3d,%3d,%3d,%3d,%3d,}\n", Input1[8], Input1[9], Input1[10], Input1[11], Input1[12]);
  TRACE_Dummy("  MSGN %d\n", Input1[14]);
  TRACE_Dummy("  yline %d\n", Input1[15]);
  TRACE_Dummy("  howmanyback %d\n", Input1[16]);
  TRACE_Dummy("  next %08x\n", *((_DWORD *)Input1 + 9));
  TRACE_Dummy("  currenty %d\n", Input1[28]);
  change_maincommand(Input1);
  return Wdisp_selectwindow();
}

