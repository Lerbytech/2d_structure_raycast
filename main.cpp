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

Field prepare_field(Field f)
{
	int x = 0;
	int y = 0;
	int i = 0;
	f.nodes = (Node*)malloc(sizeof(Node) * f.N);
	for (y = 0; y < f.H; y++)
		for (x = 0; x < f.W; x++)
		{
			f.nodes[i].val = i;
			f.nodes[i].posX = x;
			f.nodes[i].posY = y;
			i++;
		}
	
	return f;
}

void pretty_print(Field F)
{
	int x = 0;
	int y = 0;

	for (y = 0; y < F.H; y++)
	{
		for (x = 0; x < F.W; x++)
		{
			printf("%2d ", F.nodes[y * F.W + x].val);
		}
		printf("\n");
	}

}

void line_by_line_print(Field F)
{
	for (int i = 0; i < F.N; i++)
	{
		printf("%2d %2d %2d\n", F.nodes[i].val, F.nodes[i].posX, F.nodes[i].posY);
	}
}

int main()
{
	Field F;
	F = read_config_file();

	F = prepare_field(F);
	line_by_line_print(F);
	pretty_print(F);
	int u = 4;
}