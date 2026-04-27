// __Z15TE_asmTaskEntryi @ 0x1D1ED4 (432 bytes)
// WotL iOS - debug symbols

int __fastcall TE_asmTaskEntry(int a1)
{
  int no; // r0
  int v3; // r4
  int v4; // r10
  int v5; // r8
  int v6; // r2
  int *v8; // r2
  int v9; // r1
  int v10; // r12
  int v11; // r1
  int *v12; // r0
  int result; // r0
  bool v14; // zf

  no = TE_task_get_no();
  v3 = no;
  if ( a1 == 1 )
    gExecuteNo = -2;
  else
    gExecuteNo = -1;
  v4 = 16 * no;
  v5 = no << 7;
  ++*((_DWORD *)&gTaskFrame + 36 * no + 31);
  pthread_mutex_unlock(&gMutex);
  usleep(0x3E8u);
  __xpLibgpuDrawCallBack(1192);
  while ( 1 )
  {
    pthread_mutex_lock(&gMutex);
    if ( gExecuteNo )
      break;
    if ( !v3 )
      goto LABEL_14;
LABEL_16:
    pthread_mutex_unlock(&gMutex);
    usleep(0x3E8u);
  }
  if ( v3 != gExecuteNo )
    goto LABEL_16;
  v6 = *(_DWORD *)((char *)&gTaskFrame + v4 + v5 + 136);
  if ( v6 != gExecuteTaskType )
    goto LABEL_16;
  if ( !(v6 ? Wtask_status(v3) : task_status(v3)) )
    goto LABEL_16;
LABEL_14:
  asmtasknumber = v3;
  wasmtasknumber = v3;
  v8 = (int *)((char *)&gTaskFrame + v4 + v5);
  v9 = *v8;
  v10 = v8[1];
  if ( *v8 != v10 && v9 )
  {
    v11 = 1;
    v12 = (int *)((char *)&gTaskFrame + v4 + v5 + 8);
    goto LABEL_24;
  }
  result = v4 + v5;
  if ( *(_DWORD *)((char *)&gTaskFrame + v4 + v5 + 132) )
  {
    v14 = v9 == 0;
    if ( v9 )
      v14 = v10 == 0;
    if ( !v14 )
    {
      v12 = (int *)((char *)&gTaskFrame + result + 8);
      v11 = 2;
LABEL_24:
      longjmp(v12, v11);
    }
  }
  return result;
}

