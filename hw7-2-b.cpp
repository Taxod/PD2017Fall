#include<iostream>

using namespace std;

int len = 10;


void swap(int &a,int &b);

void selection_sort(int arr[], int len);

int main(){
	int arr[len] = {0};
	for(int i = 0 ; i < len ; i++){
		cin >> arr[i];
	}
	selection_sort(arr,len);
	
	
	return 0;
}
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int arr[], int len) 
{
	for (int i = 0,min = 0 ; i < len - 1; i++) 
        {
		min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[min] > arr[j])
				min = j;
	   	swap(arr[min], arr[i]);
	   	for(int i = 0 ; i < len ; i++){
			cout <<  arr[i]<< " ";
		}
		cout << endl;
	}
	
}
