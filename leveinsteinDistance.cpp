//counting how dissimilar two strings are by counting the minimum number of operations needed to transform one string to another
/*
    Recursion relation
    dist(i, j) = max(i, j) if min(i,j) = 0;
    dist(i,j) = dist(i-1, j-1) if x[i] == y[j]
    dis(i,j) = min(dist(i, j-1)'insert' + 1, dis(i-1, j)'delete' + 1, dis(i-1, j-1)'substitute + subCost)
*/
#include<iostream>
#define MAX 101

using namespace std;

int n, m;  //size of string
char x[MAX], y[MAX];

//----------SOLUTION REPRESENTATION--------------
int t[MAX][MAX];  //for memoization

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) cin >> y[i];
}

int min(int a, int b)
{
    return a < b ? a : b;
}


int solve()
{
    t[0][0] = 0;   //initialize the start of each string
    for(int i = 1; i <= n; i++) t[i][0] = i;   
    for(int j = 1; j <= m; j++) t[0][j] = j;

    int substituteCost = 0; 

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i-1] == y[j-1])  substituteCost = 0;   //no change needed
            else substituteCost = 1;                //need change

            t[i][j] = min(t[i-1][j] + 1, min(t[i][j-1] + 1, t[i-1][j-1] + substituteCost ));
        }
    }
    return t[n][m];
}

int main()
{
    input();
    cout << solve() << endl;
}