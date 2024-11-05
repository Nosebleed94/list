#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "dumpik.h"

void Dump_moment (struct List* my_List)
{
    FILE* file_html = fopen("dump.html", "w");
    fprintf(file_html,"<!DOCTYPE html>\n");
    fprintf(file_html,"<html lang=\"en\">\n\n");
    fprintf(file_html,"<head>\n");
    fprintf(file_html,"    <meta charset=\"utf-8\">\n");
    fprintf(file_html,"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n");
    fprintf(file_html,"    <title>list dump</title>\n");
    fprintf(file_html,"    <link rel=\"stylesheet\" href=\"styles.css\">\n");
    fprintf(file_html,"    </head>\n\n");
    fprintf(file_html,"<body>\n");
    fprintf(file_html,"````ssss");
    FILE* file_dump = fopen("graph.dot", "w");
    fprintf(file_dump, "\n");
    fprintf (file_dump,"digraph structs {\n");
    fprintf (file_dump,"harset = \"UTF-8\";\n");
    fprintf (file_dump,"rankdir=TB;\n");
    fprintf (file_dump,"label = \"Vovka - sladcaya golovka\";\n");
    fprintf (file_dump,"bgcolor = \"#0000aa\";\n");
    fprintf (file_dump,"fontcolor = black;\n");
    fprintf (file_dump,"fontsize = 18;\n");
    fprintf (file_dump,"style = \"rounded\";\n");   
    fprintf (file_dump,"margin = 0.3;\n"); 
    fprintf (file_dump,"splines = ortho;\n");
    fprintf (file_dump,"ranksep = 1.0;\n"); 
    fprintf (file_dump,"nodesep = 0.9;\n");
    fprintf (file_dump,"bgcolor = \"#78FFDB\";\n");
    fprintf (file_dump,"edge [color=\"#FF69B4\"]\n;");

    for (int i = 0; i < SIZE_LIST; i++)
    {
        fprintf (file_dump,"node%d [shape=record,label=\"{ip: %d|<f1> data: %d | <f2> next: %d | <f3> prev: %d}\"];\n", i, i,
        my_List->node_array[i].data, 
        my_List->node_array[i].next_elem, my_List->node_array[i].prev_elem);
    }

    fprintf (file_dump, "\n");

    for (int i = 0; i < SIZE_LIST - 1; i++)
    {
        fprintf(file_dump, "node%d:f2 -> node%d:f1;\n", i, my_List->node_array[i].next_elem);
    }

    fprintf(file_dump,"free -> node%d\n", my_List->free);
    fprintf(file_dump,"{ rank = same; node0; node1; node2; node3; node4; node5; node6; node7; node8; }\n");
    fprintf(file_dump, "}\n");
    fclose (file_dump);
    fclose (file_html);

}