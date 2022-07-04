#include "utils.h"

#include <stdio.h>
#include <stdlib.h>


void array_print(int data[], size_t n)
{
    for (int i=0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
int create_file_with_random_numbers(char *filename, size_t n)
{
    FILE *file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) 
    {
        fprintf(stderr, "Can't create file: %s !\n", filename);
        return -1;
    }

    srand(time(0));
 
    for(int i = 0; i<n; i++)
    {
        printf("%d\n", rand() % 1000);
    }

 
    fclose(file_ptr);

}
int delete_file(char *filename)
{

}
int *load_data_from(char *filename, size_t n)
{

}