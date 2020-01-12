#include<bits/stdc++.h>
#define MAX 30
using namespace std;
typedef pair<int, int> ii;
int N, M, rs = 0, cnt;
int parentNode[MAX];
vector<ii> edge;

void input()
{
    cin >> N >> M;
    int u, v;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        edge.push_back(ii(u, v));
    }
}

void init()
{
    for (int i = 1; i <= N; i++) parentNode[i] = i;
    cnt = N;
}

int findAncestor(int p)
{
    return (parentNode[p] == p) ? p : findAncestor(parentNode[p]);
}

void join2Branches(int p, int q)
{
    parentNode[findAncestor(p)] = findAncestor(q);
}

//For a graph of n nodes, each of its spanning tree will have n-1 edges

void TRY(int k)
{
    if (k == M)
    {
        cout << "k = " << k <<": cnt = " << cnt << " rs = ";
        rs += (cnt == 1); 
        cout << rs << endl;
        return;   
    }
    int u = edge[k].first;
    int v = edge[k].second;
    if (findAncestor(u) != findAncestor(v))
    { 
        cout << "-->vertices: " << u << " " << v << endl;
        int parentNodeU = findAncestor(u);
        join2Branches(u, v);
        cnt--;  //already done with one vertice so we deduct 1 from cnt
        cout << "---> k = "<< k << endl << endl; 
        TRY(k + 1);  //k is increased by 1
        //backtrack step
        cout << "---->BT: Vertices " << u << " " << v << "   k = " << k << endl;
        cnt++;   
        parentNode[parentNodeU] = parentNodeU;  
    }
    TRY(k + 1);
}


int main()
{
    input();
    init();
    TRY(0);
    cout << rs;
}