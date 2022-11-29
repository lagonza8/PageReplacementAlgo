/**
 * Definitions for helper functions to load a reference string.
 *
 * @author Luis A. Gonzalez, Acuna
 * @version 0.9
 */

#include <DataLoader.h>

#define SIZE 10
char buffer[SIZE], *ptr;

/**
 * Loads a test_scenario strut from a textfile.
 *
 * @param filename The name of the file to load.
 * @return A struct containing the loaded file.
 */
struct test_scenario* load_test_data(char* filename)
{
    FILE * filePointer = NULL;
    // a pointer to a struct FILE in RAM, the struct in RAM contains pointer to a buffer in RAM

    filePointer = fopen(filename, "r");
    // fopen() populates the FILE struct in RAM and the buffer created in RAM with a copy of the file it opened from secondary store

    if (filePointer == NULL) {
        fprintf(stderr, "Error while opening file %s\n", filename);
    }

    struct test_scenario* data = (struct test_scenario*)malloc(sizeof(struct test_scenario*));

    // read the first line from the .txt file, it is the number of pages
    data->page_count = strtol(fgets(buffer, SIZE, filePointer), &ptr, 10);
    // fgets() will stop reading characters when it reads a new line character
    printf("page count: %d \n", data->page_count);

    // read the second line from the .txt file, it is the number of available frames in RAM
    data->frame_count = strtol(fgets(buffer, SIZE, filePointer), &ptr, 10);
    printf("frame count: %d \n", data->frame_count);

    // read the third line from the .txt file, it is the number of entries in the reference string
    data->refstr_len = strtol(fgets(buffer, SIZE, filePointer), &ptr, 10);
    printf("reference string entry count: %d \n", data->refstr_len);

    // The rest of the file is dedicated to the page numbers in the reference string
    int i;
    while (!feof(filePointer)) {
        data->refstr[i] = strtol(fgets(buffer, SIZE, filePointer), &ptr, 10);
        printf("%d \n", data->refstr[i]);
    }

    fclose(filePointer);
    //releases the memory allocated in RAM for the FILE struct and buffer containing the file copy

    return data;
}