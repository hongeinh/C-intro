//tree means there is no cycle in a graph
//n nodes mean n-1 edge
//the path between 2 random nodes is unique

//---------IDEA------------
//Use 2 BFS
//1: choode a random node: find the furthest node from that, call it x  --> temporary longest path
//2: from x, find the real longest path using the same algorithm
//-------------------------

#include <iostream>
#include <list>
#include <vector>

#define MAX 100001

using namespace std;

int n;
vector<int> weight[MAX];
vector<int> adjacent[MAX];

int d[MAX]; //is depth of the node
int max_depth; 
int max_node;

void input()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
}

void init() //memset all distance to -1
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
    }
}

int BFS(int s)
{
    list<int> Q;
    Q.push_back(s);

    init();

    d[s] = 0;
    max_depth = 0;
    max_node = 0;


    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop_front();

        int sz = adjacent[v].size();
        for (int i = 0; i < sz; i++)
        {
            int x = adjacent[v][i];
            int w = weight[v][i];

            if (d[x] == -1)
            {
                Q.push_back(x);
                d[x] = d[v] + w;
            }
            if (d[x] > max_depth)
            {
                max_depth = d[x];
                max_node = x;
            }
        }
    }

    return max_node;
}

int solveLongestPath()
{
    int first_pair = BFS(1);
    int second_pair = BFS(first_pair);
    return max_depth;
}

int main()
{
    input();
    cout << solveLongestPath();
    return 0;
}