#include<iostream>
using namespace std;
int main(){
	int num = 0;
	cin >> num;
	//如果輸入者輸入1，則不會執行 --> while (true)
	 
	while(num !=1){
		if(num % 2 == 0){
			num /= 2;
			cout << num << " ";
		}else{
			num *= 3;
			num += 1;
			cout << num <<" ";
		}	
	}
	
	
	return 0;
}
