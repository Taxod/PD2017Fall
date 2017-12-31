#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1,y1,x2,y2,x3,y3;
	int x,y;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	//6用宣告變數，可以避免要改很多次 
	for(int i = 0; i < 6 ; i++){
		for(int j = 0; j < 6 ; j++){
			if( i == x1 || i == x2 || i == x3){
				break;
			}else if(j == y1 || j == y2 || j == y3){
	
			}else if((abs(i - x1)==abs(j-y1)) || (abs(i - x2)==abs(j-y2)) || (abs(i - x3)==abs(j-y3))){
				
			}else{
				cout << i << " ";
				cout << j << endl;
			}
		}
	}
	//可以用bool寫 false true 
	return 0;
}
