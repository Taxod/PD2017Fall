#include <iostream>
using namespace std;
 
 int main()
 {
 	int num = 0;
 	int temp = 0;
 	int out = 0;
 	int a = 0,b = 0;
 	
 	cin >> num >> a >> b;
 	num = 1000 - num;
 	
 	
 	temp = num;
 	out = num;
 	
 	out = out / 500;
	if(out > a){
 		cout << a << " ";
 		temp = temp - a*500;
 		out = temp;
	}else{
		cout << out << " ";
 		temp %= 500;
 		out = temp;		
	}
	
	
	out = out / 100;
 	if(out > b){
 		cout << b << " ";
 		temp = temp - b*100;
 		out = temp;
	}else{
		cout << out << " ";
 		temp %= 100;
 		out = temp;		
	} 
	
 	cout << out / 50 << " ";
 	temp %= 50;
 	out = temp;
	 
	
 	cout << out / 10 << " ";
 	temp %= 10;
 	out = temp;
	 
	
 	cout << out / 5 << " ";
 	temp %= 5;
 	out = temp;
	 
	
 	cout << out; 	
 	return 0;
 }
