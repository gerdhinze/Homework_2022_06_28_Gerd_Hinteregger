#include <stdio.h>
#include <stdlib.h>
#include <unity.h>
#include <sys/time.h>

#include "sortalgs.h"
#include "utils.h"

size_t N = 100000;
char *filename = "data.txt";
int *unsort_data = NULL;


void setUp(void)
{
create_file_with_random_numbers(filename, N);
unsort_data = load_data_from(filename, N);
}

void tearDown(void)
{
    free(unsort_data);
    delete_file(filename);
}         
void test_bubble_sort(void)
{
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    array_bubble_sort(unsort_data, N);
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
}
void test_selection_sort(void)
{
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    array_selection_sort(unsort_data, N);
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
}
void test_insertion_sort(void)
{
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    array_insertion_sort(unsort_data, N);
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
}
void test_merge_sort(void)
{
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    array_merge_sort(unsort_data, N);
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
}
void test_quick_sort(void)
{
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    
    array_quick_sort(unsort_data, N);
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("Time measured: %.6f seconds.\n", elapsed);
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_selection_sort);
    RUN_TEST(test_insertion_sort);
    RUN_TEST(test_merge_sort);
	RUN_TEST(test_quick_sort);

	return UNITY_END();
}