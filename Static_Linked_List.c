

#include "Static_Linked_List.h"

static Node Heap[HEAP_SIZE];  // Memory space to put your Nodes. Note that is is just a HEAP_SIZE * sizeof( Node ) memory array.
static int Heap_index = 0;
static int Node_Index[MAX_NUMBERS_OF_LINKED_LISTS];


void Create_Lists (void)
{

     int Loop_Index=0;

     int Total_Lists_Size = 0;

     for(Loop_Index=0; Loop_Index<HEAP_SIZE; Loop_Index++)
     {
         Heap[Loop_Index].Data=0;
         Heap[Loop_Index].List_Head=NULL;
         Heap[Loop_Index].P_Next=NULL;
         Heap[Loop_Index].List_Size=0;
         Heap[Loop_Index].List_Index=0;
     }

     if( NUMBERS_OF_LINKED_LISTS > MAX_NUMBERS_OF_LINKED_LISTS )
     {
         printf ("your Number of Lists need to be created larger than Maximum Number of Available Linked List ");
          while(1);  //test
         return;
     }

     for( Loop_Index=0; Loop_Index<NUMBERS_OF_LINKED_LISTS; Loop_Index++)
     {
        Lists[Loop_Index].List_Index = 0;
        Lists[Loop_Index].List_Head = NULL;
        Lists[Loop_Index].P_Next = NULL;

        Total_Lists_Size += Lists[Loop_Index].List_Size;
     }

     if( Total_Lists_Size > HEAP_SIZE)
     {
         // you can't make all of these lists
         printf("Your Total Size of Lists exceed the size of Heap");
         while(1);  //test
        return; //test
     }
}


static Node* create_Node ( List_ID_t List_ID , int New_Data_Input )
{
    Node * Current_Node;

    if(Heap_index >= HEAP_SIZE)
    {
        printf("Out of Memory\n");
        Current_Node = NULL;
        while(1);   //test
    }

    if( Lists[List_ID].List_Index >= Lists[List_ID].List_Size )
    {
         printf( "Exceeds the Current List_ID [%d] Size!\n",Lists[List_ID].List_ID );
         Current_Node = NULL;
         while(1);  //test
    }

    else if ( Lists[List_ID].List_Index  <  Lists[List_ID].List_Size )
    {
        while ( Heap[Heap_index].Data != 0)
        {
            Heap_index++;
        }

        Current_Node = &( Heap[Heap_index] );

       if (New_Data_Input == INPUT_USER)
       {
         printf("Enter the Data in this Current Node (%d) in the List ID [%d]=",Lists[List_ID].List_Index , Lists[List_ID].List_ID  );

         scanf ("%d",&New_Data_Input);
       }

        Current_Node ->Data = New_Data_Input;

        Current_Node ->P_Next = NULL;

        Lists[List_ID].List_Index++;

        Heap_index++;


    }

    else
    {
        //Do Nothing
        //Shouldn;t be here
    }

    return Current_Node;
}

void Insert_First_Node( List_ID_t List_ID ,  int New_Data_Input)
{

    struct Node* New_Node = create_Node (  List_ID , New_Data_Input );

    if ( New_Node != NULL )
    {
        if(Lists[List_ID].List_Head == NULL)
        {
             New_Node->P_Next = Lists[List_ID].List_Head;
             Lists[List_ID].List_Head = New_Node;
        }

        else
        {
            printf("Overwrite on the First Node in the Current List ID [%d]\n",Lists[List_ID].List_ID);
            New_Node->P_Next = Lists[List_ID].List_Head;
            Lists[List_ID].List_Head = New_Node;
        }

    }

    else if ( New_Node == NULL )
    {
        printf("Head of Current List ID [%d] is NULL [Invalid]\n",Lists[List_ID].List_ID);
        while(1);   //test
    }

    else
    {
       //Do Nothing
       //Shouldn't be here
    }

}

void Insert_last_Node( List_ID_t List_ID ,  int New_Data_Input)
{
    struct Node* New_Node = create_Node (  List_ID , New_Data_Input );

    if ( New_Node != NULL )
    {
        struct Node *List_Pointer = Lists[List_ID].List_Head ;

        if (List_Pointer == NULL)
        {
            Insert_First_Node(List_ID,New_Data_Input);
            return;
        }

        while (List_Pointer->P_Next != NULL)
        {
           List_Pointer = List_Pointer->P_Next;
        }

        List_Pointer->P_Next = New_Node;

        return;
    }

    else if ( New_Node == NULL )
    {
        printf("Last Node of Current List ID [%d] is NULL [Invalid]\n",Lists[List_ID].List_ID);
        while(1);   //test
    }

    else
    {
       //Do Nothing
       //Shouldn't be here
    }

}



void Insert_to_List (List_ID_t List_ID, unsigned char List_Element_Position, int New_Data_Input)
{
   int Index =0;
   if( Lists[List_ID].List_Head == NULL)
    {
      Insert_First_Node (List_ID ,New_Data_Input);
      return;
    }

   if( List_Element_Position == 0 )
   {
     Insert_First_Node (List_ID ,New_Data_Input);
     return;
   }

   struct Node* List_pointer = Lists[List_ID].List_Head;

    for(Index=0; Index<List_Element_Position ; Index++)
    {
        if( (List_pointer->P_Next) == NULL )
        {
           Insert_last_Node (List_ID ,New_Data_Input);
           return;
        }
        else
        {List_pointer=List_pointer->P_Next ;}
    }

    struct Node* New_Node = create_Node (  List_ID , New_Data_Input );

    if ( New_Node != NULL )
    {
        New_Node->P_Next= List_pointer->P_Next;

        List_pointer->P_Next=New_Node;
    }

    else if ( New_Node == NULL )
    {
       printf("Current Node in the Current List ID [%d] is NULL [Invalid]\n",Lists[List_ID].List_ID);
        while(1);   //test
    }

    else
    {
       //Do Nothing
       //Shouldn't be here
    }


}

int Get_List_Elements_Count (List_ID_t List_ID)
{
    printf("Number of ELements in this List ID [%d] = %d\n",Lists[List_ID].List_ID,Lists[List_ID].List_Index);
    return Lists[List_ID].List_Index;
}

void Print_List(List_ID_t List_ID)
{
    int List_Index = 0;
    struct Node* List_Pointer= Lists[List_ID].List_Head;

    printf("Current List ID [%d] have Elements =\n",Lists[List_ID].List_ID);
	while (List_Pointer != NULL)
	{
		printf("Index [%d] = %d -> ", List_Index ,List_Pointer->Data);
		List_Pointer = List_Pointer->P_Next;
		List_Index++;
	}

	printf("NULL\n"); //reaches the end of the list
}

 void Print_Heap (void)
 {

     int Heap_Index=0;

     printf("The Elements in the Heap are= \n");

     for( Heap_Index=0;Heap_Index<HEAP_SIZE;Heap_Index++)
     {
         printf("Heap[%d] = %d\n", Heap_Index , Heap[Heap_Index].Data );
     }

 }

void Reset_List (List_ID_t List_ID)
{
    struct Node* List_Pointer= Lists[List_ID].List_Head;

    int Index=0;

    for(Index=0;Index<Lists[List_ID].List_Index;Index++)
    {
        List_Pointer->Data=0;
        List_Pointer= List_Pointer->P_Next;
    }

    Heap_index=0;
    Lists[List_ID].List_Index = 0;
    Lists[List_ID].List_Head = NULL;
    Lists[List_ID].P_Next = NULL;
}

