#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

int Node_count(int size, char * arr)
{
    int i;
    int node_count = 0;
    for(i=0; i<size; i++)
    {
        if(arr[i] != arr[i+1])
        {
            node_count ++;
        }
    }
    return node_count;
}

void Allocate_data(int node_count)
{
    data = (Node *) malloc(sizeof(Node) * node_count);
}

void Init_data(int node_count)
{
    int i;
    for(i=0; i<node_count; i++)
    {
        data[i].value = '\0';
        data[i].freq = 0;
    }
}

void Freq_count(int size, char * arr)
{   
    int i;
    int fr = 1;
    int ind = 0;
    char onechar = '\0';
    for(i=0; i<size; i++)
    {
        if(arr[i] == arr[i+1] && arr[i] != '\0')
        {
            fr ++;
        }
        if(arr[i] != arr[i+1])
        {   
            onechar = arr[i];
            Insert_node(onechar, fr, ind);
            fr = 1; 
            ind ++;
        }
    }
}

void Insert_node(char val, int fr, int i)
{
    data[i].value = val;
    data[i].freq = fr;
}

void Print_data(int node_count)
{
    int i;
    for(i = 0; i<node_count; i++) {
        printf("value: %c, frequency: %d", data[i].value, data[i].freq);
        printf("\n");
    }
}

void Sort_data(int node_count)
{
    qsort(data, node_count, sizeof(Node), Freq_compare);
}

int Freq_compare(const void * a, const void * b)
{
    const Node * ia = (const Node *) a;
    const Node * ib = (const Node *) b;
    const int iv1 = ia -> freq;
    const int iv2 = ib -> freq;
    return (iv1 - iv2);
}

void Execute_data(int size, char * arr)
{
    int node_count;
    node_count = Node_count(size, arr);
    printf("Number of data nodes: %d", node_count);
    printf("\n\n");
    Allocate_data(node_count);
    Init_data(node_count);
    Freq_count(size, arr);
    Sort_data(node_count);
    Print_data(node_count);
}



