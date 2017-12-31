#include<iostream>

using namespace std;

struct Job{
	int id;
	int workload;
	int benefit;
};


void swap(int a[],int b[]);//swap people
void sort2(int icb[][3], int len);//sort people
void swap(Job& a,Job& b);//swap job
void sort(Job icbs[], int len);//sort job




int main(){
	int n , m ,k;
	Job icbs[1000] ={0}; 
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i ++){
		icbs[i].id = i;
		cin >> icbs[i].workload;
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> icbs[i].benefit;
	}  
	
	int peo[1000][3] = {0};//id time money
	for(int i = 0 ; i < m ; i ++){
		peo[i][0] = i;
	}
	int answer[1000] = {0};
	int count = 0;
	
	
	
	//sort job
	sort(icbs,n);
	
	for(int i = 0 ; i < n ; i++){	
		//sort people
		sort2(peo, m);
		bool flag = 0;
		for(int j = 0 ; j < m ; j++){ 
			if(peo[j][1] + icbs[i].workload <= k){
				answer[count] = peo[j][0]+1;
				count++;
				//refresh people record
				peo[j][1] += icbs[i].workload;
				peo[j][2] += icbs[i].benefit;
				flag = 1;
				break;
			}else{
				continue;
			}
		}
		if(flag == 0){//if no one can do the work
			answer[count] = 0;
			count ++;
		}
	}
	
	
	
	//print the answer
	for(int i = 0 ; i < n-1 ; i ++){
		cout << icbs[i].id +1<< " ";
	}
	cout << icbs[n-1].id +1 << endl;
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

void sort(Job icbs[], int len) {
	//sort by the condition
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++){
			if ((icbs[j].benefit) < (icbs[j+1].benefit)){
				swap(icbs[j], icbs[j+1]);
			}else if(icbs[j].benefit == icbs[j+1].benefit && icbs[j].workload > icbs[j+1].workload){
				swap(icbs[j], icbs[j+1]);
			}else if(icbs[j].benefit == icbs[j+1].benefit && icbs[j].workload == icbs[j+1].workload && icbs[j].id > icbs[j+1].id){
				swap(icbs[j], icbs[j+1]);
			}
		}
	}
}
void sort2(int icb[][3], int len) {
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++){
			if (icb[j][2] > icb[j+1][2]){
				swap(icb[j], icb[j+1]);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] < icb[j+1][1]){
				swap(icb[j], icb[j+1]);
			}else if(icb[j][2] == icb[j+1][2] && icb[j][1] == icb[j+1][1] && icb[j][0] > icb[j+1][0]){
				swap(icb[j], icb[j+1]);
			}
		}
	}
}

void swap(int a[],int b[]){
	int tmp[3] = {0};
	for(int i = 0 ; i < 3 ; i++){
		tmp[i] = a[i];
		a[i] = b[i];
		b[i] = tmp[i];
	}
	
}
void swap(Job& a,Job& b){
	int tmp =0;
	tmp = a.id;
	a.id = b.id;
	b.id = tmp;
	tmp = a.workload;
	a.workload = b.workload;
	b.workload = tmp;
	tmp = a.benefit ;
	a.benefit = b.benefit;
	b.benefit = tmp;	
}
