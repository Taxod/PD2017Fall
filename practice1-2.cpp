#include<iostream>
using namespace std;
int main(){
	int num = 0;
	cin >> num;
	//�p�G��J�̿�J1�A�h���|���� --> while (true)
	 
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
