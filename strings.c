#include <stdio.h>
#include <string.h>
#include "strings.h"
#define LINE 256
#define WORD 30

//gets a line from stdin and puts it in s. returns the number of chars read. returns -1 if reached EOF
int getLine(char s[]) {
    char *sPtr = s;
    int counter = 0;
    do {
        *sPtr++ = getchar();
        counter++;
    } while (*(sPtr-1) != EOF && *(sPtr-1) != '\n'); //This loop will break when either reached EOF or a line break
    if (*(sPtr-1) == EOF && counter ==1) return -1; //return -1 because reached EOF.
    *(sPtr-1) = '\0';
    return --counter; //we return --counter because we added extra one when reached either EOF or '\n'
}

//gets a word from stdin and puts it in s. returns the number of chars read. returns -1 if reached EOF.
int getWord(char w[]) {
    char *wPtr = w;
    int counter = 0;
    do {
        *wPtr++ = getchar();
        counter++;
    } while (*(wPtr-1) != EOF && *(wPtr-1) != '\n' &&  *(wPtr-1) != '\t' && *(wPtr-1) != ' '); //This loop will break when reached EOF, space, tab, or line break
    if (*(wPtr-1) == EOF && counter == 1) return -1; //return -1 because reached EOF.
    *(wPtr-1) = '\0';
    return --counter; //we return --counter because we added extra one when reached either EOF, '\n', '\t', ' '
}

//returns 1 if str2 is a substring of str1. returns  0 otherwise.
int subString( char * str1, char * str2) {
    if (strstr(str1, str2) == NULL) {
        return 0;
    }
    return 1;
}

//returns 1 if you can get string t by removing n chars from string s. returns 0 otherwise
int similar (char *s, char *t, int n) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (tLen != sLen-n) return 0; //if t.length and s.length-2 are not equal - we surely cannot get t by removing two chars from s.
    char *sPtr = s;
    char *tPtr = t;
    int misses = 0;
    while((misses <= n) && (*sPtr != '\0' || *tPtr != '\0')) { //this loop will break only if both of the pointers reached the end of the string or if we already "removed" more than n chars
        if (*sPtr != '\0' && *tPtr != '\0') { //if both of the pointers have not reached the end of the string
            if (*tPtr == *sPtr) {
                tPtr++;
                sPtr++;
            } else {
                sPtr++;
                misses++;
            }
        } else if (*tPtr == '\0' ) { //if t pointer reached the end of the string, we can still remove chars using s pointer
            sPtr++;
            misses++;
        }
    }
    if (misses != n) return 0;
    return 1;
}

//reads string (can be multiple lines) from stdin and prints the lines that str appears in.
void printLines(char * str) {
    char line[LINE];
    char *linePtr = line;
    while(getLine(linePtr) != -1) {
        if (subString(linePtr, str) == 1) printf("%s\n", linePtr);
    }
}

//reads words from stdin and prints the words that are similar to str
void printSimilarWords(char * str) {
    char word[WORD];
    char *wordPtr = word;
    while(getWord(wordPtr) != -1) {
        if (subString(wordPtr, str) == 1) {
            printf("%s\n", wordPtr);
        } else if (similar(wordPtr, str, 1) == 1) {
            printf("%s\n", wordPtr);
        }
    }
}
