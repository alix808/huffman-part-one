#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

void Allocate_memory(int size)
{
    array = (char *) malloc(sizeof(char) * size + 1);
}

void Init_array(int size)
{   
    memset(array,'\0', size);
}

void Print_array()
{   
    printf("qsort on array input: %s", array);
    printf("\n\n");
}

void Read_file(char * filename)
{
    FILE * fptr = fopen(filename, "r");
    int i = 0;
    while (!feof (fptr))
    {
        int onechar = fgetc(fptr);
        if (onechar != EOF)
        {
            array[i] = (char) onechar;
            i ++;
        }
    }
    fclose(fptr);
}

void Sort_array(int size)
{
    qsort(array, size, sizeof(char), Int_compare);
}

int Int_compare(const void * a, const void * b)
{
    const char * ia = (const char *) a;
    const char * ib = (const char *) b;
    return * ia - * ib;
}

void Execute_sort(int size, char * filename)
{   
    Allocate_memory(size);
    Init_array(size);
    Read_file(filename);
    Sort_array(size);
    Print_array();
}

void Clean_array()
{
    free(array);
}
