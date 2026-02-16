/**
 * @brief Implementa la interfaz del modulo object
 * @file object.h
 * @author Jorge Cáceres 
 * @version 0
 * @date 09-02-2026
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
 * @brief Crea un objeto asignándole un identificador único.
 *
 * Reserva memoria para la estructura Object y la inicializa.
 * El nombre del objeto se establece inicialmente como NULL.
 *
 * @param id Identificador único del objeto (debe ser distinto de NO_ID).
 * @return Puntero al nuevo objeto creado o NULL en caso de error 
 *         (memoria insuficiente o id inválido).
 */
Object* object_create(Id id);

/**
 * @brief Destruye un objeto y libera toda la memoria asociada.
 *
 * Libera primero el nombre (si existe) y después la estructura principal.
 *
 * @param object Puntero al objeto que se desea destruir.
 * @return OK si se liberó correctamente, ERROR si object es NULL.
 */
Status object_destroy(Object* object);

/**
 * @brief Obtiene el identificador único del objeto.
 *
 * @param object Puntero al objeto del que se quiere consultar el id.
 * @return El identificador del objeto o NO_ID si object es NULL.
 */
Id object_get_id(Object* object);

/**
 * @brief Asigna un nombre al objeto (realiza copia interna de la cadena).
 *
 * Si el objeto ya tenía un nombre, se libera el anterior antes de asignar el nuevo.
 *
 * @param object Puntero al objeto al que se le va a asignar el nombre.
 * @param name Cadena de caracteres con el nombre (se duplicará internamente).
 * @return OK si se asignó correctamente, ERROR en caso de punteros nulos 
 *         o fallo al reservar memoria.
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief Devuelve el nombre actual del objeto.
 *
 * @param object Puntero al objeto del que se quiere obtener el nombre.
 * @return Puntero constante a la cadena del nombre o NULL si object es NULL 
 *         o si no tiene nombre asignado. La cadena NO debe ser modificada 
 *         ni liberada por el usuario.
 */
const char* object_get_name(Object* object);

/**
 * @brief Imprime por pantalla la información del objeto.
 *
 * Muestra el id y el nombre (o indica si no tiene nombre).
 *
 * @param object Puntero al objeto que se desea imprimir.
 * @return OK si se imprimió correctamente, ERROR si object es NULL.
 */
Status object_print(Object* object);

#endif