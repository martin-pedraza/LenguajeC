#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

void menu(int op1, int op2, int tr1, int tr2);

int main()
{
    int num1;
    int num2;
    int respuesta;
    int trigger1 = 0;
    int trigger2 = 0;
    int trigger3 = 0;
    int suma;
    int resta;
    float dividido;
    int multiplicacion;
    int factA;
    int factB;

    do
    {
        system("cls");

        printf("**********MENU DE OPCIONES**********\n\n");

        menu(num1, num2, trigger1, trigger2);

        printf("Opcion de menu: ");
        scanf("%d", &respuesta);

        switch(respuesta)
        {
        case 1:
            printf("Ingresar 1er operando: ");
            scanf("%d", &num1);
            trigger1 = 1;
            break;
        case 2:
            printf("Ingresar 2do operando: ");
            scanf("%d", &num2);
            trigger2 = 1;
            break;
        case 3:
            if(trigger1==1 && trigger2==1)
            {
                suma = sumar(num1, num2);
                resta = restar(num1, num2);
                dividido = dividir(num1, num2);
                multiplicacion = multiplicar(num1, num2);
                factA = factorial(num1);
                factB = factorial(num2);
                printf("Operaciones realizadas\n\n");
                trigger3 = 1;
            }
            else
            {
                printf("Para realizar las operaciones colocar primero los operandos\n\n");
            }
            system("pause");
            break;
        case 4:
            if(trigger3 == 1)
            {
                printf("El resultado de A+B es: %d\n", suma);
                printf("El resultado de A-B es: %d\n", resta);
                if(dividido==0 && num2!=0)
                {
                    printf("El resultado de A/B es: 0\n");
                }
                else if(dividido==0)
                {
                    printf("No es posible dividir por cero\n");
                }
                else
                {
                    printf("El resultado de A/B es: %.2f\n", dividido);

                }
                printf("El resultado de A*B es: %d\n", multiplicacion);
                if(factA != 0)
                {
                    printf("El factorial de A es: %d\n", factA);
                }
                else
                {
                    printf("No existe factorial del 1er operando\n");
                }

                if(factB != 0)
                {
                    printf("El factorial de B es: %d\n\n", factB);
                }
                else
                {
                    printf("No existe factorial del 2do operando\n\n");
                }

                trigger1 = 0;
                trigger2 = 0;
                trigger3 = 0;
            }
            else
            {
                printf("Para mostrar resultados primero se debe calcular las operaciones\n\n");
            }
            system("pause");
            break;
        case 5:
            break;
        default:
            printf("Valor no valido\n\n");
            system("pause");
        }
    }
    while(respuesta != 5);

    return 0;
}

void menu(int op1, int op2, int tr1, int tr2)
{
    if(tr1)
    {
        printf("1- Ingresar 1er operando (A=%d)\n", op1);
    }
    else
    {
        printf("1- Ingresar 1er operando (A=X)\n");

    }
    if(tr2)
    {
        printf("2- Ingresar 2do operando (B=%d)\n", op2);

    }
    else
    {
        printf("2- Ingresar 2do operando (B=Y)\n");

    }

    printf("3- Calcular todas las operaciones\n");
    printf("4- Informar resultados\n");
    printf("5- Salir\n\n");
}
