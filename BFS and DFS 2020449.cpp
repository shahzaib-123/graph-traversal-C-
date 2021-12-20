//============================================================================
// Name        : BFS.cpp
// Author      : shahzaib(2020449)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<list>
using namespace std;

class graph{
private:
	int **adjmatrix;
	char *nname;
	int size;
public:
	graph(char *n,int size)
	{
		this->size=size;
		this->nname=n;
		this->adjmatrix=new int *[size];
		for(int i=0;i<this->size;i++)
		{
			adjmatrix[i]=new int [size];
		}
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<this->size;j++)
			{
				adjmatrix[i][j]=0;
			}
		}
	}
	int getindex(char ver)
	{
		for(int i=0;i<this->size;i++)
		{
			if(nname[i]==ver)
			{
				return i;
			}
		}
	}
	void addedge(char x, char y)
	{
		adjmatrix[this->getindex(x)][this->getindex(y)]=1;
		adjmatrix[this->getindex(y)][this->getindex(x)]=1;
	}
	void displayGraph()
	{
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<this->size;j++)
			{
				cout<<adjmatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void BFS(char start, char goal)
	{
		bool *visited=new bool[this->size];
		for(int i=0;i<this->size;i++)
		{
			visited[i]=false;
		}
		list<char> queu;
		visited[this->getindex(start)]=true;
		queu.push_back(start);
		while (!queu.empty())
		{
			char vertex=queu.front();
			queu.pop_front();
			cout<<vertex<<" ";
			visited[this->getindex(vertex)]=true;
			if(vertex==goal)
			{
				delete []visited;
				return;
			}
			for(int i=0;i<this->size;i++)
			{
				if(adjmatrix[this->getindex(vertex)][i]==1 && visited[this->getindex(nname[i])]==false)
				{
					queu.push_back(nname[i]);
				}
			}
		}
		delete []visited;
	}
	void DFS(char start, char goal)
	{
		bool *visited=new bool[this->size];
		for(int i=0;i<this->size;i++)
		{
			visited[i]=false;
		}
		list<char> stack;
		visited[this->getindex(start)]=true;
		stack.push_back(start);
		while (!stack.empty())
		{
			char vertex=stack.back();
			stack.pop_back();
			visited[this->getindex(vertex)]=true;
			cout<<vertex<<" ";
			if(vertex==goal)
			{
				delete []visited;
				return;
			}
			for(int i=0;i<this->size;i++)
			{
				if(adjmatrix[this->getindex(vertex)][i]==1 && visited[this->getindex(nname[i])]==false)
				{
					stack.push_back(nname[i]);
				}
			}
		}
	delete []visited;
	}
	~graph()
	{
		for(int i=0;i<this->size;i++)
		{
			delete []adjmatrix[i];
		}
		delete[] adjmatrix;
	}
};


int main() {
	char vertices[10]={'S','A','B','C','D','E','F','G','H','I'};
	int s=10;
	graph g1(vertices,10);
	g1.addedge('S','A');
	g1.addedge('S','B');
	g1.addedge('S','C');
	g1.addedge('A','D');
	g1.addedge('B','D');
	g1.addedge('C','E');
	g1.addedge('C','H');
	g1.addedge('D','F');
	g1.addedge('E','F');
	g1.addedge('E','H');
	g1.addedge('F','G');
	g1.addedge('H','G');
	g1.addedge('G', 'I');
	g1.displayGraph();
	return 0;
}
