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
    Id object;                /* id del objeto que lleva (o NO_ID) */
};

Player *player_create(Id id){

    if(id == NO_ID){
        return NULL;
    }

    Player *ply= NULL;

    //Libero memoria para un nuevo jugador
    ply =(Player*)calloc(1, sizeof(Player));
    if(!ply){
        return NULL;
    }

    //Inicializo los campos
    ply->id = id;
    ply->name[0] = '\0';
    ply->location = NO_ID;
    ply->object = NO_ID;

     return ply;
}

Status player_destroy(Player *player){

    if(player == NULL){
        return ERROR;
    }

    free(player);

    return OK;

}

Id player_get_id(Player *player){

    if(player == NULL){
        return NO_ID;
    }

    return player->id;
}

Status player_set_name(Player *player, char *name){

    if(player == NULL || name == NULL){
        return ERROR;
    }

    if(!strcpy(player->name, name)){
        return ERROR;
    }

}

const char *player_get_name(Player *player){

    if(player == NULL){
        return NULL;
    }

    return player->name;
}

Status player_set_location(Player *player, Id id){

    if(player == NULL || id == NO_ID){
        return ERROR;
    }

    player->location = id;

    return OK;
}

Id player_get_location(Player *player){

    if(player == NULL){
        return NO_ID;
    }

    return player->location;
}

Status player_set_object(Player *player, Id id){

    if(player == NULL){
        return ERROR;
    }

    player->object = id;
    return OK;
}

Id player_get_object(Player *player){

    if(player == NULL){
        return NO_ID;
    }

    return player->object;
}

Status player_print(Player *player){

    if(player == NULL){
        return ERROR;
    }

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", player->id, player->name);
    if(player->location != NO_ID){
        fprintf(stdout, "--> Location: %ld. \n", player->location);
    }
    else{
        fprintf(stdout, "No location");
    }

    if(player->object != NO_ID){
        fprintf(stdout, "--> Object: %ld. \n", player->object);
    }
    else{
        fprintf(stdout, "--> No object");
    }

    return OK;

}

