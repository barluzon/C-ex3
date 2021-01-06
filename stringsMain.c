#include <stdio.h>
#include "strings.h"
#define LINE 256
#define WORD 30

int main() {
    char wordToSearch[WORD];
    getWord(wordToSearch);
    char option[WORD];
    getWord(option);
    if (option[0] == 'a') {
        printLines(wordToSearch);
    } else if (option[0] == 'b') {
        printSimilarWords(wordToSearch);
    }
}