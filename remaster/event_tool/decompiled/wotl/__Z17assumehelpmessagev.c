// __Z17assumehelpmessagev @ 0x30C04 (876 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall assumehelpmessage()
{
  int v0; // r10
  char *v1; // r4
  int unitwork_add; // r0
  int v3; // r6
  int v4; // r1
  _BYTE *v5; // r2
  __int16 *v6; // r8
  __int16 *v7; // r5
  __int16 v8; // r0
  char *v9; // r0
  char v10; // t1
  char v11; // t1
  __int16 *v12; // r5
  __int16 v13; // r0
  char *v14; // r0
  char v15; // t1
  char v16; // t1
  __int16 v17; // r0
  char *v18; // r0
  char v19; // t1
  char v20; // t1
  __int16 *v21; // r5
  __int16 v22; // r0
  char *v23; // r0
  char v24; // t1
  char v25; // t1
  int v26; // r0
  int v27; // r0
  char *v28; // r0
  char v29; // t1
  char v30; // t1
  char *v31; // r0
  int v32; // r2
  char *v33; // r0
  char v34; // t1
  char v35; // t1
  char *v37; // [sp+0h] [bp-1Ch]

  v0 = 0;
  v37 = (char *)mallocForFile(0x20000u);
  fileReadRequest(0x24u, 0x20000u, v37);
  STEP_DISP("assume help message");
  pushmessagepacket();
  makeatcpacket(v37);
  v1 = (char *)&temporary_loaddatabuf;
  do
  {
    unitwork_add = get_unitwork_add(v0);
    v3 = unitwork_add;
    if ( *(unsigned __int8 *)(unitwork_add + 1) == 255 || *(_BYTE *)(unitwork_add + 238) )
    {
      v4 = 1;
      *v1 = -2;
      v5 = v1 + 1;
      do
      {
        ++v4;
        *v5++ = -2;
      }
      while ( v4 != 11 );
      v1 += 11;
    }
    else
    {
      getdata(1, v0);
      v6 = &astatuscinfo;
      v7 = &astatuscinfo;
      do
      {
        v8 = v7[18];
        if ( v8 && (v8 & 0x7FF) != 0x7FF )
        {
          v9 = (char *)serchmessagepointer(v8 + 26624);
          while ( 1 )
          {
            v10 = *v9++;
            *v1 = v10;
            v11 = *v1++;
            if ( (v11 & 0xFE) == 0xFE )
              break;
            if ( v1 >= registerchr )
              goto LABEL_55;
          }
        }
        else
        {
          *v1++ = -2;
        }
        ++v7;
      }
      while ( v7 != &word_25E4D0 );
      if ( word_25E4D4 )
      {
        do
        {
          v13 = v6[23];
          if ( v13 && (v13 & 0x7FF) != 0x7FF )
          {
            v14 = (char *)serchmessagepointer(v13 + 30720);
            while ( 1 )
            {
              v15 = *v14++;
              *v1 = v15;
              v16 = *v1++;
              if ( (v16 & 0xFE) == 0xFE )
                break;
              if ( v1 >= registerchr )
                goto LABEL_55;
            }
          }
          else
          {
            *v1++ = -2;
          }
          ++v6;
        }
        while ( &word_25E4D0 != v6 );
      }
      else
      {
        v12 = &astatuscinfo;
        do
        {
          v17 = v12[23];
          if ( v17 && (v17 & 0x7FF) != 0x7FF )
          {
            v18 = (char *)serchmessagepointer(v17 + 38912);
            while ( 1 )
            {
              v19 = *v18++;
              *v1 = v19;
              v20 = *v1++;
              if ( (v20 & 0xFE) == 0xFE )
                break;
              if ( v1 >= registerchr )
                goto LABEL_55;
            }
          }
          else
          {
            *v1++ = -2;
          }
          ++v12;
        }
        while ( v12 != &word_25E4CA );
        v21 = &astatuscinfo;
        do
        {
          v22 = v21[25];
          if ( v22 && (v22 & 0x7FF) != 0x7FF )
          {
            v23 = (char *)serchmessagepointer(v22 + 30720);
            while ( 1 )
            {
              v24 = *v23++;
              *v1 = v24;
              v25 = *v1++;
              if ( (v25 & 0xFE) == 0xFE )
                break;
              if ( v1 >= registerchr )
                goto LABEL_55;
            }
          }
          else
          {
            *v1++ = -2;
          }
          ++v21;
        }
        while ( v21 != &word_25E4CC );
      }
      v26 = *(unsigned __int8 *)(v3 + 2);
      if ( v26 == 161 && (*(_BYTE *)(v3 + 126) & 0xFu) > 7 )
        v27 = 24740;
      else
        v27 = v26 + 24576;
      v28 = (char *)serchmessagepointer(v27);
      while ( 1 )
      {
        v29 = *v28++;
        *v1 = v29;
        v30 = *v1++;
        if ( (v30 & 0xFE) == 0xFE )
          break;
        if ( v1 >= registerchr )
          goto LABEL_55;
      }
    }
    ++v0;
  }
  while ( v0 != 24 );
  assumehelpidx = &temporary_loaddatabuf;
  off_25E54C = temporary_btlevtbuf;
  v31 = (char *)serchmessagepointer(22528);
  v32 = 1;
  v34 = *v31;
  v33 = v31 + 1;
  temporary_btlevtbuf[0] = v34;
  do
  {
    v35 = *v33++;
    temporary_btlevtbuf[v32++] = v35;
  }
  while ( v32 != 9216 );
LABEL_55:
  popmessagepacket();
  return fileDispose(v37);
}

