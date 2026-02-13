/**
 * @brief It defines the game interface
 *
 * @file game_reader.c
 * @author Jorge Cáceres
 * @version 0
 * @date 3-01-2026
 * @copyright GNU Public License
 */


#ifndef GAME_READER_H
#define GAME_READER_H

#include "types.h"

/**
 * @brief Carga los espacios desde un archivo en el juego
 * @param game Puntero al juego ya inicializado
 * @param filename Nombre del fichero de datos
 * @return OK si todo va bien, ERROR si falla
 */
Status game_reader_load_spaces(Game *game, char *filename);

Status game_create_from_file(Game *game, char *filename);

#endif