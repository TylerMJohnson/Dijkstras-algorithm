#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "graph.h"
#include "heap.h"
#include "util.h"

using namespace std;

int main(){

	Graph* graph;
	vector<int> path;

	printf("Commands: e i w c \n");
	printf("E = Exit \n");
	printf("I = Read Ginput.txt \n");
	printf("W = Write Graph to Screen \n");
	printf("C s t iFlag = compute    s and t are nodes. iFlag 0 = Length and iFlag1 = Path \n");

	bool loaded = false;
	char cmd;
	int i, v, f;
	while (cmd != 'e') {
		cmd = nextCommand(&i, &v, &f);
		switch (cmd) {
			case 'e':
			case 'E': printf("COMMAND: %c.\n", cmd);
				cout << "Exiting Program." << endl;
				exit(0);
				break;

			case 'i':
			case 'I': printf("COMMAND: %c \n", cmd);
				if(!loaded){
					//printf("Attempting to build graph \n");
					string filename = "Ginput.txt";
					string line;
					ifstream file(filename.c_str());
					if (file.is_open()){
					    int n; //verticies
					    int m; //edges
					    file >> n >> m;
					    //std::cout << "numbers " << ' ' << n << ' ' <<  m << '\n';

					    graph = createGraph(n, m);

						int u; //from
						int v; //to
						int w; //weight

						int u2; //from
						int v2; //to
						int w2; //weight

						//std::cout << "edges: " << ' ' << m << '\n';
					    for(int i = 0; i < m; i++) {
						  file >> u >> v >> w;

						  if(u == u2 && v2 == v && w2 == w){
							  cout << "Two possible errors: \n";
							  std::cout << "Program cannot handle duplicate edges " << ' ' << u << ' ' << v << ' ' << w << '\n';
							  std::cout << "Content of Ginput.txt (Note the number of edges specified in the first line vs the actual number of edges provided!\n";
							  continue;
						  }

						  u2 = u;
						  v2 = v;
						  w2 = w;

						  //cout << "Adding edge: " << ' ' << u << ' ' << v << ' ' << w << endl;
						  addEdge(graph, u, v, w);

					    }
						file.close();
					}
					loaded = true;
				} else {
					cout << "Error:  There is already a graph loaded!" << endl;
				}
				break;

			case 'w':
			case 'W': printf("COMMAND: %c.\n", cmd);
				if(loaded){
					printGraph(graph);
				} else {
					cout << "Error:  There is no graph to print.";
				}
				break;

			case 'c':
			case 'C': printf("COMMAND: %c %d %d %d.\n", cmd, i, v, f);
				if(loaded){
					//i = first vertex
					//v = second vertex
					//f = flag (0 = length, 1 = Path)
					if(f < 0 || f > 1){
						printf("Error: Invalid flag value.");
						break;
					}
					if(i <= 0 || v <= 0 || i > graph->verticeCount || v > graph->verticeCount){
						printf("Error: Nodes are invalid.");
						break;
					}
					path = dijkstra(graph, i, v, f);
                    if ((path.size()) != 0) {
                        if (f == 1) {
                            cout << "PATH:";
                            //for each node in path print
                            for (int i = path.size() - 1; i >= 0; i--){
                                cout << path.at(i) << ",";
                            }
                            //add destination node
                            cout << v;
                            cout << endl;
                        }

                    }
                    if (i == v && f == 1) {
                        cout << "PATH:" << v;
                    }
				} else {
					printf("Error:  There is no graph to run Dijkstra’s algorithm on.");
				}
				break;
			default:
				break;
		}
	}
	return 0;
}



