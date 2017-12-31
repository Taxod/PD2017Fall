#include<iostream>

using namespace std;

int number = 10;


bool insert(int value[],int k,int n);
int main(){
	int value[number] = {0};
	//7 4 6 3 8 2 9 0 1 5
	for(int i = 0; i < number ; i ++){
		cin >> value[i];
	}
	cout <<endl;
	insert(value,0,number);
//	for(int i = 0; i < number ; i ++){
//		cout << value[i]<<" ";
//	}
	return 0;
}
bool insert(int value[],int k,int n){
	int tmp[number] = {0};
	for(int i = 0 ; i < number ; i++){
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
		for(int o = 0; o < number ; o++){
			cout << value[o] <<" ";
		}
		for(int y = 0 ; y < n ; y++){
			tmp[y] = value[y]; 
		}
		cout << endl;
	}
	
}

