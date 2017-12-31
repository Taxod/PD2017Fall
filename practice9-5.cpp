#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;
int LEN = 1001;
int main(){
	char s[LEN] = {0};
	cin.getline(s,LEN);
	int len = strlen(s);
	
	for(int i = 0; i < (len);i++){
		if(s[i] == '0' && s[i-1] == ' ' && (isspace(s[i+1]) || ispunct(s[i+1]) )){
			cout << "zero";
		}else{
			cout << s[i];
		}
	}
	return 0;
}
