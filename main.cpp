#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Field.h"

int main()
{
	Field F;
	F = read_config_file();

	F = prepare_field(F);
	print_field_line_by_line(F);
	print_field_pretty(F);
	int u = 4;
}