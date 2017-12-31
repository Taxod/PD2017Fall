#include<iostream>

using namespace std;
//bool Time::isEarlierThan(Time t);
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h, int m, int s);
	void print();
	bool isEarlierThan(Time t);
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::print()
{
	cout << hour << ":"<< minute << ":"<< second;
}
//bool Time::isEarlierThan(Time t);

bool Time::isEarlierThan(Time t){
	if(t.hour > hour){
		return 1;
	}else if(t.hour == hour && t.minute > minute){
		return 1;
	}else if(t.hour == hour && t.minute == minute && t.second > second){
		return 1;
	}else{
		return 0;
	}
}
int main()
{
	Time t1(14, 30, 0);
	Time t2(14, 25, 5);
	if(t2.isEarlierThan(t1))
		t2.print(); // 14:25:5
return 0;
}
