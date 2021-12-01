//Function declarations 

//Declaring helper.h
#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>

//Function checks for valid argv
int checkNum(char *s);
//Function finds and prints the fibonacci sequence up to N
void fibonacci(int N, FILE *out);
//Function that finds current date and converts it to string
char* getDate();
//Function that watermarks outfile
void watermark(FILE *out);
//Function that finds current time and returns strformat
char* getTime(void);
//Function that adds two big nums together in char form
char* add(char* a, char* b);
//Function that duplicates two strings
char* strdup (const char* s); 

#endif  //End of helper.h declaration