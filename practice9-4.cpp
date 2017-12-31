#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

int main(){
	int n;
	cin >> n;
	char target[51] = {0};
	char** word = new char* [n];
	cin >> target;
	for(int i = 0 ; i < n ; i++){
		word[i] = new char[51];
		cin >> word[i];
	}
	int len = strlen(target);
	for(int i = 0 ; i < len ; i++){
		target[i] = tolower(target[i]);
	}
	int flag = 1;
	for(int i = 0 ; i < n ; i ++){
		if(strlen(word[i]) == len){
				if(strcmp(word[i],target) != 0){
					flag = 0;
			}
		}
	}
	if(flag){
		cout <<"1";
	}else{
		cout << "0";
	}
	return 0;
}
