#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1,y1,x2,y2,x3,y3;
	int x,y;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	//6�Ϋŧi�ܼơA�i�H�קK�n��ܦh�� 
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
	//�i�H��bool�g false true 
	return 0;
}
