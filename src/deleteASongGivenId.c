#include "../include/givenA3.h" 

/* Function to delete a song from the playlist given its unique songId.
   Returns 1 if deletion is successful, or -1 if the song is not found. */
int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    // Check if the playlist is empty.
    if (*headLL == NULL) {
        return -1;
    }
    
    // Check if the head node contains the song to be deleted.
    if ((*headLL)->songId == givenSongId) {
        // Save the current head node in a temporary pointer.
        A3Song *temp = *headLL;
        // Update the head pointer to the next song in the list.
        *headLL = (*headLL)->nextSong;
        // Free the memory allocated for the removed song node.
        free(temp);
        return 1;
    }
    
    // Initialize two pointers for traversing the list:
    // 'prev' points to the previous node, and 'current' starts at the second node.
    A3Song *prev = *headLL;
    A3Song *current = (*headLL)->nextSong;
    
    // Traverse the list to find the song with the matching songId.
    while (current != NULL && current->songId != givenSongId) {
        // Move the previous pointer to the current node.
        prev = current;
        // Advance the current pointer to the next node.
        current = current->nextSong;
    }
    
    // If the song with the given songId was not found in the list.
    if (current == NULL) {
        return -1;
    }
    
    // Delete the song found in the middle or end of the list:
    // Bypass the 'current' node by linking 'prev' directly to 'current's next node.
    prev->nextSong = current->nextSong;
    // Free the memory allocated for the 'current' node.
    free(current);
    
    // Return 1 to indicate that the deletion was successful.
    return 1;
}
