/**
 * HAPPY + NEW - YEAR -VNEX = M
 * x[]: H A P Y N E W R V X
 * Different from 0: H N Y V ----> k = 0 3 4 8
*/

using namespace std;
#include<iostream>
#define MAX 3500

int M;
int x[MAX];
int visited[MAX];
int cnt;

int check(int v, int k)
{
    if(visited[v] == 1) return 0;
    else if(visited[v] == 0 && v == 0)
    {
        if (k == 0 || k == 3 || k == 4 || k == 8) return 0;
    }
    return 1;
}

void solution()
{
    int sum = (x[0]*10000 + x[1]*1000 + x[2]*110 + x[3]) - (x[4]*100 + x[5]*10 + x[6]) - (x[3]*1000 + x[5]*100 + x[1]*10 + x[7]) - (x[8]*1000 + x[4]*100 + x[5]*10 + x[9]) ;
    if(sum == M) cnt++;
}
void TRY(int k)
{
    for(int v = 0; v <= 9; v++)
    {
        if(check(v, k))
        {
            x[k] = v;
            visited[v] = 1;
            if(k == 9) solution();
            else TRY(k+1);
            visited[v] = 0;
        }
    }
}

int main()
{
    cin >> M;
    for(int i = 0; i <= 9; i++) visited[i] = 0;
    cnt = 0;
    TRY(0);
    cout << cnt;
}