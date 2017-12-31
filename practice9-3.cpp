#include<iostream>
#include<cstring>
using namespace std;

int LEN = 1001;

int main(){
	char a[LEN] = {0};
	char b[LEN] = {0};
	bool flag = 0;
	char* p = 0;
	cin.getline(a,1001);
	cin >> b;
	
	int lena = strlen(a);
	int lenb = strlen(b);
	for(int  i = 0 ; i < lenb; i ++){
		b[i] = tolower(b[i]);
	}
	p = strchr(a,b[0]);
	while(p != nullptr){
		if(strncmp(p,b,lenb) == 0){
			flag = 1;
		}
		p += 1;
		p = strchr(p,b[0]);
	}
//	for(int i = 0 ; i < lena ; i++){
////		cout << i;
//		if(a[i] == b[0]){
//			cout << "*";
//			if(strncmp(a[i],b,lenb) == 0){
//				flag = 1;
//			}
////			i += lenb;	
//		}
//	}

	if(flag){
		cout <<"1";
	}else{
		cout <<"0";
	}
	
	return 0;
}
