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
    int s[MAX];
    s[0] = 1;

    int longest = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++ )
        {
            if( a[i] > a[j] && s[i] < s[j] + 1 )
            {
                s[i] = s[j] + 1;
            }

            if( s[i] > longest )
            {
                longest = s[i];
            }
        }
    }

    return longest;
}

int main()
{
    input();
    cout << solve() << endl;
}
