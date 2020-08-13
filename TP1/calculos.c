#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int sumar(int op1, int op2)
{
    return op1 + op2;
}

int restar(int op1, int op2)
{
    return op1 - op2;
}

float dividir(int op1, int op2)
{
    if(op2==0)
    {
        return op2;
    }
    else
    {
        return (float)op1 / op2;
    }
}

int multiplicar(int op1, int op2)
{
    return op1 * op2;
}

int factorial(int op)
{
    int fac=1;
    if(op == 1)
    {
        return 1;
    }
    else if(op > 1)
    {
        for(int i=1; i<=op; i++)
        {
            fac *= i;
        }
    }
    else
    {
        return 0;
    }

    return fac;
}
