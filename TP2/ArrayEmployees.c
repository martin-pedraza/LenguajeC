#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


int initEmployees(Employee list[], int len)
{
    int flag = -1;
    for(int i = 0; i<len; i++)
    {
        list[i].isEmpty = 1;
        flag=0;
    }
    return flag;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int flag = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            list[i].id = id;
            strncpy(list[i].name, name, 51);
            strncpy(list[i].lastName, lastName, 51);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            flag = 0;
            break;
        }
    }
    return flag;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int flag = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty==0)
        {
            flag = i;
        }
    }
    return flag;
}

int removeEmployee(Employee list[], int len, int id)
{
    int indice = findEmployeeById(list, len,id);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
        list[indice].isEmpty = 1;
        return 0;
    }
}

int sortEmployees(Employee list[], int len, int order)
{
    Employee aux;
    int flag = -1;
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].sector>list[j].sector && list[i].isEmpty==0 && order==1)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            if(list[i].sector<list[j].sector && list[i].isEmpty==0 && order==0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            if(list[i].sector==list[j].sector && strcmp(strlwr(list[i].lastName), strlwr(list[j].lastName))>0 && list[i].isEmpty==0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            flag=0;
        }
    }
    return flag;
}

int printEmployees(Employee list[], int length)
{
    int flag = -1;
    system("cls");
    printf("*****LISTADO DE EMPLEADO*****\n\n");
    printf(" id      apellido        nombre     salario  sector\n\n");
    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("%d    %10s    %10s    %5.2f    %d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
            flag = 0;
        }
    }
    return flag;
}
