#include<iostream>
using namespace std;
int main(){
	int num1 = 0, num2 = 0,smaller_num = 0,larger_num = 0;
	int gcd = 0;
//	greatest common divisor -> gcd
	cin >> num1 >> num2;
	if(num1 > num2){
		smaller_num = num2;
		larger_num = num1;
	}else{
		smaller_num = num1;
		larger_num = num2;
	}
	// find the largest gcd 
	for(int i = 1; i <= smaller_num ; i++){
		if(num1 % i == 0 && num2 % i == 0){
			gcd = i;
		}
	}
	if(gcd == 1){
		cout << larger_num - smaller_num;
	}else if(smaller_num == gcd){
		cout << larger_num + smaller_num;
	}else{
		cout << gcd;
	}
	
	return 0;
}
