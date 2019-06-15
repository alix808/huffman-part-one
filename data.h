#ifndef DATA_H
#define DATA_H

typedef struct data {
    char value;
    int freq;
} Node;

Node * data;

int Node_count(int size, char * arr);

void Allocate_data(int node_count);

void Init_data(int node_count);

void Freq_count(int size, char * arr);

void Insert_node(char val, int fr, int i);

void Sort_data(int node_count);

int Freq_compare(const void * a, const void * b);

void Print_data(int node_count);

void Execute_data(int size, char * arr);

#endif