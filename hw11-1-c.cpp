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

struct Triangle{
	Point p1;
	Point p2;
	Point p3;
	void addPoint(Point p);

};
void Triangle::addPoint(Point p){
	bool flag = 0;
	if(p.isSmallerThan(p1)){
		flag = 1;
	}else if(p.isSmallerThan(p2)){
		flag = 1;
	}else if(p.isSmallerThan(p3)){
		flag =1;
	}
	if(flag){
		if(p1.isSmallerThan(p2) && p3.isSmallerThan(p2)){
			p2 = p;
		}else if(p1.isSmallerThan(p3) && p2.isSmallerThan(p3)){
			p3 = p;
		}else if(p2.isSmallerThan(p1) && p3.isSmallerThan(p1)){
			p1 = p;
			}
	}
}

int main(){
	Triangle a = {1,1,4,4,3,3};
	Point p = {2,2};
	a.addPoint(p);
	return 0;
}
