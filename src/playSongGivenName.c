#include "../include/givenA3.h"

/* Function to search for a song by its name (case-insensitive) in the playlist.
   It recursively traverses the linked list until a matching song is found. */
int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]){
    // If the current node is NULL, the end of the playlist has been reached without a match.
    if (headLL == NULL){
        return -1;
    }

    // Use case-insensitive comparison to check if the current song's name matches the provided name.
    if (strcasecmp(headLL->songName, givenSongName) == 0){
        // Print the song's ID.
        printf("ID: %d\n", headLL->songId);
        // Print the song's name.
        printf("Song Name: %s\n", headLL->songName);
        // Indicate that the following output will be the song's notes.
        printf("Notes:\n");
        // Loop through the array of 21 song notes.
        for (int i = 0; i < 21; i++) {
            // Print the current note.
            printf("%s", headLL->songNotes[i]);
            // Print a period as a separator between notes, except after the last note.
            if (i != 20){
                printf(".");
            }
        }
        // End the note list with a newline.
        printf("\n");
        // Return 1 to indicate the song was found and its details printed.
        return 1;
    }

    // If no match is found and this is the last song, return -1.
    if (headLL->nextSong == NULL){
        return -1;
    }

    // Recursively search in the next node of the playlist.
    return playSongGivenName(headLL->nextSong, givenSongName);
}