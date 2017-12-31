#include<iostream>

using namespace std;

int main(){
	int n = 0 , m = 0 ;
	int know[10000] = {0};
	int beknow [10000] = {0};
	int knum[10000] = {0};
	int bnum[10000] = {0};
	cin >> n >> m;
	int kcount = 0;
	int bcount = 0;
	for(int i= 0; i < 2*m ; i++){
		if(i % 2 == 0){
			cin >> know[kcount];
			kcount ++;
		}else{
			cin >> beknow[bcount];
			bcount ++;
		}
	}
//	for(int i = 0; i < m ; i ++){
//		cout << know[i] << " " << beknow[i] << endl;
//	}
	for(int j = 0 ; j < m ; j ++){
		for(int i = 1 ; i <= n ; i++){
			if(know[j] == i){
				knum[i]++;
			}
			if(beknow[j] == i){
				bnum[i]++;
			}
		}	
	}
//	for(int i = 0;i <= n;i++ ){
//		cout << knum[i] << " " << bnum[i] << endl; 
//	}
	int bigbeknownum = 0;
	int bigknownum = 0;
	for(int i = 1 ; i <= n; i ++){
		if(bnum[i] > bigbeknownum){
			bigbeknownum = bnum[i]; 
		}
		if(knum[i] > bigknownum){
			bigknownum = knum[i]; 
		}
	}
	cout << bigbeknownum << " " << bigknownum;
	return 0;
}
