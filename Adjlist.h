
#ifndef _AdjList_H
#define _AdjList_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
 
// A class to represent an adjacency liat
class AdjList
{

public:
	AdjList();
	~AdjList();

	AdjListNode *head;	//pointer to head of list

	// A utility function to create a new adjacency list node
	struct AdjListNode* newAdjListNode(int dest, int weight);

	void printList();

private:

	void printHelper(AdjListNode* node);

};


#endif