//Function declarations 

//Declaring helper.h
#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>

//Function checks for valid argv
int checkNum(char *s);
//Function finds and prints the fibonacci sequence up to N
void fibonacci(unsigned long long N, FILE *out);
//Function that finds current date and converts it to string
char* getDate();
//Function that watermarks outfile
void watermark(FILE *out);
//Function that finds current time and returns strformat
char* getTime(void);

#endif  //End of helper.h declaration
