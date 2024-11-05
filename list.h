#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

const int WARNING                  = -1;
const int IMMUTABLE_ELEM           =  0;
const size_t PHANTOM_POSITION      =  0;
const int SIZE_LIST                =  9;
const int MEANING_PHANTOM_ELEM     = -1;
const int STEP_BACK                =  1;
const int TWO_STEPS_BACK           =  2;

struct ListNode
{
    int data;
    int next_elem;
    int prev_elem;
};

struct List
{
    ListNode* node_array;
    int free;
    int remember_free;
    FILE* file_dump;
};

void Constr_List                                (struct List* my_List);
void Deductr                                    (struct List* my_List);
void Adding_element_to_the_begging              (struct List* my_List, int added_elem);
void Adding_element_to_the_end                  (struct List* my_List, int added_elem);
void Adding_element_after_the_specified_index   (struct List* my_List, int added_elem, int index_after_which_fill);
void Deleting_element_at_the_end                (struct List* my_List);
void Deleting_element_by_position               (struct List* my_List, int position);
int  Check_for_list_fulness                     (struct List* my_List);
int  Remember_free_adding                       (struct List* my_List);
int  Returning_the_next_index                   (struct List* my_List, int index_after_which_fill);
int  Returning_the_prev_index                   (struct List* my_List, int index);
#endif // LIST_H