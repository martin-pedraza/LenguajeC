#include "LinkedList.h"
#include "funcion.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int anio;
    char color[20];
    float precio;
} eAuto;

#endif // AUTO_H_INCLUDED

eAuto* car_new();
/** \brief Crea un struct con sus parametros vacios
 *
 * \return struct Retorna  (NULL) Error: si el puntero es NULL
                                (puntero) Si ok
 *
 */

eAuto* car_newParam(char* id, char* marca, char* anio, char* color, char* precio);
/** \brief Crea un struct con sus parametros inicializados
 *
 * \param char con id
 * \param char con marca
 * \param char con anio
 * \param char con color
 * \param char con precio
 * \return struct Retorna  (NULL) Error: si el puntero es NULL
                                (puntero) Si ok
 *
 */

int car_mostrar(eAuto* unAuto);
/** \brief Muestra parametros de un struct
 *
 * \param struct a analizae
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_lista(LinkedList* lista);
/** \brief Muestra una lista de los struct del linkedlist
 *
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_setMarca(eAuto* this, char* marca);
/** \brief Valida e inicializa los valores de struct
 *
 * \param struct
 * \param char con marca
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_setAnio(eAuto* this, int anio);
/** \brief Valida e inicializa los valores de struct
 *
 * \param struct
 * \param int con anio
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_setColor(eAuto* this, char* color);
/** \brief Valida e inicializa los valores de struct
 *
 * \param struct
 * \param char con color
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_setPrecio(eAuto* this, float precio);
/** \brief Valida e inicializa los valores de struct
 *
 * \param struct
 * \param float con precio
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_alta(LinkedList* lista);
/** \brief Se agrega struct en linkedlist
 *
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_baja(LinkedList* lista);
/** \brief Se quita struct en linkedlist
 *
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int car_modificar(LinkedList* lista);
/** \brief Se modifica struct en linkedlist
 *
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int proximoId();
/** \brief Llama a otra funcion para obtener ID
 *
 * \return int con ID
 *
 */
