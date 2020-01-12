/**
 * COUNT THE NUMBER OF NODES AT GIVEN LEVEL USING BFS IN AN UNDIRECTED GRAPH
 * IDEA: use BFS
*/

using namespace std;

#include<iostream>
#include<vector>
#include<list>
#define MAX 1000
int numberOfNodes, numberOfEdges, level;
vector<int> adjacent[MAX];

void input()
{
    cin >> numberOfNodes >> numberOfEdges >> level;
    for(int i = 1; i <= numberOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }   
}

int d[MAX];
int cnt;

void init()
{
    for(int i = 1; i <= numberOfNodes; i++)
    {
        d[i] = -1;
    } 
}

void BFS(int s)
{
    d[s] = 0;
    list<int> Q;
    Q.push_back(s);

    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop_front();
        int sz = adjacent[x].size();

        for (int i = 0; i < sz; i++)
        {
            int u = adjacent[x][i];
            if(d[u] == -1)
            {
                Q.push_back(u);
                d[u] = d[x] + 1;
                cout << "d[" << u << "] = " << d[u] << endl;
            }
            if(d[u] == level) cnt++;
        }
    }
}

void BFS()
{
    cnt = 0;
    for(int i = 1; i <= numberOfNodes; i++)
    {
        if(d[i] == -1)
        {
            //cout << "BFS(" << i << ")" <<endl;
            BFS(i);
        }
    }
    cout << cnt << endl;
}

int main()
{
    input();
    init();
    BFS();
}