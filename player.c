/**
 * @brief Implementa el modulo player
 *
 * @file player.c
 * @author Sergio
 * @version 0
 * @date 12-02-26
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Player {
    Id id;        /* id del jugador */
    Id location;  /* id de la localizacion del jugador */
};

Player* player_create(Id id) {

    if (id == NO_ID) {
        return NULL;
    }

    Player *ply = NULL;

    ply = (Player *)calloc(1, sizeof(Player));
    if (!ply) {
        return NULL;
    }

    /* Inicializo la id jugador y localizacion */
    ply->id = id;
    ply->location = NO_ID;

    return ply;
}

Status player_destroy(Player* player) {

    if (player == NULL) {
        return ERROR;
    }

    free(player);

    return OK;
}

Id player_get_id(Player* player) {

    if (player == NULL) {
        return NO_ID;
    }

    return player->id;
}

Status player_set_location(Player *player, Id location) {

    if (player == NULL || location == NO_ID) {
        return ERROR;
    }

    player->location = location;

    return OK;
}

Id Player_get_location(Player *player) {

    if (player == NULL) {
        return NO_ID;
    }

    return player->location;
}

Status player_print(Player *player) {

    if (player == NULL) {
        return ERROR;
    }

    fprintf(stdout, "---> Player, Id: %ld\n", player->id);

    if (player->location != NO_ID) {
        fprintf(stdout, "---> Location, id: %ld\n", player->location);
    } else {
        fprintf(stdout, "---> Location: No hay localizacion\n");
    }

    return OK;
}
