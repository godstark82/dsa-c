// C code to implement hashing
#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -999



//! Hash Function -> H(x) = x % P;
int hashFunction(int key){
    return key % TABLE_SIZE;
}

//! Init A Empty Table
void initTable(int table[]){
    for(int i = 0; i < TABLE_SIZE; i++){
        table[i] = EMPTY;
    }
}





int main()
{
    return 0;
}