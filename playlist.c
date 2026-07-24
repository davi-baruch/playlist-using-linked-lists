#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

// Functions
Playlist *create_playlist(){
    Playlist *playlist1 = (Playlist*)malloc(sizeof(Playlist));

    if (playlist1 == NULL){
        printf("Error creating playlist\n");
        return NULL;
    }

    playlist1->current_music = NULL;
    playlist1->tail = NULL;
    playlist1->head = NULL;
    playlist1->total = 0;

    printf("Playlist created\n");

    return playlist1;

}

void print_playlist(Playlist *playlist1){
    int i = 0;

    if(playlist1 == NULL){
        printf("Invalid playlist\n");
        return;
    }

    if(playlist1->head == NULL){
        printf("\nEmpty playlist\n");
    }

    else{
        Music *current = playlist1->head;
        printf("-------------\n");
        printf("  Playlist: \n");
        printf("-------------\n");

        while(current != NULL){
            i++;
            printf("Music #%d | Id %d, Title: %s, Artist: %s, Duration: %d\n", i, current->id, current->title, current->artist, current->duration);
            current = current->prox;
        }
    }
}

int playlist_duration(Playlist *playlist1){
    int total_duration = 0;

    Music *current = playlist1->head;

    while(current != NULL){
        total_duration += current->duration;
        current = current->prox;
    }

    return total_duration;
}

void insert_music(Playlist *playlist1, Music *music1){
    if (playlist1 == NULL || music1 == NULL) {
        printf("Invalid playlist or music\n");
        return;
    }

    if(playlist1->total == 0){
        playlist1->head = music1;
        playlist1->tail = music1;
        playlist1->current_music = music1;
    }

    else{
        playlist1->tail->prox = music1;
        music1->ant = playlist1->tail;
        playlist1->tail = music1;
    }
    playlist1->total ++;

}

void remove_music(Playlist *playlist1, Music *music1){
    if (playlist1 == NULL || music1 == NULL) {
        printf("Invalid playlist or music\n");
        return;
    }

    // se a musica a ser removida for a atual
    if(music1 == playlist1->current_music){
        // se a musica atual não for a última
        if(music1->prox != NULL){
            playlist1->current_music = music1->prox;
        }
        // se for a última
        else{
            playlist1->current_music = music1->ant;
        }
    }

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

    free(music1);

    playlist1->total --;

    printf("\nMusic removed\n");
}

void play(Playlist *playlist1){
    Music *music = play_current_music(playlist1);

    if (music == NULL){
        printf("Empty playlist\n");
    }
    else{
        printf("Playing %s by %s\n", music->title, music->artist);
    }
}