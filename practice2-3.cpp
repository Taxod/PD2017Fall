#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	int n = 0;
	int m = 0;
	float num[1500] = {0};
	float answer[1500] = {0};
	float temp = 0;
	float difference = 0;
	int k ;
	cin >> k >> m;
	for (int i = 0; i < m ; i++){
		cin >> num[i];
	}
	float mindifference = 50000;
	int minloc = 0;

	for(int n = 2; n <= k ; n++){
		
		
		
	for(int i = 0; i <= m-n ; i++){
		temp = 0;
		for(int j = 0 ; j < n ;j++){
			temp += num[i + j];
		}
		answer[i] = temp / n;
	}
	for(int i = 0; i < m-n ;i++){
		difference += abs(answer[i] - num[i+n]);
//		cout << answer[i] << " " << num[i+n]<< endl ;
	}
//	cout << difference / (m-n) << " " << n << endl;
	if ((difference / (m-n)) < mindifference){
		mindifference = (difference / (m-n));
		minloc = n;
	}
	difference = 0;



	
	}
	mindifference *= 100;
//	cout << mindifference << endl; 
	mindifference = static_cast<int>(mindifference);
//	cout << mindifference << endl; 
	mindifference = static_cast<float>(mindifference);
	mindifference /= 100;
	cout << minloc << " " << mindifference;
	return 0;
}
