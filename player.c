/**
 * @brief Implementa el player
 *
 * @file player.c
 * @author Sergio
 * @version 0
 * @date 08-02-2026
 * @copyright GNU Public License
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Player {
    Id id;                    /* identificador del jugador */
    char name[WORD_SIZE + 1]; /* nombre del jugador */
    Id location;              /* id del espacio donde está */
    Id object;                /* id del objeto que lleva */
};

Player *player_create(Id id) {
    Player *ply = NULL;

    if (id == NO_ID) {
        return NULL;
    }

    ply = (Player *)calloc(1, sizeof(Player));
    if (!ply) {
        return NULL;
    }

    ply->id = id;
    ply->name[0] = '\0';
    ply->location = NO_ID;
    ply->object = NO_ID;

    return ply;
}

Status player_destroy(Player *player) {
    if (player == NULL) {
        return ERROR;
    }

    free(player);
    return OK;
}

Id player_get_id(Player *player) {
    if (player == NULL) {
        return NO_ID;
    }

    return player->id;
}

Status player_set_name(Player *player, const char *name) {
    if (player == NULL || name == NULL) {
        return ERROR;
    }

    strcpy(player->name, name);
    player->name[WORD_SIZE] = '\0';

    return OK;
}

const char *player_get_name(Player *player) {
    if (player == NULL) {
        return NULL;
    }

    return player->name;
}

Status player_set_location(Player *player, Id id) {
    if (player == NULL || id == NO_ID) {
        return ERROR;
    }

    player->location = id;
    return OK;
}

Id player_get_location(Player *player) {
    if (player == NULL) {
        return NO_ID;
    }

    return player->location;
}

Status player_set_object(Player *player, Id id) {
    if (player == NULL) {
        return ERROR;
    }

    player->object = id;
    return OK;
}

Id player_get_object(Player *player) {
    if (player == NULL) {
        return NO_ID;
    }

    return player->object;
}

Status player_print(Player *player) {
    if (player == NULL) {
        return ERROR;
    }

    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", (long)player->id, player->name);

    if (player->location != NO_ID) {
        fprintf(stdout, "--> Location: %ld.\n", (long)player->location);
    } else {
        fprintf(stdout, "--> No location\n");
    }

    if (player->object != NO_ID) {
        fprintf(stdout, "--> Object: %ld.\n", (long)player->object);
    } else {
        fprintf(stdout, "--> No object\n");
    }

    return OK;
}
