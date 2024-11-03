#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

const int WARNING                  =  -1;
const int IMMUTABLE_ELEM           =  0;
const size_t PHANTOM_POSITION      =  0;
const int SIZE_LIST                =  4;
const int MEANING_PHANTOM_ELEM     = -1;


struct ListNode {
    int data;
    int next_elem;
    int prev_elem;
};

struct List{
    ListNode* node_array;
    int free;
};

void Constr_List                   (struct List* my_List);
void Debug_moment                  (struct List* my_List);
void Deductr                       (struct List* my_List);
void Adding_element_to_the_begging (struct List* my_List, int added_elem);
void Adding_element_to_the_end     (struct List* my_List, int added_elem);
void Adding_element_to_position    (struct List* my_List, int added_elem, int position);
int  Check_for_list_fulness        (struct List* my_List);

#endif // LIST_H