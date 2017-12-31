#include<iostream>

using namespace std;


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
	void printNicely();
	print12Hour(static bool iftw);
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
void Time::printNicely(){
	if(hour < 10){
		cout << "0"<<hour << ":";
	}else{
		cout << hour << ":";
	}
	if(minute < 10){
		cout << "0" << minute << ":" ;
	}else{
		cout << minute << ":";
	}
	if(second < 10){
		cout << "0" << second;
	}else{
		cout << second;
	}
}

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



Time::print12Hour(bool iftw){
	
}
int main()
{
	Time t1(14, 30, 0);
	Time t2(14, 25, 5);
	t1.printNicely(); // 14:30:00
	cout << "\n";
	Time::print12Hour(true);
	t1.printNicely(); // 02:30:00 PM
return 0;
}
