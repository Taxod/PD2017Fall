#include<iostream>
#include<ctime>
#include<cstdlib>

int LEN = 20;
using namespace std;

void setRN (int rn[],int LEN);

int main(){
	srand(time(nullptr));
	int rn[20] = {0};
	setRN(rn,LEN);
	for(int i = 0 ; i < LEN ; i++){
		cout << rn[i] %10001<<" ";
	}
	return 0;
}
void setRN (int rn[],int LEN){
	for(int i = 0; i < LEN ; i++){
		rn[i] = rand();
	}
}

