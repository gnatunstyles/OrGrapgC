#include "myFun.h"
#include "test/tests.h"

int main(FILE *inputFile) {
    FILE *outputFile;
    inputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\input.txt", "rt");
    outputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\output.txt", "w");
    myFun(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    tests();
}
