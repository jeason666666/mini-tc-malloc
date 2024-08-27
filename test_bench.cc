#include <iostream>
#include <thread>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include "tcmalloc.h"

#define THREAD_NUM 100
#define MALLOC_TIME 1000
#define MALLOC_SIZE 1000

void test_malloc()
{
    std::vector<std::thread> vecThreads;

    clock_t start, end;
    start = clock();

    for (int i = 0; i < THREAD_NUM; i++)
    {
        vecThreads.push_back(std::thread([](){
            for (int k = 0; k < MALLOC_TIME; k ++)
            {
                void* tmp = malloc(MALLOC_SIZE);
            }
        }));
    }

    for (auto& thread : vecThreads)
    {
        thread.join();
    }

    end = clock();
    float duration = (double)(end - start) / CLOCKS_PER_SEC; 

    printf("-----------------------------------------------------\n");
    printf("malloc\n");
    printf("%d threads tcmalloc %d times %d size  %f seconds\n",
    THREAD_NUM, MALLOC_TIME, MALLOC_SIZE, duration);
}


void test_tcmalloc()
{
    std::vector<std::thread> vecThreads;
    clock_t start, end;
    
    start = clock();

    for (int i = 0; i < THREAD_NUM; i++)
    {
        vecThreads.push_back(std::thread([](){
            for (int k = 0; k < MALLOC_TIME; k ++)
            {
                void* tmp = tcmalloc::malloc(MALLOC_SIZE);
            }
        }));
    }

    for (auto& thread : vecThreads)
    {
        thread.join();
    }

    end = clock();
    float duration = (double)(end - start) / CLOCKS_PER_SEC; 
    printf("-----------------------------------------------------\n");
    printf("tcmalloc\n");
    printf("%d threads tcmalloc %d times %d size  %f seconds\n", 
    THREAD_NUM, MALLOC_TIME, MALLOC_SIZE, duration);
}

int main()
{

    test_malloc();
    test_tcmalloc();

    return 0;
}