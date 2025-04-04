#include "../include/givenA3.h" 
#include "../include/helper.h"

/* Function to create a playlist by reading song data from a CSV file.
Returns the number of songs read and added to the playlist, or -1 on error. */
int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]){
    // Declare variables for generating song IDs, measuring string lengths, counting songs, and reading lines.
    int id, len, i = 0, line;
    // Buffer for reading the header or other file lines.
    char buffer[500];
    // Temporary pointer for newly allocated song nodes.
    A3Song *temp;

    // Open the CSV file for reading; return -1 if the file cannot be opened.
    FILE *fptr = fopen(fileName, "r");
    if (fptr == NULL){
        return -1;
    }

    // Read and discard the header line of the CSV file.
    fgets(buffer, 500, fptr);

    // Allocate memory for the first song node.
    *headLL = malloc(sizeof(A3Song));
    if (*headLL == NULL){
        fclose(fptr);
        return -1;
    }

    // Read the first song record from the file using a formatted fscanf.
    // The format expects the song name (up to 25 characters) and 21 song notes (each up to 4 characters).
    line = fscanf(fptr, " %25[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,]\n",
            (**headLL).songName, (**headLL).songNotes[0], (**headLL).songNotes[1], (**headLL).songNotes[2], (**headLL).songNotes[3],
            (**headLL).songNotes[4], (**headLL).songNotes[5], (**headLL).songNotes[6], (**headLL).songNotes[7],
            (**headLL).songNotes[8], (**headLL).songNotes[9], (**headLL).songNotes[10], (**headLL).songNotes[11],
            (**headLL).songNotes[12], (**headLL).songNotes[13], (**headLL).songNotes[14], (**headLL).songNotes[15],
            (**headLL).songNotes[16], (**headLL).songNotes[17], (**headLL).songNotes[18], (**headLL).songNotes[19],
            (**headLL).songNotes[20]);
    
    // If fscanf returns -1, no valid song record was read; set headLL to NULL and return 0 songs.
    if (line == -1){
        (*headLL) = NULL;
        return 0;
    }

    // Set the nextSong pointer of the first node to NULL (end of list).
    (**headLL).nextSong = NULL;
    
    // Calculate the length of the song name and generate a song ID by adding a random number.
    len = strlen((**headLL).songName);
    id = rand()%1000;
    (**headLL).songId = len + id;

    // Increment the song counter.
    i++;

    // Continuously read the remaining song records from the file.
    while (1) {
        // Allocate memory for a new song node.
        temp = malloc(sizeof(A3Song));
        if (temp == NULL){
            fclose(fptr);
            return -1;
        }
        // Attempt to read a song record with the same format.
        // If exactly 22 fields are not read, assume end of file or invalid record, free memory and exit the loop.
        if (fscanf(fptr,
            " %25[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,], %4[^,]\n",
            temp->songName, temp->songNotes[0], temp->songNotes[1], temp->songNotes[2],
            temp->songNotes[3], temp->songNotes[4], temp->songNotes[5],
            temp->songNotes[6], temp->songNotes[7], temp->songNotes[8],
            temp->songNotes[9], temp->songNotes[10], temp->songNotes[11],
            temp->songNotes[12], temp->songNotes[13], temp->songNotes[14],
            temp->songNotes[15], temp->songNotes[16], temp->songNotes[17],
            temp->songNotes[18], temp->songNotes[19], temp->songNotes[20]) != 22)
        {   
            free(temp); // Free the allocated node if the record is incomplete.
            break;
        }


        // Calculate the length of the new song's name and generate a unique song ID.
        len = strlen((temp)->songName);
        do {
            id = rand() % 1000;
            (temp)->songId = len + id;
        } while (duplicateID(*headLL, (temp)->songId) == -1);

        // Insert the new song at the end of the linked list.
        addToEnd(&(*headLL), &temp);
        
        // Increment the song counter.
        i++;
    }

    // Close the file after reading all records.
    fclose(fptr);
    // Return the total number of songs added to the playlist.
    return i;
}
