/**
 * @brief Implementa la interfaz del modulo player
 *
 * @author Sergio
 * @version 0
 * @date 04-02-26
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/*Declaración de funciones publicas*/
/**
 * @brief Crea un nuevo jugador inicializado.
 *
 * @param id Identificador del jugador.
 * @return Puntero al nuevo jugador o NULL si hay error.
 */
Player* player_create(Id id);

/**
 * @brief Destruye el jugador liberando memoria.
 *
 * @param player Puntero al jugador.
 * @return OK si todo va bien o ERROR si player es NULL.
 */
Status player_destroy(Player* player);

/**
 * @brief Obtiene el id del jugador.
 *
 * @param player Puntero al jugador.
 * @return Id del jugador o NO_ID si player es NULL.
 */
Id player_get_id(Player* player);

/**
 * @brief Establece la localizacion del jugador.
 *
 * @param player Puntero al jugador.
 * @param location Id del espacio donde esta el jugador.
 * @return OK si todo va bien o ERROR si hay algun fallo.
 */
Status player_set_location(Player *player, Id location);

/**
 * @brief Obtiene la localizacion del jugador.
 *
 * @param player Puntero al jugador.
 * @return Id de la localizacion o NO_ID si hay algun fallo.
 */
Id player_get_location(Player *player);

/**
 * @brief Asigna un objeto al jugador.
 *
 * @param player Puntero al jugador.
 * @param id Identificador del objeto que porta el jugador.
 * @return OK si todo va bien o ERROR si hay algun fallo.
 */
Status player_set_object(Player* player, Id id);

/**
 * @brief Obtiene el objeto que porta el jugador.
 *
 * @param player Puntero al jugador.
 * @return Id del objeto portado o NO_ID si no lleva ninguno o hay error.
 */
Id player_get_object(Player* player);

/**
 * @brief Obtiene el id de la localizacion del jugador.
 *
 * @param player Puntero al jugador.
 * @return Id de la localizacion o NO_ID si player es NULL.
 */
Id player_get_location(Player *player);

/**
 * @brief Imprime la informacion del jugador.
 *
 * @param player Puntero al jugador.
 * @return OK si todo va bien o ERROR si player es NULL.
 */
Status player_print(Player *player);

#endif /* PLAYER_H */
