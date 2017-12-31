#include<iostream>
using namespace std;
int main(){
	int a, b, c, p;
//	max(a-bp)(p-c)
	int max_profit = -1,profit = 0;
	cin >> a >> b >> c;
	p = c ;
	while(max_profit < profit){
		p ++;
		max_profit = profit;
		profit = (a - b * p)*(p - c);
	}
	cout << p - 1 << " "; 
	cout << max_profit;
	return 0;
}
