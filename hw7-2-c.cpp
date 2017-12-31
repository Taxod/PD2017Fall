#include<iostream>

using namespace std;



void bubble_sort(int arr[], int len);

int len = 10;

int main() {
	int arr[len] = {0};
	
	for (int i = 0; i < len; i++)
		cin >>  arr[i];
	
	
	
	bubble_sort(arr, len);
	
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
		for (int i = 0; i < len; i++)
			cout << arr[i] << " ";
		cout << endl;	

	}
		
	
}
