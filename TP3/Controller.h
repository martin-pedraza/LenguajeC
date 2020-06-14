int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int subMenu();
int ordenar();
int proximoId();
int ordenId(void* emp1, void* emp2);
int ordenHoras(void* emp1, void* emp2);
int ordenSueldos(void* emp1, void* emp2);
int ordenNombres(void* emp1, void* emp2);
int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

