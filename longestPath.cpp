/**
 * FIND THE LONGEST PATH ON A TREE
 * IDEA: USE 2 BFS
 * 1st BFS: from a random node v, find node x which is the furthest from v
 * 2nd BFS: from node x above, find node y which is the furthest from x.
 * ---> PATH (x, y) is the true longest path
*/

using namespace std;

#include <iostream>
#include <vector>
#include <list>

#define MAX 100001

int numberOfNodes, numberOfEdges;
vector<int> adjacent[MAX];
vector<int> weight[MAX];


void input()
{
    cin >> numberOfNodes >> numberOfEdges;
    for (int i = 1; i <= numberOfEdges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
}

int depth[MAX];
void init()
{
    for (int i = 1; i <= numberOfNodes; i++)
    {
        depth[i] = -1;
    }
}

int furthestNode;
int furthestDistance;

int BFS(int s)
{
    list<int> Q;
    Q.push_back(s);

    depth[s] = 0;
    furthestNode = 0;
    furthestDistance = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        int sz = adjacent[u].size();
        for (int i = 0; i < sz; i++)
        {
            int x = adjacent[u][i];
            if (depth[x] == -1)
            {
                Q.push_back(x);
                depth[x] = depth[u] + weight[u][i];

            }
            if (depth[x] > furthestDistance)
            {
                furthestDistance = depth[x];
                furthestNode = x;
            }
        }
    }

    return furthestNode;
}

void BFS()
{
    init();
    int x = BFS(1);
    init();
    int y = BFS(x);
    cout << furthestDistance << endl;
}

int main()
{
    input();
    BFS();
}