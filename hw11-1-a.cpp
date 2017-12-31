#include<iostream>
#include<cmath>
using namespace std;

struct Point{
	int x;
	int y;
	bool isSmallerThan(Point p);
};
bool Point::isSmallerThan(Point p){
	if(x < p.x){
		return true;
	}else if(x == p.x && y < p.y){
		return true;
	}else{
		return false;
	}
}

int main(){
	Point a = {3,4};
	Point b = {3,5};
	cout << a.isSmallerThan(b);
	return 0;
}
