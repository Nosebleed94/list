#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main ()
{   
    int added_elem = 10;

    struct List my_List = {0};

    Constr_List (&my_List);

    Adding_element_to_the_end (&my_List, added_elem);

    added_elem = 333;

    Adding_element_to_the_end (&my_List, added_elem);

    fprintf(stderr,"free now = [%d]\n", my_List.free);

    Debug_moment (&my_List);

    Deductr (&my_List);

    return 0;
}

