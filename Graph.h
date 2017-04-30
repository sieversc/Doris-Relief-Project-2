#ifndef _Graph_H
#define _Graph_H

#include <string>
#include <iostream>
#include <set>
using namespace std;


class Graph{

	public:

		/***********************************************************
			Default constructor for the graph class
				*creates an empty adjacency matrix
		**********************************************************/
		Graph(int n);

		~Graph();

		/***********************************************************
			local variables
		************************************************************/

		int **adjmat;

		int length;


		/************************************************************
			Creates an empty adjacency matrix of side dimensions length x length
				*assigns 0 weight to each nodes distance to itself
				* assigns -1 weight if two nodes are not connected
		************************************************************/
		void createMatrix(int length);

		/************************************************************
			connects startNode to Endnode and assigns a weight
		************************************************************/
		void addEdge(int startNode, int endNode, int weight);

		/************************************************************
			prints out every element in the n x n array in a grid
		************************************************************/
		void displayMatrix();

		void dijkstra(int source);

	private:

		int findMin(int distance[], bool visited[]);

		void printDijkstra(int distance[]);
};

#endif