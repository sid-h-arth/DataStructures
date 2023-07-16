#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void addedge(int a,int b,unordered_map<int,vector<int>> &adj)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void printT(unordered_map<int,vector<int>> &adj,int V)
{
	for(int i=1; i<=V; i++)
	{
		cout<<i<<": ";
		for(auto x : adj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}

int dist[6];
void dfs(int s,unordered_map<int,vector<int>> &adj,int p)
{
	for(auto x : adj[s])
	{
		if(x==p)
			continue;
		dist[x]=dist[s]+1;
		dfs(x,adj,s);
	}
}

int main()
{
	int V,E;
	cout<<"Enter the number of Nodes: ";
	cin>>V;//number of vertices
	E=V-1;//edges
	unordered_map<int,vector<int>> adj(V+1);
	cout<<endl<<"Enter the edges: "<<endl;
	for(int i=0; i<E; i++)
	{
		int a=0,b=0;
		cin>>a>>b;
		addedge(a,b,adj);
	}
	cout<<endl<<"adjaceny List: "<<endl;
	printT(adj,V);
	dist[1]=0;
	dfs(1,adj,-1);
	int mx_node,max_height=-1;
	for(int i=1; i<=V; i++)
	{
		if(dist[i]>max_height)
		{
			max_height=dist[i];
			mx_node=i;
		}
		dist[i]=0;//reset i for next dfs
	}
	
	dfs(mx_node,adj,-1);
	int mx_depth=-1;
	for(int i=1; i<=V; i++)
	{
		if(dist[i]>mx_depth)
			mx_depth=dist[i];
	}
	cout<<endl<<"Max Diameter: "<<mx_depth;
	return 0;
}
