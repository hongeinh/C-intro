/**
 * MINIMUM SPANNING TREE
 * Version 1.3
 * 
 * Self-implementation using previously explained algorithm
 * 
*/


#include<iostream>
#include<vector>
#include<algorithm>   //for sort()

using namespace std;

int numberOfNodes, numberOfEdges;
int parent[200000];

//initialize disjoint sets
void init()
{
    for(int p = 1; p <= numberOfNodes; p++)
    {
        parent[p] = p;
    }
}

//return the root of the disjoint set
int ancestorOf(int p)
{
    if(parent[p] != p) return ancestorOf(parent[p]);
    else return parent[p];
}

void merge(int p, int q)
{
    int anc_p = ancestorOf(p);
    parent[anc_p] = ancestorOf(q);
}

typedef pair<int,int> ii;   //store start node and end node of an edge
typedef pair<int, ii> iii;  //store weight of an edge and its nodes

#define f first             //short form for first
#define s second            //short form for second

vector<iii> edge;           //store information of edges

void input()
{
    cin >> numberOfNodes >> numberOfEdges;
    for(int i = 1; i <= numberOfEdges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //iii(a, b) is a way to initialize value for a pair. Other ways: make_pair; iii.first = && iii.second = ..;
        edge.push_back(iii(w, ii(u, v)));
    }
}

void solve()
{

    int result = 0;

    input();
    init();

    sort(edge.begin(), edge.end());
    
    vector<iii> :: iterator it;
    for(it = edge.begin(); it != edge.end(); it++)
    {
        if(ancestorOf(it->s.f) != ancestorOf(it->s.s))
        {
            result += it->f;
            merge(it->s.f, it->s.s);
        }
    }

    cout << result << endl;

}

int main()
{
    solve();
}