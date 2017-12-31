#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n = 0;
	cin >> n;
	char** t = new char* [n];
	char** s = new char* [n];
	for(int i = 0 ; i < n ; i++){
		t[i] = new char [11];
		s[i] = new char [11];
	}
	int* num = new int [n];
	for(int i = 0 ; i < n ; i++){
		cin >> t[i] >> s[i] >> num[i];
	}
	char trash[2] = {0};
	cin.getline(trash,2);
	char* target = new char[10001];
	cin.getline(target,10001);
	char** word = new char*[1000];
	for(int i = 0 ; i < 1000 ; i++){
		word[i] = new char [11];
	}
	int wordCnt = 0;
	char delim[]= " ";
	char* start = strtok(target, delim);
	while(start != nullptr)
	{
		strcpy(word[wordCnt], start);
		wordCnt++;
		start = strtok(nullptr, delim);
	}
	long long* ans = new long long [wordCnt];
	for(int i = 0 ; i < wordCnt ; i++){
		ans[i] = 0;
	}
	for(int i = 0 ; i < wordCnt ; i++){
		for(int j = 0 ;j < n ; j++){
			if(strcmp(word[i],s[j]) == 0){
				ans[i] = num[j];
				int tmp = j;
				for(int k = 0 ; k < n; k++){
					if(strcmp(t[tmp],s[k]) == 0){
						ans[i] *= num[k];
						tmp = k;
						k= -1;
					}
				}
			}
		}
	}
	for(int i = 0 ; i < wordCnt-1 ; i++){
		cout << ans[i] << " ";
	}
	cout << ans[wordCnt-1];
	return 0;
}
