#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define LEN 1000


int menu();
int menuModificar();
void mostrarSalario(Employee list[], int len);


int main()
{
    int trigger = 0;
    int respuesta = 1;
    int autoId = 1000;
    Employee lista[LEN];

    char nom[51];
    char ape[51];
    float slry;
    int sec;

    int modId;
    int indx;
    char modNom[51];
    char modPe[51];
    float modSlry;
    int modSec;

    int bajaId;

    int orden;

    initEmployees(lista, LEN);
    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printf("*****ALTA DE EMPLEADO*****\n\n");
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(nom);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(ape);
            printf("Ingrese salario: ");
            scanf("%f", &slry);
            printf("Ingrese numero del sector: ");
            scanf("%d", &sec);

            if(addEmployee(lista, LEN, autoId, nom, ape, slry, sec) == 0)
            {
                printf("Empleado agregado\n\n");
                autoId++;
            }
            else
            {
                printf("Error. No se ha agregado al empleado");
            }

            break;
        case 2:
            if(trigger)
            {
                system("cls");
                printf("*****MODIFICAR EMPLEADO*****\n\n");
                printf("Ingrese el id: ");
                scanf("%d", &modId);

                indx = findEmployeeById(lista, LEN, modId);


                if(indx==-1)
                {
                    printf("Id no corresponde a un empleado\n\n");
                }
                else
                {
                    switch(menuModificar())
                    {
                    case 1:
                        printf("Ingrese nombre: ");
                        fflush(stdin);
                        gets(modNom);
                        strncpy(lista[indx].name, modNom, 51);
                        break;
                    case 2:
                        printf("Ingrese apellido: ");
                        fflush(stdin);
                        gets(modPe);
                        strncpy(lista[indx].lastName, modPe, 51);
                        break;
                    case 3:
                        printf("Ingrese salario: ");
                        scanf("%f", &modSlry);
                        lista[indx].salary = modSlry;
                        break;
                    case 4:
                        printf("Ingrese sector: ");
                        scanf("%d", &modSec);
                        lista[indx].sector = modSec;
                        break;
                    default:
                        printf("Opcion ha modificar no valida");
                    }
                }
            }
            else
            {
                printf("Primero se debe dar de alta a algun empleado\n\n");
            }

            break;
        case 3:
            if(trigger)
            {
                system("cls");
                printf("*****BAJA DE EMPLEADO*****\n\n");
                printf("Ingrese el id: ");
                scanf("%d", &bajaId);

                if(removeEmployee(lista, LEN, bajaId)==0)
                {
                    printf("Empleado dado de baja\n\n");
                }
                else
                {
                    printf("Error. No se ha podido dar de baja al empleado\n\n");
                }
            }
            else
            {
                printf("Primero se debe dar de alta a algun empleado\n\n");
            }

            break;
        case 4:
            if(trigger)
            {
                printf("Ingrese el orden (1 o 0): ");
                scanf("%d", &orden);

                sortEmployees(lista, LEN, orden);
                printEmployees(lista, LEN);
                mostrarSalario(lista, LEN);
            }
            else
            {
                printf("Primero se debe dar de alta a algun empleado\n\n");
            }
            break;
        case 5:
            respuesta = 0;
            break;
        default:
            printf("No es una opcion valida\n\n");
        }
        for(int i=0; i<LEN; i++)
        {
            if(lista[i].isEmpty==0)
            {
                trigger=1;
                break;
            }
            else
            {
                trigger=0;
            }
        }
        system("pause");

    }
    while(respuesta);

    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("*****MENU DE OPCIONES*****\n\n");
    printf("1- ALTA DE EMPLEADO\n");
    printf("2- MODIFICAR EMPLEADO\n");
    printf("3- BAJA DE EMPLEADO\n");
    printf("4- INFORMAR\n");
    printf("5- SALIR\n");

    printf("\nElegir opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuModificar()
{
    int opcion;
    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Salario\n");
    printf("4-Sector\n\n");
    printf("Que desea modificar? ");
    scanf("%d", &opcion);
    return opcion;
}

void mostrarSalario(Employee list[], int len)
{
    float acumulador = 0;
    int contador = 0;
    float promedio;
    int empProm = 0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acumulador += list[i].salary;
            contador++;
        }
    }
    promedio=acumulador/contador;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > promedio)
        {
            empProm++;
        }
    }
    printf("\n\n*****PROMEDIO DE SALARIOS*****\n\n");
    printf("El total de los salarios es: %.2f\n", acumulador);
    printf("El promedio de los salarios es: %.2f\n", promedio);
    printf("La cantidad de empleados que superan el salario promedio es: %d\n\n", empProm);

}
