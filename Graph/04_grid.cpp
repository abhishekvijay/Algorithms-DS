
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

#define MAX			10
#define UNVISITED	-1
#define VISITED		1

typedef vector<int> vi;
vi adjlist[10];
int vistd[10];

void bfs_list(int node)
{
	int temp = 0;
	queue<int> que;

	que.push(node);
	vistd[node] = VISITED;

	while(!que.empty())
	{
		temp = que.front();
		que.pop();

		cout<<" "<<temp;

		vi::iterator pos;
		for(pos = adjlist[temp].begin(); pos != adjlist[temp].end(); ++pos)
		{
			if (vistd[*pos] == UNVISITED)
			{
				que.push(*pos);
				vistd[*pos] = VISITED;
			}
		}
	}
}

void adj_list_method(void)
{
	int nodes, edges, u, v;
	register int i;

	cout<<"Enter Nodes & Edges - ";
	cin>>nodes>>edges;

	for(i=0; i<edges; ++i)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	for(i=0; i<nodes; ++i)
		vistd[i] = UNVISITED;

	for(i=0; i<nodes; ++i)
	{
		if (vistd[i] == UNVISITED)
			bfs_list(i);
	}

	cout<<endl;

	return;
}


void solve_grid(void)
{
	adj_list_method();

//	adj_matrix_method();

}