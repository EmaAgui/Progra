#include "CtypeH.h"


int miToupper(int ch)
{
    return ES_MINUSCULA(ch)? ch - 32 : ch;
}


int miTolower(int ch)
{
    return ES_MAYUSCULA(ch)? ch + 32 : ch;
}
