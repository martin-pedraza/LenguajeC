#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

#endif // FUNCION_H_INCLUDED

int cargarTexto(char* path, LinkedList* lista);
/** \brief carga los datos de un archivo de texto
 *
 * \param nombre del archivo
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int cargarBinario(char* path, LinkedList* lista);
/** \brief carga los datos de un archivo binario
 *
 * \param nombre del archivo
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int guardarTexto(char* path, LinkedList* lista);
/** \brief guarda los datos del linkedlist en un archivo de texto
 *
 * \param nombre del archivo
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int guardarBinario(char* path, LinkedList* lista);
/** \brief guarda los datos del linkedlist en un archivo binario
 *
 * \param nombre del archivo
 * \param linkedlist
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int menuFiltro();
/** \brief Muestra un menu de filtros
 *
 * \return la opcion elegida del menu
 *
 */

int subMenu();
/** \brief Muestra un menu para modificaciones
 *
 * \return la opcion elegida del menu
 *
 */

int filtrarMarca(void* unAuto);
/** \brief Se filtran elementos segun marca
 *
 * \param puntero a void
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int filtrarColor(void* unAuto);
/** \brief Se filtran elementos segun color
 *
 * \param puntero a void
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int filtrarAnio(void* unAuto);
/** \brief Se filtran elementos segun anio
 *
 * \param puntero a void
 * \return retorna 0 si todo OK
                1 si Error
 *
 */

int filtrarPrecio(void* unAuto);
/** \brief Se filtran elementos segun precio
 *
 * \param puntero a void
 * \return retorna 0 si todo OK
                1 si Error
 *
 */
