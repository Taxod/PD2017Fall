#include<iostream>

using namespace std;

int main(){
	int n[9] = {0};
	for(int i = 0 ; i < 9 ; i++){
		cin >> n[i];
	}
	int ans = 0;
	if((n[0]+n[1]+n[2])==15){
		ans++;
	}
	if((n[3]+n[4]+n[5])==15){
		ans++;
	}
	if((n[6]+n[7]+n[8])==15){
		ans++;
	}
	if((n[0]+n[3]+n[6])==15){
		ans++;
	}
	if((n[1]+n[4]+n[7])==15){
		ans++;
	}
	if((n[2]+n[5]+n[8])==15){
		ans++;
	}
	if((n[0]+n[4]+n[8])==15){
		ans++;
	}
	if((n[2]+n[4]+n[6])==15){
		ans++;
	}
	cout << ans;
	return 0;
}
