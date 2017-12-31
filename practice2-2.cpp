#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int n = 0;
	int m = 0;
	int num[1500] = {0};
	int answer = 0;
	cin >> n >> m;
	for (int i = 0; i < m ; i++){
		cin >> num[i];
//		cout << num [i];
	}
	for(int i = 0; i <= m-n ; i++){
		answer = 0 ;
		for(int j = 0 ; j < n ;j++){
			answer += num[i + j];
//			cout << num[i + j] << " ";
		}
//		cout << endl;
//		cout << answer << " ";
		cout << answer / n << " ";
	}
	
	return 0;
}
