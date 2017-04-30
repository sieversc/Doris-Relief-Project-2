#ifndef _MinHeap_
#define _MinHeap_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Adjlist.h"
using namespace std;

struct MinHeapNode
{
	int v;
	int dist;	
};


class MinHeap
{
public:

	int size;
	int capacity;
	int *pos;
	struct MinHeapNode* array;


	MinHeap(int capacity);
	~MinHeap();

	struct MinHeapNode* newMinHeapNode(int v, int dist);

	MinHeap* createMinHeap(int capacity);

	void swapMinHeapNode(struct MinHeapNode a, struct MinHeapNode b);

	void heapify(int index);

	bool isEmpty();

	MinHeapNode extractMin();

	void decreaseKey(int v, int dist);

	bool isInMinHeap(int v);

	void printArray(int dist[], int n);


};

#endif