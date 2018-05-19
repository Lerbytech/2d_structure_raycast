#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int val;
	int posX;
	int posY;
};
struct Field
{
	int N;
	int W;
	int H;
	float nodeW;
	float nodeH;	
	Node* nodes;
};

Field read_config_file()
{
	Field RES;

	FILE *file = fopen("config.txt", "r");
	if (file == NULL)
	{
		printf("config file not found!!!\n");
		exit(1);
	}

	const size_t line_size = 300;
	char* line = (char*)malloc(line_size);
	char* delimiter = "= ";
	while (fgets(line, line_size, file) != NULL)
	{
		if (strstr(line, "#") == line)
			continue;
		
		if (strstr(line, "N = ") == line)
		{
			line = strstr(line, delimiter) + 2;
			RES.N = atoi(line);
			continue;
		}

		if (strstr(line, "W = ") == line)
		{
			line = strstr(line, delimiter) + 2;
			RES.W = atoi(line);
			continue;
		}
		
		if (strstr(line, "H = ") == line)
		{
			line = strstr(line, delimiter) + 2;
			RES.H = atoi(line);
			continue;
		}

		if (strstr(line, "nodeW = ") == line)
		{
			line = strstr(line, delimiter) + 2;
			RES.nodeW = atof(line);
			continue;
		}
		if (strstr(line, "nodeH = ") == line)
		{
			line = strstr(line, delimiter) + 2;
			RES.nodeH = atof(line);
			continue;
		}
		printf("%s", line);
	}
	return RES;
}

int main()
{
	Field F;
	F = read_config_file();
	int u = 4;
}