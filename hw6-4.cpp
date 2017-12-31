#include<iostream>

using namespace std;


void _sort(char serialtmp[], int indexlen);
int essential(const int site[][100],int n, bool compare [] , bool comparesite[],int index[]);
bool checkbool(bool comparesite[],int m);
int refreshbool(bool compare [],const int site[][100],const float cost [],float avecostall[],int n,bool comparesite [],const char serial[]);
float avecost(bool compare [],const int site[][100],const float cost [],float avecost[],int n,bool comparesite []);

int main(){
	int n = 0, m = 0;
	int site[25][100] = {0};
	char serial[26];
	float cost[25] = {0};	
	bool compare[25] = {0};
	float avecostall[25]= {0};
	bool comparesite[100] = {0};
	//0 Flase , 1 True
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++ ){
		cin >> site[i][0];
		for(int k = 1; k <= site[i][0] ; k ++){
			cin >> site[i][k];
			site[i][k]--;
		}
	}
	
	
	for(int i = 0; i < n ; i ++){
		cin >> serial[i];
	}


	for(int i = 0; i < n ;i ++){
		cin >> cost[i];
	}
	for(int i = 0; i < m ;i ++){
		comparesite[i] = 1;
	}
	for(int i = 0; i < n; i ++){
		compare[i] = 1;
	}

	int counttime = 0;
	char answer[100] = {0};
	int index[25] = {0};
	int indexlen;
	indexlen = essential(site,n,compare,comparesite,index);
	for(int i = 0; i < indexlen ; i++){
		compare[index[i]] = 0;
		for(int j = 1 ; j <= site[index[i]][0];j++){
			comparesite[site[index[i]][j]] = 0;
		}
	}
	
	char serialtmp[26] = {0};
	
	for(int i = 0 ; i < indexlen ; i++){
		serialtmp[i] = serial[index[i]];
	}




	_sort(serialtmp,indexlen);
	
//	for(int i = 0; i < n ; i++){
//		if(compare[i] == 0  && checkbool(comparesite,m) != 0){
//			cout << serial[i] << " ";
//		}else if(compare[i] == 0 && checkbool(comparesite,m) == 0){
//			cout << serial[i];
//			return 0;
//		} 
//	}
	for(int i = 0 ; i < indexlen ; i++){
		if(i == indexlen-1 && checkbool(comparesite,m) == 0){
			cout << serialtmp[i];
			return 0;			
		}else{
			cout << serialtmp[i] << " ";
		}
		
	}
	
	
	
	while(checkbool(comparesite,m)){
		avecost(compare,site,cost,avecostall,n,comparesite);
		answer[counttime] =  serial[refreshbool(compare,site,cost,avecostall,n,comparesite,serial)];
		counttime ++;
	}
	for(int i = 0;i < counttime-1 ; i ++){
		cout << answer[i] << " ";
	}
	cout << answer[counttime-1];

	return 0 ;
}

float avecost(bool compare [],const int site[][100],const float cost [],float avecostall[],int n,bool comparesite []){
	int count = 0;
	for(int j = 0 ;j < n ; j++){
		if(compare[j]){ //j °ò¦a¥x 
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

int refreshbool(bool compare [],const int site[][100],const float cost [],float avecostall[],int n,bool comparesite [],const char serial[]){
	float mincost = 2147483647;
	int minindex = 0;//********************************************
	for(int i = 0; i < n ; i ++){
		if(avecostall[i] < mincost && compare[i]){
			mincost = avecostall[i];
			minindex = i;
		}else if(avecostall[i] == mincost && compare[i] && int(serial[i]) < int(serial[minindex])){
			mincost = avecostall[i];
			minindex = i;
		}
	}
	for(int i = 1; i <= site[minindex][0] ; i++){
		comparesite[site[minindex][i]] = 0;
	}
	compare[minindex] = 0;
	

	return minindex;
}


bool checkbool(bool comparesite[],int m){
	bool flag = 0;
	for(int i = 0; i < m ; i++){
		if(comparesite[i]){
			flag = 1;
		}
	}
	return flag;
}

int essential(const int site[][100],int n , bool compare [] , bool comparesite[],int index[]){
	int countindex = 0;
	for(int i = 0 ; i < n; i ++){
		for(int j = 1; j <= site[i][0] ; j++){
			int flagg = 1;
			for(int k = 0;k < n ; k ++){
				for(int p = 1;p <= site[k][0] ; p++){
					if(i == k){
						continue;
					}
					if(site[i][j] - site[k][p] == 0){
						flagg = 0;
					}
				}
			}
			if(flagg == 1){
				index[countindex] = i;
				countindex++;
				break;
			}
		}
	}
	return countindex;
}

void _sort(char serialtmp[], int indexlen) {
	for (int i = 0; i < indexlen - 1; i++)
		for (int j = 0; j < indexlen - 1 - i; j++){
		
			if (int(serialtmp[j]) > int(serialtmp[j + 1])){
				char temp = 0;
				temp = serialtmp[j];
				serialtmp[j] = serialtmp[j+1];
				serialtmp[j+1] = temp;
			}
	}
}

/*
5 9
4 1 2 5 6
4 6 5 3 9
4 8 7 1 2
1 4
4 2 5 3 4
A B C D E
10 8 6 4 7
*/
