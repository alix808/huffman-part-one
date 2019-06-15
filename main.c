#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "size.h"
#include "sort.h"
#include "data.h"

int main(int argc, char ** argv)
{   
    int size;
    size = Execute_size(argv[1]); 
    
    Execute_sort(size, argv[1]);
    Execute_data(size, array);
    

    return 0;  
}