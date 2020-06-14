#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("No se pudo cargar los datos\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("Datos cargados con exito\n\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("No se pudo cargar los datos\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("Datos cargados con exito\n\n");
            }
            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("Empleado dado de alta\n\n");
            }
            else
            {
                printf("No se ha podido dar de alta\n\n");
            }
            break;
        case 4:
            if(!controller_editEmployee(listaEmpleados))
            {
                printf("Empleado modificado\n\n");
            }
            else
            {
                printf("No se ha podido modificar\n\n");
            }
            break;
        case 5:
            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("Empleado dado de baja\n\n");
            }
            else
            {
                printf("No se ha podido dar de baja\n\n");
            }
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("No se pudo guardar los datos\n\n");
            }
            else
            {
                printf("Guardado con exito\n\n");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados))
            {
                printf("No se pudo guardar los datos\n\n");
            }
            else
            {
                printf("Guardado con exito\n\n");
            }
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            option=10;
            break;
        default:
            printf("Opcion no valida\n\n");
        }
        system("pause");
    }
    while(option != 10);
    return 0;
}

int menu()
{
    int op;
    system("cls");
    printf("*****Menu*****\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    return op;
}
