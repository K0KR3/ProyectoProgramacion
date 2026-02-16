/**
 * @brief Implementa el modulo player
 *
 * @file player.c
 * @author Sergio
 * @version 0
 * @date 04-02-26
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Defino una estructura privada*/
struct _Player {
    Id id;                    /*!< Identificador del jugador */
    Id location;              /*!< Identificador de la ubicación del jugador */
    Id object;                /*!< Identificador del objeto que porta (si lo hay) */
};

Player* player_create(Id id) {
    Player *newPlayer = NULL;

    if (id == NO_ID) {
        return NULL;
    }

    newPlayer = (Player *) calloc(1, sizeof(Player));
    if (newPlayer == NULL) {
        return NULL;
    }

    /* Inicialización de variables */
    newPlayer->id = id;
    newPlayer->location = NO_ID;
    newPlayer->object = NO_ID;

    return newPlayer;
}

Status player_destroy(Player* player) {
    if (!player) {
        return ERROR;
    }

    free(player);
    return OK;
}

Id player_get_id(Player* player) {
    if (!player) {
        return NO_ID;
    }
    return player->id;
}

Status player_set_location(Player *player, Id location) {
    if (!player || location == NO_ID) {
        return ERROR;
    }
    player->location = location;
    return OK;
}

Id player_get_location(Player *player) {
    if (!player) {
        return NO_ID;
    }
    return player->location;
}

Status player_set_object(Player* player, Id id) {
    if (!player) {
        return ERROR;
    }
    player->object = id;
    return OK;
}

Id player_get_object(Player* player) {
    if (!player) {
        return NO_ID;
    }
    return player->object;
}

Status player_print(Player *player) {

    if (!player) {
        return ERROR;
    }
    
    fprintf(stdout, "---> Location: %ld\n", player->location);
    fprintf(stdout, "---> Object: %ld\n", player->object);

    return OK;
}
