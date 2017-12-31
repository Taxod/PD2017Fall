#include<iostream>

using namespace std;

int main(){
//	declare the question demand
	int S = 0, s = 0, co = 0, cu = 0, I = 0, n = 0;
	cin >> S >> s >> co >> cu >> I >> n; 
	int xi = 0;
	int cost = 0;
	
//	count day out of stock
	int count_day = 0;
	
	for(int i = 0 ;i < n; i++){
		cin >> xi;
		//stock enough
		if(I > xi){
			I -= xi;
			//calculate holding cost
			cost += (I * co);
			//check if need to replenishment
			if(I <= s){
				I = S;
			}
		//out of stock
		}else if(I < xi){
			I = xi - I;
			//calculate shortage cost
			cost += (I * cu);
			I = S;
			count_day ++;
		//require and stock the same
		}else if(I == xi){
			I = S;
		}
	}
	cout << count_day << " " << cost;
	return 0;
}
