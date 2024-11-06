#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "dumpik.h"
#include "filinghtml.h"

int main ()
{
    struct List my_List = {0};

    Filling_the_beginning_of_html ();
    Constr_List (&my_List);
    Adding_element_to_the_end (&my_List, 10);
    Adding_element_to_the_end (&my_List, 333);
    Adding_element_to_the_end (&my_List, -5);
    Deleting_element_by_position (&my_List, 2);
    Filling_the_end_of_html ();
    Deductr (&my_List);

    return 0;
}

