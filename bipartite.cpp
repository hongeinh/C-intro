/**
 * BIPARTITE GRAPH: a graph whose vertices can be divided into 2 disjoint and independent sets and such that every edge connects a vertex in to one in
 * @AUTHOR: HONG ANH
 * IDEA: BFS, for every node we give it a d value, if a node and its parent's values are both even or odd then this graph is not bipartite
*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

int n, m;
vector<int> adjacent[100];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; 
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    
}

int d[100];
void init()
{
    for (int i = 1; i < n; i++) d[i] = -1;
    
}

bool BFS(int s)
{
    d[s] = 0;
    list<int> Q;
    Q.push_back(s);

    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop_front();
        int sz = adjacent[v].size();
        for (int i = 0; i < sz; i++)
        {
            int u = adjacent[v][i];
            if(d[u] == -1)
            {
                d[u] = d[v] + 1;
                Q.push_back(u);
            }
            else if( d[u] > -1 && d[v] % 2 == d[u] % 2) return false;
        }
    }

    return true;
}

int BFS()
{
    for (int i = 1; i <= n; i++)
    {
        if(d[i] == -1 && BFS(i) == false) return 0;

    }
    return 1;
}

int main()
{
    input();
    init();
    cout << BFS();
}