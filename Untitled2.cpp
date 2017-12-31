#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
 
class MyString
{
    private:
        int len;
        char* str;
    public:
        MyString();
//      friend main();
        MyString(char* c);
        MyString(const MyString& c);
        ~MyString();
         
        int length();
        int find(char ch, int pos = 1);
        void assign(const char* st);
        void assign(MyString mStr);
        char* getStr();
        void print();
         
        char* name;
        void setname(char* c);
 
};
MyString::MyString(){
    len = 0;
    str = nullptr;
}
MyString::MyString(char* c){
    len = strlen(c);
    str = new char[len+1];
    strcpy(str, c);
}
MyString::MyString(const MyString& c){
    len = strlen(c.str);
    str = new char[len+1];
    strcpy(str, c.str);
//    name = c.name;
}
MyString::~MyString(){
    delete [] str;
    delete [] name;
}
int MyString::length(){
    return strlen(str);
}
int MyString::find(char ch, int pos /*= 1*/){
    char* ptr = nullptr;
    pos --;
    ptr = strchr(&str[pos],ch);
    if(ptr == nullptr){
        return 0;
    }else{
        return (ptr-str)+1;
    }
}
//void MyString::assign(const char* st){
//	int mylen = len;
//	len = strlen(st);
////	cout << len <<"*\n";
//	if(len > mylen){
//		delete [] str;
//		str = new char [len+1];
//	}
//	strcpy(str,st);
////	str[len] = '\0';
//}
//void MyString::assign(MyString mStr){
//	int mylen = len;
//	len = mStr.len;
////	cout << len <<"*\n";
//	if(len > mylen){
//		delete [] str;
//		str = new char [len+1];
//		strcpy(str,mStr.getStr());
//	}
//	else{
//		strcpy(str,mStr.getStr());
//	}
////	str[len] = '\0';
//	
//}
void MyString::assign(const char* st){
    len = strlen(st);
    delete [ ] str;
    str = new char [len+1];
    strcpy(str,st);
}
void MyString::assign(MyString mStr){
    len = strlen(mStr.getStr());
    delete [ ] str;
    str = new char [len+1];
    strcpy(str,mStr.getStr());
}
char* MyString::getStr(){
    return str;
}
void MyString::print(){
    cout << str;
}
void MyString::setname(char* c){
    len = strlen(c);
    name = new char[len+1];
    strcpy(name, c);
}
 
 
static int count = 0;
MyString do_declare(char* target);
MyString do_copy(char* target,MyString* p[],const int count);
void do_length(char* target,MyString* p[],const int count);
void do_find(char* target,MyString* p[],const int count);
void do_assignString(char* target,MyString* p[],const int count);
void do_assignObject(char* target,MyString* p[],const int count);
void do_print(char* target,MyString* p[],const int count);
 
 
void split(char* target,char s[][53],char delim[]);
void split(char* target,char s2[][22],char delim[]);
 
 
int main(){
    int n = 0;
    cin >> n;
    char trash[2] = {0};
    cin.getline(trash,2);
     
    char c[101] = {0};
    MyString* p[100] = {0};
//  int count = 0;
    for(int i = 0 ; i < n ; i++){
        cin.getline(c,101);
        if(strncmp(c,"declare ",7)==0){
            p[count] = new MyString(do_declare(c));
            count ++;
        }else if(strncmp(c,"copy ",4)==0){
            p[count] = new MyString(do_copy(c,p,count));
            count++;
        }else if(strncmp(c,"length ",6)==0){
            do_length(c,p,count);
        }else if(strncmp(c,"find ",4)==0){
            do_find(c,p,count);
        }else if(strncmp(c,"assignString ",12)==0){
            do_assignString(c,p,count);
        }else if(strncmp(c,"assignObject ",12)==0){
            do_assignObject(c,p,count);
        }else if(strncmp(c,"print ",5)==0){
            do_print(c,p,count);
        }
    }
    return 0;
}
 
 
 
void do_print(char* target,MyString* p[],const int count){
    char s [2][22] = {0};
    char delim[] = " ";
    split(target,s,delim);
    for(int j = 0 ; j < count ; j++){
        if(strcmp(p[j]->name,s[1]) == 0){
            p[j]->print();
            cout << endl;
        }
    }
}
 
 
void do_assignObject(char* target,MyString* p[],const int count){
    char s [3][22] = {0};
    char delim[] = " ";
    split(target,s,delim);
//    if(strcmp(s[1],s[2])==0){
//    	
//	}else{
		for(int j = 0 ; j < count;j++){
	        if(strcmp(p[j]->name,s[1])==0){
	            for(int k = 0 ; k < count ; k++){
	                if(strcmp(p[k]->name,s[2]) == 0){
	                	char tmp[53];
	                	strcpy(tmp, p[k]->getStr());
	                    p[j]->assign(tmp);
//						(*p[j]).assign(*p[k]);
	                }
	            }
	        }
    	}
//	}
    
}
 
 
 
void do_assignString(char* target,MyString* p[],const int count){
    char s [2][53] = {0};
    char s2 [2][22] = {0};
    char delim[] = "\"";
    char delim1 []= " ";
    split(target,s,delim);
    split(s[0],s2,delim1);
     
    for(int j = 0 ; j < count ; j++){
        if(strcmp(p[j]->name,s2[1]) == 0){
            p[j]->assign(s[1]);
        }
    }
}
void do_find(char* target,MyString* p[],const int count){
    char s [4][22] = {0};
    char delim[] = " ";
    split(target,s,delim);
    for(int j = 0 ; j < count ; j++){
        if(strcmp(p[j]->name,s[1]) == 0){
            int f = 0;
            f = p[j]->find(s[2][0],atoi(s[3]));
            cout << f <<endl;
        }
    }
     
}
void do_length(char* target,MyString* p[],const int count){
    char s [2][22] = {0};
    char delim[] = " ";
    split(target,s,delim);
     
    for(int j = 0 ; j < count ; j++){
        if(strcmp(p[j]->name,s[1]) == 0){
            cout << p[j]->length() << endl;
        }
    }
     
} 
MyString do_copy(char* target,MyString* p[],const int count){
    char s [3][22] = {0};
    char delim[] = " ";
    split(target,s,delim);
     
    MyString t;
    for(int j = 0 ; j < count ; j++){
        if(strcmp(p[j]->name,s[2])==0){
            t.assign(p[j]->getStr()); 
        }
    }
    t.setname(s[1]);
    return t;
}
MyString do_declare(char* target){
    char s [2][53] = {0};
    char s2 [2][22] = {0};
    char delim[] = "\"";
    char delim1 []= " ";
    split(target,s,delim);
    split(s[0],s2,delim1);
     
    MyString t(s[1]);
    t.setname(s2[1]);
     
    return t;
}
 
 
void split(char* target,char s[][53],char delim[]){
    int wordCnt = 0;
    char* start = strtok(target, delim);
    while(start != nullptr)
    {
        strcpy(s[wordCnt], start);
        wordCnt++;
        start = strtok(nullptr, delim);
    }
}
 
 
void split(char* target,char s2[][22],char delim[]){
    int cnt = 0;
    char* start = strtok(target," ");
    while(start != nullptr)
    {
        strcpy(s2[cnt], start);
        cnt++;
        start = strtok(nullptr, " ");
    }
}

