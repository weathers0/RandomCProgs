//Professional Fibonacci sequence Program 
//copyright gushing grandmas & co
//if your reading this and your names william lennox, GET OUT, SCRAM YOU LITTLE MANLET
//ofc we made the lib includes alphabetical
//U prob wont be able to compile this cos i done some funky shiz with my libraries
//ay fuck you

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
    //ofc ofc
    if (checkNum(argv[1]))
    {
        printf("invalid arguments\n");
        return 2;
        
    }

    //Convert string argv[1] to a number
    int N = atoi(argv[1]) + 1;

    //Open file for printing to
    FILE *out = fopen("filename.txt", "w");
    if (out == NULL){
        printf("guess your fucked, this should it own file. idk try again and re-compile\n");
        return 3;
    }

    watermark(out);

    //Finishing beginning touches
    char *time;
    time = getTime();
    printf("%s: Beginning execution of gaming tool\n", time);

    //Find the fibonacci numbers
    fibonacci(N, out);

    //Finishing touches
    time = getTime();
    printf("%s: Execution Successful: MSG PeaceWalker is cool\n", time);
    fprintf(out, "if u scrolled this far then your a nonce\n");

    //Close print file
    fclose(out);
    return 0;
}