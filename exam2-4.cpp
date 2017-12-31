#include<iostream>

using namespace std;

int main(){
	int n = 0,conflict = 0,budget = 0;
	int c[100] = {0};
	int cost[100] = {0};
	int con[4950][2] = {0};
	cin >> n >> conflict >> budget;
	for(int i = 0 ; i < n ; i++){
		cin >> c[i];
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> cost[i];
	}
	for(int i = 0; i < conflict ; i++){
		for(int j = 0 ; j < 2; j++){
			cin >> con[i][j];
			con[i][j] -= 1;
		}
	}
	int total_cost = 0;
	bool compare[100] = {0};
	for(int i = 0 ; i < n ;i++){
		compare[i] = 1;
	}
	int answer[100] = {0};
	int count = 0;
	
	
	
	
	
	while(true){
		int maxc = -1000000;
		int maxcindex = 0;
		
		
		//選擇 
		for(int i = 0;i < n ;i++){
			if(c[i] > maxc && compare[i] ){
				maxc = c[i];
				maxcindex = i;
			}else if(c[i] == maxc && compare[i] && cost[i] < cost[maxcindex]){
				maxc = c[i];
				maxcindex = i;
			}
		}
		
		
		total_cost += cost[maxcindex];
		if(total_cost > budget){
			total_cost = total_cost - cost[maxcindex];
//			break;//超出預算 
			compare[maxcindex] = 0;
			bool end = 1;
			for(int i = 0; i < n ; i++){
				if(compare[i] == 1){
					end = 0;
				}
			}
			if(end == 1){
				break;
			}
			continue;
		}
		
		//更新bool，處理王不見王 
		for(int i = 0; i < conflict; i++){
			for(int j = 0 ; j < 2 ; j++){
				if(maxcindex == con[i][j]){
					for(int k = 0 ; k < 2;k++){
						compare[con[i][k]] = 0;
					}
				}
			}
		}
		
		
		
		
		compare[maxcindex] = 0;
		answer[count] = maxcindex;
		count ++;
		
		
		//是不是都被選完了 
		bool end = 1;
		for(int i = 0; i < n ; i++){
			if(compare[i] == 1){
				end = 0;
			}
		}
		if(end == 1){
			break;
		}
	}
	
	
	
	
	
	for(int i = 0 ; i < count-1; i++){
		cout << answer[i]+1 <<" ";
	}
	cout << answer[count-1] + 1;
//	for(int i=0;i<n;i++){
//		cout<<compare[i];
//	}
//	cout<<total_cost;
	return 0;
} 
