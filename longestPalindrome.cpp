//Find the longest palindrome subsequence
//Naive approach using recursion
//To better the algo can use memoization
#include<iostream>
#define MAX 101

using namespace std;

int n;
int a[MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
       cin >> a[i];
    }
    
}

int solve(int i, int j)
{
    if(i > j) return 0;
    else if( i == j ) return 1;

    if( a[i] == a[j] ) return solve( i + 1, j - 1) + 2;  //cuz these 2 characters are alike
    else return max(solve( i + 1, j ), solve( i, j - 1 ));

}

int main()
{
    input();
    cout << solve(0, n) << endl;
    return 0;
}