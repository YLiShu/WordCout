#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }
    int count = 0;
    if (strcmp(argv[1], "-c") == 0) {
        char c;
        while ((c = fgetc(fp)) != EOF) {
            count++;
        }
        printf("字符数：%d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {
        char c;
        int in_word = 0;
        while ((c = fgetc(fp)) != EOF) {
            if (c == ' ' || c == '\t' || c == '\n' || c == ',') {
                if (in_word) {
                    count++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }
        if (in_word) {
            count++;
        }
        printf("单词数：%d\n", count);
    } else {
        printf("Invalid parameter %s\n", argv[1]);
        return 1;
    }
    fclose(fp);
    return 0;
}
