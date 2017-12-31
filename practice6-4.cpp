#include<iostream>

using namespace std;

bool binarySearch(int value[],int from,int to,int target);


int main(){
	int value[7] = {2,5,9,13,16,20,28};
	int target = 0;
	cin >> target;
	cout << binarySearch(value,0,7,target);
	return 0;	
}

bool binarySearch(int value[],int from,int to,int target){
	int temp = to - from;
	temp = temp / 2;
				
	while(true){
		if(value[temp] == target){
			return true;
		}else{
			if(temp == 0){
				return false;
			}
			if(value[temp] < target){
				temp = to + from;
				temp = temp / 2;
				from = temp;
			}else{
				temp = to + from;
				temp = temp / 2;
				to = temp;
			}
		}
	}	
	return false;
}
