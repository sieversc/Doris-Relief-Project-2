#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits.h>

Graph::Graph(int n){
	createMatrix(n);
}

Graph::~Graph(){

}

void Graph::createMatrix(int length){

	this->length = length;

	adjmat = new int* [length];

	for(int i = 0; i < length; i++){

		adjmat[i] = new int [length];

		for(int j = 0; j < length; j++){
			adjmat[i][j] = -1;
			if(i==j){
				adjmat[i][j] = 0;
			}
		}
	}
}

void Graph::addEdge(int start, int end, int weight){

	if(start < 0 || end < 0 || weight < 0 || start > length || end > length){
		cout << "Enter positive values\n";
	}

	else{
		adjmat[start][end] = weight;
		adjmat[end][start] = weight;
	}
}

void Graph::displayMatrix(){
	int i,j;

	cout << endl << "__________________________________________________________\n";
	for(i=0; i<length; i++){
		for(j=0; j<length; j++){
			cout << adjmat[i][j] << "	 ";
		}
		cout << " |" << endl;
	}

	cout << "__________________________________________________________\n" << endl;
}

int Graph::findMin(int distance[], bool visited[]){
	int minimum[2] = {INT_MAX};
	int min = INT_MAX;
	int index = INT_MAX;

	for(int i=0; i<length; i++){
		if(visited[i] == false && distance[i] <= min){
			min = distance[i];
			index = i;
		}
	}

	return index;
}

void Graph::printDijkstra(int distance[]){
	cout << "Vertex		Distance from Source" << endl;
	for(int i=0; i<length; i++){
		cout << i << "			" << distance[i] << endl;
	}
}

void Graph::dijkstra(int source){

	int distance[length];
	bool visited[length];

	for(int i=0; i<length; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	
	distance[source] = 0;

	for(int count=0; count<length-1; count++){
		int u = findMin(distance, visited);
		visited[u] = true;

		for(int v=0; v<length; v++){
			if(!visited[v] && adjmat[u][v] && adjmat[u][v] != -1 && distance[u] != INT_MAX && distance[u] + adjmat[u][v] < distance[v]){
				distance[v] = distance [u] + adjmat[u][v];
			}

		}

	}

	printDijkstra(distance);
}