#include<iostream>
#include<math.h>
using namespace std;
int hanoi(char from, char via , char to , int disc,int num);

int main(){
    char from = 'A';
    char via = 'B';
    char to = 'C';
    int disc;
    int num;
    cin >> disc >> num;
    
    int middle = pow(2,disc-1);
	if(middle == num){
		cout << "Disc " << disc << " from A to C"  << endl;
	}else if(middle > num){
		hanoi(from,via ,to ,disc,num);	
	}else{
		num = num - middle;
		hanoi( to,from,via ,disc,num);
	}
    
     
     
    return 0;
     
}
 
 
 
int hanoi(char from, char via , char to , int disc,int num){
    static int count = 1;
    static int flag2 = 1;   
    if(disc == 1){
        if(flag2 == 0){
        	return 0;
		}
		if(count == num){
            cout << "Disc 1 from " << from << " to " << to << endl;
            flag2 = 0;
            return 0;
        }
        count ++;       
    }else{
        hanoi(from,to ,via,disc-1,num);
        if(flag2 == 0){
        	return 0;
		}
		if(count == num ){
            cout << "Disc " << disc << " from " << from <<" to "<< to <<endl;
            flag2 = 0;
            return 0;
        }
        count ++;
        hanoi(via,from,to,disc-1,num);}
}
