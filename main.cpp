#include "graph.hpp"

int main()
{
	int size = 0;
	std::cout <<"Insert graph size"<<std::endl;
	std::cin>>size;
	Graph g(size);
	g.input();
	g.print();
	if (g.is_connected())
		std::cout<<"Graph is connected"<<std::endl;
	else
		std::cout<<"Graph isn't connected"<<std::endl;
	//std::cout<<"Insert graph connectivity: k = ";
	//int k = 0;
	//std::cin >> k;	
	if (!g.connected_component())
		std::cout<<"There isn't Kp"<<std::endl;
	std::cout<<std::endl;
}
	
