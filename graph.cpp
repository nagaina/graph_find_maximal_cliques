#include "graph.hpp"
#include <algorithm>

Vertex::Vertex(const Neighbours& ob)
{
	int size = ob.size();
	neighbour.resize(size);

	for (int i = 0; i < size; ++i)
		neighbour[i] = ob[i];
}

void Vertex::add_edge(int x)
{	
	neighbour.push_back(x - 1);
}

void Vertex::input()
{
	int n = 1;
	while (n)
	{
		std::cin >> n;
		add_edge(n);
	}

	neighbour.pop_back(); // the last is 0, that's why	
}

int Vertex::number_of_edge()
{
	return neighbour.size();
}

//
// Graph
//

Graph::Graph(int size):vertices(size) {}

void Graph::input()
{
	int size = vertices.size();
	
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Insert the neighbours of "<< i+1 <<"(0 for end)"<<std::endl;
		vertices[i].input();
	}
}

void Graph::print()
{
	int size = vertices.size();
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Vertex is "<< i+1<<" ";
		int n = vertices[i].number_of_edge();
		for (int j = 0; j < n; ++j)
			std::cout << vertices[i].neighbour[j] + 1<<" ";
		std::cout<<std::endl;
	}
}
	
bool Graph::is_connected()
{
	int size = vertices.size();	
	visited.resize(size);
	for (int i = 0; i < size; ++i)
		visited[i] = false;

	DFS(0);
	
	for (int i = 0; i < size; ++i)
		if (visited[i] == false)
			return false;

	return true;
}

void Graph::DFS(int v)
{
		visited[v] = true;
		std::vector<int>::iterator i;
		for ( i  = vertices[v].neighbour.begin() ; i != vertices[v].neighbour.end(); ++i)
		if(!visited[*i])
			DFS(*i);
}	

bool Graph::connected_component()
{
	//if (k > vertices.size())
	//	return false;
	R.clear();
	P.clear();
	X.clear();
	for (int i = 0; i < vertices.size(); ++i)
		P.push_back(i);
	BK(R,P,X);
		
	int size = connected_comp.size();
	for (int i = 0; i < size; ++i)
	{
		std::cout<<"Maximal clique ";
		int n = connected_comp[i].number_of_edge();
		for (int j = 0; j < n; ++j)
			std::cout << connected_comp[i].neighbour[j] + 1<<" ";
		std::cout<<std::endl;
	}
	return true;
}

void Graph::BK(std::vector<int> R, std::vector<int> P, std::vector<int> X)
{
	//std::cout<<"CAll"<<std::endl;
	if (X.size() == 0 && P.size() == 0)
		connected_comp.push_back(R);
	for (int i = 0; i < P.size(); ++i)
	{
		std::vector<int> R_new;
		for (int j = 0; j < R.size(); ++j)
			R_new.push_back(R[j]);
		R_new.push_back(P[i]);
		
	//std::cout<<"CAll1"<<std::endl;
		std::vector<int> P_new;
		if (P.size() != 0)
			for (int l = 0; l < vertices[P[i]].number_of_edge(); ++l)
			{
				int at = vertices[P[i]].neighbour[l];
				std::vector<int>::iterator it = std::find(P.begin(), P.end(), at);
				if (it != P.end())
					P_new.push_back(at);	
			}
	//std::cout<<"CAll2"<<std::endl;
		
		std::vector<int> X_new;
		if (X.size() != 0)
			for (int l = 0; l < vertices[X[i]].number_of_edge(); ++l)
			{
				int at = vertices[X[i]].neighbour[l];
				std::vector<int>::iterator it = std::find(X.begin(), X.end(), at);
				if (it != X.end())
					X_new.push_back(at);	
			}
		BK(R_new, P_new, X_new);
		if (P.size() != 0)
		{
			for (int l = 0; l < vertices[P[i]].number_of_edge(); ++l)
			{
				int at = vertices[P[i]].neighbour[l];
				std::vector<int>::iterator it = std::find(P.begin(), P.end(), at);
				if (it != P.end())
					P.erase(it);
			}
			for (int l = 0; l < vertices[P[i]].number_of_edge(); ++l)
				X.push_back(vertices[P[i]].neighbour[l]);
		}	
	}
}

