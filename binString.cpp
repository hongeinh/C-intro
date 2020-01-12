//generate all binary strings with no consecutive 1s

#include<iostream>
#define MAX 100
using namespace std;

int n;
int t[2][MAX] = { 0 };

void input()
{
    cin >> n;
}

int solve()
{
    //base case 
    t[0][1] = 1;
    t[1][1] = 1;

    for(int i = 2; i <= n; i++)
    {
        t[1][i] = t[0][i-1];
        t[0][i] = t[0][i-1] + t[1][i-1];
    }

    return t[0][n] + t[1][n];

}

int main()
{
    input();
    cout << solve() << endl;
}