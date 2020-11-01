#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//(RU) Что такое слово? (для данных условий)
    // Словом является любая последовательность, состоящая из букв и цифр[a-z;A-Z;0-9]
//(EN) What is a word?
    // A word is a sequence of alphanumeric characters

int main(void) {

    // char* string = "Hey! What's up?"; // Hey! What is up???

    char* string;
    bool in_word_flag = false;
    int words = 0;
    printf("Enter a string: ");
    scanf("%s", string);

    for(int i = 0; i < strlen(string); i++) {
        if (isalnum(string[i]) && in_word_flag == false) {
            in_word_flag = true;
            words++;
        } else if (!isalnum(string[i]) && in_word_flag == true) {
            in_word_flag = false;
        }
    }
    printf("------\t\t\t\n");
    printf("Words:\t\t\t%d\n", words);
    printf("------\t\t\t\n");

    return EXIT_SUCCESS;
}