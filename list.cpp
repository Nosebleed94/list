#include "list.h"

void Constr_List (struct List* my_List)
{
    size_t i = 0;
    int arr_constr_stage_prev_elem = 0;
    my_List->node_array = (struct ListNode*)calloc(SIZE_LIST, sizeof(struct ListNode));
    my_List->free = 1;
    int arr_elem_data[SIZE_LIST]   = {MEANING_PHANTOM_ELEM, 0, 0, 0};
    int arr_constr_stage_next_elem[SIZE_LIST] = {0, 2, 3, 0};  
     
    for (i = 0; i < SIZE_LIST; i++)
    {
        my_List->node_array[i].data = arr_elem_data[i];
        my_List->node_array[i].next_elem = arr_constr_stage_next_elem[i];
        my_List->node_array[i].prev_elem = arr_constr_stage_prev_elem;
    }
}

void Debug_moment (struct List* my_List)
{
    size_t i = 0;

    for (i = 0; i < SIZE_LIST; i++)
    {
        fprintf(stderr,"%d ", my_List->node_array[i].data);
    }

    fprintf(stderr,"\n");

    for (i = 0; i < SIZE_LIST; i++)
    {
        fprintf(stderr,"%d ", my_List->node_array[i].next_elem);
    }

    fprintf(stderr,"\n");

    for (i = 0; i < SIZE_LIST; i++)
    {
        fprintf(stderr,"%d ", my_List->node_array[i].prev_elem);
    } 
}

void Deductr (struct  List* my_List)
{
    free (my_List->node_array);
}

void Adding_element_to_the_begging (struct List* my_List, int added_elem)
{
    Check_for_list_fulness (my_List);

    int remember_free = my_List->node_array[my_List->free].next_elem;
    my_List->node_array[my_List->free].data = added_elem;
    my_List->node_array[my_List->free].next_elem = my_List->node_array[PHANTOM_POSITION].next_elem;
    my_List->node_array[my_List->free].prev_elem = IMMUTABLE_ELEM;
    my_List->node_array[my_List->node_array[PHANTOM_POSITION].prev_elem].next_elem = IMMUTABLE_ELEM; 
    my_List->node_array[my_List->node_array[PHANTOM_POSITION].next_elem].prev_elem = my_List->free;
    my_List->node_array[PHANTOM_POSITION].next_elem = my_List->free;
    my_List->free = remember_free;
}

void Adding_element_to_the_end (struct List* my_List, int added_elem)
{
    Check_for_list_fulness (my_List);

    my_List->node_array[my_List->free].data = added_elem;
    int remember_free =  my_List->free;
    my_List->free = my_List->node_array[my_List->free].next_elem;
    int old_last  = my_List->node_array[PHANTOM_POSITION].prev_elem;
    my_List->node_array[remember_free].next_elem = 0;
    my_List->node_array[remember_free].prev_elem = old_last;
    my_List->node_array[PHANTOM_POSITION].prev_elem = remember_free;
    my_List->node_array[old_last].next_elem = remember_free;
}



int Check_for_list_fulness (struct List* my_List)
{
    if (my_List->free == SIZE_LIST - 1)
    {
        fprintf(stderr,"Warning, but the list is full. Further actions will be uncorrected. To add a new element, delete the old onen\n");
        return -1;
    }
    else
    {
        return 1;
    }
}
