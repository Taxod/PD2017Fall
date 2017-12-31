#include<iostream>

using namespace std;

int main(){
	int n = 0 , y = 0, z = 0;
	int rnum[101] = {0};
	int flag = 0;
	int num = 0;
	int count = 0;
	cin >> n >> y >> z;
	for(int i = 0 ; i < n ; i ++){
		cin >> num;
		if(num > y && num < z){
			rnum[count] = num;
			count ++;
		}
	}
	if(count == 0){
		cout << "0";
	}else{
		for(int i = 0; i < count-1; i ++){
			cout << rnum[i] << " ";
		}
		cout << rnum[count-1];
	}
	

	return 0;
}
