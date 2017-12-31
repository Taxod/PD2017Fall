#include <iostream>
using namespace std;
 
 int main()
 {
 	int num = 0;
 	int out = 0;
 	
 	// enter the money
	cin >> num;
 	
 	// calculate the change
 	num = 1000 - num;
	out = num;
 	
 	//calculate the number of five hundred dollars
 	cout << out / 500 << " ";
	//change reduce fivehundred we had get.
 	num %= 500;
 	out = num;
	
 	cout << out / 100 << " ";
 	num %= 100;
 	out = num;
	 
	
 	cout << out / 50 << " ";
 	num %= 50;
 	out = num;
	 
	
 	cout << out / 10 << " ";
 	num %= 10;
 	out = num;
	 
	
 	cout << out / 5 << " ";
 	num %= 5;
 	out = num;
	 
	
 	cout << out;
 	
 	return 0;
 }
