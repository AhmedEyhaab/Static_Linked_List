
#include "Static_Linked_List.h"


int main (void)
{

    Create_Lists();

    Insert_to_List(LIST_ID_0,2,104);
    Insert_First_Node( LIST_ID_1,705);
    Insert_last_Node( LIST_ID_0 ,504);
    Insert_to_List( LIST_ID_1, 4,704);

    Print_List(LIST_ID_0);

    Print_List(LIST_ID_1);

    Print_Heap();

    Get_List_Elements_Count(LIST_ID_0);

    Reset_List(LIST_ID_0);

    Get_List_Elements_Count(LIST_ID_0);

    int i = 0;

    for(i=0;i<Lists[LIST_ID_0].List_Size;i++)
    {
        Insert_to_List(LIST_ID_0,i,INPUT_USER);
    }

    Get_List_Elements_Count(LIST_ID_0);

    Print_List(LIST_ID_0);

    Print_Heap();

    return 0;
}

