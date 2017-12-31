#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;
int the_same_len(char s[],char t[]);//檢查至多有多少字元一樣 
int LEN = 101;

int main(){
	int n = 0;
	cin >> n;
	// how to getline int? 
	char tmp[2] ;
	cin.getline(tmp,2);
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
			ptr = nullptr;
			ptr = strstr(s[i],target);
			if(ptr != nullptr){
				answer[i] = 10000;
				ptr = nullptr;
			}else{
				answer[i] = the_same_len(s[i],target)*10;
			}
		}else if(strstr(s[i],target) != nullptr){
			answer[i] = 1000;
			ptr = strstr(s[i],target);
			while(ptr != nullptr){
				answer[i] ++;
				ptr = strstr(ptr+1,target);
			}
		}else{
			answer[i] = the_same_len(s[i],target)*10;
		}
	}


//	char*** spli = new char** [n];
//	for(int i = 0 ; i < n ; i ++){
//		spli[i] = new char*[100];
//		for(int j = 0 ; j < 100 ; j++){
//			spli[i][j] = new char[LEN];
//		} 
//	}
//	
//	for(int i = 0 ; i < n ; i ++){
//		for(int j = 0 ; j < 100;j++){
//			for(int k = 0 ; k < LEN;k++){
//				spli[i][j][k] = 0;
//			}
//		}
//	}
	
//	char d[]=",.?!:; ";
//	int wordcnt[100] = {0};
//	for(int i = 0; i < n ; i ++){
//		char* start = strtok(s[i],d);
//		while(start != nullptr){
//			strcpy(spli[i][wordcnt[i]],start);
//			wordcnt[i] ++;
//			start = strtok(nullptr,d);
//		}	
//	}
	char d[]=",.?!:; ";
	char** spot = new char* [LEN];
	for(int i = 0 ; i < LEN; i++){
		spot[i] = new char [LEN];
	}
	int spotnum = 0;
	char* start = strtok(target,d);
	while(start != nullptr){
		strcpy(spot[spotnum],start);
		spotnum ++;
		start = strtok(nullptr,d);
	}
	
	/*5
This is
This is an apple
This is an apple. This is not a book.
Oh yeah!!!!
Today is his birthday
This is*/
	
	
	
	int wordcnt[100] = {0};
	for(int i = 0; i < n ; i ++){
		char* start = strtok(s[i],d);
		while(start != nullptr){
			char cmp [101] = {0};
			strcpy(cmp,start);
			for(int j = 0 ; j < spotnum ; j++){
				if(strlen(spot[j]) == strlen(cmp) 
				&& strstr(cmp,spot[j]) != nullptr){
					answer[i]++;
				}	
			}
			start = strtok(nullptr,d);
		}	
	}
	
	//release memory	
	for(int i = 0 ; i < n ; i++){
		delete [] s[i];
	}
	delete [] s;

	
	
//	for(int i = 0 ; i < LEN ;i++){
//		for(int j = 0 ; j < LEN ;j ++){
//			spli[i][j] = 0;
//		}
//	}

	



//	for(int i = 0 ; i < n ; i++){
//		for(int j = 0 ; j < wordcnt[i] ; j++){
//			for(int k = 0 ; k < spotnum; k++){
//				if(strlen(spot[k]) == strlen(spli[i][j]) 
//				&& strstr(spli[i][j],spot[k]) != nullptr){
////					answer[i]++;
//				}
//			}
//		}
//	}


	
	
	//print answer
	for(int i = 0 ; i < n-1 ; i++){
		cout << answer[i] <<",";
	}
	cout << answer[n-1];
	
	

	
	return 0;
}


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
