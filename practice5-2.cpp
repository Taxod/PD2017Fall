#include <iostream>

using namespace std;
int min(int a,int b);
int gcd(int a,int b);

int main(){
	int a , b ;
	cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}
int gcd(int a, int b){
	int gcd = 0;
	for(int i = 1; i <= min(a,b); i++){
		if(b % i == 0 && a % i == 0 && i > gcd){
			gcd = i;
		}
	}
	//有更好的做法 
	return gcd;
}
int min(int a, int b){
	int minnum = 0;
	if (a > b)
	{
		minnum = b;
	}else if (b > a)
	{
		minnum = a;
	}else{
		return 0;
	}
	return minnum;
}
