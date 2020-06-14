#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    char buffer[4][1000];
    int cant;
    Employee* auxEmp;
    ll_clear(pArrayListEmployee);
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant==4)
        {
            auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(pArrayListEmployee, auxEmp);
            error=0;
        }
    }
    return error;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* auxEmp;
    char idS[10];
    char horasS[10];
    char sueldoS[10];
    ll_clear(pArrayListEmployee);
    while(!feof(pFile))
    {
        fread(auxEmp, sizeof(Employee), 1, pFile);
        auxEmp = employee_newParametros(itoa(auxEmp->id, idS, 10), auxEmp->nombre, itoa(auxEmp->horasTrabajadas, horasS, 10), itoa(auxEmp->sueldo, sueldoS, 10));
        ll_add(pArrayListEmployee, auxEmp);
        error=0;
    }
    return error;
}
