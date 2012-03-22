#include <stdio.h>
#include "value.h"
#include "parse.h"
#include "parse_file.h"

/* Parse directly from a FILE. */
static FILE *source_file = 0;  /* source of characters */

void file_read_ch(void)
	{
	ch = fgetc(source_file);
	}

struct value *parse_file(FILE *file)
	{
	read_ch = file_read_ch;
	source_file = file;
	return parse_source();
	}