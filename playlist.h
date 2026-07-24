#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "music.h"

// Structs
typedef struct Playlist{
    Music *head;
    Music *tail;
    Music *current_music;
    int total;

} Playlist;

// Functions prototypes for playlist
Playlist *create_playlist();
void print_playlist(Playlist *playlist1);
int playlist_duration(Playlist *playlist1);
void play_music(Playlist *playlist1);
void insert_music(Playlist *playlist1, Music *music1);
void remove_music(Playlist *playlist1, Music *music1);

#endif