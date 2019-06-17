#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define fileLength 5
#define TRUE 0
#define FALSE 1

int myFun(FILE *inputFile, FILE *outputFile) {
    char(*graphEx)[fileLength] = malloc(fileLength * sizeof(char[fileLength]));
    struct graphWriter {
        char fromLetter;
        char space;
        char toLetter;
        char esc;
    };
    struct graphWriter letters[10];
    int i = 0;
    while (fscanf(inputFile, "%c%c%c%c", &(letters[i].fromLetter),
                  &(letters[i].space), &(letters[i].toLetter), &(letters[i].esc)) != EOF) {
        if (!isalpha(letters[i].fromLetter) || (letters[i].space != ' ') ||
            !isalpha(letters[i].toLetter) || isalpha(letters[i].esc)) {
            break;
        }
        float flag = FALSE;
        for (int f = 0; f < i; f++) {
            if (letters[i].fromLetter == graphEx[f][0]) {
                for (int k = 3; k < 10; k++) {
                    if (graphEx[f][k] == '\000') {
                        char *buffer = (char *) malloc(1 * sizeof(char));
                        *buffer = letters[i].toLetter;
                        graphEx[f][k] = *buffer;
                        flag = TRUE;
                        free(buffer);
                        break;
                    }
                }
            }
        }
        if (flag == FALSE) {
            for (int j = i; j < 10; j++) {
                if (letters[i].fromLetter != graphEx[j][0]) {
                    char *buffer = (char *) malloc(3 * sizeof(char));
                    buffer[0] = letters[i].fromLetter;
                    buffer[1] = '-';
                    buffer[2] = letters[i].toLetter;
                    for (int k = 0; k < 3; k++) {
                        graphEx[j][k] = buffer[k];
                    }
                    free(buffer);
                    break;
                }
            }
        }
        i++;
    }
    if (!isalpha(graphEx[0][0])) {
        fprintf(outputFile, "Error. Wrong Input.");
        return 0;
    }
    for (int k = 0; k < fileLength; k++) {
        for (int j = 0; j < fileLength; j++) {
            if (graphEx[k][0] == 0) break;
            if (graphEx[k][j] == 0) {
                fprintf(outputFile, "\n");
                break;
            }
            fprintf(outputFile, "%c ", (graphEx[k][j]));
        }
    }
    free(graphEx);
    return 0;
}