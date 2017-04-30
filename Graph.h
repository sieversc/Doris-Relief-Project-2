
#ifndef _Graph_H
#define _Graph_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Adjlist.h"

class Graph
{
public:
	Graph(int v);
	~Graph();
	
	int size;
	AdjList* array;

	void createGraph(int v);

	void  addEdge(int src, int dest, int weight);

	void printAdjList();
};


#endif