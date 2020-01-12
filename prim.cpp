//Implement an algorithm that will find the minimum spanning tree of a given graph
//---------IDEA -------
/*
** Apply Prim's algorithm
*/
#include<iostream>
#include<vector>

#define MAX 100001

using namespace std;
//INPUT-------------------------------------------------------
int numberOfNodes, numberOfEdges;
vector<int> adjacent[MAX];
vector<int> weight[MAX];

//SOLUTION REP-------------------------------------------------
int answer;
int mstSet[MAX];  //minimum spanning tree set: keeps track of the nodes that have been included int the tree
int key[MAX];
int parent[MAX];
//SOLUTION-----------------------------------------------------
void input()
{
    cin >> numberOfNodes >> numberOfEdges;

    for(int i = 1; i <= numberOfEdges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);

        weight[u].push_back(w);
        weight[v].push_back(w);
    }
}

void init(int s)
{
    for (int i = 1; i <= numberOfNodes; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = s;
    }
    key[s] = 0;
    mstSet[s] = 1; //s is included int the MST
    parent[s] = -1; ///parent of root is empty
}

//utility func to find an adjacent node x of s which w(s,x) is min
int minimumAdjacentNode(int s)
{
    int min_weight = INT_MAX;
    int min_node = 0;

    int sz = adjacent[s].size();
    for(int i = 0; i < sz; i++)
    {
        if(weight[s][i] < min_weight)
        {
            min_weight = weight[s][i];
            min_node = adjacent[s][i];
        }
    }

    return min_node;
}

int findMST(int s)
{
    init(s);
    

    

    for (int i = 1; i <= numberOfEdges; i++)
    {
        int u = minimumAdjacentNode(s);
        mstSet[u] = 1;
        
        for(int v = 1; v <= numberOfEdges; v++)
        {
            //if there is edge (u,v) and v not in MST yet and key v is greater than weight of edge(u,v)
            if(adjacent[u][v] && !mstSet[v] & weight[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = weight[u][v];
            }
        }

    }
    
}

int solve()
{
    answer = 0;
    input();

    return answer;
}