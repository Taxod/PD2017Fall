#include <iostream>

using namespace std;

int  main()
{
	int m = 0,k = 0;
	int tmp = 0;
	cin >> tmp >> m >> k;
	int* N = new int [tmp];

	for (int i = 0; i < tmp; ++i)
	{
		cin >> N[i];
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


	char* k_c = new char[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> k_c[i];
		for (int j = 0; j < 2; ++j)
		{
			cin >> br[i][j];
			br[i][j]-- ;
		}
	}


	for (int i = 0; i < m; ++i)
	{
		if (y[i])
		{
			z[i] = -1;
		}
	}

	//車站有多少車
	int* now = new int [tmp];
	for (int i = 0; i < tmp; ++i)
	{
		now[i] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		if (!y[i])
		{
			now[z[i]]++;
		}
	}
 
	for (int i = 0; i < k; ++i)
	{
		if (k_c[i] == 'S')
		{
			br[i][1]++;
			N[br[i][0]] += br[i][1]; 
		}else{
			if ((y[br[i][0]] && br[i][1] != -1) || (!y[br[i][0]] && br[i][1] == -1))
			{
				// cout << " *" << i << "* "<<endl;
				if (br[i][1] == -1 || now[br[i][1]] < N[br[i][1]])
				{
						for (int j = 0; j < 2; ++j)
						{
							z[br[i][j]] = br[i][j+1];
							if (br[i][j+1] == -1)
							{
								y[br[i][j]] = 1;
							}else{
								y[br[i][j]] = 0;
							}
							j++;
						}
						for (int p = 0; p < tmp; ++p)
						{
							now[p] = 0;
						}
						for (int p = 0; p < m; ++p)
						{
							if (!y[p])
							{
								now[z[p]]++;
							}
						}
						// cout << " *" << i << "* ";
						// for (int p = 0; p < tmp; ++p)
						// {
						// 	cout <<N[p] <<":"<< now[p] << " ";
						// }
						// cout << endl;
				}else{
					continue;
				}
			}else{
				continue;
			}
		}
	}



int* location = new int [tmp];
	for (int i = 0; i < tmp; ++i)
	{
		location[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		if (z[i] != -1)
		{
			location[z[i]]++;
		}
	}
	




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





	return 0;
}