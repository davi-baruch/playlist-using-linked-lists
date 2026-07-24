#ifndef MUSIC_H
#define MUSIC_H

#include "playlist.h"

// Structs
typedef struct Music{
    int id;
    char title[50];
    char artist[50];
    int duration;
    struct Music *prox;
    struct Music *ant;

} Music;

// Functions prototypes for music
Music *create_music(int id, const char *title, const char *artist, int duration);
Music *play_current_music(Playlist *playlist1);
Music *play_next_music(Playlist *playlist1);
Music *play_previous_music(Playlist *playlist1);
Music *move_music(Playlist *playlist1, Music *music1, int new_position);
Music *search_music(Playlist *playlist1, int position);

#endif