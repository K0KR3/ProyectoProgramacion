/**
 * @brief It defines the object module interface
 *
 * @file object.h
 * @author Jorge Cáceres 
 * @version 0
 * @date 09-02-2026
 * @copyright GNU Public License
 */
#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Object
{
    Id id;
    char name[WORD_SIZE + 1];
};

Object* object_create(Id id){
    Object *object = NULL;
    if (id == NO_ID) return NULL;

    object = (Object*)calloc(1, sizeof(Object));
    if(object == NULL) {
        return NULL;
    }

    object->id = id;
    object->name[0] = '\0';

    return object;
}

Status object_destroy(Object* object){
    if (!object) {
    return ERROR;
  }

  free(object);
  return OK;
}

Id object_get_id(Object* object){
     if (!object) {
    return NO_ID;
  }
  return object->id;
}

Status object_set_name(Object* object, char* name){
    if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* object_get_name(Object* object){
     if (!object) {
    return NULL;
  }
  return object->name;
}

Status object_print(Object* object) {
    if (!object) {
        return ERROR;
    }

    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n",
            object->id,
            (object->name[0] != '\0') ? object->name : "<no name set>");


    return OK;
}
