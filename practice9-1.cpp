#include<iostream>
#include<cstring>
using namespace std;

int LEN = 1001;

int main(){
	char s[LEN] = {0};
	cin.getline(s,1000);
//	char* p = strchr(s, '!');
	char* p = s;
	int count = 0;
//	cout << p <<endl;
//	cout << p+1;
	while(*p != '\0'){
		switch(*p){
			case ',':
				count ++;
				break;
			case '!':
				count++;
				break;
			case '.':
				count++;
				break;
			case ':':
				count++;
				break;
			case ';':
				count++;
				break;
			case '?':
				count++;
				break;
		}
		p = p+1;
	}
	cout << count;
//	while(p != NULL)
//	{
//		count ++;
//		p = strchr(p, ',.:;!?');
//	}

//	cout << count;
	return 0;
}
