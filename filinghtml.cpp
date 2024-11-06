#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "filinghtml.h"

void Filling_the_beginning_of_html ()
{
    FILE* file_html = fopen ("dump.html", "a+");
    assert(file_html != nullptr);

    fprintf (file_html,"<!DOCTYPE html>\n");
    fprintf (file_html,"<html lang=\"en\">\n\n");
    fprintf (file_html,"<head>\n");
    fprintf (file_html,"    <meta charset=\"utf-8\">\n");
    fprintf (file_html,"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n");
    fprintf (file_html,"    <title>list dump</title>\n");
    fprintf (file_html,"    <link rel=\"stylesheet\" href=\"styles.css\">\n");
    fprintf (file_html,"</head>\n\n");
    fprintf (file_html,"<body>\n");
    fclose(file_html);
}

void Filling_the_end_of_html ()
{
    FILE* file_html = fopen( "dump.html", "a+");
    assert (file_html != nullptr);
    fprintf (file_html,"<body>\n\n");
    fprintf (file_html,"</html>");
    fclose (file_html);
}

