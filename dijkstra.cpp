//FIND THE SHORTEST DISTANCE FROM THE SOURCE TO EACH NODE

#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int numberOfNodes;
int weightMatrix[MAX][MAX];
int distanceArr[MAX];  //distance[i]: shortest distance from source node the node i
queue<int> Q;          //queue of all nodes in the graph
int visitedNodes[MAX]; //by the end of the algorithm, all nodes should be in this array

int shortestPath[MAX]; //keeps track of the nodes in the shortest path, initially this array is empty

void input()
{
    cin >> numberOfNodes;

    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
        {
            cin >> weightMatrix[i][j];
        }
    }
}


void initializeDistance()
{
    distanceArr[0] = 0;
    visitedNodes[0] = 0;
    for (int i = 1; i < numberOfNodes; i++)
    {
        distanceArr[i] = INT_MAX;
        visitedNodes[i] = 0;
    }
}

void printDistance()
{
    for(int i = 0; i < numberOfNodes; i++)
    {
        cout << distanceArr[i] << " ";
    }
    cout << endl;
}

int minDistance()
{
    //utility function
    //find the node which has not been visited and has the minimum distance
    int min = INT_MAX;
    int min_index = -1;
    for(int i = 1; i < numberOfNodes; i++)
    {
        if(visitedNodes[i] == 0 && distanceArr[i] < min)
        {
            min = distanceArr[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstraAlgorithm()
{
    for(int i = 0; i < numberOfNodes - 1; i++)
    {
        int u = minDistance();
        visitedNodes[u] = 1;  //node u has been visited 

        for(int v = 0; v < numberOfNodes; v++)
        {
            //if node v has not been visited and edge(u,v) has weight and sum distance is less than distance of v 
            if(!visitedNodes[v] && weightMatrix[u][v] && distanceArr[u] != INT_MAX && distanceArr[u] + weightMatrix[u][v] < distanceArr[v] )
            {
                distanceArr[v] = distanceArr[u] + weightMatrix[u][v];
            }
        }
    }
}

void solve()
{
    input();
    initializeDistance();
    dijkstraAlgorithm();
    printDistance();
}

int main()
{
    solve();
    return 0;
}