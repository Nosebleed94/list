#include <stdlib.h>
#include <stdio.h>

int main ()
{
    file_dump *file_dump = fopen("graph.dot", "w");

    fprintf(file_dump, "digraph structs {\n");
    fprintf(file_dump, "  rankdir=TB;\n\n");

    for (int i = 0; i < 5; i++)
    {
        fprintf (file_dump, "  node%d [shape=record,label=\"{<f1> x%d1 | <f2> x%d2 | <f3> x%d3}\"];\n", i, i, i, i);
    }
    fprintf (file_dump, "}\n");
    fclose (file_dump);

    return 0;
}

