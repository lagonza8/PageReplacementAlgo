/**
 * Definitions for helper functions to load a reference string.
 *
 * @author Luis A. Gonzalez, Acuna
 * @version 0.9
 */

#include <DataLoader.h>

//structs
/*
struct test_scenario {
    int refstr_len;
    int refstr[512];
    int page_count;
    int frame_count;
};
*/


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
    fclose(filePointer);
    //releases the memory allocated in RAM for the FILE struct and buffer containing the file copy
}