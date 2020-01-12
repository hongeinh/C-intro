//return smallest path from (0,0) to (n,m)
//can only go right or down aka (i+1,j) or (i, j+1)
#include<iostream>
#define MAX 101
using namespace std;

int n, m; //row, column
int a[MAX][MAX]; //a[i][j] = cost of (i,j)
int t[MAX][MAX]; //t[i][i] = min total cost to reach (i, j)

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}
int solve()
{
    t[0][0] = a[0][0];
    for(int i = 1; i < n; i++)
    {
        t[i][0] = t[i][0] + a[i][0];
    }
    for(int i = 1; i < m; i++)
    {
        t[0][i] = t[0][i] + a[0][i];
    }

    for(int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            t[i][j] = t[i][j] + min(t[i-1][j], t[i][j-1]);
        }
    }

    return t[n-1][m-1];
}

int main()
{
    input();
    cout << solve() << endl;
}