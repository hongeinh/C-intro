using namespace std;
#include<iostream>
#define MAX 100001
#define MOD 1000000007
int n, m;
int a[MAX];
int cnt;

void solve()
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] > m) continue;
        else
        {
            for(int j = 0; j < i; j++)
            {
                int temp = a[i] + a[j];
                if(temp <= m) cnt++;
            }
        }
    }
    cout << cnt%MOD << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve();
}