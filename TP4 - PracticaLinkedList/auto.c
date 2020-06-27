#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "auto.h"
#include "LinkedList.h"
#include "funcion.h"

static int obtenerId();

eAuto* car_new()
{
    eAuto* newCar;
    newCar = (eAuto*) malloc(sizeof(eAuto));
    if(newCar!=NULL)
    {
        newCar->id=0;
        strcpy(newCar->marca, "");
        newCar->anio = 0;
        strcpy(newCar->color, "");
        newCar->precio = 0;
    }
    return newCar;
}

eAuto* car_newParam(char* id, char* marca, char* anio, char* color, char* precio)
{
    eAuto* newCar;
    newCar = car_new();
    if(newCar!=NULL)
    {
        newCar->id = atoi(id);
        strcpy(newCar->marca, marca);
        newCar->anio = atoi(anio);
        strcpy(newCar->color, color);
        newCar->precio = atof(precio);
    }
    return newCar;
}

int car_mostrar(eAuto* unAuto)
{
    int error = 1;
    if(unAuto!=NULL)
    {
        printf(" %d  %10s    %d   %10s    %.2f\n", unAuto->id, unAuto->marca, unAuto->anio, unAuto->color, unAuto->precio);
        error=0;
    }
    return error;
}

int car_lista(LinkedList* lista)
{
    int error = 1;
    int tam = ll_len(lista);
    eAuto* auxCar;
    system("cls");
    printf(" Id        Marca  Anio         Color  Precio\n");
    if(lista!=NULL && tam)
    {
        error=0;
        for(int i=0; i<tam; i++)
        {
            auxCar = (eAuto*) ll_get(lista, i);
            if(auxCar != NULL)
            {
                car_mostrar(auxCar);
            }
        }
    }
    else
    {
        printf("No hay autos que mostrar\n\n");
    }
    return error;
}


int car_alta(LinkedList* lista)
{
    int error=1;
    char marca[20];
    int anio;
    char color[20];
    float precio;
    int id = obtenerId();
    eAuto* car = car_new();
    car->id=id;
    system("cls");
    printf("*****ALTA AUTO*****\n\n");
    do
    {
        printf("Ingrese marca: ");
        fflush(stdin);
        gets(marca);
    }
    while(car_setMarca(car, marca));
    do
    {
        printf("Ingrese anio(1990-2010): ");
        scanf("%d", &anio);
    }
    while(car_setAnio(car, anio));
    do
    {
        printf("Ingrese color: ");
        fflush(stdin);
        gets(color);
    }
    while(car_setColor(car, color));
    do
    {
        printf("Ingrese precio(0-50000): ");
        scanf("%f", &precio);
    }
    while(car_setPrecio(car, precio));
    if(!ll_add(lista, car))
    {
        error=0;
    };
    return error;
}

static int obtenerId()
{
    static int id = 50;
    id++;
    return id;
}

int proximoId()
{
    return obtenerId();
}

int car_setMarca(eAuto* this, char* marca)
{
    int error=1;
    eAuto* aux = this;
    if(strlen(marca)>=3 && strlen(marca)<20)
    {
        strcpy(aux->marca, marca);
        error=0;
    }
    return error;
}

int car_setAnio(eAuto* this, int anio)
{
    int error=1;
    eAuto* aux = this;
    if(anio>=1990 && anio<=2010)
    {
        aux->anio = anio;
        error=0;
    }
    return error;
}

int car_setColor(eAuto* this, char* color)
{
    int error=1;
    eAuto* aux = this;
    if(strlen(color)>=3 && strlen(color)<20)
    {
        strcpy(aux->color, color);
        error=0;
    }
    return error;
}

int car_setPrecio(eAuto* this, float precio)
{
    int error=1;
    eAuto* aux = this;
    if(precio>=0 && precio<=50000)
    {
        aux->precio = precio;
        error=0;
    }
    return error;
}

int car_baja(LinkedList* lista)
{
    int error = 1;
    int id;
    int seguro;
    eAuto* auxCar;
    int indice=-1;
    int tam = ll_len(lista);
    if(!car_lista(lista))
    {
        do
        {
            printf("Ingrese id: ");
            scanf("%d", &id);

            for(int i=0; i<tam; i++)
            {
                auxCar = (eAuto*) ll_get(lista, i);
                if(auxCar->id==id)
                {
                    indice = ll_indexOf(lista, auxCar);
                    break;
                }
            }
        }
        while(indice==-1);
        car_mostrar(auxCar);
        printf("Esta seguro de eliminar? 1-SI 2-NO \n");
        scanf("%d", &seguro);
        if(seguro==1)
        {
            error=0;
            ll_remove(lista, indice);
        }
    }
    return error;
}

int car_modificar(LinkedList* lista)
{
    int error = 1;
    int id;
    int seguro;
    char marca[20];
    int anio;
    char color[20];
    float precio;
    eAuto* auxCar;
    int indice=-1;
    int tam = ll_len(lista);
    if(!car_lista(lista))
    {
        do
        {
            printf("Ingrese id: ");
            scanf("%d", &id);

            for(int i=0; i<tam; i++)
            {
                auxCar = (eAuto*) ll_get(lista, i);
                if(auxCar->id==id)
                {
                    indice = ll_indexOf(lista, auxCar);
                    break;
                }
            }
        }
        while(indice==-1);
        car_mostrar(auxCar);
        printf("Esta seguro de modificar? 1-SI 2-NO\n");
        scanf("%d", &seguro);
        if(seguro==1)
        {
            error=0;
            switch(subMenu())
            {
            case 1:
                do
                {
                    printf("Ingrese marca: ");
                    fflush(stdin);
                    gets(marca);
                }
                while(car_setMarca(auxCar, marca));
                break;
            case 2:
                do
                {
                    printf("Ingrese anio: ");
                    scanf("%d", &anio);
                }
                while(car_setAnio(auxCar, anio));
                break;
            case 3:
                do
                {
                    printf("Ingrese color: ");
                    fflush(stdin);
                    gets(color);
                }
                while(car_setColor(auxCar, color));
                break;
            case 4:
                do
                {
                    printf("Ingrese precio: ");
                    scanf("%f", &precio);
                }
                while(car_setPrecio(auxCar, precio));
                break;
            default:
                printf("Opcion no valida\n\n");
                error=1;
            }
        }
    }
    return error;
}
