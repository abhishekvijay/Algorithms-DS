
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

/*#####################################################################################*/

int grid[MAX][MAX];
int mvstd[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

typedef struct POINT
{
	int x; int y;
} point;


void bfs_matrix(int x, int y)
{
	register int i;
	point que[MAX*MAX] = {0, };
	int f = 0, r = 0, x1 = 0, y1 = 0;

	que[r].x = x; que[r++].y = y;
	mvstd[x][y] = VISITED;

	while(f != r)
	{
		point temp = que[f++];

		cout<<" "<<temp.x<<" "<<temp.y<<endl;

		for(i=0; i<4; ++i)
		{
			x1 = temp.x + dx[i];
			y1 = temp.y + dy[i];

			if (x1 >= 0 && x1 < MAX && y1 >= 0 && y1 < MAX && (grid[x1][y1] == 1) &&(mvstd[x1][y1] == UNVISITED))
			{
				que[r].x = x1; que[r++].y = y1;
				mvstd[x1][y1] = VISITED;
			}
		}
	}

	return;
}

void adj_matrix_method()
{
	int nodes, edges, u, v;
	register int i, j;

	cout<<"Enter Nodes & Edges - ";
	cin>>nodes>>edges;

	//init()
	for(i=0; i<nodes; ++i)
	{		
		for(j=0; j<nodes; ++j)
		{
			grid[i][j] = -1;
			mvstd[i][j] = UNVISITED;
		}
	}

	for(i=0; i<edges; ++i)
	{
		cin>>u>>v;
		grid[u][v] = 1;
		grid[v][u] = 1;
	}

	for(i=0; i<nodes; ++i)
	{
		for(j=0; j<nodes; ++j)
		{
			if ((grid[i][j] == 1) && (mvstd[i][j] == UNVISITED))
				bfs_matrix(i, j);
		}
	}

	cout<<endl;

	return;
}


void solve_grid(void)
{
	adj_list_method();

	adj_matrix_method();

}