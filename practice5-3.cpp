#include <iostream>

using namespace std;
int min(int a,int b);
int gcd(int a,int b);
int threegcd(int a,int b,int c);

int main(){
	int a , b , c;
	cin >> a >> b >> c;
	cout << threegcd(a,b,c);
	return 0;
}
int threegcd(int a,int b,int c){
	int temp = 0;
	int threegcd = 0;
	temp = gcd(a,b);
	threegcd = gcd(temp,c);
	return threegcd;
}
int gcd(int a, int b){
	int gcd = 0;
	for(int i = 1; i <= min(a,b); i++){
		if(b % i == 0 && a % i == 0 && i > gcd){
			gcd = i;
		}
	}
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
/*gcd(int a , int b ,int c);
gcd(gcd(a,b),c)
*/
