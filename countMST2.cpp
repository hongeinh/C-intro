//COUNT NUMBER OF SPANNING TREE//
//----IDEA----//
/*
 
Use backtrack to enumerate through all possible spanning tree
Use disjoint sets to check if it's a cycle or not
-----> core method: TRY(k)
 
For a graph of n nodes, its spanning tree will have n-1 edges
*/
#include<iostream>
#define MAX_N 101
#define MAX_M 1001
 
using namespace std;
 
int numberOfNodes;
int numberOfEdges;
 
//endpoints of the i-th edge of the graph
int b[MAX_M];   //begin
int e[MAX_M];   //end
 
//--------SOLUTION REPRESENTATION----
//x[i] set of indices of edges of spanning trees
int x[MAX_N];   //indices of selected edges x[1] < x[2] < ... < x[numberOfNodes -1]
int p[MAX_N];
int r[MAX_N];
int set[MAX_N];
int cnt;    //to count number of spanning trees
 
void input()
{
	cin >> numberOfNodes >> numberOfEdges;
	for(int i = 1; i <= numberOfEdges; i++)
	{
		cin >> b[i] >> e[i];
	}
}
 
 
void makeSet(int x)
{
	p[x] = x;
	r[x] = 0;
}
 
void link(int x, int y)
{
	if(r[x] > r[y]) p[y] = x;
	else{
		p[x] = y;
		if(r[x] == r[y]) r[y] = r[y] + 1;
	}
}
 
int findSet(int x)
{
	if(x != p[x]) p[x] = findSet(p[x]);
	return p[x];
}
 
 
int checkNoCycle(int val, int k)
{
	//int v in this situation will be the index 
	//check if set edges induces a cycle
	for(int i = 1; i <= numberOfNodes; i++) makeSet(i);
	for(int i = 1; i < k; i++)
	{
		int u = b[x[i]];
		int v = e[x[i]];
		int ru = findSet(u);
		int rv = findSet(v);
		
		if(ru == rv) return 0;   //there is a cycle
		link(ru, rv); 
	}
	
	if(findSet(b[val]) == findSet(e[val]) )  return 0;
	return 1;
}
 
void solution()
{
	cnt++;
}
 
void TRY(int k)
{
	for(int v = x[k-1] + 1; v <= numberOfEdges; v++)   //for representation 
	{
		if(checkNoCycle(v,k))
		{
			x[k] = v;
			if(k == numberOfNodes - 1) solution();
			else TRY(k+1);
		}
	}
}
 
void solve()
{
	cnt = 0;
	TRY(1);   //k is edge
	cout << cnt;
}
 
int main()
{
	input();
	solve();
}