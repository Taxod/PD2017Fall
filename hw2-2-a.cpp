#include <iostream>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = x1; i <= x2; i++)
	{
		for(int j = y1; j <= y2; j++)
		{
			cout << "(" << i << ", " << j << ") ";
		}
		cout << "\n";
	}
return 0;
}
