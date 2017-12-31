#include<iostream>

using namespace std;
void swap(int a[],int b[],int arr[][3]);
void sort(int icb[][3], int len);
void sort2(int icb[][3], int len);
int main(){
	int n , m ,k;
	int icb[1000][3] = {0};
	
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i ++){
		icb[i][0] = i;
		cin >> icb[i][1];
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> icb[i][2];
	}  
	
	int peo[1000][3] = {0};//time money
	for(int i = 0 ; i < m ; i ++){
		peo[i][0] = i;
	}
	int answer[1000] = {0};
	int count = 0;
	
	sort(icb,n);
	
	for(int i = 0 ; i < n ; i++){
//	cout << i <<"//";	
		sort2(peo, m);
//		cout << endl;
//		for(int h = 0 ; h < m ;h++){
//			for(int t = 0 ; t < 3 ; t++){
//				cout << peo[h][t] << " ";
//			}
//			cout << endl;
//		}
//		cout << "-----------------\n";
		
		bool flag = 0;
		for(int j = 0 ; j < m ; j++){ 
			if(peo[j][1] + icb[i][1] <= k){
				answer[count] = peo[j][0]+1;
				count++;
				peo[j][1] += icb[i][1];
				peo[j][2] += icb[i][2];
				flag = 1;
//				cout << endl;
//				for(int h = 0 ; h < m ;h++){
//					for(int t = 0 ; t < 3 ; t++){
//						cout << peo[h][t] << " ";
//					}
//					cout << endl;
//				}
//				cout << endl;
				break;
			}else{
				continue;
			}
		}
		if(flag == 0){
			answer[count] = 0;
			count ++;
		}
	}
	for(int i = 0 ; i < n-1 ; i ++){
		cout << icb[i][0]+1<< " ";
	}
	cout << icb[n-1][0]+1 << endl;
	for(int i = 0 ; i < count-1 ; i++){
		cout << answer[i] << " ";
	}
	cout << answer[count-1]<<endl;
	int minc = 100000;
	for(int i =0 ; i < m ; i++){
		if(peo[i][2] < minc){
			minc = peo[i][2];
		}
	}
	cout << minc;
	return 0;
} 

void sort(int icb[][3], int len) {
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++){
			if (icb[j][2] < icb[j+1][2]){
				swap(icb[j], icb[j+1],icb);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] > icb[j+1][1]){
				swap(icb[j], icb[j+1],icb);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] == icb[j+1][1] && icb[j][0] > icb[j+1][0]){
				swap(icb[j], icb[j+1],icb);
			}
		}
	}
}
void sort2(int icb[][3], int len) {
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++){
			if (icb[j][2] > icb[j+1][2]){
				swap(icb[j], icb[j+1],icb);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] < icb[j+1][1]){
				swap(icb[j], icb[j+1],icb);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] == icb[j+1][1] && icb[j][0] > icb[j+1][0]){
				swap(icb[j], icb[j+1],icb);
			}
		}
	}
}




void swap(int a[],int b[],int arr[][3]){
	int tmp[3] = {0};
	for(int i = 0 ; i < 3 ; i++){
		tmp[i] = a[i];
		a[i] = b[i];
		b[i] = tmp[i];
	}
	
}
