#include "Graph.h"
#include "Adjlist.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;


//Create a graph with v vertices
Graph::Graph(int v)
{
	size = v;
	array = new AdjList[v];

	for (int i = 0; i < v; ++i){
        array[i].head = NULL;
	}
}

Graph::~Graph()
{

}

void Graph::addEdge(int src, int dest, int weight)
{
	struct AdjListNode* newNode = array[src].newAdjListNode(dest, weight);
	newNode -> next = array[src].head;
	array[src].head = newNode;

	newNode = array[dest].newAdjListNode(src, weight);
	newNode->next = array[dest].head;
	array[dest].head = newNode;
}

void Graph::printAdjList()
{
	cout << "Vertex		Neighbors" << endl;
	for(int i = 0; i < size; i++){
		cout << i << "\t\t";
		array[i].printList();
		
		cout << endl;

	}


}