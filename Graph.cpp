#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <string>

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
		}
	}
}

void Graph::addEdge(int start, int end, int weight){

	if(start < 0 || end < 0 || weight < 0 || start > length || end > length){
		cout << "Enter positive values\n";
	}

	else{
		adjmat[start][end] = weight;
	}
}

void Graph::displayMatrix(){
	int i,j;

	for(i=0; i<length; i++){
		for(j=0; j<length; j++){
			cout << adjmat[i][j] << " ";
		}
		cout << endl;
	}
}
