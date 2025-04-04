#include "../include/givenA3.h" 
#include "../include/helper.h"

/* Function to count the occurrences of a specific musical note in a given song,
 identified by its songId in the linked list (playlist) */
int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]){
    // If the playlist is empty, return -1 to indicate the song was not found
    if (headLL == NULL){
        return -1;
    }
    // Remove trailing newline character, if present
    if (whichNote[strlen(whichNote) - 1] == '\n'){
        whichNote[strlen(whichNote) - 1] = '\0';
    }

    // Validate the provided note using findNote; if it returns 0, the note is invalid, so return -1
    if (findNote(whichNote) == 0) return -1;
    
    // Check if the current song's ID matches the given song ID
    if (headLL->songId == givenSongId){
        int count = 0;
        char finalNote[100];
        // Loop through all 21 notes of the song
        for (int i = 0; i < 21; i++){
            // Special handling for the 21st note (index 20)
            if (i == 20){
                // Copy the note into finalNote
                strcpy(finalNote, headLL->songNotes[i]);
                // Truncate finalNote to the length of whichNote for a proper comparison
                finalNote[strlen(whichNote)] = '\0';
                // Compare the truncated note with whichNote; if they match, increment the count
                if (strcmp(whichNote, finalNote) == 0){
                    count++;
                }
            } else {
                // For other notes, compare directly with whichNote
                if (strcmp(whichNote, headLL->songNotes[i]) == 0){
                    count++;
                }
            }
        }
        // Return the total count of occurrences of the note in the song
        return count;
    }

    // If the current song does not match and there is no next song, return -1 indicating not found
    if (headLL->nextSong == NULL){
        return -1;
    }
    
    // Recursively check the next song in the playlist for the given song ID
    return countNotesInASong(headLL->nextSong, givenSongId, whichNote);
}
