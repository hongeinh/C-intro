//find the increasing subsequence with the highest weight

#include<iostream>
#define MAX 101
 
using namespace std;

int n; 
int a[MAX];

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
}

int solve()
{
    int weight[MAX];
    int sum[MAX];

    weight[0] = 1;
    sum[0] = a[0];

    int maxW = a[0];

    for(int i = 1; i < n; i++)
    {
        
        for(int j = 0; j < i; j++)
        {
            if( a[j] < a[i] && weight[i] < weight[j] + 1)
            {
                weight[i] = weight[j] + 1;
                if(sum[i] < sum[j] + a[i]) sum[i] = sum[j] + a[i];
                
            }
        }
    }
}