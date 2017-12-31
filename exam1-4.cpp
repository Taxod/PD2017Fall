#include<iostream>

using namespace std;

int main(){
	int n = 0;
	int d[100] = {0};
	int p[100] = {0};
	int w[100] = {0};
	int s1 = 0 , s2 = 0;
	cin >> n ;
	for(int i = 0 ; i < n ; i ++){
		cin >> d[i];
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> p[i];
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> w[i];
	}
	cin >> s1 >> s2;
	int time = 0;
	int worktimeex[100] = {0};
	int worktime[100] = {0};
	for(int i = 0;i < n ; i++){
		time += p[w[i]-1];
		worktime[w[i]] = time;
	}
	int delay = 0;
	for(int i = 1; i<= n ; i++){
		if(worktime[i] > d[i-1]){
			delay++;
		}
	}
	
	
//	for(int i = 0 ; i <= n ; i ++){
//		cout << worktime[i] << " " << i << endl;
//	}
	
	
	
	int index1 = 0;
	int index2 = 0;
	int temp = 0;
	for(int i = 0; i < n ; i++){
		if(w[i] == s1){
			index1 = i;
		}
		if(w[i] == s2){
			index2 = i;
		}
	}
	temp = w[index1];
	w[index1] = w[index2];
	w[index2] = temp;
	
//	for(int i = 0; i < n ; i++){
//		cout << w[i] << " ";
//	}
	
	time = 0;
	for(int i = 0;i < n ; i++){
		time += p[w[i]-1];
		worktimeex[w[i]] = time;
	}
	
	int delayex = 0;
	for(int i = 1; i<= n ; i++){
		if(worktimeex[i] > d[i-1]){
			delayex++;
		}
	}
	
	cout << delay<< " " <<delayex;

	return 0;
}
