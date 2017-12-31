#include<iostream>
using namespace std;

//check if all element are coverd
bool checkbool(bool comparesite[],int m);

//choose set
int ChooseSet(bool compare [],const int site[][100],const float cost [],float avecost[],int n,bool comparesite [],const char serial[]);

//calculate sets' average cost
float avecost(bool compare [],const int site[][100],const float cost [],float avecost[],int n,bool comparesite []);



int main(){
	int n = 0, m = 0;
	
	//elements
	int site[100][100] = {0};
	
	//the alphabets
	char serial[100];
	
	//sets' cost
	float cost[100] = {0};	
	
	//mark the set choosed or not.
	bool compare[100] = {0};
	
	//sets' average cost.
	float avecostall[100]= {0};
	
	//mark the elements choosed or not.
	bool comparesite[100] = {0};
	
	
	
	
	int firstn = 0;
	
	cin >> firstn >> m;
	
	n = firstn;
	
	
	bool which_is_two[100] = {0};
	bool which_first[100] = {0}; 
	int nouse[100] = {0};
	int countwhich = 0;
	for(int i = 0 ; i < firstn ;i++){
		cin >> nouse[i]; 
		countwhich++;    
		if(nouse[i] == 2){
			which_first[countwhich-1] = 1;
			which_is_two[countwhich] = 1;
			countwhich++;
			n++;
		}
	}


	int indexnumber[100] = {0};
	for(int i = 0 ; i < n; i++){
		cin >> serial[i] >> indexnumber[i] >> cost[i]  >> site[i][0]; 
		for(int k = 1; k <= site[i][0] ; k ++){
			cin >> site[i][k];
			site[i][k]--;
			//let the indexes start from 0 
		}
	}
	
	

	for(int i = 0; i < m ;i ++){
		comparesite[i] = 1;
	}
	
	for(int i = 0; i < n; i ++){
		compare[i] = 1;
	}
	
	
	
	int counttime = 0;
	int answer[100] = {0};
	


	while(checkbool(comparesite,m)){
		avecost(compare,site,cost,avecostall,n,comparesite);
		answer[counttime] =  ChooseSet(compare,site,cost,avecostall,n,comparesite,serial);
		counttime ++;
	}



	for(int i = 0;i < counttime-1 ; i ++){
		if(which_is_two[answer[i]]){
			cout << serial[answer[i]] << "-2 ";	
		}else if(which_first[answer[i]]){
			cout << serial[answer[i]] << "-1 "; 
		}else{
			cout << serial[answer[i]] << " ";
		}
	}
	if(which_is_two[answer[counttime-1]]){
		cout << serial[answer[counttime-1]] << "-2";	
	}else if(which_first[answer[counttime-1]]){
		cout << serial[answer[counttime-1]]<< "-1"; 
	}else{
		cout << serial[answer[counttime-1]];
	}

	return 0 ;
}


//calculate set's average cost.
float avecost(bool compare [],const int site[][100],const float cost [],float avecostall[],int n,bool comparesite []){
	int count = 0;
	for(int j = 0 ;j < n ; j++){
		if(compare[j]){
			for(int i = 1; i <= site[j][0]; i++){
				if(comparesite[site[j][i]]){
					count ++;
				}
			}	
			avecostall[j] = cost[j] / count;		
			count = 0;
		}
	}
	
	return 0;
}


//choose set
int ChooseSet(bool compare [],const int site[][100],const float cost [],float avecostall[],int n,bool comparesite [],const char serial[]){
	float mincost = 2147483647;
	int minindex = 0;
	
//	choose set which average cost is smallest.
	for(int i = 0; i < n ; i ++){
		if(avecostall[i] < mincost && compare[i]){
			mincost = avecostall[i];
			minindex = i;
		}else if(avecostall[i] == mincost && compare[i] && static_cast<int>(serial[i]) < static_cast<int>(serial[minindex])){
			
			//when the average cost are the same. check if the alphabet is smaller.
			mincost = avecostall[i];
			minindex = i;
		}
	}
	
	//mark the element which were choosed.
	for(int i = 1; i <= site[minindex][0] ; i++){
		comparesite[site[minindex][i]] = 0;
	}


	//mark the set which was choosed,including the same nameindex.
	for(int i = 0 ; i < n ; i ++){
		if(int(serial[i]) == int(serial[minindex])){
			compare[i] = 0;
		}
	}

	return minindex;
}


//check if all elements are coverd.
bool checkbool(bool comparesite[],int m){
	bool flag = 0;
	for(int i = 0; i < m ; i++){
		if(comparesite[i]){
			flag = 1;
		}
	}
	return flag;
}
