#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "music.h"

Music *create_music(int id, const char *title, const char *artist, int duration){
    Music *music1 = (Music*)malloc(sizeof(Music));
    
    if (music1 == NULL){
        printf("Error creating music\n");
        return NULL;
    }

    music1->id = id;
    music1->duration = duration;
    strncpy(music1->title, title, 50);
    strncpy(music1->artist, artist, 50);

    music1->prox = NULL;
    music1->ant = NULL;

    printf("Music created\n");

    return music1;
    
}

Music *play_current_music(Playlist *playlist1){
    // se a playlist estiver vazia
    if(playlist1->current_music == NULL){
        printf("Empty playlist\n");
        return NULL;
    }
    else{
        return playlist1->current_music;
    }
}

Music *play_next_music(Playlist *playlist1){
    // se a playlist estiver vazia
    if(playlist1->current_music == NULL){
        printf("Empty playlist\n");
        return NULL;
    }
    // se a música atual for a última
    else if(playlist1->current_music->prox == NULL){
        playlist1->current_music = playlist1->head;
    }
    else{
        playlist1->current_music = playlist1->current_music->prox;
    }

    return playlist1->current_music;
}

Music *play_previous_music(Playlist *playlist1){
    // se a playlist estiver vazia
    if(playlist1->current_music == NULL){
        printf("Empty playlist\n");
        return NULL;
    }
    // se a música atual for a primeira
    else if(playlist1->current_music == playlist1->head){
        playlist1->current_music = playlist1->tail;
    }
    else{
        playlist1->current_music = playlist1->current_music->ant;
    }

    return playlist1->current_music;
}

Music *search_music(Playlist *playlist1, int position){
    if(playlist1 == NULL || position < 1){
        printf("Invalid position\n");
        return NULL;
    }

    Music *current_music = playlist1->head;
    int current_position = 1;

    while(current_music != NULL){
        if(current_position == position){
            return current_music;
        }
        else{
            current_music = current_music->prox;
            current_position++;
        }
    }

    printf("Couldn't find this position\n");

    return NULL;
}

Music *move_music(Playlist *playlist1, Music *music1, int new_position){
    if(playlist1 == NULL || music1 == NULL || new_position < 1){
        printf("Invalid position\n");
        return NULL;
    }

    Music *destination_music = search_music(playlist1, new_position);

    if(destination_music == NULL){
        printf("couldn't find this position\n");
        return NULL;
    }
    else if(destination_music == music1){
        printf("Music is already in this position\n");
        return NULL;
    }
    else{
        // se a música a ser removida for a primeira da playlist
        if(music1 == playlist1->head){
            playlist1->head = music1->prox;

            // se a primeira música não for a única da playlist
            if(playlist1->head != NULL){
                playlist1->head->ant = NULL;
            }
            // se a primeira música for a única música da playlist
            else{
                playlist1->tail = NULL;
            }
        }

        // se a música a ser removida for a última da playlist
        else if(music1 == playlist1->tail){
            playlist1->tail = music1->ant;
            if(playlist1->tail != NULL){
                playlist1->tail->prox = NULL;
            }
        }

        // se a música a ser removida estiver no meio da playlist
        else{
            music1->ant->prox = music1->prox;
            music1->prox->ant = music1->ant;
        }
    }

    // Inserindo a música na nova posição
    if(new_position == 1){
        playlist1->head = music1;
        music1->prox = destination_music;
        music1->ant = NULL;
        destination_music->ant = music1;
    }
    // se a nova posição for tail
    else if(destination_music == playlist1->tail){
        playlist1->tail = music1;
        music1->ant = destination_music;
        music1->prox = NULL;
        destination_music->prox = music1;
    }
    else{
        music1->prox = destination_music;
        music1->ant = destination_music->ant;
        destination_music->ant->prox = music1;
        destination_music->ant = music1;
    }

    return music1;
}