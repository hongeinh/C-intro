//expression queue

#include <iostream>
#include <list>
#define MAX 200001

using namespace std;

int n;
int a[MAX];
int b[MAX];

list<int> expression;
list<int> num;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 1; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}

void toQueue()
{
    num.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (b[i] != 2)
        {
            expression.push_back(b[i]);
            cout << "to exp: " << expression.back() << endl;
            num.push_back(a[i]);
            cout << "to num: " << num.back() << endl;
        }
        else
        {
            int f = num.back();
            num.pop_back();
            f = f*a[i];
            num.push_back(f);
            cout << "to exp: None "  << endl;
            cout << "to num: " << num.back() << endl;
        }
    }
}

int solve()
{
    input();
    toQueue();
    int answer = num.front();
    num.pop_front();
    while(!expression.empty())
    {
        int f = expression.front();
        if(f == 0)
        {
            answer = answer - num.front();
        }
        else if(f == 1)
        {
            answer = answer + num.front();
        }
        expression.pop_front();
        num.pop_front();
    }
    return answer;
}

int main()
{
    
    cout << solve();
    return 0;

}