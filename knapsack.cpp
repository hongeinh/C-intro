#include <iostream>
#define MAX 101
using namespace std;

int n;
int W;
int value[MAX];
int weight[MAX];
 
//---------SOLUTION REPRESENTATION---------
int f[MAX][MAX] = { 0 };

void input()
{
    cin >> n >> W;
    for(int i = 1; i <= n; i++) cin >> value[i];
    for(int i = 1; i <= n; i++) cin >> weight[i];
}

int max(int a, int b)
{
    return a > b ? a : b;
}


int solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(weight[i] > j)
            {
                //overweight
                f[i][j] = f[i][j-1];
            }
            else
            {
                f[i][j] = max(f[i][j-1], f[i][j -weight[i]] + value[i]);
            }
        }
    }
    
    return f[n][W];
}

int main()
{
    input();
    cout << solve << endl;
}