#include<iostream>
using namespace std;
int main(){
//	int num = 0;
	for(int num = 2 ; num < 1000000 ; num++){
		while(num !=1){
			if(num % 2 == 0){
				num /= 2;
//				cout << num << " ";
			}else{
				num *= 3;
				num += 1;
//				cout << num <<" ";
			}		
		}
	}
	
	
	
	return 0;
}
