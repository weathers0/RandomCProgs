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
    char *s;
    s = getDate();

    //Do printing
    fprintf(out, "|------------------------------------------------------------------------|\n");
    fprintf(out, "| This was generated on %s by Will's Epic Algorithms Co.    |\n", s);
    fprintf(out, "| All fibonacci numbers are now registered trademarks                    |\n");
    fprintf(out, "| under Will's Epic Algorithms and all associated registered corporations|\n");
    fprintf(out, "| because he said so. Any attempt to use or pirate these numbers will    |\n");
    fprintf(out, "| result in prosecution and harsh legal action.                          |\n");
    fprintf(out, "|------------------------------------------------------------------------|\n");
}


void fibonacci(unsigned long long N, FILE *out)
{
    fprintf(out, "0\n1\n");
    if (N > 2)
    {
        unsigned long long i = 0;
        unsigned long long j = 1;
        unsigned long long next = 0;

        for (int z = 0; z < N - 2; z++)
        {
            //Next is i + j
            next = i + j;
            //old j becomes the new i
            i = j;
            //old next becomes the new j
            j = next;
            //Print j (the old next)
            fprintf(out, "%llu\n", j);
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
    //Concatenate and return
    char *sdate = malloc(sizeof(char) * 16);
    sprintf(sdate, "%s %i %s %i", sday, mday, month, year + 1900);
    return sdate;
}

char* getTime(void)
{
    time_t curTime;
    time(&curTime);
    struct tm *myTime = localtime(&curTime);

    //Get date values
    int month = myTime->tm_mon;
    int mday = myTime->tm_mday;
    int sec = myTime->tm_sec;
    int min = myTime->tm_min;
    int hour = myTime->tm_hour;

    //Concatenate and return
    char *stime = malloc(sizeof(char) * 50);
    sprintf(stime, "%i/%i at %i:%i:%i", mday, month, hour, min, sec);
    return stime;
}
