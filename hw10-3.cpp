#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;
int the_same_len(char s[],char t[]);//�ˬd�ܦh���h�֦r���@�� 
int LEN = 101;

int main(){
	int n = 0;
	cin >> n;
	// how to getline int? 
	char tmp[10] ;
	cin.getline(tmp,10);
	char** s = new char*[n];
	for(int i = 0 ; i < n ; i++){
		s[i] = new char[LEN];
		cin.getline(s[i],LEN);
	}
	char target[LEN] = {0};
	cin.getline(target,LEN);
	




	int answer[1000] = {0};
	char* ptr = nullptr;
	for(int i = 0; i < n ; i++){
		if(strlen(s[i]) == strlen(target)){
			//�ˬd�O���O�����@�� 
			ptr = nullptr;
			ptr = strstr(s[i],target);
			if(ptr != nullptr){
				answer[i] = 10000;
				ptr = nullptr;
			}else{
				//�ˬd�ܦh���h�֦r���@�� 
				answer[i] = the_same_len(s[i],target)*10;
			}
		}else if(strstr(s[i],target) != nullptr){//�ˬd�O���O�Q�]�t 
			answer[i] = 1000;
			ptr = strstr(s[i],target);
			while(ptr != nullptr){
				answer[i] ++;
				ptr = strstr(ptr+1,target);
			}
		}else{
			//�ˬd�ܦh���h�֦r���@�� 
			answer[i] = the_same_len(s[i],target)*10;
		}
	}
	
	//release memory	
	for(int i = 0 ; i < n ; i++){
		delete [] s[i];
	}
	delete [] s;

	
	
	//print answer
	for(int i = 0 ; i < n-1 ; i++){
		cout << answer[i] <<",";
	}
	cout << answer[n-1];
	
	

	
	return 0;
}


//�ˬd�ܦh���h�֦r���@��
int the_same_len(char s[],char t[]){
	int m = 0;
	for(int i = 0 ; i < strlen(t) ; i ++ ){
		for(int j = 0 ; j < strlen(s); j++){
			int count = 0;
			if(t[i] == s[j]){
				count ++;
				int tp = 1;
				while((tp+j) < strlen(s)){
					if(t[i+tp] == s[j+tp]){
						count ++;
						tp++;
					}else{
						break;
					}
				}
			}
			if(count > m){
				m = count;
			}
		}
	}
	return m;
}
