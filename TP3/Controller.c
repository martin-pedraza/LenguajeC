#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

static int obtenerId();

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f = fopen(path, "r");
    if(f!=NULL)
    {
        if(!parser_EmployeeFromText(f, pArrayListEmployee))
        {
            error=0;
        }
        fclose(f);
    }
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f = fopen(path, "rb");
    if(f!=NULL)
    {
        if(!parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
            error=0;
        }
        fclose(f);
    }
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int id = obtenerId();
    Employee* emp = employee_new();
    emp->id=id;
    system("cls");
    printf("*****ALTA EMPLEADO*****\n\n");
    do
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
    }
    while(employee_setNombre(emp, nombre));
    do
    {
        printf("Ingrese horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
    }
    while(employee_setHorasTrabajadas(emp, horasTrabajadas));
    do
    {
        printf("Ingrese sueldo: ");
        scanf("%d", &sueldo);
    }
    while(employee_setSueldo(emp, sueldo));

    if(ll_add(pArrayListEmployee, emp) == 0)
    {
        error=0;
    };
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;
    int id;
    int seguro;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmp;
    int indice=-1;
    int tam = ll_len(pArrayListEmployee);
    if(!controller_ListEmployee(pArrayListEmployee))
    {
        do
        {
            printf("Ingrese id: ");
            scanf("%d", &id);

            for(int i=0; i<tam; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmp->id==id)
                {
                    indice = ll_indexOf(pArrayListEmployee, auxEmp);
                    break;
                }
            }
        }
        while(indice==-1);
        printf(" %4d     %10s        %3d      %d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
    }
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
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);
            }
            while(employee_setNombre(auxEmp, nombre));
            break;
        case 2:
            do
            {
                printf("Ingrese horas trabajadas: ");
                scanf("%d", &horas);
            }
            while(employee_setHorasTrabajadas(auxEmp, horas));
            break;
        case 3:
            do
            {
                printf("Ingrese sueldo: ");
                scanf("%d", &sueldo);
            }
            while(employee_setSueldo(auxEmp, sueldo));
            break;
        default:
            printf("Opcion no valida\n\n");
            error=1;
        }
    }
    return error;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int id;
    int seguro;
    Employee* auxEmp;
    int indice=-1;
    int tam = ll_len(pArrayListEmployee);
    if(!controller_ListEmployee(pArrayListEmployee))
    {
        do
        {
            printf("Ingrese id: ");
            scanf("%d", &id);

            for(int i=0; i<tam; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmp->id==id)
                {
                    indice = ll_indexOf(pArrayListEmployee, auxEmp);
                    break;
                }
            }
        }
        while(indice==-1);
        printf(" %4d     %10s        %3d      %d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
        printf("Esta seguro de eliminar? 1-SI 2-NO");
        scanf("%d", &seguro);
        if(seguro==1)
        {
            error=0;
            ll_remove(pArrayListEmployee, indice);
        }
    }
    return error;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmp;
    system("cls");
    printf(" Id        Nombre  Horas trabajadas  Sueldo\n");
    if(pArrayListEmployee!=NULL && tam)
    {
        error=0;
        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmp != NULL)
            {
                printf(" %4d     %10s        %3d      %d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
            }
        }
    }
    else
    {
        printf("No hay empleados que mostrar\n\n");
    }

    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;
    switch(ordenar())
    {
    case 1:
        ll_sort(pArrayListEmployee, ordenId, 1);
        break;
    case 2:
        ll_sort(pArrayListEmployee, ordenNombres, 1);
        break;
    case 3:
        ll_sort(pArrayListEmployee, ordenHoras, 1);
        break;
    case 4:
        ll_sort(pArrayListEmployee, ordenSueldos, 1);
        break;
    default:
        printf("No es una opcion valida\n\n");
        error=1;
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* emp;
    int tam = ll_len(pArrayListEmployee);
    FILE* f = fopen(path, "w");
    if(f!=NULL)
    {
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<tam; i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(f, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            error=0;
        }
        fclose(f);
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f = fopen(path, "wb");
    Employee* emp;
    int tam = ll_len(pArrayListEmployee);
    if(f!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(emp, sizeof(Employee), 1, f);
            error=0;
        }
        fclose(f);
    }
    return error;
}


int subMenu()
{
    int op;
    printf("\n1- Nombre\n");
    printf("2- Horas Trabajadas\n");
    printf("3- Sueldo\n\n");
    printf("Que desea modificar? ");
    scanf("%d", &op);
    return op;
}

int ordenId(void* emp1, void* emp2)
{
    if(((Employee*)emp1)->id > ((Employee*)emp2)->id)
    {
        return 1;
    }
    if(((Employee*)emp1)->id < ((Employee*)emp2)->id)
    {
        return -1;
    }
    return 0;
}

int ordenHoras(void* emp1, void* emp2)
{
    if(((Employee*)emp1)->horasTrabajadas > ((Employee*)emp2)->horasTrabajadas)
    {
        return 1;
    }
    if(((Employee*)emp1)->horasTrabajadas < ((Employee*)emp2)->horasTrabajadas)
    {
        return -1;
    }
    return 0;
}

int ordenSueldos(void* emp1, void* emp2)
{
    if(((Employee*)emp1)->sueldo > ((Employee*)emp2)->sueldo)
    {
        return 1;
    }
    if(((Employee*)emp1)->sueldo < ((Employee*)emp2)->sueldo)
    {
        return -1;
    }
    return 0;
}

int ordenNombres(void* emp1, void* emp2)
{
    if(strcmp(((Employee*)emp1)->nombre, ((Employee*)emp2)->nombre)>0)
    {
        return 1;
    }
    if(strcmp(((Employee*)emp1)->nombre, ((Employee*)emp2)->nombre)<0)
    {
        return -1;
    }
    return 0;
}

int ordenar()
{
    int op;
    system("cls");
    printf("1- Id\n");
    printf("2- Nombre\n");
    printf("3- Horas trabajadas\n");
    printf("4- Sueldo\n\n");
    printf("Como quieres ordenar? ");
    scanf("%d", &op);
    return op;
}

static int obtenerId(){
    static int id = 1000;
    id++;
    return id;
}

int proximoId(){
    return obtenerId();
}
