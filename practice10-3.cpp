#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int LEN = 1000000;
void setRN (int rn[],int LEN);
int main(){
	srand(time(nullptr));
	int *rn = 0;
	rn = new int [1000000];
	setRN(rn,LEN);
	for(int i = 0 ; i < LEN ; i++){
		cout << rn[i] %10001<<" ";
	}
	delete [] rn;
	return 0;
}
void setRN (int rn[],int LEN){
	for(int i = 0; i < LEN ; i++){
		rn[i] = rand();
	}
}

