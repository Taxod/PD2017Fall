#include <iostream >
using namespace std;
int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	while(a != 0)
	{
		if(b >= 5)
			b++;
		else if(b < 5)
			b--;
		cout << a << " " << b << "\n";
		a--;
	}
	return 0;
} 
