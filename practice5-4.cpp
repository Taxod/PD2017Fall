#include <iostream>

using namespace std;
int highGradeCnt(int threshold,int gradeCnt ,int grade[]);
int main(){
	int threshold = 0, n = 0;
	int grade[50] = {0};
	cin >> n >> threshold;
	for(int i = 0; i < n ; i ++){
		cin >> grade[i];
	}
	cout << highGradeCnt(threshold, n, grade);
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

