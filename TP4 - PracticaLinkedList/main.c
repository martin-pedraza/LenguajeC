#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "auto.h"
#include "funcion.h"

int menu();

int main()
{
    int opcion=1;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* filtro = NULL;
    if(lista==NULL)
    {
        printf("No se pudo crear la lista\n\n");
        exit(EXIT_FAILURE);
    }
    do
    {
        switch(menu())
        {
        case 1:
            if(!cargarTexto("autos.csv", lista))
            {
                printf("Cargado!\n\n");
            }
            else
            {
                printf("No se pudo cargar\n\n");
            }
            break;
        case 2:
            if(!cargarBinario("autos.bin", lista))
            {
                printf("Cargado!\n\n");
            }
            else
            {
                printf("No se pudo cargar\n\n");
            }
            break;
        case 3:
            if(!car_alta(lista))
            {
                printf("Auto dado de alta\n\n");
            }
            else
            {
                printf("No se ha podido dar de alta\n\n");
            }
            break;
        case 4:
            if(!car_modificar(lista))
            {
                printf("Auto modificado\n\n");
            }
            else
            {
                printf("No se ha podido modificar\n\n");
            }
            break;
        case 5:
            if(!car_baja(lista))
            {
                printf("Auto dado de baja\n\n");
            }
            else
            {
                printf("No se ha podido dar de baja\n\n");
            }
            break;
        case 6:
            car_lista(lista);
            break;
        case 7:
            switch(menuFiltro())
            {
            case 1:
                filtro=ll_filter(lista, filtrarMarca);
                if(!guardarTexto("filtroMarca.csv", filtro))
                {
                    printf("Guardado!\n\n");
                }
                else
                {
                    printf("No se pudo guardar\n\n");
                }
                break;
            case 2:
                filtro=ll_filter(lista, filtrarAnio);
                if(!guardarTexto("filtroAnio.csv", filtro))
                {
                    printf("Guardado!\n\n");
                }
                else
                {
                    printf("No se pudo guardar\n\n");
                }
                break;
            case 3:
                filtro=ll_filter(lista, filtrarColor);
                if(!guardarTexto("filtroColor.csv", filtro))
                {
                    printf("Guardado!\n\n");
                }
                else
                {
                    printf("No se pudo guardar\n\n");
                }
                break;
            case 4:
                filtro=ll_filter(lista, filtrarPrecio);
                if(!guardarTexto("filtroPrecio.csv", filtro))
                {
                    printf("Guardado!\n\n");
                }
                else
                {
                    printf("No se pudo guardar\n\n");
                }
                break;
            default:
                printf("Opcion no valida\n\n");
            }
            break;
        case 8:
            if(!guardarTexto("autos.csv", lista))
            {
                printf("Guardado!\n\n");
            }
            else
            {
                printf("No se pudo guardar\n\n");
            }
            break;
        case 9:
            if(!guardarBinario("autos.bin", lista))
            {
                printf("Guardado!\n\n");
            }
            else
            {
                printf("No se pudo guardar\n\n");
            }
            break;
        case 10:
            opcion=0;
            break;
        default:
            printf("Opcion no valida\n\n");
        }
        system("pause");
    }
    while(opcion);
    return 0;
}

int menu()
{
    int op;
    system("cls");
    printf("*****Menu*****\n\n");
    printf("1. Cargar los datos(modo texto).\n");
    printf("2. Cargar los datos(modo binario).\n");
    printf("3. ALTA\n");
    printf("4. MODIFICAR\n");
    printf("5. BAJA\n");
    printf("6. LISTAR\n");
    printf("7. FILTRAR\n");
    printf("8. Guardar(modo texto).\n");
    printf("9. Guardar(modo binario).\n");
    printf("10.Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    return op;
}
