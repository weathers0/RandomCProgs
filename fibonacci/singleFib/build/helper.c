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


void fibonacci(int N, FILE *out)
{
    if (N > 0)
    {
        char *final; 
        char *cur = strdup("0");
        char *prev = cur;
        cur = strdup("1");

        for (int i = 1; i < N; i++)
        {
            char *next = add(prev, cur);
            free(prev);
            prev = cur;
            cur = next;
            final = cur;
        }
        free(prev);
        fprintf(out, "Fib(%d) = %s\n", N, final);
    }
}

char* add(char *a, char *b)
{
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);

    if (a_len < b_len)
    {
        char *c = a; a = b; b = c;
        size_t x = a_len; a_len = b_len; b_len = x;
    }

    size_t i, c_len = a_len + 1;
    char *c = malloc(c_len + 1);
    if (c == NULL)
    {
        printf("out of memory loloololollol\n");
        exit(1);
    }
    c[0] = '0';
    memcpy(c + 1, a, a_len + 1);

    for (i = 1; i <= b_len; i++) 
    {
        if ((c[c_len - i] += b[b_len - i] - '0') > '9')
        {
            c[c_len - i] -= 10;
            c[c_len - i - 1]++;
        }
    }
    for (; c[c_len - i] > '9'; i++) 
    {
        c[c_len - i] -= 10;
        c[c_len - i - 1]++;
    }
    if (c[0] == '0' && c_len > 1) 
    {
        memmove(c, c + 1, c_len--);
    }
    return c;
}

char* strdup (const char* s)
{
  size_t slen = strlen(s);
  char* result = malloc(slen + 1);
  if(result == NULL)
  {
    return NULL;
  }

  memcpy(result, s, slen+1);
  return result;
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
    char *stime = malloc(sizeof(char) * 18);
    sprintf(stime, "%02d/%02d at %02d:%02d:%02d", mday, month, hour, min, sec);
    return stime;
}