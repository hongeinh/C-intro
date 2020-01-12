/**
 * COUNT ALL POSSIBLE PATHS BETWEEN 2 NODES
 * IDEA: Use DFS and Backtrack
 * @AUTHOR: HONG ANH
*/


using namespace std;

#include<iostream>
#include<vector>
#include<list>
#define MAX 1000
int numberOfVertices, numberOfEdges, fromV, toV;
vector<int> adjacent[MAX];

void input()
{
    cin >> numberOfVertices >> numberOfEdges >> fromV >> toV;
    for(int i = 1; i <= numberOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

int cnt;
int visited[MAX];
void init()
{
    for (int i = 1; i <= numberOfVertices; i++)
    {
        visited[i] = 0;
    }
    
}
void DFS(int s)
{
    visited[s] = 1;
    if(s == toV)
    {
        cnt++;
    }
    else
    {
        int sz = adjacent[s].size();
        for(int i = 0; i < sz; i++)
        {
            int x = adjacent[s][i];
            if(!visited[x]) DFS(x);
        }
    }
    visited[s] = 0; //backtrack
}

void DFS()
{
    cnt = 0;
    DFS(fromV);
    cout << cnt << endl;
}

int main()
{
    input();
    init();
    DFS();
}