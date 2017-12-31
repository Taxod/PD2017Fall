#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int m = 0,k = 0;
	int tmp = 0;
	cin >> tmp >> m >> k;
	int** N = new int* [tmp];

	for (int i = 0; i < tmp; ++i)
	{
		int tmp2 = 0;
		cin >> tmp2;
		N[i] = new int [tmp2];
	}
	bool *y = new bool [m];
	int *z = new int [m];
	for (int i = 0; i < m; ++i)
	{
		cin >> y[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> z[i];
		z[i]--;
	}
	int** br = new int*[k];
	for (int i = 0; i < k; ++i)
	{
		br[i] = new int[2];
	}

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> br[i][j];
			br[i][j]-- ;//let the number begin from zero
		}
	}





//mark the bick borrowed.
	for (int i = 0; i < m; ++i)
	{
		if (y[i])
		{
			z[i] = -1;
		}
	}





	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			z[br[i][j]] = br[i][j+1];//refresh the bick condition(location)
			j++;//jump to next borrow record
		}
	}





	int* location = new int [tmp];
	//initialize the array
	for (int i = 0; i < tmp; ++i)
	{
		location[i] = 0;
	}
	//count the bick number of every station
	for (int i = 0; i < m; ++i)
	{
		if (z[i] != -1)
		{
			location[z[i]]++;
		}
	}
	






//print answer
	bool flag2 = 0;
	for (int i = 0; i < tmp; ++i)
	{
		if (flag2)
		{
			cout << endl;
		}
		bool flag = 0;
		cout << location[i] <<":";
		for (int j = 0; j < m; ++j)
		{
			if (flag && z[j] == i)
			{
				cout << " ";
			}
			if (z[j] == i)
			{
				cout << j+1;
				flag = 1;
			}
		}
		flag2 = 1;
	}





	//release memory
	for (int i = 0; i < tmp; ++i)
	{
		delete [] N[i];
	}
	for (int i = 0; i < k; ++i)
	{
		delete [] br[i];
	}
	delete [] N;
	delete [] br;
	delete [] y;
	delete [] z;
	delete [] location;

	return 0;
}
