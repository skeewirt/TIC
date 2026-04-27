// __Z13wasm_functionmmmmmm @ 0x2F6A0 (392 bytes)
// WotL iOS - debug symbols

int __fastcall wasm_function(
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
  if ( !wasmtasknumber )
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
  v8 = wasmtaskframeptr;
  *((_DWORD *)wasmtaskframeptr + 12) = 0;
  v8[13] = 0;
  switch ( a1 )
  {
    case 0u:
LABEL_5:
      result = wasmfunction(a1, a2, a3, wasmfunction, a5);
      break;
    case 1u:
LABEL_6:
      result = wasmfunction(a2, a2, a3, wasmfunction, a5);
      break;
    case 2u:
LABEL_7:
      result = wasmfunction(a2, a3, a3, wasmfunction, a5);
      break;
    case 3u:
LABEL_8:
      result = wasmfunction(a2, a3, a4, wasmfunction, a5);
      break;
    case 4u:
      goto LABEL_10;
    case 5u:
      a5 = a6;
LABEL_10:
      result = wasmfunction(a2, a3, a4, v7, a5);
      break;
    default:
LABEL_11:
      result = 0;
      break;
  }
  return result;
}

