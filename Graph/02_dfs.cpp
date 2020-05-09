

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

#define VISITED		1
#define UNVISITED	-1

typedef vector<int>	vi;

vi adjList[15];
int vstd[15];

void run_dfs(int node)
{
	vstd[node] = VISITED;
	cout<<"node - "<<node<<endl;

	vi::iterator pos;
	for(pos = adjList[node].begin(); pos != adjList[node].end(); ++pos)
	{
		if (vstd[*pos] == UNVISITED)
			run_dfs(*pos);
	}
}

void depth_first_search()
{
	register int i;
	int u,v,num,edges,cc=0;
	
	cout<<"Enter Nodes & Edges - ";
	cin>>num>>edges;

	for(i=0; i<edges; ++i)
	{
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
		vstd[i] = UNVISITED;
	}

	for(i=0; i<num; ++i)
	{
		if (vstd[i] == UNVISITED)
		{
			run_dfs(i);
			cc += 1;
		}
	}

	cout<<endl;

	return;
}