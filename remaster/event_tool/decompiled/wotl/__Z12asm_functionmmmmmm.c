// __Z12asm_functionmmmmmm @ 0x2F328 (392 bytes)
// WotL iOS - debug symbols

int __fastcall asm_function(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v7; // r3
  _DWORD *v8; // r12
  int result; // r0

  v7 = a5;
  if ( !asmtasknumber )
  {
    switch ( a1 )
    {
      case 0u:
        goto LABEL_5;
      case 1u:
        goto LABEL_6;
      case 2u:
        goto LABEL_7;
      case 3u:
        goto LABEL_8;
      case 4u:
        goto LABEL_10;
      case 5u:
        a5 = a6;
        goto LABEL_10;
      default:
        goto LABEL_11;
    }
  }
  v8 = asmtaskframeptr;
  *((_DWORD *)asmtaskframeptr + 12) = 0;
  v8[13] = 0;
  switch ( a1 )
  {
    case 0u:
LABEL_5:
      result = asmfunction(a1, a2, a3, asmfunction, a5);
      break;
    case 1u:
LABEL_6:
      result = asmfunction(a2, a2, a3, asmfunction, a5);
      break;
    case 2u:
LABEL_7:
      result = asmfunction(a2, a3, a3, asmfunction, a5);
      break;
    case 3u:
LABEL_8:
      result = asmfunction(a2, a3, a4, asmfunction, a5);
      break;
    case 4u:
      goto LABEL_10;
    case 5u:
      a5 = a6;
LABEL_10:
      result = asmfunction(a2, a3, a4, v7, a5);
      break;
    default:
LABEL_11:
      result = 0;
      break;
  }
  return result;
}

