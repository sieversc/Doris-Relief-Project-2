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

		void createMatrix(int length);

		void addEdge(int startNode, int endNode, int weight);

		void displayMatrix();

	private:

};

#endif