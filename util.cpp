#include "util.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "heap.h"

using namespace std;

/*string filename = "Ginput.txt";

Graph readAndBuildGraph() {
	string line;
	ifstream file(filename.c_str());
	if (file.is_open()){
	    int n; //verticies
	    int m; //edges
	    file >> n >> m;
	    //std::cout << "numbers " << ' ' << n << ' ' <<  m << '\n';

	    Graph graph* = graph->createGraph(n, m);

	    for(int i = 0; i < m; i++) {
	      int u; //from
	      int v; //to
	      int w; //weight
		  file >> u >> v >> w;

		  graph->addEdge(graph, u, v, w, i);
		  //assign to graph

		  std::cout << "edge: " << ' ' << u << ' ' << v << ' ' << w << '\n';
	    }
		file.close();
	}
	return graph*;
}*/


int nextCommand(int *i, int *v, int *f) {
	char character;
	while (cin >> character) {
	    if(character == ' ' || character == '\t' || character == '\n' || character == '0'){
			continue;
		} else if (character == 'E' || character == 'e') {
			break;
		} else if (character == 'I' || character == 'i') {
			break;
		} else if (character == 'W' || character == 'w') {
			break;
		} else if (character == 'C' || character == 'c') {
			printf("Please enter first vertex. \n");
			cin >> *i;
			//scanf("%d", *i);
			printf("Please enter second vertex. \n");
			cin >> *v;
			//scanf("%d", *v);
			printf("Please enter iFlag (0 = length, 1 = Path) \n");
			cin >> *f;
			//scanf("%d", *i);
			break;
		} else {
			cout << "Invalid Command\n" << endl;
			break;
			//cout << "Invalid Command\n" << endl;
			//printf("COMMAND: %c \n", character);
		}
	}
	return character;
}
