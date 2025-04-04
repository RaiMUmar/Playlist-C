#include "../include/givenA3.h" 

/* Function to search for a song in the playlist by its songId and print its details.
   It traverses the linked list recursively until the song is found. */
int playSongGivenId(A3Song *headLL, int givenSongId){
    // Base case: if the playlist is empty, return -1 (song not found)
    if (headLL == NULL){
        return -1;
    }
    
    // Check if the current song's ID matches the given songId
    if (headLL->songId == givenSongId){
        // Print the song's ID
        printf("ID: %d\n", headLL->songId);
        // Print the song's name
        printf("Song Name: %s\n", headLL->songName);
        // Indicate the start of the song's notes output
        printf("Notes:\n");
        // Loop through all 21 notes of the song
        for (int i = 0; i < 21; i++) {
            // Print the current note
            printf("%s", headLL->songNotes[i]);
            // Print a period separator between notes, except after the last note
            if (i != 20){
                printf(".");
            }
        }
        // End the note display with a newline
        printf("\n");
        // Return 1 to indicate the song was found and played successfully
        return 1;
    }

    // If this is the last song in the list and it doesn't match, return -1 (song not found)
    if (headLL->nextSong == NULL){
        return -1;
    }
    
    // Recursively search the next node in the playlist
    return playSongGivenId(headLL->nextSong, givenSongId);
}
