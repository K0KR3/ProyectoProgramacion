/**
 * @brief Define la interfaz del módulo Player
 *
 * @file player.h
 * @author Sergio
 * @version 0
 * @date 08-02-2026
 * @copyright
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/**
 * @brief Tipo de dato Player
 *
 *  Estructura: sus campos se definen en player.c
 */
typedef struct _Player Player;

/**
 * @brief Crea un nuevo jugador
 *
 * Reserva memoria para un jugador e inicializa sus campos.
 *
 * @param id Identificador del nuevo jugador
 * @return Puntero al nuevo jugador o NULL si hay error
 */
Player *player_create(Id id);

/**
 * @brief Destruye un jugador
 *
 * Libera la memoria reservada para el jugador.
 *
 * @param player Puntero al jugador a destruir
 * @return OK si todo fue bien, ERROR en caso contrario
 */
Status player_destroy(Player *player);

/**
 * @brief Devuelve el id de un jugador
 *
 * @param player Puntero al jugador
 * @return Id del jugador o NO_ID si hay error
 */
Id player_get_id(Player *player);

/**
 * @brief Establece el nombre de un jugador
 *
 * @param player Puntero al jugador
 * @param name Cadena con el nombre del jugador
 * @return OK si todo fue bien, ERROR en caso contrario
 */
Status player_set_name(Player *player, char *name);

/**
 * @brief Devuelve el nombre de un jugador
 *
 * @param player Puntero al jugador
 * @return Cadena con el nombre o NULL si hay error
 */
const char *player_get_name(Player *player);

/**
 * @brief Establece la localización de un jugador
 *
 * La localización es el id del espacio (Space) donde se encuentra.
 *
 * @param player Puntero al jugador
 * @param id Id del espacio donde estará el jugador
 * @return OK si todo fue bien, ERROR en caso contrario
 */
Status player_set_location(Player *player, Id id);

/**
 * @brief Devuelve la localización de un jugador
 *
 * @param player Puntero al jugador
 * @return Id del espacio donde está o NO_ID si hay error
 */
Id player_get_location(Player *player);

/**
 * @brief Establece el objeto que porta el jugador
 *
 * @param player Puntero al jugador
 * @param id Id del objeto a portar (o NO_ID)
 * @return OK si todo fue bien, ERROR en caso contrario
 */
Status player_set_object(Player *player, Id id);

/**
 * @brief Devuelve el objeto que porta el jugador
 *
 * @param player Puntero al jugador
 * @return Id del objeto portado o NO_ID si hay error
 */
Id player_get_object(Player *player);

/**
 * @brief Muestra la información del jugador
 *
 * @param player Puntero al jugador
 * @return OK si todo fue bien, ERROR en caso contrario
 */
Status player_print(Player *player);

#endif