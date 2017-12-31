#include<iostream>
using namespace std;
int main(){
	int a, b, c, p;
//	max(a-bp)(p-c)
	int max_profit = -1,profit = 0;
	cin >> a >> b >> c;
	p = ((-b*c)-a)/(-2*b);
	max_profit = (a-b*p)*(p-c);
	cout << p <<" " << max_profit;
	return 0;
//	公式解小數可能出問題 
}
