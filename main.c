#include "playlist.h"
#include "music.h"

int main(){
    // create a playlist, add musics and get total playlist duration
    Playlist *myplaylist = create_playlist();

    Music *music1 = create_music(1, "The Trooper", "Iron Maiden", 200);
    Music *music2 = create_music(2, "War Pigs", "Black Sabbath", 250);
    Music *music3 = create_music(3, "Like a stone", "Audioslave", 150);
    Music *music4 = create_music(4, "Something in the way", "Nirvana", 200);

    insert_music(myplaylist, music1);
    insert_music(myplaylist, music2);
    insert_music(myplaylist, music3);
    insert_music(myplaylist, music4);

    print_playlist(myplaylist);
    playlist_duration(myplaylist);

    // remove musics
    remove_music(myplaylist, music2);
    print_playlist(myplaylist);
    remove_music(myplaylist, music1);
    print_playlist(myplaylist);
    remove_music(myplaylist, music4);
    print_playlist(myplaylist);

    insert_music(myplaylist, music1);
    insert_music(myplaylist, music2);
    insert_music(myplaylist, music4);

    // play musics
    play_music(myplaylist);
    play_next_music(myplaylist);
    play_previous_music(myplaylist);

    // move musics
    move_music(myplaylist, music1, 4);
    move_music(myplaylist, music4, 1);
    move_music(myplaylist, music4, 3);
    move_music(myplaylist, music2, 3);

    print_playlist(myplaylist);

    return 0;
}