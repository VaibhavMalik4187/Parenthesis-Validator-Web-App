#include <iostream>
#include <vector>

using namespace std;

/*
You can divide all vertices of a graph in 2 sets such that all the edges from the graph are from set 1 to set 2
--> what we can do is the coloring of the vertices

Note : it is also known as 2 coloring problem

Approach :
--> we need to check if the graph contains a cycle and that cycle contains odd number of vertices
--> either an odd cycle or a vertex pointing to an already visited vertex having the same color

The code is quite similar to cycle detection 
*/

bool dfs_helper(vector <int> graph[],int node,int *visited,int color,int parent)
{
	//come to a node 

	visited[node]=color;

	for(auto nbr : graph[node])
	{
		//iterate over all the neighbours 

		if(visited[nbr]==0)
		{
			//means the node is unvisited

			bool subProb=dfs_helper(graph,nbr,visited,node,(3-color));

			if(subProb==false)
			{
				return false;
			}
		}
		else if(nbr!=parent && color==visited[nbr])
		{
			return false;
		}
	}

	return true;
}

bool dfs(vector <int> graph[],int n)
{
	int visited[n]={0};

	int color=1;
	bool ans=dfs_helper(graph,0,visited,-1,color);

	//later on let's print the colors

	for(int i=0;i<n;i++)
	{
		cout<<i<<" - Color - "<<visited[i]<<endl;
	}

	return ans;
}


int main()
{
	int n,m;

	cin>>n>>m;

	vector <int> graph[n];

	while(m--)
	{
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	//BFS or DFS by coloring teh nodes at each step (current node has been colored 1 and thus the neighbouring node should be having color 2)

	if(dfs(graph,n))
	{
		cout<<"Yes it is a BIPARTITE graph"<<endl;
	}
	else
	{
		cout<<"No it is not a BIPARTITE graph"<<endl;
	}

	return 0;
}