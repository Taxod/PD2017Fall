#include <iostream >
using namespace std;
int main(){
	
	int num1 = 0, num2 = 0;
	//first time enter the numbers.
	cout << "Please enter two numbers , "
		 << "separated by a white space: ";
	cin >> num1 >> num2;
	while(1){
		//check if two numbers equal or which larger.
		if(num1 > num2)
			cout << "The larger one is " << num1;
		if(num1 < num2)
			cout << "The larger one is " << num2;
		if(num1 == num2){
			cout << "The two are equal";
			//two number are equal .end the program.
			return 0;
		}
		//two numbers aren't equal. enter the numbers again.
		cout << "Please enter two numbers , "
			 << "separated by a white space: ";
		cin >> num1 >> num2;		
	}
	return 0;
}
