#include<iostream>
using namespace std;
int parent[1000];
int rrank[1000];
void init(int n)
{
	for(int i=1; i<=n; i++)
	{
		parent[i]=i;
		rrank[i]=0;
	}
}

int findP(int node)
{
	if(node==parent[node])
		return node;
	return parent[node]=findP(parent[node]);
}

void Union(int u,int v)
{
	u=findP(u);
	v=findP(v);
	if(rrank[u]>rrank[v])
		parent[v]=u;
	else if(rrank[v]>rrank[u])
		parent[u]=v;
	else
	{
		parent[v]=u;
		rrank[u]++;
	}
}

int main()
{
	int V;
	cout<<"enter the number of nodes: ";
	cin>>V;
	init(V);
	Union(1,2);
	Union(2,3);
	Union(4,5);
	Union(6,7);
	Union(5,6);
	if(findP(2)!=findP(6))
		cout<<"different components";
	else
		cout<<"same components";
	return 0;
}
