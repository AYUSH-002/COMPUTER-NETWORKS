#include <bits/stdc++.h>
using namespace std;
struct node
{
    unsigned distance[6];
    unsigned from[6];
} disVecRou[10];
int main()
{
    int cost[6][6];
    int n,i, j, k;
    cout << "Enter the number of nodes in the graph: "<<endl;
    cin >> n;
    cout << "Enter the cost matrix: "<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            cost[i][i] = 0;
            disVecRou[i].distance[j] = cost[i][j];
            disVecRou[i].from[j] = j;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (disVecRou[i].distance[j] > cost[i][k] + disVecRou[k].distance[j])
                {
                    disVecRou[i].distance[j] = disVecRou[i].distance[k] + disVecRou[k].distance[j];
                    disVecRou[j].distance[i] = disVecRou[i].distance[j];
                    disVecRou[i].from[j] = k;
                    disVecRou[j].from[i] = k;
                }
            }
        }
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        cout << "For router: " << i + 1<<endl;
        for (j = 0; j < n; j++)
        {
            cout << "Node" << j + 1 << " via " << disVecRou[i].from[j] + 1 << " distances: " << disVecRou[i].distance[j];
            cout<<endl;
        }
    }
    cout <<endl;
    return 0;
}
