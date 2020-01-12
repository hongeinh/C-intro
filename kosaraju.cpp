/**
 * STRONGLY CONNECTED COMPONENT USING KASARAJU'S ALGORITHM
 * IDEA: Use 2 DFS
 * Data structure: stack and set
*/

#include<iostream>
#include<vector>
#include<stack>
#define MAX 1000007
using namespace std;

int numberOfVertices, numberOfEdges;
int result;
vector<int> adjacent[MAX];
vector<int> adjacent_reverse[MAX];

stack<int> STACK;
int visited[MAX];


void input()
{
    cin >> numberOfVertices >> numberOfEdges;
    
    for(int i = 1; i <= numberOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent_reverse[v].push_back(u);
    }
}

void init()
{
    for(int i = 0; i <= numberOfVertices; i++) visited[i] = 0;
}


void DFS(int v)
{
    if(!visited[v])
    {
        visited[v] = 1;
        //cout << v << " ";
        int sz = adjacent[v].size();
        for(int i = 0; i < sz; i++)
        {
            int u = adjacent[v][i];  //adjacent node of v
            DFS(u);
        }
        //only push when all children nodes have been visited
        STACK.push(v);
    }
}


void DFS()
{
    for(int i = 0; i <= numberOfVertices; i++) DFS(i);
}

void util(int v)
{
    visited[v] = 1;
    //cout << v << " ";
    int sz = adjacent_reverse[v].size();
    for(int i = 0; i < sz; i++)
    {
        int u = adjacent_reverse[v][i];
        if(!visited[u]) util(u);
    
    }
   
}

int reverseDFS()
{
    result = 0;
    init();
    while(!STACK.empty())
    {
        int v = STACK.top();
        STACK.pop();
        if(!visited[v])
        {
            util(v);
            result++;
        }
         
    }
    cout << result << endl;
}

void solve()
{
    input();
    init();
    //cout << "In stack: ";
    DFS();
    //cout << endl;
    //cout << "Connected component: " << endl;
    reverseDFS();
}

int main()
{
    solve();
}