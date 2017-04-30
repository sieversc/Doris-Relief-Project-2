#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <string>

int main(){

	Graph *test = new Graph(5);

	test -> addEdge(0, 1, 4);

	test -> addEdge(0, 2, 8);

	test -> addEdge(1, 2, 1);

	test -> addEdge(1, 3, 6);

	test -> addEdge(2, 3, 1);

	test -> addEdge(2, 4, 22);

	test->displayMatrix();

	test -> dijkstra(0);

	return(0);
}