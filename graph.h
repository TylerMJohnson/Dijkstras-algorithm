#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>

#include "heap.h"
#include "util.h"

struct LIST{
	int id;
	int weight;
	struct LIST *next;
};

struct Graph{
	LIST* head;
	int index;
	int verticeCount;
	int edgeCount;
};

Graph* createGraph(int numOfVertices, int numOfEdges);
LIST* createNewNode(int id, int weight);
void addEdge(Graph* array, int i, int j, int weight);

void printGraph(Graph* graph);
Heap singleSource(Graph* graph, int src);
vector<int> dijkstra(Graph* graph, int src, int dst, int flag);

#endif
