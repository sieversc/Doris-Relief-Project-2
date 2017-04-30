#include "Graph.h"
#include "Adjlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;


AdjList::AdjList(){
	AdjListNode *head = NULL;
}

AdjList::~AdjList(){

}

struct AdjListNode* AdjList::newAdjListNode(int dest, int weight){

	struct AdjListNode* newNode = new AdjListNode;

	newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    
    return newNode;

}

void AdjList::printList()
{
	if(head != NULL){
		printHelper(head);
	}
}



void AdjList::printHelper(AdjListNode* node){
	cout << node->dest << ", " << node->weight << "\t\t";
	if(node->next != NULL){
		printHelper(node->next);
	}

}