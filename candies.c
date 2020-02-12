//hackerrank

#include<stdio.h>

long long int a[100005];
long long int arr[100005];
int n;
long long int sol;

void solve()
{
    sol = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] < arr[i+1]) a[i+1] = a[i] + 1;
    }
    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] > arr[i+1] && a[i] < a[i+1] + 1) a[i] = a[i+1] + 1;
    }
    for(int i = 0; i < n; i++) sol += a[i]; 
    printf("%lld", sol);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        a[i] = 1;
        scanf("%lld", &arr[i]);
    }
    solve();
}
