#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b ;
	for(int i = a; i <= b; i++)
	{
		for(int j = a; j <= b; j++)
		{
			if(i < j){
				cout << "(" << i << ", " << j << ") ";	
			}
		}
		cout << "\n";
	}
return 0;
}
