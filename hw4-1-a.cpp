#include<iostream>
using namespace std;
int main(){
	int i = 0;
	short sGood = 32765;
	while(i < 10)
	{
		short sBad = sGood + i;
		cout << sGood + i << " " << sBad << "\n";
		i = i + 1;
	}
	return 0;
}
