#include<iostream>

using namespace std;


bool insert(int value[],int k,int n);
int main(){
	int value[9] = {2,5,9,12,7,4,11,8,1};
	
	for(int i = 0; i < 9 ; i ++){
		cout << value[i]<<" ";
	}
	cout <<endl;
	insert(value,4,9);
	for(int i = 0; i < 9 ; i ++){
		cout << value[i]<<" ";
	}
	return 0;
}
bool insert(int value[],int k,int n){
	int tmp[9] = {0};
	for(int i = 0 ; i < 9 ; i++){
		tmp[i] = value[i];
	}
	
	int temp = 0;
	for(int i = k ; i < n ; i++){
		for(int j = 0; j < i; j++){
			if(value[i] < value[j]){
				temp = value[j];
				value[j] = value[i];
				int count = j+1;
				int a = value[i]; 
				for(int p = j; p < n;p++){
					if(tmp[p] != a){
						value[count] = tmp[p];
						count ++;
					}
				}
				break;
			}
		}
		for(int y = 0 ; y < n ; y++){
			tmp[y] = value[y]; 
		}
	}
	
}

