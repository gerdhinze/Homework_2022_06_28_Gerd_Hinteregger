#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// This program will create different sequence of
// random numbers on every program run
int main(void)
{ 
    // Use current time as seed for random generator
    srand(time(0));
 
    for(int i = 0; i<10; i++)
        printf("%3d\n", rand() % 100);
 
    return 0;
}