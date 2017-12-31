#include <iostream>

using namespace std;
int min(int a,int b);

int main(){
	int a , b ;
	cin >> a >> b;
	cout << min(a,b);
	return 0;
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
