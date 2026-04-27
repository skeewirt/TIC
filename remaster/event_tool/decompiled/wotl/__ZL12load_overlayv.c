// __ZL12load_overlayv @ 0x5DC64 (284 bytes)
// WotL iOS - debug symbols

void __fastcall load_overlay()
{
  if ( loadoverlay )
  {
    if ( loadoverlayflg )
    {
      TRACE_Dummy("loadonefile B\n");
      asmfunction = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))fileReadCheck;
      if ( !asm_function(1u, 0, 0, 0, 0, 0) )
      {
        loadoverlayflg = 0;
        loadoverlay = 0;
      }
    }
    else
    {
      TRACE_Dummy("!!!! load_overlay loadoverlayseq[%d]:0x%08x\n", loadoverlay, loadoverlayseq[loadoverlay]);
      asmfunction = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))fileReadRequest;
      if ( !asm_function(
              3u,
              loadoverlayseq[loadoverlay],
              loadoverlaylen[loadoverlay],
              (unsigned int)EffectLoadAddress + overlayadrlst[loadoverlay],
              0,
              0) )
      {
        hockRead(nullptr, 0, loadoverlayseq[loadoverlay]);
        TRACE_Dummy("loadonefile A\n");
        loadoverlayflg = 1;
      }
    }
  }
}

