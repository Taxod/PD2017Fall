#include<iostream>

using namespace std;

int main(){
	int n = 0;
	int grade[100][100] = {0};
	char gradetemp = 0;
	cin >> n;
	for(int i = 0; i < n ; i ++){
		for(int j = 0 ; j < 3 ; j++){	
			if( j == 2){
				cin >> gradetemp;
				grade[i][j] = int(gradetemp);	
			}else{
				cin >> grade[i][j];
			}
			
		}
	}
	
	int flag = 0 , q = 0;
	char qtemp = 0;
	cin >> flag;
	if(flag == 0){
		cin >> q;	
	}else{
		cin >> qtemp;
		q = int(qtemp);
	}
	
	
	if(flag == 1){
		for(int i = 0 ; i < n ; i++){
			if(grade[i][2] == q){
				if((grade[i][1]+grade[i][0]) % 2 != 0){
					cout << ((grade[i][1]+grade[i][0])/2) + 1;	
				}else{
					cout << ((grade[i][1]+grade[i][0])/2);	
				}
			}
		}
	}else{
		for(int i = 0; i < n ; i++){
			if(q >= grade[i][0] && q <= grade[i][1]){
				cout << char(grade[i][2]);
			}
		}
	}
	return 0;
}
