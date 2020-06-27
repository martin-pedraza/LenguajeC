#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "auto.h"
#include "LinkedList.h"
#include "funcion.h"

int cargarTexto(char* path, LinkedList* lista)
{
    int error=1;
    FILE* f = fopen(path, "r");
    char buffer[5][1000];
    int cant;
    eAuto* auxCar;
    ll_clear(lista);

    if(f!=NULL)
    {
        fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        while(!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(cant==5)
            {
                auxCar = car_newParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                ll_add(lista, auxCar);
                error=0;
            }
        }
        fclose(f);
    }
    return error;
}

int cargarBinario(char* path, LinkedList* lista)
{
    int error=1;
    FILE* f = fopen(path, "rb");
    ll_clear(lista);
    if(f!=NULL)
    {
        do
        {
            eAuto* auxCar = car_new();
            if(auxCar!=NULL)
            {
                if(fread(auxCar, sizeof(eAuto), 1, f))
                {
                    ll_add(lista, auxCar);
                }
                else
                {
                    break;
                }
            }
            error=0;
        }
        while(!feof(f));
        fclose(f);
    }
    return error;
}

int guardarTexto(char* path, LinkedList* lista)
{
    int error=1;
    eAuto* car;
    int tam = ll_len(lista);
    FILE* f = fopen(path, "w");
    if(f!=NULL)
    {
        fprintf(f, "id,marca,anio,color,precio\n");
        for(int i=0; i<tam; i++)
        {
            car = (eAuto*) ll_get(lista, i);
            fprintf(f, "%d,%s,%d,%s,%.2f\n", car->id, car->marca, car->anio, car->color, car->precio);
            error=0;
        }
        fclose(f);
    }
    return error;
}

int guardarBinario(char* path, LinkedList* lista)
{
    int error=1;
    FILE* f = fopen(path, "wb");
    eAuto* car=NULL;
    int tam = ll_len(lista);
    if(f!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            car = (eAuto*) ll_get(lista, i);
            if(car!=NULL)
            {
                fwrite(car, sizeof(eAuto), 1, f);
            }
        }
        error=0;
        fclose(f);
    }
    return error;
}

int filtrarMarca(void* unAuto)
{
    int auxReturn = 0;
    eAuto* x;
    if(unAuto!=NULL)
    {
        x = (eAuto*) unAuto;
        if(strcmp(x->marca, "Ford")==0)
        {
            auxReturn = 1;
        }
    }
    return auxReturn;
}

int filtrarColor(void* unAuto)
{
    int auxReturn = 0;
    eAuto* x;
    if(unAuto!=NULL)
    {
        x = (eAuto*) unAuto;
        if(strcmp(x->color, "Pink")==0)
        {
            auxReturn = 1;
        }
    }
    return auxReturn;
}

int filtrarAnio(void* unAuto)
{
    int auxReturn = 0;
    eAuto* x;
    if(unAuto!=NULL)
    {
        x = (eAuto*) unAuto;
        if(x->anio>2000 && x->anio<2005)
        {
            auxReturn = 1;
        }
    }
    return auxReturn;
}

int filtrarPrecio(void* unAuto)
{
    int auxReturn = 0;
    eAuto* x;
    if(unAuto!=NULL)
    {
        x = (eAuto*) unAuto;
        if(x->precio>35000 && x->precio<43000)
        {
            auxReturn = 1;
        }
    }
    return auxReturn;
}

int menuFiltro()
{
    int op;
    system("cls");
    printf("*****Filtros*****\n\n");
    printf("1. Guardar archivo por marca(Ford)\n");
    printf("2. Guardar archivo por anio(2000-2005)\n");
    printf("3. Guardat archivo por color(Pink)\n");
    printf("4. Guardar archivo por precio(35000-43000)\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    return op;
}

int subMenu()
{
    int op;
    printf("\n1- Marca\n");
    printf("2- Anio\n");
    printf("3- Color\n");
    printf("4- Precio\n\n");
    printf("Que desea modificar? ");
    scanf("%d", &op);
    return op;
}

