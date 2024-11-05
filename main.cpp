#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "dumpik.h"

int main ()
{   
    int added_elem = 10;

    int index = 2;

    struct List my_List = {0};

    Constr_List (&my_List);

    Adding_element_to_the_end (&my_List, added_elem);

    added_elem = 333;

    Adding_element_to_the_end (&my_List, added_elem);

    added_elem = -5;

    Adding_element_to_the_end (&my_List, added_elem);

    Deleting_element_by_position (&my_List, index);

    fprintf(stderr,"free = [%d]", my_List.free);

    Dump_moment (&my_List);

    Deductr (&my_List);

    return 0;
}

