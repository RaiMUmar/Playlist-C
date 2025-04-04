#include "../include/givenA3.h" 

/* Main Function, creates an option menu for you to call other functions/tasks */
int main(){
    // Variable declarations and initializations
    int status, choice = 0, enter = 1, beginOrEnd, givenSongId;
    char input[50], *ptr, givenSongName[MAX_LENGTH], whichNote[100], fileName[MAX_LENGTH] = "MusicalTunes.csv";
    long userChoice;
    A3Song *headLL = NULL; // Pointer to the head of the linked list representing the playlist
    bool worked;
    srand(time(NULL)); // Seed the random number generator

    // Main menu loop - continues until the user selects option 9 (Exit)
    do {
        // Print the menu options for the user
        printf("======================================================\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a new song to an existing playlist\n");
        printf("3. Play all songs in the given playlist\n");
        printf("4. Play a song from the playlist, given its id\n");
        printf("5. Play a song from the playlist, given its name\n");
        printf("6. Count the number of occurrences of a note in a given song\n");
        printf("7. Delete a song from the playlist, given its id\n");
        printf("8. Delete the entire playlist\n");
        printf("9. Exit\n");
        printf("======================================================\n");
        printf("Enter your choice: ");

        // Get user input for menu selection
        fgets(input, 50, stdin);

        // Check if input contains a newline character; if not, the input is too long
        char *res = strpbrk(input, "\r\n");
        if (!res) {
            printf("Input Too Long!!\n");
            choice = 0;
            enter = 0;
        } else {
            *res = '\0'; // Replace newline with null terminator
        }

        // Convert input string to a long integer
        userChoice = strtol(input, &ptr, 10);
        if (ptr == input || *ptr != '\0') { // Check for conversion errors (non-numeric input)
            printf("Invalid Type!!\n");
            choice = 0;
            enter = 0;
        } else {
            choice = userChoice;
        }
        
        // Validate the user choice against available options (1 to 9)
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && enter){
            printf("Invalid Choice!!\n");
        }

        // Reset flag for next iteration
        enter = 1;

        // Option 1: Create a new playlist by reading songs from the file "MusicalTunes.csv"
        if (choice == 1){
            status = createPlayList(&headLL, fileName);
            if (status == -1) printf("File not Read!\n");
            if (status == 0) printf("0 Songs Found!\n");
            if (status > 0) printf("Number of songs in the playlist: %d\n\n", status);
        }

        // Option 2: Add a new song to the existing playlist
        if (choice == 2){
            printf("Add song to beginning (1), to end (2): ");
            scanf("%d", &beginOrEnd);
            while(getchar() != '\n'); // Clear the input buffer
            
            worked = addNewSong(&headLL, beginOrEnd);
            // Check if adding the song was unsuccessful
            if (worked == !true){
                printf("Faliure adding song!\n");
            }
        }

        // Option 3: Play all songs in the playlist
        if (choice == 3){
            if (headLL == NULL) printf("No Songs in PlayList!\n");
            if (headLL != NULL) playPlayList(headLL);
        }

        // Option 4: Play a specific song by its id
        if (choice == 4){
            if (headLL == NULL) {
                printf("No Songs in PlayList!\n");
            } else {
                printf("ID To Find: ");
                scanf("%d", &givenSongId);
                while(getchar() != '\n'); // Clear the input buffer
                status = playSongGivenId(headLL, givenSongId);
                if (status == -1) printf("Song with %d ID does not exist\n", givenSongId);
            }
            
        }

        // Option 5: Play a specific song by its name
        if (choice == 5){
            if (headLL == NULL) {
                printf("No Songs in PlayList!\n");
            } else {
                printf("Name To Find: ");
                fgets(givenSongName, MAX_LENGTH, stdin);
                // Remove trailing newline character, if present
                if (givenSongName[strlen(givenSongName) - 1] == '\n'){
                    givenSongName[strlen(givenSongName) - 1] = '\0';
                }
                status = playSongGivenName(headLL, givenSongName);
                if (status == -1) printf("Song with %s name does not exist\n", givenSongName);  
            } 
        }

        // Option 6: Count the occurrences of a specific note in a given song by id
        if (choice == 6){
            if (headLL == NULL) {
                printf("No Songs in PlayList!\n");
            } else {
                printf("Enter the id of the song you want to count the notes in: ");
                scanf("%d", &givenSongId);
                while(getchar() != '\n'); // Clear the input buffer
                printf("Enter the note you want to count: ");
                fgets(whichNote, 100, stdin);

                status = countNotesInASong(headLL, givenSongId, whichNote);
                if (status == -1) {
                    printf("Song not found!\n");
                } else {
                    printf("Number of times the note appears: %d\n", status);
                }
            }
            
        }

        // Option 7: Delete a song from the playlist by its id
        if (choice == 7){
            if (headLL == NULL) {
                printf("No Songs in PlayList!\n");
            } else {
                printf("ID To Find: ");
                scanf("%d", &givenSongId);
                while(getchar() != '\n'); // Clear the input buffer
                deleteASongGivenId(&headLL, givenSongId);
                // Check deletion status; note: the variable "status" is not updated here after deletion
                if (status == -1) printf("Song with %d ID does not exist\n", givenSongId);
            }
            
        }

        // Option 8: Delete the entire playlist
        if (choice == 8){
            if (headLL != NULL){
                deletePlayList(&headLL);
                headLL = NULL; // Reset the head pointer after deletion
                printf("All Songs Deleted!\n\n");
            } else {
                printf("There is no playlist to delete!\n");
            }
            
        }

    } while (choice != 9); // Exit the loop when the user selects option 9

    return 0; // End of program
}