#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addedege(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int v)
{
	for(int i=0; i<v; i++)
	{
		cout<<i<<" : ";
		for(auto x:adj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}
void path(vector<int> adj[],int v,int s,vector<bool> &visited,queue<int> &q,vector<int> &dist)
{
	q.push(s);	
	visited[s]=true;
	dist[s]=0;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(auto x:adj[f])
		{
			if(visited[x]==false)
			{
				dist[x]=dist[f]+1;
				visited[x]=true;
				q.push(x);
			}
		}
	}	
}

int main()
{
	int v=4;
	vector<int> adj[v];
	addedege(adj,0,1);
	addedege(adj,1,2);
	addedege(adj,2,3);
	addedege(adj,3,0);
	addedege(adj,3,1);
	printGraph(adj,v);
	
	vector<bool> visited(v,false);
	vector<int> dist(v,INT_MAX);
	queue<int> q;
	
	for(int i=0; i<v; i++)
	{
		if(!visited[i])
			path(adj,v,i,visited,q,dist);
	}
	
	cout<<"Distances: "<<endl;
	for(int i=0; i<v; i++)
	{
		cout<<"0 : "<<i<<" = "<<dist[i]<<endl;
	}
}
