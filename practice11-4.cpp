#include<iostream>
#include<cstring>
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
//	print12Hour(static bool iftw);
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
class Event
{
private:
  char* name;
  Time start;
  Time end;
public:
  Event(char* n, Time s, Time t); 
  ~Event();
  void printNicely();
};
Event::Event(char* n , Time s,Time t){
//	*name = n;
	int nameLen = strlen(n);//ª`·N³o­Ó <-------------------- 
	names = new char[nameLen+1];
	strcpy(names,n);
	start = s;
	end = t;
}
Event::~Event(){
	delete [ ] names;
}
void Event::printNicely(){
	cout << *names << endl;
	cout << "Start:" << s.hour<<":"<<s.minute<<":"<<s.second << endl;
	cout << "End:" << t.hour<<":"<<t.minute<<":"<<t.second << endl;
} 
int main()
{
  char n1[] = "PD";
  Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
  e1.printNicely(); 
  
//  Event e2(e1); // copy an object
//  char n2[] = "Calculus";
//  e2.setName(n2);
//  e2.printNicely();
//  e1.printNicely(); // "Calculus" ?
                    // run-time error?
    
  return 0;
}
