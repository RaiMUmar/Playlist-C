#include "../include/givenA3.h" 

/* Function to play (display) the entire playlist.
   It prints the song details for each song in the linked list recursively. */
void playPlayList(A3Song *headLL){
    // Base case: if the current node is NULL, there are no more songs to display.
    if (headLL == NULL) {
        return;
    }
    
    // Print the song's unique identifier.
    printf("ID: %d\n", headLL->songId);
    // Print the song's name.
    printf("Song Name: %s\n", headLL->songName);
    // Indicate that the following output will list the song's notes.
    printf("Notes:\n");
    // Loop through all 21 notes of the song.
    for (int i = 0; i < 21; i++) {
        // Print the current note.
        printf("%s", headLL->songNotes[i]);
        // Print a period between notes, except after the last note.
        if (i != 20){
            printf(".");
        }
    }
    // Move to a new line after printing all notes.
    printf("\n");
    // Recursively call playPlayList for the next song in the playlist.
    playPlayList(headLL->nextSong);
}
