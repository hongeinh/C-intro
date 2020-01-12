//****MINIMUM SPANNING TREE****//
/**
 * version 1.2
 * IDEA: Data structure: DISJOINT SETS + KRUSKAL'S ALGORITHM
 * A disjoint set is a set of adjacent nodes, each set will have one root, ideally the depth of a set is one as every node is connected directly to the root
 * anc(int p): to find ancestor of p, which is the root of the disjoint set containing p (similar to teacher's algorithm)
 * In this version, we implicitly understand that we are using disjoint set data structure, however no real disjoint set is created
 * 
 *----------> please refer to minimumSpanningTree.txt for more details on the problem
 */

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long int par[230997];

//find the root of the 'disjoint set'
long long int anc(int p){ 
    if (par[p]==p) return p;    
    else return par[p]=anc(par[p]); 
}


//We join two disjoint sets, which contain p and q respectively, together to produce a new set
void join(long long int p, long long int q){ 
    par[anc(p)]=anc(q); 
}
 
typedef pair<long long int, long long int> ii;
typedef pair<long long int, ii> iii;

#define X first
#define Y second

vector<iii> edge;
int n, m;  
 
main(){
    /*
    * n: number of nodes in the tree
    * m: number of edges in the tree
    * i for iteration in loop
    * p: temp for starting node
    * q: temp for ending node
    * w: weight 
    * r: result
    * 
    */
    long long int i, p, q, w, r=0;
    cin >> n >> m;

    //at first each node is an ancestor of itself, which means itself is a disjoint set
    for (i=1; i<=n; i++) par[i]=i;


    /*
    * FUCNTIONALITY: INPUT FUNCTION  ----> can separate
    */
    while (m--){
        //input starting node, ending node and weight of this edge
        cin >> p >> q >> w;
        /*
        * ii(p,q): create an undirected edge between 2 nodes
        * iii(w, ii(p,q)): a vector of vector, relate the edge of 2 nodes with its weight
        * edge.push_back(iii(w, ii(p,q))): push this to the edge list 
        * we implicitly understand that edge is actually a list, but representing it as a vector in this algorithm proves better management
        */
        edge.push_back(iii(w, ii(p, q)));
    }

    //sort the list of edges according to the weight of each edge in ascending order
    sort(edge.begin(), edge.end());

    vector<iii>::iterator it;
    for (it = edge.begin(); it!=edge.end(); it++){
        if (anc(it->Y.X) != anc(it->Y.Y)){
            join(it->Y.X, it->Y.Y);
            r += it->X;
        }
    }                                                                                                                 
    cout << r;
}