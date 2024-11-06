#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>

#include "list.h"
#include "dumpik.h"

void Dump_moment (struct List* my_List)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    long seconds = tv.tv_sec;
    long microseconds = tv.tv_usec;
    
    char filename[100] = {0};
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.dot",  seconds, microseconds);
    FILE* file_html = fopen ("dump.html", "a+");
    FILE* file_dump = fopen (filename, "a+");
    // fprintf (file_html, "<img src =\"filename\"/>\n");
    fprintf (file_dump, "\n");
    fprintf (file_dump,"digraph structs {\n");
    fprintf (file_dump,"charset = \"UTF-8\";\n");
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
        fprintf (file_dump, "node%d:f2 -> node%d:f1;\n", i, my_List->node_array[i].next_elem);
    }

    char command[80];
    snprintf(command, sizeof(command), "echo dot -Tpng %s -o %.22s.png", filename, filename);
    // fprintf(stderr, "%s\n", command);
    // fprintf(stderr, "%ld\n", strlen(command));
    // fprintf(stderr, "%ld\n", system (command));
    system (command);
    //fprintf(stderr, "dot -Tpng %s -o %.22s.png\n", filename, filename);
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.png",  seconds, microseconds);
    fprintf (file_html,       "<img src=\"%s\"/>\n", filename);
    fprintf (file_dump,"free -> node%d\n", my_List->free);
    fprintf (file_dump,"{ rank = same; node0; node1; node2; node3; node4; node5; node6; node7; node8; }\n");
    fprintf (file_dump, "}\n");
    fclose (file_dump);
    fclose (file_html);
}