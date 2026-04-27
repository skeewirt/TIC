// __ZL12scrollupdownP9COMRECORDPiS1_S1__0 @ 0x1CB07C (516 bytes)
// WotL iOS - debug symbols

void *__fastcall scrollupdown(int a1, int *a2, _DWORD *a3)
{
  __int16 *v4; // r5
  _DWORD *v7; // r8
  _DWORD *v8; // r0
  __int16 v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r2
  char *v13; // r2
  _WORD v15[4]; // [sp+0h] [bp-24h] BYREF
  __int16 v16; // [sp+8h] [bp-1Ch] BYREF
  __int16 v17; // [sp+Ah] [bp-1Ah]
  __int16 v18; // [sp+Ch] [bp-18h]
  __int16 v19; // [sp+Eh] [bp-16h]

  v4 = *(__int16 **)(a1 + 48);
  v7 = (_DWORD *)import_localpad(0);
  v8 = (_DWORD *)import_localpad(1);
  v9 = *(_WORD *)(a1 + 6);
  v16 = *(_WORD *)a1;
  v17 = *(_WORD *)(a1 + 2);
  v18 = *(__int16 *)(a1 + 4) >> 2;
  if ( !tutorialstartf )
  {
    v19 = v9;
    if ( (*v8 & 0x80) != 0 || *((_DWORD *)asmtaskframeptr + 256 * asmtasknumber + 24) )
    {
      if ( (*v7 & 0x1000) != 0 && *a2 )
      {
        v10 = *a2 - *v4;
        if ( v10 < 0 )
          v10 = 0;
        *a2 = v10;
LABEL_13:
        soundf = 3;
LABEL_16:
        asmClearBuffer(&optionbuffer, *(__int16 *)(a1 + 6) * *(__int16 *)(a1 + 4) / 2);
        scrollinit(a1, a2, (unsigned int)&optionbuffer);
        *a3 = 0;
        PSX_LoadImage(&v16, &optionbuffer);
        v15[0] = v16;
        v15[1] = (unsigned __int8)(v17 - 2) + (v17 & 0xFF00);
        v15[2] = v18;
        v15[3] = 2;
        ClearImage(v15, 0, 0, 0);
        return &optionbuffer;
      }
      if ( (*v7 & 0x4000) != 0 && *a2 != v4[1] )
      {
        v11 = *a2 + *v4;
        *a2 = v11;
        v12 = v4[1];
        if ( v11 > v12 )
          *a2 = v12;
        goto LABEL_13;
      }
      v13 = (char *)asmtaskframeptr + 1024 * asmtasknumber;
      if ( *((_DWORD *)v13 + 24) )
      {
        *((_DWORD *)v13 + 24) = 0;
        goto LABEL_16;
      }
    }
  }
  return nullptr;
}

