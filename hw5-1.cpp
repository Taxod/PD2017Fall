#include<iostream>

using namespace std;

int main(){
	int m, n, k, h;
	cin >> m >> n >> k >> h;


	//input the score.
	int num[100][100] = {0};
	for(int i = 0; i < m ; i++){
		for(int j = 0; j < n ; j++){
			cin >> num[i][j];
		}
	}

	//input the Seller which meet the condition.
	int L[100] = {0};
	for(int i = 0; i < h ; i++){
		cin >> L[i];
	}


	// store the overview evaluation
	int Evaluation[100] = {0};
	
	//store the sum of evaluation
	int Etemp = 0;
	
	//record the evaluation frequency
	int count = 0;

	for(int i = 0 ; i < m ; i++){
		//initialize the sum of evaluation and evaluation frequency
		count = 0;
		Etemp = 0;
		for(int j = 0; j < n ; j++){
			if(num[i][j] != 0 ){
				count ++;
			}
			Etemp += num[i][j];
		}
		
		//calculate the overview evaluation
		Evaluation[i] = Etemp - k * count; 
	}


	
	
	//to record which seller is meeting the condition
	//if the seller meet the condition, which index will be assigned "1". 
	int record[100] = {0};
	
	for(int i = 0; i < h ;i++){
		record[L[i]-1] = 1;
	}


	
	//avoid the seller, which isn't meetind the condition, being choosed.
	for(int i = 0; i < m ; i++){
		if(record[i] != 1){
			Evaluation[i] =  -2147483647;
		}
	}




	//compare the numbers, and find out the top three numbers.

	
	int big1 = -2147483647 , big2 = -2147483647,big3= -2147483647;
	int big1index = 0 , big2index = 0,big3index = 0;
	for(int i = 0;i < m ; i++){
		if(Evaluation[i] > big1){
			big3 = big2;
			big2 = big1;
			big1 = Evaluation[i];
			big3index = big2index;
			big2index = big1index;
			big1index = i; 
		}else if(Evaluation[i] > big2){
			big3 = big2;
			big2 = Evaluation[i];
			big3index = big2index;
			big2index = i;
		}else if(Evaluation[i] > big3){
			big3 = Evaluation[i];
			big3index = i;
		}
	}
	

	// print the answer	
	if(h >= 3){
		cout << big1index+1 << " " << big2index+1 << " " << big3index+1;	
	}else if( h >= 2){
		cout << big1index+1 << " " << big2index+1;
	}else{
		cout << big1index+1;
	}



	return 0;
}
