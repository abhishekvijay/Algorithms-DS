

#include <stdio.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>

using namespace std;

#define VISITED		1
#define UNVISITED	-1

typedef vector<int> vi;

vi adjL[15];
int visited[15];
queue<int> que;

void run_bfs(int node)
{
	register int i;
	int tnode;
	que.push(node);
	visited[node] = VISITED;

	while(!que.empty())
	{
		tnode = que.front();
		que.pop();

		cout<<" "<<tnode;

		for(i=0; i < (int)adjL[tnode].size(); ++i)
		{
			if (visited[adjL[tnode][i]] == UNVISITED)
			{
				que.push(adjL[tnode][i]);
				visited[adjL[tnode][i]] = VISITED;
			}
		}
	}
}

void breadth_first_search()
{
	int nodes, edges;
	register int i;
	int u, v;

	cout<<"Enter nodes & edges - "<<endl;
	cin>>nodes>>edges;

	for(i=0; i<edges; ++i)
	{
		cin>>u>>v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
		visited[i] = UNVISITED;
	}

	for(i=0; i<nodes; ++i)
	{
		if (visited[i] != VISITED)
			run_bfs(i);
	}
	
	cout<<endl;

	return;
}
