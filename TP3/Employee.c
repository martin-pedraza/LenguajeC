#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new(){
    Employee* newEmp;
    newEmp = (Employee*) malloc(sizeof(Employee));
    if(newEmp!=NULL)
    {
        newEmp->id=0;
        strcpy(newEmp->nombre, "");
        newEmp->horasTrabajadas = 0;
        newEmp->sueldo = 0;
    }
    return newEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* newEmp;
    newEmp = employee_new();
    if(newEmp!=NULL)
    {
        newEmp->id = atoi(idStr);
        strcpy(newEmp->nombre, nombreStr);
        newEmp->horasTrabajadas = atoi(horasTrabajadasStr);
        newEmp->sueldo = atoi(sueldoStr);
    }
    return newEmp;
}

int employee_setNombre(Employee* this,char* nombre){
    int error=1;
    Employee* aux = this;
    if(strlen(nombre)>=3 && strlen(nombre)<128){
        strcpy(aux->nombre, nombre);
        error=0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int error=1;
    Employee* aux = this;
    if(horasTrabajadas>=0 && horasTrabajadas<400){
        aux->horasTrabajadas = horasTrabajadas;
        error=0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo){
    int error=1;
    Employee* aux = this;
    if(sueldo>=0){
        aux->sueldo = sueldo;
        error=0;
    }
    return error;
}
