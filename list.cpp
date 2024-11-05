#include "list.h"
#include "dumpik.h"

void Constr_List (struct List* my_List)
{
    size_t i = 0;
    int arr_constr_stage_prev_elem = 0;
    my_List->node_array = (struct ListNode*)calloc(SIZE_LIST, sizeof(struct ListNode));
    my_List->free = 1;
    my_List->remember_free = 0;
    int arr_elem_data[SIZE_LIST] = {MEANING_PHANTOM_ELEM, 0, 0, 0, 0, 0, 0, 0, 0};
    int arr_constr_stage_next_elem[SIZE_LIST] = {0, 2, 3, 4, 5, 6, 7, 8, 0};  
     
    for (i = 0; i < SIZE_LIST; i++)
    {
        my_List->node_array[i].data = arr_elem_data[i];
        my_List->node_array[i].next_elem = arr_constr_stage_next_elem[i];
        my_List->node_array[i].prev_elem = arr_constr_stage_prev_elem;
    }
}

void Deductr (struct  List* my_List)
{
    free (my_List->node_array);
}

void Adding_element_to_the_begging (struct List* my_List, int added_elem)
{
    Check_for_list_fulness (my_List);

    int remember_free = Remember_free_adding (my_List);
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
    int remember_free = my_List->free;
    my_List->free = Remember_free_adding (my_List);
    int old_last = my_List->node_array[PHANTOM_POSITION].prev_elem;
    my_List->node_array[remember_free].next_elem = 0;//FIXME - Владимир, что за 0????
    my_List->node_array[remember_free].prev_elem = old_last;
    my_List->node_array[PHANTOM_POSITION].prev_elem = remember_free;
    my_List->node_array[old_last].next_elem = remember_free;
    Dump_moment (my_List);
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

void Adding_element_after_the_specified_index (struct List* my_List, int added_elem, int index_after_which_fill)
{
    Check_for_list_fulness (my_List);

    int remember_free = Remember_free_adding (my_List);
    my_List->node_array[my_List->free].data = added_elem;
    int remember_next_index = Returning_the_next_index (my_List, index_after_which_fill);
    my_List->node_array[my_List->free].next_elem = remember_next_index;
    my_List->node_array[index_after_which_fill].next_elem = my_List->free;
    my_List->node_array[remember_next_index].prev_elem = my_List->free;
    my_List->node_array[my_List->free].prev_elem = index_after_which_fill;
    my_List->free = remember_free;
    Dump_moment (my_List);
}

int Returning_the_next_index (struct List* my_List, int index)
{
    int next_index = my_List->node_array[index].next_elem;
    return next_index;
}

int Returning_the_prev_index (struct List* my_List, int index)
{
    int prev_index = my_List->node_array[index].prev_elem;
    return prev_index;
}

int Remember_free_adding (struct List* my_List)
{
    int remember_free = my_List->node_array[my_List->free].next_elem;
    return remember_free;
}

void Deleting_element_at_the_end (struct List* my_List)
{
    int prev_free = my_List->free - STEP_BACK;
    my_List->node_array[prev_free].data = 0;
    my_List->node_array[prev_free].next_elem = my_List->free;
    my_List->node_array[prev_free].prev_elem = 0;
    int index_last_element = my_List->free - TWO_STEPS_BACK;
    my_List->node_array[index_last_element].next_elem = PHANTOM_POSITION;
    my_List->node_array[PHANTOM_POSITION].prev_elem = index_last_element;
    my_List->free = prev_free; 
}

void Deleting_element_by_position (struct List* my_List, int index)
{
    my_List->remember_free = my_List->free;
    int return_next_elem = Returning_the_next_index (my_List, index);
    int return_prev_elem = Returning_the_prev_index (my_List, index);
    my_List->node_array[return_prev_elem].next_elem = return_next_elem;
    my_List->node_array[return_next_elem].prev_elem = return_prev_elem;
    my_List->node_array[index].data = 0;
    my_List->node_array[index].prev_elem = 0;
    my_List->node_array[index].next_elem = my_List->free;
    my_List->free = index;
}

