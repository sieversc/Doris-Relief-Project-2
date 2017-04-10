#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <string>

int main(){

	Graph *test = new Graph(5);

	test -> addEdge(0, 1, 4);

	test -> addEdge(0, 2, 8);

	test -> addEdge(1, 2, 6);

	test->displayMatrix();

	return(0);
}