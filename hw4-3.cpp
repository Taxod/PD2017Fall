#include<iostream>

using namespace std;

int main(){
//	declare the question demand
	int S = 0, s = 0, co = 0, cu = 0, I = 0, n = 0;
	cin >> S >> co >> cu >> I >> n; 
	int num[10000] = {0};
	int mincost = 10000000,mins = 0;
	int cost = 0;
	
	
	
	for(int i = 0;i < n ; i++){
		cin >> num[i];
	}
	
	
	
	int Itemp = 0;
	Itemp = I;
	
	
	for(int s = 0; s < S; s++){
		//initialize Inventory and cost
		I = Itemp;
		cost = 0;
		//calculat cost
		for(int i = 0 ;i < n; i++){			
			//stock enough
			if(I > num[i]){
				I -= num[i];
				//calculate holding cost
				cost += (I * co);
				//check if need to replenishment
				if(I <= s){
					I = S;
				}
				cout << cost << endl ;
			//out of stock
			}else if(I < num[i]){
				I = num[i] - I;
				//calculate shortage cost
				cost += (I * cu);
				cout << cost << endl; 
				I = S;
			//require and stock the same
			}else if(I == num[i]){
				I = S;
			}
		}
		
		cout <<" -----------------------" << endl;
		//store the minimum cost and it's s.
		if(cost < mincost){
			mins = s;
			mincost = cost;
		}
	}
	cout << mins << " " << mincost;
	return 0;
}
