#include "../include/givenA3.h" 
#include "../include/helper.h"

/* Function to add a new song to the playlist at the beginning or end */
bool addNewSong(A3Song **headLL, int beginOrEnd){
    // Validate that the insertion position is either 1 (beginning) or 2 (end)
    if (beginOrEnd != 1 && beginOrEnd != 2){
        printf("Invalid value passed!!\n\n");
        return false;
    }
    
    // Declare a buffer for input, an array of musical notes, and other variables
    char buffer[MAX_LENGTH], notes[7][4] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
    int len, random, skip = 0;
    // Allocate memory for a new song node
    A3Song *temp = malloc(sizeof(A3Song));
    if (temp == NULL) return false;  // Return false if memory allocation fails

    // If the playlist is empty, initialize it and set a flag to indicate this is the first song
    if (*headLL == NULL){
        skip = 1;
        *headLL = malloc(sizeof(A3Song));
        if (*headLL == NULL) return false;  // Return false if memory allocation fails
    }

    // Prompt the user to enter the song name and read it into buffer
    printf("Song Name: ");
    fgets(buffer, MAX_LENGTH, stdin);
    // Remove the trailing newline character if it exists
    if (buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }

    // Copy the entered song name into the song node's songName field
    strcpy((*temp).songName, buffer);
    // Get the length of the song name to help generate a unique song ID
    len = strlen(buffer);

    // For the first song, generate a song ID without checking for duplicates
    if (skip){
        random = rand()%1000;
        (*temp).songId = len + random; 
    }
    // For subsequent songs, generate a song ID and ensure it is not a duplicate
    if (!skip){
        do {
            random = rand()%1000;
            (*temp).songId = len + random;
        } while(duplicateID((*headLL)->nextSong, (temp)->songId) == -1);
    }
    
    // Randomly assign musical notes to the song; fill 21 entries in the songNotes array
    for (int i = 0; i < 21; i++){
        strcpy((*temp).songNotes[i], notes[rand()%7]);
    }

    // If not the first song, insert the new song node either at the beginning or the end of the playlist
    if (!skip){
        if (beginOrEnd == 1){
            // Insert at the beginning: set the new node's nextSong to current head and update headLL
            (*temp).nextSong = *headLL;
            *headLL = temp;
        }
        if (beginOrEnd == 2){
            // Insert at the end: use the addToEnd function to append the new song
            addToEnd(&(*headLL), &temp);
        }
    }

    // For the first song in the playlist, ensure nextSong is NULL and update headLL
    if (skip){
        (*temp).nextSong = NULL;
        *headLL = temp;
    }

    // Return true to indicate the song was successfully added
    return true;
}


