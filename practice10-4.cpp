#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int LEN = 1000000;
void setRN (long long rn[],int LEN);
void hist(const long long value[], int len, int freq[], int binCnt);
int main(){
	srand(time(nullptr));
	long long *rn = 0;
	rn = new long long [1000000];
	setRN(rn,LEN);
	for(int i = 0 ; i < LEN ; i++){
		rn[i] *= (100000/32767);//RAND_MAX
		rn[i] %= 10001;
	}
	int freq[5] = {0};
	
	hist(rn,LEN,freq,5);
	for(int i = 0; i < 5 ; i++){
		cout << freq[i] << endl;
	}
	
	delete [] rn;
	return 0;
}
void setRN (long long rn[],int LEN){
	for(int i = 0; i < LEN ; i++){
		rn[i] = rand();
	}
}
void hist(const long long value[], int len, int freq[], int binCnt){
	for(int i=0 ;i < LEN ; i++){
		if(value[i] < 2000){
			freq[0]++;
		}else if(value[i] < 4000){
			freq[1]++;
		}else if(value[i] < 6000){
			freq[2]++;
		}else if(value[i] < 8000){
			freq[3]++;
		}else if(value[i]<10000){
			freq[4]++;
		}
	}
}
