// __ZL13psp_unit_loadv @ 0xAA700 (216 bytes)
// WotL iOS - debug symbols

int __fastcall psp_unit_load()
{
  int v0; // r5
  char *CD; // r8
  int inited; // r6
  int BinaryData; // r0
  int v4; // r4
  _WORD v6[4]; // [sp+0h] [bp-20h] BYREF
  _WORD __dst[4]; // [sp+8h] [bp-18h] BYREF

  memcpy(__dst, &psp_unit_load(void)::C.195, sizeof(__dst));
  memcpy(v6, &psp_unit_load(void)::C.196, sizeof(v6));
  v0 = 0;
  CD = (char *)numa_fileAllocateCD(0x36Fu, 0x1000u);
  inited = __bpInitBinpackData();
  while ( v0 < __bpGetFileNum(inited) )
  {
    BinaryData = __bpGetBinaryData(inited, v0++);
    v4 = BinaryData;
    PSX_LoadImage(v6, BinaryData);
    ++v6[1];
    PSX_LoadImage(__dst, v4 + 32);
    __dst[0] += __dst[2];
  }
  DrawSync(0);
  fileDispose(CD);
  return saveVram("psp_unit_load");
}

