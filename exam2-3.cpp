#include<iostream>
#include<cmath>
using namespace std;

void bubble_sort(int arr[], int len);
int main(){
	int n = 0;
	int k = 0;
	int num[100] = {0};
	cin >> n >> k;
	for(int  i = 0 ; i < n ;i ++){
		cin >> num[i];
	}
	
	float ave = 0;
	for(int i = 0 ; i < n ; i++){
		ave += num[i];
	}
	ave /= n;
	
	float sd = 0;
	
	for(int i = 0 ; i < n ;i++){
		sd = sd + (num[i] - ave)*(num[i] - ave);
	}
	sd /= n;
	sd = sqrt(sd);
	
	int answer[100] = {0};
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		if(abs(num[i]-ave) > int(sd*k)){
			answer[count] = num[i];
			count ++;
		}
	}
//	cout << int(sd*k);
	if(count == 0){
		cout << "-1";
		return 0;
	}
	bubble_sort(answer, count);
	for(int i = 0; i < count-1; i++){
		cout << answer[i] << " ";
	}
	cout << answer[count-1];
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
