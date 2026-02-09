/**
 * @brief It defines the game interface
 *
 * @file game_reader.c
 * @author Jorge C y Sergio R
 * @version 0
 * @date 3-01-2026
 * @copyright GNU Public License
 */


#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "types.h"

/**
 * @brief Carga los espacios desde un archivo en el juego
 * @param game Puntero al juego ya inicializado
 * @param filename Nombre del fichero de datos
 * @return OK si todo va bien, ERROR si falla
 */
Status game_load_spaces(Game *game, char *filename);

#endif