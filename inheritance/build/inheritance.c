//Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

//Global variables
int GENERATIONS;
int INDENT_LENGTH = 1;

//Function prototypes
person *create_family(int generations);
void print_family(person *p, int generation, FILE *out);
void free_family(person *p);
char random_allele();
bool checkdig(char *s);

int main(int argc, char *argv[])
{
    //Print time initiated
    time_t s, val = 1;
    s = time(NULL);
    struct tm* curtime = localtime(&s);
    printf("%02d:%02d:%02d: Beginning execution\n",
            curtime->tm_hour, curtime->tm_min, curtime->tm_sec);

    //Validate cmd-line args
    if (argc != 2)
    {
        printf("Lol enter right stoopid\n");
        return 2;
    }
    else if (!checkdig(argv[1]))
    {
        printf("Lol are u dumb\n");
        return 3;
    }
    GENERATIONS = atoi(argv[1]);

    //Seed random number generator
    srand(time(0));

    //Calculate indent length of max tree width
    INDENT_LENGTH = INDENT_LENGTH * (2 ^ (GENERATIONS - 1));

    //Log time
    s = time(NULL);
    curtime = localtime(&s);
    printf("%02d:%02d:%02d: Beginning family generation\n",
            curtime->tm_hour, curtime->tm_min, curtime->tm_sec);
    
    //Create a new family with N generations
    person *p = create_family(GENERATIONS);

    char *outname = malloc(sizeof(char) * 50);
    sprintf(outname, "../output/inheritance(%d).txt", GENERATIONS);
    FILE *out = fopen(outname, "w");
    if (out == NULL)
    {
        printf("Some stuff did some stuff\n");
        return 4;
    }
    free(outname);

    //Log time
    s = time(NULL);
    curtime = localtime(&s);
    printf("%02d:%02d:%02d: Printing family\n",
            curtime->tm_hour, curtime->tm_min, curtime->tm_sec);
    //Print family tree of blood types
    print_family(p, 0, out);

    //Log time
    s = time(NULL);
    curtime = localtime(&s);
    printf("%02d:%02d:%02d: Freeing memory\n",
            curtime->tm_hour, curtime->tm_min, curtime->tm_sec);

    //Free memory
    free_family(p);

    //Print time finished
    s = time(NULL);
    curtime = localtime(&s);
    printf("%02d:%02d:%02d: Execution complete, all memory successfully freed\n",
            curtime->tm_hour, curtime->tm_min, curtime->tm_sec);
    exit(0);
}

//Create a new individual with `generations`
person *create_family(int generations)
{
    //Allocate memory for new person
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        printf("Lol some shiz broke\n");
        exit(1);
    }

    //Generation with parent data
    if (generations > 1)
    {
        //Recursively create blood type histories for parents
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        //Randomly assign child alleles based on parents

        //Getting parents' alleles
        char p1[2] = {p->parents[0]->alleles[0], p->parents[0]->alleles[1]};
        char p2[2] = {p->parents[1]->alleles[0], p->parents[1]->alleles[1]};

        //randomly selecting an allele from each parent and assigning to p's allele field
        p->alleles[0] = p1[rand() % 2];
        p->alleles[1] = p2[rand() % 2];
    }

    //Generation without parent data - (grandparents, random alleles generated)
    else
    {
        //Set parent pointers to NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        //Randomly assign alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    //Return newly created person
    return p;
}

//Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    //TODO: Handle base case
    if (p == NULL)
    {
        return;
    }

    //Free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    //TODO: Free child
    free(p);
}

//Print each family member and their alleles.
void print_family(person *p, int generation, FILE *out)
{
    //Handle base case
    if (p == NULL)
    {
        return;
    }
    //Print indentation
    for (int i = 0; i < generation; i++)
    {
        fprintf(out, "   ");
    }

    //Print person
    fprintf(out, "Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1, out);
    print_family(p->parents[1], generation + 1, out);
}

//Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}

bool checkdig(char *s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}