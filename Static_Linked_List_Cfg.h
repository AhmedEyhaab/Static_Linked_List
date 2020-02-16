
#ifndef  _Static_Linked_List_Cfg_H_


#define _Static_Linked_List_Cfg_H_


#include <stdio.h>
#include <stdlib.h>

//#define NULL      (void *)0
#define HEAP_SIZE   15
#define MAX_NUMBERS_OF_LINKED_LISTS  3
#define INPUT_USER  (-1)



typedef enum { LIST_ID_0 , LIST_ID_1 , NUMBERS_OF_LINKED_LISTS}List_ID_t;

typedef struct Node
{
    List_ID_t List_ID;
    int List_Index;
    int List_Size;
    struct Node * List_Head;
    int Data;
    struct Node * P_Next;
} Node;


extern Node Lists[NUMBERS_OF_LINKED_LISTS];


#endif
