#include <iostream>

using namespace std;
int highGradeCnt(int threshold,int gradeCnt ,int grade[]);
int mosthighgrades(int threshold,int assignment ,int gradeCnt ,int grade[][50]);
int main(){
	int m = 0 ,threshold = 0, n = 0;
	int grade[10][50] = {0};
	cin >> m >> n >> threshold;
	
	for(int i = 0; i < m ; i ++){
		for(int k = 0 ; k < n ; k ++){
			cin >> grade[i][k];	
		}
	}
	cout << mosthighgrades(threshold,m ,n , grade) + 1;

	return 0;
}

int highGradeCnt(int threshold,int gradeCnt ,int grade[]){
	int count = 0;
	for(int i = 0; i < gradeCnt ; i ++){
		if(grade[i] >= threshold){
			count ++;
		}
	}
	return count;
}
int mosthighgrades(int threshold,int assignment ,int gradeCnt ,int grade[][50]){
	
	int maxtime = 0;
	int maxindex = 0;
	for(int  i = 0; i < assignment;i++){
		if(highGradeCnt(threshold,gradeCnt ,grade[i]) > maxtime){
			maxtime = highGradeCnt(threshold,gradeCnt ,grade[i]);
			maxindex = i;
		}
	}
	return maxindex;
}

