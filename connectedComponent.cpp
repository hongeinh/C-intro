/**
 * CONNECTED COMPONENTS OF AN UNDIRECTED GRAPH
 * IDEA: USE DFS TO EXPLORE THE GRAPH. USE A GLOBAL VARIABLE nCC TO KEEP TRACK OF THE NUMBER OF CONNECTED COMPONENT
 * AND A DEPTH ARRAY TO KEEP TRACK OF WHICH NODE HAS BEEN VISITED.
*/  

#include<iostream>
#include<vector>
#define MAX 100007
using namespace std;

int numberOfEdges, numberOfVertices;
vector<int> adjacent[MAX];

void input()
{
    cin >> numberOfVertices >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

int visited[MAX];
void init()
{
    for (int i = 1; i <= numberOfVertices; i++)
    {
        visited[i] = 0;
    }
    
}

int nCC;
void DFS(int s)
{
    visited[s] = 1; 
    int sz = adjacent[s].size();
    for(int i = 0; i < sz; i++)
    {
        int u = adjacent[s][i];
        if(!visited[u])
        {
            DFS(u);
        }
    }
}

void DFS()
{
    nCC = 0;
    for (int i = 1; i <= numberOfVertices; i++)
    {
        if( !visited[i] )
        {
            DFS(i);
            nCC++;
        }
    }
    
    cout << nCC << endl;
}

int main()
{
    input();
    init();
    DFS();
}