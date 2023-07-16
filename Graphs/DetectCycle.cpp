#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int> aj[],int u,int v)
{
	aj[u].push_back(v);
	aj[v].push_back(u);
}
bool DFS(vector<int> aj[],vector<bool> &visited,int s,int p)
{
	visited[s]=true;
	for(auto x:aj[s])
	{
		if(visited[x]==false)
		{
			if(DFS(aj,visited,x,s))
				return 1;
		}
		else if(x!=p)
			return 1;
	}
	return 0;
}
bool cycle(vector<int> aj[],int v)
{
	vector<bool> visited(v+1,false);
	for(int i=0; i<v; i++)
	{
		if(visited[i]==false)
		{
			if(DFS(aj,visited,i,-1))
				return 1;
		}
	}
	return 0;
}


void printGraph(vector<int> aj[],int v)
{
	for(int i=0; i<v; i++)
	{
		cout<<i<<" : ";
		for(auto x:aj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}
int main()
{
	int v=6;
	vector<int> aj[v];
	addedge(aj,0,1);
	addedge(aj,1,2);
	addedge(aj,1,3);
	addedge(aj,3,2);
	addedge(aj,2,4);
	addedge(aj,4,5);
	printGraph(aj,v);
	if(cycle(aj,v))
		cout<<"cycle detected";
	else
		cout<<"No Cycle";
	return 0;
}
