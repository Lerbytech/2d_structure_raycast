#pragma once
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

Field read_config_file();
Field prepare_field(Field f);
void print_field_pretty(Field F);
void print_field_line_by_line(Field F);