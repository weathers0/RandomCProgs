//Code for functions so main looks sexy

#include "helper.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>


int checkNum(char *s)
{
    //Repeat over the length of s
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //Check if each char in s is a digit
        if (!isdigit(s[i]))
        {
            return 1;
        }
    }
    return 0;
}

//Watermarks new outfile
void watermark(FILE *out)
{
    //Get date
    char s[15];
    strcpy(s, getDate());

    //Do printing
    fprintf(out, "|------------------------------------------------------------------------|\n");
    fprintf(out, "| This was generated on %s by Will's Epic Algorithms Co.    |\n", s);
    fprintf(out, "| All fibonacci numbers are now registered trademarks                    |\n");
    fprintf(out, "| under Will's Epic Algorithms and all associated registered corporations|\n");
    fprintf(out, "| because he said so. Any attempt to use or pirate these numbers will    |\n");
    fprintf(out, "| result in prosecution and harsh legal action.                          |\n");
    fprintf(out, "|------------------------------------------------------------------------|\n");
}


void fibonacci(long long N, FILE *out)
{
    fprintf(out, "0\n1\n");

    if (N > 2)
    {
        for (long long z = 0, i = 0, j = 1, next = 0; z < N - 2; z++)
        {
            //Next is i + j
            next = i + j;
            //old j becomes the new i
            i = j;
            //old next becomes the new j
            j = next;
            //Print j (the old next)
            fprintf(out, "%i\n", j);
        }
    }
}

//Gets the current date in the format day dd mon yyyy
char* getDate(void)
{
    //Time struct generator
    time_t curTime;
    time(&curTime);
    struct tm *myTime = localtime(&curTime);

    //Array for wdays
    char* wday[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    //Array for months
    char* mon[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    //Get date values
    char *sday = wday[myTime->tm_wday];
    int mday = myTime->tm_mday;
    char *month = mon[myTime->tm_mon + 1];
    int year = myTime->tm_year;
    printf("isodufygb\n");

    //Concatenate and return
    char *sdate = malloc(sizeof(char) * 16);
    sprintf(sdate, "%s %i %s %i", sday, mday, month, year + 1900);
    printf("%s\n", sdate);
    return sdate;
}