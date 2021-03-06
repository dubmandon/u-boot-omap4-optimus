#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

typedef struct __battery_graph_prop
{
	s32 x;
	s32 y;
} battery_graph_prop;

extern int reference_graph(int __x, battery_graph_prop* ref_battery_graph, int arraysize, int* error_range);
