# inheritance.c

This is a program that simulates gene inheritance.
A family tree is created recursively as a binary search tree.
Each person has two pointers to their parents, who each have two pointers to their parents. The top level is randomly generated

To run, click the run.bat file or call it from the command line.
The program will ask for a number, then simulate the requested number of generations.
The outfile will be called inheritance(N).txt where N is the number you entered in batch file.

To save on file size, the outfile will be layed out as below (example with input of 3):
Generation 0, blood type BA
   Generation 1, blood type OB
      Generation 2, blood type AO
      Generation 2, blood type BA
   Generation 1, blood type AA
      Generation 2, blood type OA
      Generation 2, blood type OA

This can be better visualised like this:
<!-- language: lang-none -->
    _____________________________
    |Generation 2, blood type AO|-----|   _____________________________
    _____________________________     |---|Generation 1, blood type OB|-----|
    _____________________________     |   _____________________________     |
    |Generation 2, blood type BA|-----|                                     |
    _____________________________                                           |    _____________________________
                                                                            |----|Generation 0, blood type BA|
    _____________________________                                           |    _____________________________
    |Generation 2, blood type OA|-----|   _____________________________     |
    _____________________________     |---|Generation 1, blood type OB|-----|
    _____________________________     |   _____________________________
    |Generation 2, blood type OA|-----|
    _____________________________

(very proud of this)

If you want to make changes to my beautiful code, recompile using the included comp.bat script (if you have gcc). 

Currently, inheritance(26) is the highest that I have been able to go without running out of stack memory. If you know how to increase this, please email me or something
