#include<iostream>
#include<cmath>
using namespace std;

struct Point{
	int x;
	int y;
	double distOri();
	bool isSmallerThan(Point p);
};
double Point::distOri(){ 
	return sqrt(pow(x, 2) + pow(y, 2));
}
bool Point::isSmallerThan(Point p){
	if(x < p.x){
		return true;
	}else if(x == p.x && y < p.y){
		return true;
	}else{
		return false;
	}
}
int compare(Point p1, Point p2);
int main(){
	Point a = {3,4};
	Point b = {3,5};
	cout << a.isSmallerThan(b);
	return 0;
}
int compare(Point p1, Point p2){
	if(p1.x < p2.x){
		return -1;
	}else if(p1.x == p2.x && p1.y < p2.y){
		return -1;
	}else if(p1.x == p2.x && p1.y == p2.y){
		return 0;
	}else{
		return 1;
	}
}
