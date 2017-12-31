#include <iostream>

using namespace std;
const int MAX_CITY = 500;
//const int MAX_BUDGET = 10000;

void avecost_f(bool coverd[][MAX_CITY],const float Construct_cost[],float avecost[],int village);

void avecost_f(bool coverd[][MAX_CITY],const float Construct_cost[],float avecost[],int village,int population[]);
int choose(float avecost[],bool compare[],int village);

int refreshbool(bool compare[],bool coverd[][MAX_CITY],int mincostindex,int village,bool comparesite[]);

bool check(int village,bool comparesite[]);

int main()
{
    int village = 0,cost = 0,dis_c = 0, dis_s = 0;
    //village < 500,cost < 1000
    int population[MAX_CITY] = {0};
    // population<1000
    float Construct_cost[MAX_CITY] = {0};
    // Construct_cost < 1000
    int dis[MAX_CITY][MAX_CITY] = {0};
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
    for (int k = 0; k < village; k++){
        for (int i = 0; i < village; i++){
            for (int j = 0; j < village; j++){
                if (dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    
    
    
    //距離滿足的城鎮
    bool satisfy_coverd[MAX_CITY][MAX_CITY] = {0};
    //距離覆蓋的城鎮
    bool coverd[MAX_CITY][MAX_CITY] = {0};
    
    for (int i = 0; i < village; ++i)
    {
        for (int j = 0; j < village; ++j)
        {
            if (dis[i][j] <= dis_s) {
                coverd[i][j] = true;
                satisfy_coverd[i][j] = true;
            } else if (dis[i][j] <= dis_c) {
                coverd[i][j] = true;
            } else {
                coverd[i][j] = false;
            }
        }
        
        
    }
    
    
    
    bool compare[MAX_CITY] = {0};        //記錄被選的城鎮
    bool comparesite[MAX_CITY] = {0};    //記錄是不是全部被覆蓋
    for (int i = 0; i < village; ++i)
    {
        compare[i] = 1;
        comparesite[i] = 1;
    }
    
    float avecost[MAX_CITY] = {0};
    
    int answer[MAX_CITY] = {0};
    int answer_count = 0;
    int mincostindex = 0;
    
    /*
     9 200 30 15
     10 20 30 40 50 60 70 80 90
     30 90 90 90 90 90 90 90 90
     7 -1 -1 8 15 23 18 -1
     11 -1 5 -1 -1 -1 -1
     -1 4 -1 -1 -1 6
     -1 -1 18 -1 -1
     -1 -1 -1 10
     -1 -1 12
     9 -1
     -1
     */
    
    int total_cost = 0;

    //
    while(check(village,comparesite)){
        avecost_f(coverd, Construct_cost, avecost, village);
        mincostindex = choose(avecost, compare, village);
        answer[answer_count] = mincostindex;
        answer_count++;
        refreshbool(compare, coverd, mincostindex, village, comparesite);
    }
    
    for (int i = 0; i < answer_count; ++i)
    {
        total_cost = total_cost + Construct_cost[answer[i]];
    }
    
    // while(1){
    //     avecost_f(satisfy_coverd, Construct_cost, avecost, village);
    //     mincostindex = choose(avecost, compare, village);
    //     total_cost += Construct_cost[mincostindex];
    //     if (total_cost > cost)
    //     {
    //         break;
    //     }
    //     answer[answer_count] = mincostindex;
    //     answer_count++;
    //     refreshbool(compare, satisfy_coverd, mincostindex, village, comparesite);
    // }



    while(1){
        int mincost2 = 10000000;
        int mincostindex2 = 0;
        for (int i = 0; i < village; ++i)
        {
            if (compare[i] && Construct_cost[i] < mincost2)
            {
                mincost2 = Construct_cost[i];
                mincostindex2 = i;
            }
        }
        compare[mincostindex2] = 0;
        total_cost += mincost2;
        if (total_cost > cost)
        {
            break;
        }
        answer[answer_count] = mincostindex2;
        answer_count++;
    }
    
    
    
    
    
    for (int i = 0; i < answer_count-1; ++i)
    {
        cout << answer[i]+1 << " ";
    }
    cout << answer[answer_count-1]+1;
    
    
    
    return 0;
}

//計算每一個的ＣＰ
void avecost_f(bool coverd[][MAX_CITY],const float Construct_cost[],float avecost[],int village){
    for (int i = 0; i < village; ++i)
    {
        int count = 0;
        for (int j = 0; j < village; ++j)
        {
            if (coverd[i][j] == true)
            {
                count ++;
            }
        }
        avecost[i] = Construct_cost[i] / count;
    }
}


void avecost_f(bool coverd[][MAX_CITY],const float Construct_cost[],float avecost[],int village,int population[]){
    for (int i = 0; i < village; ++i)
    {
        int count = 0;
        for (int j = 0; j < village; ++j)
        {
            if (coverd[i][j] == true)
            {
                count += population[j];
            }
        }
        avecost[i] = Construct_cost[i] / count;
    }
}



//選ＣＰ值高的
int choose(float avecost[],bool compare[],int village){
    int mincost = 100000000;
    int mincostindex = 0;
    for (int i = 0; i < village; ++i)
    {
        if (avecost[i] < mincost && compare[i])
        {
            mincostindex = i;
            mincost = avecost[i];
        }
    }
    return mincostindex;
}

//更新bool，被選的城鎮(coverd)
int refreshbool(bool compare[],bool coverd[][MAX_CITY],int mincostindex,int village,bool comparesite[]){
    compare[mincostindex] = 0;
    for (int i = 0; i < village; ++i)
    {
        if (coverd[mincostindex][i] == true)
        {
            comparesite[i] = 0;
            for (int j = 0; j < village; ++j)
            {
                coverd[j][i] = false;//注意要不要包含自己
            }
        }
        
    }
    return 0;
}

//確定是不是每一個被覆蓋
bool check(int village,bool comparesite[]){
    bool flag = 0;
    for (int i = 0; i < village; ++i)
    {
        if (comparesite[i] != 0)
        {
            flag = 1;
        }
    }
    return flag;
}
