#include "../include/givenA3.h" 

/* Function to delete the entire playlist (linked list) by freeing all allocated nodes. */
void deletePlayList(A3Song **headLL){
    // Check if the pointer to the head pointer is NULL; if so, there is nothing to delete.
    if (headLL == NULL){
        return;
    }

    // Check if the current node is the only node in the list (its nextSong is NULL).
    if ((*headLL)->nextSong == NULL){
        free(*headLL); // Free the single node.
        return;
    }

    // Recursively call deletePlayList on the rest of the list starting from the next node.
    deletePlayList(&(*headLL)->nextSong);

    // After the rest of the list is deleted, free the current node.
    free(*headLL);
}

