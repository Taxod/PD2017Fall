#include <iostream>

using namespace std;


void avecost_f(int coverd[][500],const float Construct_cost[],float avecost[],int village);
int choose(float avecost[],bool compare[],int village);

int refreshbool(bool compare[],int coverd[][500],int mincostindex,int village,bool comparesite[]);

bool check(int coverd[][500],int village,bool comparesite[]);

int main()
{
    int village = 0,cost = 0,dis_c = 0, dis_s = 0;
    //village < 500,cost < 1000
    int population[500] = {0};
    // population<1000
    float Construct_cost[500] = {0};
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
    for (int k = 0; k < village; k++){
    	for (int i = 0; i < village; i++){
        	for (int j = 0; j < village; j++){
            	if (dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
        
            
                
    

    int coverd[500][500] = {0};

    for (int i = 0; i < village; ++i)
    {
    	for (int j = 0; j < village; ++j)
    	{
    		if (dis[i][j] <= dis_s) {
                coverd[i][j] = 2;
            } else if (dis[i][j] <= dis_c) {
                coverd[i][j] = 1;
            } else {
                coverd[i][j] = 0;
            }	
    	}

    	
    }
	


	// int coverd2[500][500] = {0};



 //    // int test[500][500] = {0};
 //    for (int i = 0; i < village; ++i)
 //    {
 //    	for (int j = 0; j < village; ++j)
 //    	{
 //    		if (coverd[i][j]== 2)
 //    		{
 //    			coverd2[i][j] = 2;
 //    			cout << coverd2[i][j];
 //    		}else{
 //    			coverd2[i][j] = 0;
 //    		}
 //    	}
 //    }

    	// int test[500][500] = {0};

		// for (int i = 0; i < village; ++i)
		// {
		// 	// cout << i;
		// 	for (int j = 0; j < village; ++j)
		// 	{
				
		// 		cout << coverd2[i][j] <<" ";
		// 	}
		// 	cout << endl;
		// }






    
    bool compare[500] = {0};
    bool comparesite[500] = {0};
	for (int i = 0; i < village; ++i)
	{
		compare[i] = 1;
		comparesite[i] = 1;
	}

	float avecost[500] = {0};    

	int answer[500] = {0};
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
	while(check(coverd,village,comparesite)){
		avecost_f(coverd,Construct_cost,avecost,village);
		mincostindex = choose(avecost,compare,village);
		total_cost += Construct_cost[mincostindex];
		answer[answer_count] = mincostindex;
		answer_count++;
		refreshbool(compare,coverd,mincostindex,village,comparesite);		
	}









	// for (int i = 0; i < answer_count; ++i)
	// {
	// 	for (int j = 0; i < village; ++j)
	// 	{
	// 		cout << coverd2[answer[i]][j] << " ";
	// 		if (coverd2[answer[i]][j] == 2)
	// 		{
	// 			for (int k = 0; k < village; ++k)
	// 			{
	// 				coverd2[k][j] = 0;
	// 			}
	// 		}
	// 	}
		
	// }


	// while(true){
	// 	cout << "*";
	// 	break;
	// 	avecost_f(coverd2,Construct_cost,avecost,village);
	// 	break;
	// 	mincostindex = choose(avecost,compare,village);
	// 	total_cost += Construct_cost[mincostindex];
	// 	break;
	// 	if (total_cost > cost)
	// 	{
	// 		break;
	// 	}
	// 	answer[answer_count] = mincostindex;
	// 	answer_count++;
	// 	refreshbool(compare,coverd2,mincostindex,village,comparesite);	
	// }
	

	for (int i = 0; i < answer_count-1; ++i)
	{
		cout << answer[i]+1 << " ";
	}
	cout << answer[answer_count-1]+1;



    return 0;
}


void avecost_f(int coverd[][500],const float Construct_cost[],float avecost[],int village){
	for (int i = 0; i < village; ++i)
	{
		int count = 0;
		for (int j = 0; j < village; ++j)
		{
			if (coverd[i][j] == 1 || coverd[i][j] == 2)
			{
				count ++;
			}
		}
		avecost[i] = Construct_cost[i] / count;
	}
}

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

int refreshbool(bool compare[],int coverd[][500],int mincostindex,int village,bool comparesite[]){
	compare[mincostindex] = 0;
	for (int i = 0; i < village; ++i)
	{
		if (coverd[mincostindex][i] != 0)
		{
			comparesite[i] = 0;
			for (int j = 0; j < village; ++j)
			{
				coverd[j][i] = 0;//注意要不要包含自己
			}
		}
		
	}
	return 0;
}

bool check(int coverd[][500],int village,bool comparesite[]){
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
