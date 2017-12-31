#include<iostream>

using namespace std;
void bubble_sort(int arr[], int len);

int main(){
	int n = 0;
	int num[50] = {0};
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num[i];
	}
	if(n < 3){
		cout << "0";
		return 0;
	}
	bubble_sort(num, n);
//	for(int i = 0 ; i < n ; i++){
//		cout << num[i] <<" ";
//	}
	int answer[100] = {0};
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			for(int k = 0 ; k < n;k++){
				if(num[i] != num[j] && num[i] != num[k] && num[j] != num[k] && num[i] < num[j] && num[j] < num[k]){
					if(num[i]*num[i] + num[j]*num[j] == num[k]*num[k]){
						answer[count] = num[i];
						count ++;
					}
				}
			}
		}
	}
	if(count == 0){
		cout <<"0";
		return 0;
	}
	cout << count <<" ";
	bubble_sort(answer,count);
	cout << answer[0];
	return 0;
} 
void bubble_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

	}
		
	
}
