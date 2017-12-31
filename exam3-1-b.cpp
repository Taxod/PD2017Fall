#include <iostream >
using namespace std;
int* maxWrong(int a, int b,int*c,int*d)
{
	if(b > a)
//		return &b;
		cout << &b<<endl;
	else
//		return &a;
		cout << &a;
	if(d > c)
		cout << c <<endl;
	else
		cout << d;
}
int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int* maxAddr = maxWrong(a, b,&a,&b);
	cout << "*" << &b << endl;
//	cout << maxAddr << "\n";
return 0;
}

