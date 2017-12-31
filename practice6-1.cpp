#include<iostream>

using namespace std;

bool search(int A[],int n,int t);


int main(){
	int A[1000] = {0};
	int n ;
	int t;
	cin >> n >> t;
	
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	
	cout << search(A,n,t);
	
	
	return 0;
}
bool search(int A[],int n,int t){
	for(int i = 1; i <= n ; i++){
		if(A[i] == t){
			return true;
		}
	}
	return false;
}

