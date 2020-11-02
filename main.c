#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int get_words(FILE* fp);

char* get_filename(void);

int main(void) {

    FILE* fp = fopen(get_filename(), "r");

    if (!fp) {
        perror("Error opening a file!");
        return EXIT_FAILURE;
    }

    printf("Words:\t%d\n", get_words(fp));

    fclose(fp);

    return EXIT_SUCCESS;
}

int get_words(FILE* fp) {
    bool in_word_flag = false;
    int words = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalnum(c) && in_word_flag == false) {
            in_word_flag = true;
            words++;
        } else if (!isalnum(c) && in_word_flag == true) {
            in_word_flag = false;
        }
    }
    
    return words;
}

char* get_filename(void) {
    static char filename[32];
    char* message = "Input a filename: ";

    printf("%s", message);
    scanf("%s", filename);

    return filename;
}