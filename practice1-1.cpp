#include<iostream>
using namespace std;
int main(){
//	man:18
//	woman:16
	int gender = 0;
	int age = 0;
	cin >> gender >> age;
	if(age >= 18 ){
		cout >> "Yes";
	}else if(age >= 16 && gender == 0){
		cout >> "Yes";
	}else{
		cout >> "No"; 
	}
	return 0;
}
