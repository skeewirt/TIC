// __Z11move_camerav @ 0x74E84 (1468 bytes)
// WotL iOS - debug symbols, no obfuscation

void __fastcall __noreturn move_camera()
{
  int v0; // r5
  char *Input1; // r4
  int v2; // r0
  char *v3; // r4
  int v4; // r0
  __int16 eventflag; // r0
  int v6; // r1
  int v7; // r2
  int *v8; // r0
  int v9; // r1
  signed int v10; // r3
  signed int v11; // r3
  int v12; // r4
  int v13; // r11
  int v14; // r2
  int v16; // r10
  int v17; // r1
  int v18; // r12
  int v19; // r8
  int v20; // r8
  int v21; // r0
  int v22; // r0
  int v23; // r3
  int v24; // r0
  int v25; // r0
  int v26; // r4
  int v27; // r6
  int v28; // r1
  int v29; // r12
  int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // [sp+10h] [bp-98h]
  int v34; // [sp+14h] [bp-94h]
  int v35; // [sp+18h] [bp-90h]
  int v36; // [sp+28h] [bp-80h]
  int v37; // [sp+2Ch] [bp-7Ch]
  int v38; // [sp+30h] [bp-78h]
  int v39; // [sp+34h] [bp-74h]
  int v40; // [sp+38h] [bp-70h]
  int v41; // [sp+3Ch] [bp-6Ch]
  int *v42; // [sp+40h] [bp-68h]
  _DWORD v43[8]; // [sp+50h] [bp-58h] BYREF
  _DWORD v44[4]; // [sp+70h] [bp-38h] BYREF
  int v45; // [sp+80h] [bp-28h]
  int v46; // [sp+8Ch] [bp-1Ch]

  v0 = 1;
  v39 = cameraoperateflg & 3;
  v37 = (cameraoperateflg & 0xC) >> 2;
  v38 = (cameraoperateflg & 0xF0) >> 4;
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) = 4;
  Input1 = (char *)asmGetInput1();
  v2 = cnvtobinshort(Input1);
  v3 = Input1 + 2;
  v44[0] = v2;
  do
  {
    v4 = cnvtobinshort(v3);
    v3 += 2;
    v44[v0++] = v4;
  }
  while ( v0 != 8 );
  if ( resetcameraangleflag )
  {
    resetcameraangleflag = 0;
    eventflag = read_eventflag(30);
    v6 = eventflag;
    if ( (int)abs32(eventflag - v45 + 4096) < (int)abs32(eventflag - v45) )
      v6 = (__int16)(eventflag + 4096);
    write_eventflag(30, v6);
  }
  v7 = 1;
  v8 = evtworkptr;
  v43[0] = evtworkptr[cameraworkofs[0]];
  do
  {
    v43[v7] = v8[cameraworkofs[v7]];
    ++v7;
  }
  while ( v7 != 7 );
  v9 = 1;
  v10 = v43[0] & 0xFFFFF000;
  if ( v43[0] < 0 )
    v10 = (v43[0] & 0xFFFFF000) + 3;
  v43[0] = v10 >> 2;
  do
  {
    v11 = v43[v9] & 0xFFFFF000;
    if ( (int)v43[v9] < 0 )
      v11 += 3;
    v43[v9++] = v11 >> 2;
  }
  while ( v9 != 3 );
  v12 = v46;
  v36 = 0;
  v40 = 0;
  v46 = v12 / iOS_GetFrameRate();
  if ( v46 <= 0 )
    v46 = 1;
  v13 = v46;
  v34 = 32 * v46;
  v41 = -v46;
LABEL_60:
  if ( v36 >= v13 )
  {
    v28 = (unsigned __int16)linkf;
    if ( !linkf )
    {
      do
      {
        v29 = *(_DWORD *)((char *)v44 + 2 * v28);
        if ( v29 != 10000 )
          evtworkptr[*(unsigned __int16 *)((char *)cameraworkofs + v28)] = v29 << 10;
        v28 += 2;
      }
      while ( v28 != 6 );
    }
    v30 = 3;
    while ( 1 )
    {
      v31 = v44[v30];
      if ( v31 != 10000 )
        evtworkptr[cameraworkofs[v30]] = v31;
      if ( ++v30 == 7 )
      {
        anticamera();
        asmTaskEntry();
        task_killmyself();
      }
    }
  }
  v27 = 0;
  v26 = 0;
  while ( 1 )
  {
    v33 = cameraworkofs[v26];
    v42 = evtworkptr;
    v14 = v44[v27];
    if ( v14 == 10000 )
      goto LABEL_58;
    if ( linkf && v26 <= 2 )
      goto LABEL_58;
    if ( v26 > 2 )
    {
      v18 = v43[v27];
      v17 = (v14 - v18) << 6;
      if ( (unsigned int)(v17 + 95) > 0xBE )
      {
        v16 = v18 << 6;
LABEL_28:
        if ( !v39 )
          goto LABEL_35;
        if ( !v37 )
        {
          if ( v26 <= 2 )
            goto LABEL_37;
LABEL_35:
          v32 = asmMUL64(v17, v36, v13) + v16;
          if ( v26 <= 2 )
          {
LABEL_39:
            v32 *= 4;
            goto LABEL_49;
          }
LABEL_50:
          if ( v32 <= 0 )
          {
            if ( (unsigned __int8)v32 <= 0x1Fu )
              v32 -= 64;
          }
          else if ( (unsigned __int8)v32 > 0x20u )
          {
            v32 += 64;
          }
          v32 /= 64;
LABEL_57:
          v42[v33] = v32;
          goto LABEL_58;
        }
        if ( v37 == 1 && v26 <= 2 )
        {
          v32 = asmMUL64(v17, v36, v13) + v16;
          goto LABEL_39;
        }
LABEL_37:
        if ( v39 == 1 )
        {
          v19 = v17 * 2 * v38;
          v35 = asmMUL64(2 * (16 - v38) * v17 + v19, v36, v34);
          v32 = v35 + asmMUL64(v19, (v13 - v36) * v36, 32 * v13 * v13) + v16;
          if ( v26 <= 2 )
            goto LABEL_39;
LABEL_49:
          if ( v26 > 2 )
            goto LABEL_50;
          goto LABEL_57;
        }
        v20 = 2 * v17;
        if ( v13 <= v40 )
        {
          v24 = asmMUL64(v20 * 2 * v38, 2 * v13 - v40, v13);
          v25 = asmMUL64(2 * (16 - v38) * v20 + v20 * 2 * v38 + v24, v41, v34);
          v23 = v25;
          if ( v26 <= 2 )
          {
            v22 = 4 * v16 + v20;
            goto LABEL_47;
          }
          v22 = v25 + v20;
        }
        else
        {
          v21 = asmMUL64(v20 * 2 * v38, v40, v13);
          v22 = asmMUL64(2 * (16 - v38) * v20 + v21, v40, v34);
          if ( v26 <= 2 )
          {
            v23 = 4 * v16;
LABEL_47:
            v32 = v22 + v23;
            goto LABEL_49;
          }
        }
        v32 = v16 + v22 / 4;
        goto LABEL_49;
      }
    }
    else
    {
      v16 = v43[v27];
      v17 = (v14 << 8) - v16;
      if ( (unsigned int)(v17 + 1535) > 0xBFE )
        goto LABEL_28;
    }
LABEL_58:
    ++v26;
    ++v27;
    if ( v26 == 7 )
    {
      anticamera();
      asmTaskEntry();
      ++v36;
      v40 += 2;
      v41 += 2;
      goto LABEL_60;
    }
  }
}

