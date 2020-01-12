#include <iostream>
#define MAX 1000

using namespace std;

int n, K, Q;     //n clients, k trucks, each truck of capacity q
int c[MAX][MAX]; //c[i][j] distance from i to j;
int d[MAX];      //d[i] client i want d[i] packages

//--------- SOLUTION REPRESENTATION------------
int x[MAX];       //x[i] is the next point of i;
int y[MAX];       //y[k] is the starting point of truck k
int load[MAX];    //load of each truck
int visited[MAX]; //visited[i] = 1 means client i-th had been visited
int segments;     //number of segments accumulated
int nbRoutes;

void input()
{
    cin >> n >> K >> Q;

    d[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
}

void solution()
{
    for (int k = 1; k <= K; k++)
    {
        int s = y[k];
        cout << "route[" << k << "]:  0" << endl;

        for (int v = s; v != 0; v = x[v])
        {
            cout << v << " ";
        }
        cout << "0" << endl;
    }

    cout << "---------------------" << endl;
}

int checkX(int v, int k)
{
    if (v > 0 && visited[v])
        return 0; //has visited that client
    if (load[k] + d[v] > Q)
        return 0; //overload
    return 1;
}

int checkY(int v, int k)
{
    if (v == 0)
        return 1;
    if (load[k] + d[v] > Q)
        return 0;
    return !visited[v];
}

void TRY_X(int s, int k)
{
    if (s == 0)
    {
        if (k < K)
            TRY_X(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, k))
        {
            x[s] = v;
            visited[v] = 1;
            load[k] = load[k] + d[v];
            segments++;
            if (v > 0)
                TRY_X(v, k);
            else
            {
                if (k == K)
                {
                    if (segments = n + nbRoutes)
                        solution();
                }
                else
                {
                    TRY_X(y[k+1], k+1);
                }
            }

            segments--;
            load[k] = load[k] - d[v];
            visited[v] = 0;
        }
    }
}

void TRY_Y(int k)
{
    for( int v = (y[k-1] == 0 ? 0 : y[k-1]); v <= n; v++)
    {
        if(checkY(v, k))
        {
            y[k] = v;
            visited[v] = 1;
            load[k] = load[k] + d[v];
            if(v > 0) segments ++;
            if(k < K) TRY_Y(k+1);
            else{
                nbRoutes = segments;
                TRY_X(y[1], 1);
            }

            load[k] = load[k] - d[v];
            visited[v] = 0;
            if(v > 0) segments--;
        }
    }
}

void solve()
{
    for(int v = 1; v <= n; v++)
    {
        visited[v] = 0;
    }

    y[0] = 0;
    TRY_Y(1);
}

int main()
{
    input();
    solve();
    return 1;
}