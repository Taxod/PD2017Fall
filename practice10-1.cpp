#include<iostream>

using namespace std;
void bubbleSort(const int unsorted[], int sorted[], int len);
void insertionSort(const int unsorted [], int sorted [], int len);

int main(){
	int sorted[] = {7,5,3,3,9,6,7};
	int unsorted[] = {7,5,3,3,9,6,7};
	int len = 7;
//	bubbleSort(unsorted,sorted,len);
	insertionSort(unsorted,sorted,len);

	for(int i = 0 ; i < len ; i++){
		cout << sorted[i] <<" ";
	}
	return 0;
}

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}





// -------------------------------------
void insertionSort(const int unsorted[], int sorted[], int len){
	for(int i = 0 ; i < len ; i ++){
		int j = 0;
		int min_ = 0;
		while(j < i){
			min_ = j;
			j++;
		}
	}
}





void bubbleSort(const int unsorted[], int sorted[], int len){
//	for(int i = 0 ; i < len ; i ++){
//		sorted[i] = unsorted[i];
//	}
	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len-1 ; j++){
			if(sorted[j] > sorted[j+1]){
				int tmp = sorted[j];
				sorted[j] = sorted[j+1];
				sorted[j+1] = tmp;
			}
		}
	}
}
