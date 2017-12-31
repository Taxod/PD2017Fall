#include<iostream>

using namespace std;
int hanoi(char from, char via , char to , int disc,int num);
int main(){
	char from = 'A';
	char via = 'B';
	char to = 'C';
	int disc;
	int num;
	cin >> disc >> num;
	hanoi(from,via ,to ,disc,num);
	
	
	return 0;
	
}



int hanoi(char from, char via , char to , int disc,int num){
	static int count = 1;
	static int flag2 = 1;	
	if(disc == 1){
//		cout << "Disc 1 From " << from << " to " << to << count<< endl ;
		if(count == num && flag2 == 1){
			cout << "Disc 1 from " << from << " to " << to /*<< count*/<< endl;
			flag2 = 0;
			return 0;
		}
		count ++;		
	}else{
		hanoi(from,to ,via,disc-1,num);
//		cout << "Disc " << disc << " From " << from <<" to "<< to << count<<endl;
		if(count == num && flag2 == 1){
			cout << "Disc " << disc << " from " << from <<" to "<< to/* << count*/<<endl;
			flag2 = 0;
			return 0;
		}
		count ++;
		hanoi(via,from,to,disc-1,num);}
}
