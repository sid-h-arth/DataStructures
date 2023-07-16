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
		for(auto x : aj[i])
		{
				cout<<x<<" ";
		}
		
		cout<<endl;
	}
}

int main()
{
	int v=4;
	vector<int> aj[v];
	addedge(aj,0,1);
	addedge(aj,0,2);
	addedge(aj,1,2);
	addedge(aj,2,3);
	printgraph(aj,v);
	return 0;
}
