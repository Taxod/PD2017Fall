#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    int village = 0,cost = 0,dis_c = 0, dis_s = 0;
    //village < 500,cost < 1000
    int population[500] = {0};
    // population<1000
    int Construct_cost[500] = {0};
    // Construct_cost < 1000
    int dis[500][500] = {0};
    // village = 10;
    
    cin >> village >> cost >> dis_c >> dis_s;
    for (int i = 0; i < village; ++i)
    {
        cin >> population[i];
    }
    for (int i = 0; i < village; ++i)
    {
        cin >> Construct_cost[i];
    }
    for (int i = 0; i < village; ++i)
    {
        dis[i][i] = 0;
        for (int j = i+1; j < village; ++j)
        {
            cin >> dis[i][j];
            if (dis[i][j] == -1) {
                dis[i][j] = 10001;
            }
            dis[j][i] = dis[i][j];
        }
    }

    // Floyd-Warshall algorithm to get shortest paths
    for (int k = 0; k < village; k++)
        for (int i = 0; i < village; i++)
            for (int j = 0; j < village; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    
    for (int i = 0; i < village; ++i)
    {
        for (int j = 0; j < village; ++j)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }



    
    return 0;
}