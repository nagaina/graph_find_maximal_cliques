#ifndef _graph_hpp_
#define _graph_hpp_

#include <vector>
#include <iostream>

class Vertex;

typedef std::vector<int> Neighbours;
typedef std::vector<Vertex> Vertices;

struct Vertex
{
	Vertex(const Neighbours& = Neighbours());
	void input();
	void add_edge(int);
	void print();
	int number_of_edge();
	Neighbours neighbour;
};

class Graph
{
public:
	Graph(int = 0);
	void input();
	void print();
	bool is_connected();
	bool connected_component();
private:
	void DFS(int);
	void BK(std::vector<int> , std::vector<int>, std::vector<int>);
 
	Vertices vertices;
	std::vector<bool> visited;
	Vertices connected_comp;
	Neighbours R;
	Neighbours P;
	Neighbours X;
};

#endif
