#include <assert.h>
#include <stdio.h>
#include "../myFun.h"

void test1(void) {
    char str[6];
    char *str1;
    char *str2;
    FILE *inputFile, *outputFile, *tFile;
    inputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\input1.txt", "rt");
    outputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\output1.txt", "w");
    myFun(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    outputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\output1.txt", "rt");
    tFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\trueouts\\tr1.txt", "rt");
    while (1) {
        str1 = fgets(str, sizeof(str), outputFile);
        str2 = fgets(str, sizeof(str), tFile);
        if (str2 == NULL) {
            printf("test1 : successful\n");
            break;
        }
        if (str1 != str2) {
            printf("test1 : failed\n");
            break;
        }

    }
    fclose(outputFile);
    fclose(tFile);
}

void test2(void) {
    char str[6];
    char *str1;
    char *str2;
    FILE *inputFile, *outputFile, *tFile;
    inputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\input2.txt", "rt");
    outputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\output2.txt", "w+");
    myFun(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    outputFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\output2.txt", "rt");
    tFile = fopen("C:\\Users\\User\\CLionProjects\\lab5\\test\\trueouts\\tr2.txt", "rt");
    while (1) {
        str1 = fgets(str, sizeof(str), outputFile);
        str2 = fgets(str, sizeof(str), tFile);
        if (str2 == NULL) {
            printf("test2 : successful\n");
            break;
        }
        if (str1 != str2) {
            printf("test2 : failed\n");
            break;
        }
    }
    fclose(outputFile);
    fclose(tFile);
}

int tests(void) {
    test1();
    test2();
    printf("all tests passed");
    return 0;
}