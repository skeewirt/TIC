// __ZL17tutorial_padwritePi @ 0x60C8C (468 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall tutorial_padwrite(unsigned int *a1)
{
  unsigned int v2; // r6
  int eventflag; // r0
  unsigned int v4; // r4
  int v5; // r2
  int GlobalCounter; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  char v15; // r3
  int v16; // r2
  int v17; // r3
  char v18; // r3
  unsigned int result; // r0

  if ( *a1 == 2316 )
    resetFFT();
  if ( iOS_getReset() )
  {
    iOS_setReset(0);
    resetFFT();
  }
  v2 = *a1;
  *a1 &= read_eventflag(41) ^ 0xFFFF;
  eventflag = read_eventflag(42);
  v4 = eventflag;
  if ( eventflag )
  {
    if ( (eventflag & 0x2000) != 0 )
    {
      GlobalCounter = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADLright[%08x]\n", GlobalCounter);
    }
    if ( (v4 & 0x8000) != 0 )
    {
      v7 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADLleft [%08x]\n", v7);
    }
    if ( (v4 & 0x1000) != 0 )
    {
      v8 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADLup   [%08x]\n", v8);
    }
    if ( (v4 & 0x4000) != 0 )
    {
      v9 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADLdown [%08x]\n", v9);
    }
    if ( (v4 & 0x20) != 0 )
    {
      v10 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADRright[%08x]\n", v10);
    }
    if ( (v4 & 0x80) != 0 )
    {
      v11 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADRleft [%08x]\n", v11);
    }
    if ( (v4 & 0x10) != 0 )
    {
      v12 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADRup   [%08x]\n", v12);
    }
    if ( (v4 & 0x40) != 0 )
    {
      v13 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADRdown [%08x]\n", v13);
    }
    if ( (v4 & 0x100) != 0 )
    {
      v14 = iOS_getGlobalCounter();
      TRACE_Dummy(" tutoKeyinput PADselect[%08x]\n", v14);
    }
    v15 = v4 & 0xA;
    v16 = v4 & 0xA;
    if ( (v4 & 0xA) != 0 )
      v15 = 1;
    if ( v16 == 10 )
      v17 = 0;
    else
      v17 = v15 & 1;
    if ( v17 )
      v16 ^= 0xAu;
    v18 = v4 & 0xF5;
    v4 = v16 | v4 & 0xFFFFFFF5;
    v5 = v18 & 5;
    if ( v5 != 5 && v5 != 0 )
      v5 ^= 5u;
  }
  else
  {
    v5 = 0;
  }
  result = v5 | *a1 | v4 & 0xFFFFFFFA | v2 & 0xFFFF0000;
  *a1 = result;
  return result;
}

