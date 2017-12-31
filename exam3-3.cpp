#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n = 0;
	char s[1001] = {0};
	char ta[6] = {0};
	cin.getline(s,1001);
	cin.getline(ta,6);
	int q[1001] = {0};
	int target[6] = {0};
	int len = strlen(s);
	for(int i = 0 ; i < len ; i++){
		q[i] = s[i];
	}
	int t_len = strlen(ta);
	for(int i = 0 ; i < t_len ; i++){
		target[i] = ta[i];
	}
	
	for(int i = 1; i < 26; i++){
		int temp[1001] = {0};
		for(int j = 0 ; j < len;j++){
			temp[j] = q[j];
			temp[j] += i;
			if(temp[j] > 122){
				temp[j] %= 122;
				temp[j] += 96; 
			}
		}
		for(int j = 0; j < len ; j++){
			if(temp[j] == target[0]){
				bool flag = 1;
				for(int k = 0 ; k < t_len ; k++){
//					if( j+k > len){
//						break;
//					}
					if(temp[j+k] == target[k]){
					}else{
						flag =0;
					}
				}
				if(flag == 1){
					cout << i <<": ";
					for(int l = 0 ; l < len ; l++){
						if(temp[l] >= 97 && temp[l] <= 122){
							cout << char(temp[l]);
						}else{
							cout <<" ";		
						}
					}
					cout <<endl;
					continue;
				}
			}
		}
		
	}
	return 0;
}
