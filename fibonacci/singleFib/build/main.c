//Fibonacci sequence thingy
//By Willyham
//Oliver smelly
//Enjoy the alphabetical lib includes

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("invalid number of arguments\n");
        return 1;
    }

    //Check that argv for N is a number
    if (checkNum(argv[1]))
    {
        printf("invalid arguments\n");
        return 2;
        
    }

    //Convert string argv[1] to a number
    int N = atoi(argv[1]);

    //Get file name from N
    char outptr[50];
    sprintf(outptr, "../output/fib(%d).txt", N);

    //Open file for printing to
    FILE *out = fopen(outptr, "w");
    if (out == NULL)
    {
        printf("No folder named output. Create one and re-run\n");
        return 3;
    }
    watermark(out);

    //Finishing beginning touches
    char *time;
    time = getTime();
    printf("%s: Beginning execution\n", time);

    //Find the fibonacci numbers
    fibonacci(N, out);

    //Finishing touches
    time = getTime();
    printf("%s: Execution Successful!\n", time);
    fprintf(out, "if u scrolled this far then u get a cookie\n");

    //Close print file
    fclose(out);
    return 0;
}