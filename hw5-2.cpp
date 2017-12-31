#include<iostream>
using namespace std;
int main(){
	int num[100][100] = {0};
	int n;
	cin >> n;
	
	if(n == 0){
		cout << "1 0";
		return 0;
	}
	
	int ifn1 = 0;
	if(n == 1){
		cin >> ifn1;
		cout << "1 2 "<< ifn1;
		return 0;
	}
	
	
	for(int i = 0; i < n ; i ++){
		for(int j = i + 1 ; j < n ; j ++){
			cin >> num[i][j];
			num[j][i] = num [i][j];
			num[i][i] = 2147483647; // notice 
		}
	}


	int count = 0;
	int x = 0;
	int minnum = 2147483647;
	int minindex = 0;
	int D = 0;
	while(count != (n)){
		minnum = 2147483647;
		
		for(int i = 0 ; i < n ; i ++){
			if((num[x][i] < minnum) && (i != x) && count != n-1 && i != 0 ){
				minnum = num[x][i];
				minindex = i;
			}
		}
		
		cout << x + 1 << " " ;
		
		D += num[x][minindex];
		num[x][minindex] = 2147483647; // notice !!!!!!!!!!!!
		num[minindex][x] = num[x][minindex];
		
		if( x != 0){
			for(int i = 0; i < n ; i++){
				num[x][i] = 2147483647;//notice !!!!!!!!!!!!
				num[i][x] = 2147483647;
			}
			
		}
		
		
		
		x = minindex;
		count ++;
		
		
		if(count == (n-1)){
			D += num[x][0];
			cout << x+1 << " ";
			break;
		}
		
		
		/*test*/
//	for(int i = 0; i < n ;i ++){
//		for(int j = 0 ; j < n ;j ++){
//			cout << num[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//	cout << endl;
//
//
	}
	
	/**/
	cout << D;
	return 0;
}
