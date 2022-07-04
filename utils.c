#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
        return EXIT_FAILURE;
    }

    srand(time(0));
 
    for(int i = 0; i<n; i++)
    {
        printf("%d\n", rand() % 1000);
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}

int delete_file(char *filename)
{
    return remove(filename);
}

int *load_data_from(char *filename, size_t n)
{
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", filename);
    }
    
    int *data = calloc(n, sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        fscanf(file_ptr, "%d", &data[i]);
    }
    fclose(file_ptr);

    return data;
}