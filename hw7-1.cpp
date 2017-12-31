#include<iostream>

using namespace std;

int catalan(int n);


int main(){
	int n;
	cin >> n;
	cout << catalan(n);
	return 0;
} 

int catalan(int n){
	int ans = 0;
	if (n == 0){
		return 1;	
	}
    for (int i = 0; i < n; i++){
    	ans += catalan(i) * catalan(n-i-1);	
	}
    return ans;
}
