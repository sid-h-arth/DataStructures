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
void graphBFS(vector<int> aj[],int v,int s)
{
	vector<bool> visited(v+1,false);
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

int main()
{
	int v=5;
	vector<int> aj[v];
	addedge(aj,0,1);
	addedge(aj,0,2);
	addedge(aj,1,2);
	addedge(aj,1,3);
	addedge(aj,2,3);
	addedge(aj,3,4);
	addedge(aj,2,4);
	cout<<"Adjacency List: "<<endl;
	printgraph(aj,v);
	cout<<endl<<"BFS Traversal:"<<endl;
	graphBFS(aj,v,0);
	return 0;
}
