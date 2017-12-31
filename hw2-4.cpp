#include<iostream>
using namespace std;
int main(){
	int num1 = 0, num2 = 0,smaller_num = 0;
	int gcd1 = 0, gcd2 = 0;
	int count = 0;
//	greatest common divisor -> gcd
	cin >> num1 >> num2;
	if(num1 > num2){
		smaller_num = num2;
	}else{
		smaller_num = num1;
	}
	for(int i = 1; i <= smaller_num ; i++){
		if(num1 % i == 0 && num2 % i == 0){
			if(count % 2 == 1){
				gcd1 = i;	
			}else{
				gcd2 = i;
			}
			count ++;
		}
	}
	if(gcd1 > gcd2){
		cout << gcd2;
	}else{
		cout << gcd1;
	}
	return 0;
}
