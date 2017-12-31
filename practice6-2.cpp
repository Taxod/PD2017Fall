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
	bool t0 = 0;
	if( n != 0){
		t0 = search(A,n-1,t);
	}
	if(t0 == true || A[n] == t){
		return true;
	}	
	else{
		return false;
	}
		
}

/*
n = 2
search(A,1,t)

n = 1

search(A,0,t)

n = 0
if(t0 == true || A[0] == t){

return true
}else{
return false;
}*/


