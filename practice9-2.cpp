#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	char s[1001] = {0};
	cin.getline(s,1000);
	int count = 0;
	while(s[count] != '\0'){
		s[count] = tolower(s[count]);
		cout << s[count];
		count ++;
	}
	cout << endl;
	s[0] = toupper(s[0]);
	char* p = s;
	while(*p != '\0'){
		if(*p == ' '){
			*(p+1) = toupper(*(p+1));
		}
		p = p+1;
	}
//	for(int i = 0 ; i < count ; i++){
//		if(s[i] == ' '){
//			s[i+1] = toupper(s[i+1]);
//		}
//	}
	cout << s;
	return 0;
}
