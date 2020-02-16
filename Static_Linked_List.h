
#ifndef  _Static_Linked_list_H_


#define _Static_Linked_list_H_


#include "Static_Linked_List_Cfg.h"


//-------------------- Public Functions Declaration APIs ------------------------//
extern void Create_Lists (void);

extern void Insert_First_Node( List_ID_t List_ID ,  int New_Data_Input);

extern void Insert_last_Node( List_ID_t List_ID ,  int New_Data_Input);

extern void Insert_to_List (List_ID_t List_ID, unsigned char List_Element_Position, int New_Data_Input);

extern int Get_List_Elements_Count (List_ID_t List_ID);

extern void Print_List(List_ID_t List_ID);

extern void Print_Heap (void);

extern void Reset_List (List_ID_t List_ID);


#endif
