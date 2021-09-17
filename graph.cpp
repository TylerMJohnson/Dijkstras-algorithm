#include "graph.h"

using namespace std;

/**
 * Creates a new graph
 */
Graph* createGraph(int vcount, int ecount){
	Graph* array = (Graph*) malloc(sizeof(Graph) * (vcount + 1));
	array->verticeCount = vcount;
	array->edgeCount = ecount;
	for(int i = 1; i <= vcount; i++){
		array[i].head = NULL;
		array[i].index = i;
	}
	return array;
}

/**
 * Creates new node.
 */
LIST* createNewNode(int id, int weight){
	LIST* newNode = new LIST;
	newNode->id = id;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

/**
 * Add edge to graph.
 */
void addEdge(Graph* graph, int from, int too, int weight){
	if((from <= graph->verticeCount && too <= graph->verticeCount) && (from > 0 && too > 0)){
		LIST* newNode = createNewNode(too, weight);
		newNode->next = graph[from].head;
		graph[from].head = newNode;
	}
}

/**
 * Prints the graph.
 */
void printGraph(Graph* graph){
	cout << "Vertices: " << graph->verticeCount << " Edges: " <<  graph->edgeCount << "\n";
	for(int i = 1; i <= graph->verticeCount; i++){
		cout << graph[i].index << ": ";
		if(graph[i].head != NULL){
			LIST* iterator = graph[i].head;
			while(iterator){
				cout << "(" << iterator->id << ", " << iterator->weight << ");";
				iterator = iterator->next;
			}
			cout << endl;
		}
	}
	cout << "\n";
}

/**
 * Initializes Single Source
 */
Heap singleSource(Graph* graph, int from){
	Heap heap = createHeap(graph->verticeCount);
	Element* distances = (Element*) malloc((graph->verticeCount +1 ) * sizeof(Element));

	for(int i = 1; i <= graph->verticeCount; i++){
		distances[i].key = INT_MAX;
		distances[i].vertex = i;
	}
	distances[from].key = 0;
	buildHeap(heap, distances);

	free(distances);
	return heap;
}

/**
 * Applies Dijkstras algo.
 */
vector<int> dijkstra(Graph* graph, int from, int too, int output){
	vector<int> vect;
	int* path = (int*) malloc(sizeof(int) * (graph->verticeCount + 1));
	for(int i = 1; i <= graph->verticeCount; i++){
		path[i] = -1;
	}
	Element* elements = (Element*) malloc((graph->verticeCount + 1) * sizeof(Element));
	Element u, v;
	Heap heap = singleSource(graph, from);

	for(int i = 1; i <= graph->verticeCount; i++){
		elements[i].key = INT_MAX;
		elements[i].vertex = i;
	}
	elements[from].key = 0;

	LIST* node;

	while(!isEmpty(heap)){
		u = extractMin(heap);
		node = graph[u.vertex].head;
		while(node != NULL){
			v = elements[node->id];
			if(v.key > u.key + node->weight){
				decreaseKey(heap, v.vertex, u.key + node->weight);
				elements[v.vertex].key = u.key + node->weight;
				path[v.vertex] = u.vertex;
			}
			node = node->next;
		}
	}

	int index = too;
	if(elements[too].key == INT_MAX){
        cout << "Sorry, node " << too <<" is not reachable from node " << from << endl;
	}else{
	    if (output == 0) {
            cout << "Length: " << elements[too].key << endl;
        }
	}
	while(path[index] != -1){
		vect.push_back(path[index]);
		index = path[index];
	}

	free(heap.data);
	free(elements);
	free(path);
	return vect;
}
