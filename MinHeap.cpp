
#include "MinHeap.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;


MinHeap::MinHeap(int capacity)
{
	size = 0;
	this->capacity = capacity;
	pos = new int[capacity];
	array = new MinHeapNode[capacity];
}

MinHeap::~MinHeap()
{

}

struct MinHeapNode newMinHeapNode(int v, int dist)
{
	struct MinHeapNode newNode;
	newNode.v = v;
	newNode.dist = dist;
	return newNode;
}

void MinHeap::swapMinHeapNode(struct MinHeapNode a, struct MinHeapNode b)
{
	struct MinHeapNode temp = a;
	a = b;
	b = temp;
}

bool MinHeap::isEmpty()
{

	return(size==0);
}

void MinHeap::heapify(int index)
{
	int smallest, left, right;
	smallest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if(left< size && array[left].dist < array[smallest].dist){
		smallest = left;
	}

	if(right < size && array[right].dist < array[smallest].dist){
		smallest = right;
	}

	if(smallest != index){
		MinHeapNode smallNode = array[smallest];
		MinHeapNode indexNode = array[index];

		pos[smallNode.v] = index;
		pos[indexNode.v] = smallest;

		swapMinHeapNode(array[smallest], array[index]);

		heapify(smallest);
	}
}

MinHeapNode MinHeap::extractMin()
{
	struct MinHeapNode root;
	root = array[0];

	struct MinHeapNode last = array[size-1];
	array[0] = last;

	pos[root.v] = size-1;
	pos[last.v] = 0;

	size--;
	heapify(0);

	return root;
}

void MinHeap::decreaseKey(int v, int dist)
{
	int i = pos[v];
	array[i].dist = dist;

	while(i && array[i].dist < array[(i-1)/2].dist)
	{
		pos[array[i].v] = (i-1)/2;
		pos[array[(i-1)/2].v] = i;
		swapMinHeapNode(array[i], array[(i-1)/2]);

		i = (i-1)/2;
	}
}

bool MinHeap::isInMinHeap(int v)
{
	if(pos[v] < size){
		return true;
	}
	return false;
}
