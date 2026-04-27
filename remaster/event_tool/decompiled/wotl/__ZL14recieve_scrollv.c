// __ZL14recieve_scrollv @ 0x5DB4C (180 bytes)
// WotL iOS - debug symbols

int *__fastcall recieve_scroll()
{
  __int16 *MapAngle; // r0
  int *v1; // r2
  int v2; // r3
  int *MapScale; // r0
  int *v4; // r3
  int *result; // r0
  int *v6; // r2

  MapAngle = (__int16 *)getMapAngle();
  v1 = evtworkptr;
  theSvectorPtr = (int)MapAngle;
  evtworkptr[29] = *MapAngle;
  v1[30] = MapAngle[1];
  v2 = MapAngle[2];
  v1[31] = v2;
  if ( v2 == -1 )
    v1[31] = 0;
  MapScale = (int *)getMapScale();
  v4 = evtworkptr;
  theVectorPtr = (int)MapScale;
  evtworkptr[32] = *MapScale;
  v4[32] = MapScale[1];
  v4[32] = MapScale[2];
  result = getMapScrollXYZ();
  v6 = evtworkptr;
  theVectorPtr = (int)result;
  evtworkptr[26] = *result;
  v6[27] = result[1] - ((unsigned __int16)eventshakef << 12);
  v6[28] = result[2];
  eventshakef = 0;
  return result;
}

