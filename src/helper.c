#include "../include/givenA3.h" 
#include "../include/helper.h"

/* Function to add a song node to the end of the playlist (linked list). */
void addToEnd(A3Song **headLL, A3Song **temp){
    // If the current node's nextSong is NULL, we are at the end of the list.
    if ((**headLL).nextSong == NULL){
        // Set the new node's nextSong to NULL as it will be the new last node.
        (**temp).nextSong = NULL;
        // Link the current node to the new node.
        (**headLL).nextSong = *temp;
        return;
    }

    // Otherwise, recursively call addToEnd on the next node.
    addToEnd(&(**headLL).nextSong, temp);
}

/* Function to check for duplicate song IDs in the linked list. */
int duplicateID(A3Song* headLL, int id){
    // If the current node's songId matches the given id, a duplicate is found.
    if (headLL->songId == id) return -1;
    
    // If we've reached the end of the list without finding a duplicate, return 1.
    if (headLL->nextSong == NULL) return 1;

    // Recursively check the next node in the list.
    return duplicateID(headLL->nextSong, id);
}

/* Function to check if a given note is valid by comparing it to a list of predefined musical notes. */
int findNote(char whichNote[4]){
    // Array of valid musical notes.
    char notes[7][4] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
    int note = 0;

    // Iterate over the list of valid notes.
    for (int i = 0; i < 7; i++){
        // Compare the given note with each valid note.
        if (strcmp(whichNote, notes[i]) == 0) note = 1;
    }

    // Return the flag indicating whether the note was found.
    return note;
}
