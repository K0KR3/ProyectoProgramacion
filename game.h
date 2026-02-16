/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"

#define MAX_SPACES 100

typedef struct _Game {
  Player *player;            
  Object *object;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Command *last_cmd;
  Bool finished;
} Game;

/* Declaración de funciones públicas*/
/** 
 * @brief Crea el juego
 * 
 * @param game Puntero al juego
 * @return OK si todo va bien o ERROR si game es NULL
 */
Status game_create(Game *game);

/**
 * @brief Crea el juego desde un fichero
 * 
 * @param game Puntero al juego 
 * @param filename archivo de texto
 * @return OK si todo va bien o ERROR si game es NULL
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief Destruye el juego en caso de error 
 * 
 * @param game Puntero al juego
 * @return OK si todo va bien o ERROR si game es NULL 
 */
Status game_destroy(Game *game);

/**
 * @brief Obtiene el espacio
 * 
 * @param game Puntero al juego 
 * @param id Identificador 
 * @return Puntero al Space con ese id, o NULL si hay error
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief Obtener la localizacion del jugador
 * 
 * @param game Puntero al juego
 * @return Identificador del jugador
 */
Id game_get_player_location(Game *game);

/**
 * @brief Establece la localización del jugador
 * 
 * @param game Puntero al juego
 * @param id del jugador
 * @return OK si todo va bien o ERROR si game es NULL
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief Obtienes la localización del juagdor
 * 
 * @param game Puntero al juego
 * @return Identificador de la localizacion del objeto
 */
Id game_get_object_location(Game *game);

/**
 * @brief Establece la localización del objeto
 * 
 * @param game Puntero al juego
 * @param id del objeto
 * @return OK si todo va bien o NULL si hay error
 */
Status game_set_object_location(Game *game, Id id);

/**
 * @brief Obtiene el ultimo comando
 * 
 * @param game 
 * @return Command* o NULL si hay error
 */
Command* game_get_last_command(Game *game);

/**
 * @brief Establece el ultimo comando
 * 
 * @param game Puntero al juego
 * @param command Comando
 * @return OK si todo va bien o NULL si hay error
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief Indica si el juego ha terminado
 * 
 * @param game Puntero al juego
 * @return TRUE si ha terminado o FALSE si no ha terminado 
 */
Bool game_get_finished(Game *game);
/**
 * @brief Establece si el juego ha terminado
 * 
 * @param game 
 * @param finished 
 * @return OK si todo va bien o NULL si hay error 
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief Imprime el estado del jugador
 * 
 * @param game Puntero al juego
 */
void game_print(Game *game);

/**
 * @brief Añade un espacio al juego
 * 
 * @param game Puntero al juego
 * @param space Puntero al espacio
 * @return OK si todo va bien o NULL si hay error 
 */
Status game_add_space(Game *game, Space *space);

#endif
