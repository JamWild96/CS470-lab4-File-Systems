#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jam_libFS.h"

#define BUFFER_SIZE 1024

void printMenu(void) {
    printf("\n---- libFS Test Menu ----\n");
    printf("1. Create file\n");
    printf("2. Open file\n");
    printf("3. Write introduction to file\n");
    printf("4. Read file and display contents\n");
    printf("5. Close file\n");
    printf("6. Delete file\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;
    FS_FILE file = NULL;
    const char *filename = "Jam_Wilder_Introduction.txt"; // Change "YourName" to your actual name

    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        /* Clear input buffer */
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                if (file) {
                    printf("File is already created and open.\n");
                } else {
                    file = fileCreate(filename);
                    if (file) {
                        printf("File '%s' created successfully.\n", filename);
                    }
                }
                break;
            }
            case 2: {
                if (file) {
                    printf("File is already open.\n");
                } else {
                    file = fileOpen(filename, "r+");
                    if (file) {
                        printf("File '%s' opened successfully.\n", filename);
                    }
                }
                break;
            }
            case 3: {
                if (!file) {
                    printf("File is not open. Please create or open the file first.\n");
                } else {
                    /* Move file pointer to beginning before writing */
                    fseek(file, 0, SEEK_SET);
                    /* Define an introduction text with 3–4 sentences and 2 paragraphs */
                    const char *introText =
                        "Hello, my name is Jam. I am a senior computer science student at CWU eager to learn system programming. \n"
                        "I enjoy solving complex problems and developing innovative solutions. This project has given me an opportunity to explore file system operations in depth.\n"
                    	"I plan on hopefully making my own operating system one day, as well as implement machine learning into the ECU's of cars one day.\n"
			"I really want to graduate and start working in the industry as soon as possible and start working on my own goals on the side, and also keep learning. \n";

                    size_t len = strlen(introText);
                    size_t written = fileWrite(introText, sizeof(char), len, file);
                    if (written == len) {
                        printf("Introduction written successfully to '%s'.\n", filename);
                    } else {
                        printf("Error writing to file.\n");
                    }
                }
                break;
            }
            case 4: {
                if (!file) {
                    printf("File is not open. Please create or open the file first.\n");
                } else {
                    /* Rewind file to beginning for reading */
                    rewind(file);
                    char buffer[BUFFER_SIZE];
                    size_t bytesRead = fileRead(buffer, sizeof(char), BUFFER_SIZE - 1, file);
                    buffer[bytesRead] = '\0';
                    printf("\nContents of '%s':\n%s\n", filename, buffer);
                }
                break;
            }
            case 5: {
                if (!file) {
                    printf("No file is open to close.\n");
                } else {
                    if (fileClose(file) == 0) {
                        printf("File closed successfully.\n");
                    } else {
                        printf("Error closing file.\n");
                    }
                    file = NULL;
                }
                break;
            }
            case 6: {
                if (file) {
                    printf("Please close the file before deletion.\n");
                } else {
                    if (fileDelete(filename) == 0) {
                        printf("File '%s' deleted successfully.\n", filename);
                    } else {
                        printf("Error deleting file '%s'.\n", filename);
                    }
                }
                break;
            }
            case 7: {
                if (file) {
                    fileClose(file);
                }
                printf("Exiting program.\n");
                exit(0);
                break;
            }
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
