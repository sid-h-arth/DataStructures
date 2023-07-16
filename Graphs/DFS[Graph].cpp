#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int> aj[],int u,int v)
{
	aj[u].push_back(v);
	aj[v].push_back(u);
}
void printgraph(vector<int> aj[],int v)
{
	for(int i=0; i<v; i++)
	{
		cout<<i<<" : ";
		for(auto x:aj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}
void dfs(vector<int> aj[],int s,vector<bool> &visited)
{
	visited[s]=true;
	cout<<s<<" ";
	for(auto u:aj[s])
	{
		if(visited[u]==false)
		{
			visited[u]=true;
			dfs(aj,u,visited);
		}
	}
}
void DFS_disc(vector<int> aj[],int v)
{
	vector<bool> visited(v,false);
	for(int i=0; i<v; i++)
	{
		if(visited[i]==false)
			dfs(aj,i,visited);
	}
}

int main()
{
	int v=8;
	vector<int> aj[v];
	addedge(aj,0,2);
	addedge(aj,0,1);
	addedge(aj,2,3);
	addedge(aj,1,3);
	addedge(aj,1,4);
	addedge(aj,3,4);
	addedge(aj,5,6);
	addedge(aj,6,7);
	printgraph(aj,v);
	cout<<"DFS Traversal: "<<endl;
	DFS_disc(aj,v);
	return 0;
}
