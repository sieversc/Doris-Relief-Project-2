#include "Graph.h"
#include "Adjlist.h"
#include "MinHeap.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;


void print(int dist[], int n){

	cout << "Vertex\tDistance from Source\n";
	for(int i = 0; i <n; i++)
	{
		cout << endl << i << "\t\t" << dist[i];
	}

	cout << endl;
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool visited[], int V)
{
   // Initialize min value
   int min = INT_MAX;
   int min_index;
  
   for (int v = 0; v < V; v++){
     if (visited[v] == false && dist[v] <= min){
         min = dist[v];
         min_index = v;
     }
   }
  
   return min_index;
}

void dijkstra(Graph* graph, int src)
{
	int v = graph->size;
	int dist[v];

	bool visited[v];

	for(int i = 0; i < v; i++){
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	dist[src] = 0;

	for(int count = 0; count < v-1; count++){

		int u = minDistance(dist, visited, v);

		visited[u] = true;

		AdjListNode* node = graph->array[u].head;

		int v = node->dest;

		//cout << endl << endl << "|v=" << v <<" u=" << u <<  ", node weight = " << node->weight << "|" << endl << "  |dist[u]=" << dist[u] << "|" << endl;

		while(node != NULL){
			v = node->dest;

			//cout << "  |Node: " << node->dest << "|" <<  endl;

			if(node->weight + dist[u] < dist[v]){
				dist[v] = node->weight + dist[u];
			}

			node = node->next;

		}
	}

	print(dist, v);
}




int main()
{
	int v = 7;
	Graph* graph = new Graph(v);

	graph->addEdge(0,1,1);
	graph->addEdge(1,2,1);
	graph->addEdge(2,4,1);
	graph->addEdge(4,3,1);
	graph->addEdge(3,0,1);

	graph->addEdge(2,5,20);
	graph->addEdge(4,6,10);
	graph->addEdge(5,6,1);



	graph -> printAdjList();

	dijkstra(graph, 0);

return(0);
}