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

void graphBFS(vector<int> aj[],vector<bool>& visited,int s)
{
	visited[s]=true;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		cout<<f<<" ";
		for(int i : aj[f])
		{
			if(visited[i]==false)
			{
				visited[i]=true;
				q.push(i);
			}
		}
	}
}

void disconnected_graph(vector<int> aj[],int v)
{
	vector<bool> visited(v+1,false);
	int count=0;
	for(int i=0; i<v; i++)
	{
		if(visited[i]==false)
		{
			graphBFS(aj,visited,i);
			count++;
		}		
	}
	cout<<endl<<"Total Number of discontinuous graphs: ";
	cout<<count;
}

int main()
{
	int v=7;
	vector<int> aj[v];
	addedge(aj,0,1);
	addedge(aj,0,2);
	addedge(aj,1,3);
	addedge(aj,2,3);
	addedge(aj,4,5);
	addedge(aj,5,6);
	addedge(aj,6,4);
	cout<<"Adjacency List: "<<endl;
	printgraph(aj,v);
	cout<<endl<<"BFS Traversal:"<<endl;
	disconnected_graph(aj,v);
	return 0;
}
