#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstring>
using namespace std ;


// ---------2018/1/2---------
const int NAME_LEN = 21; //���W�r������
char name[] = "NO_NAME"; // default name
const int Leaderboard_num = 4; //�Ʀ�]�W���H��
int score = 0; // default score
void gameover();//�����C��
void Leaderboard(char c[][NAME_LEN],int s[]); // �s�@�Ʀ�]
void Clr();//�M������
void first_page();//�Ĥ@��
// -----------------------------
const int N = 23;

struct Point {
    int x,y;
    void set(int X, int Y) {x=X; y=Y;}
};

HANDLE hIn, hOut;                           //I/O ���
Point  body[32], cookie, v = {-2,0};        //���, ����, ���ʦV�q,
char   room[N][N*2+4];                      //�ж�
int    delay_time = 100;                    //����ɶ�
int    x1=2,y1=1,x2=(N-1)*2,y2=N-1, len=2;  //�ж����, ����
bool   bExit = false;                       //�O�_����C��

void gotoxy (int x, int y)
{
    static COORD c;  
    c.X = x; c.Y = y;
    SetConsoleCursorPosition (hOut, c);
}

void draw (int x, int y, char* s)
{
    gotoxy (x,y);
    cout << s;
}
void draw (int x, int y, int s)
{
    gotoxy (x,y);
    cout << s;
}
void drawList (char* a, char* b, char* c, int w, int h=1)
{
    static char* p = room[0];
    for (int i; h--; *p++=*c, *p++=c[1], *p++=0, p++)
        for (*p++='\n', *p++=*a, *p++=a[1], *p++=a[2],
            i=w-2; i--;) *p++=*b, *p++=b[1];  
}
void put_cookie ()
{
    cookie.x = 3 + rand()%(N-2) * 2;
    cookie.y = 2 + rand()%(N-3);
   
}



void key_control()
{
    static DWORD count;
    static INPUT_RECORD ir;
        
    ReadConsoleInput (hIn, &ir, 1, &count);
    if (!ir.Event.KeyEvent.bKeyDown) return;           
    switch (ir.Event.KeyEvent.wVirtualKeyCode) {                    
        case VK_UP   : if (v.y !=  1) v.set(0,-1); break;
        case VK_DOWN : if (v.y != -1) v.set(0, 1); break;
        case VK_LEFT : if (v.x !=  2) v.set(-2,0); break;                        
        case VK_RIGHT: if (v.x != -2) v.set( 2,0); break;
        case VK_ESCAPE: bExit = true;
    }        
}

void move_snack()
{   
    int i;
    int& x = body[0].x;
    int& y = body[0].y;
    for (i=1; i<len; i++)                   //�ˬd�ۨ��I��
        if (body[0].x == body[i].x &&
            body[0].y == body[i].y ) break;

    if (i!=len || x<=x1 || x>x2 || y<=y1 || y>y2) {
        gameover();//2018/1/2--------------------------------------
		return;
    }
    if (x == cookie.x && y == cookie.y) {   //�Y�쭹��
        delay_time -= 2;
        if (++len > 30) {
            draw (16,10, "Y o u    W i n");
            getch(); 
			bExit = true;
            return;
        }put_cookie();
    }
    else draw (body[len-1].x, body[len-1].y, "  ");
    for (i=len-1; i>0; --i)
        body[i] = body[i-1];
    x += v.x;
    y += v.y;
    for (i=0; i<len; ++i)
        draw (body[i].x, body[i].y, "�i");
}


void Clr()//�M������ 
{
        COORD coordScreen = { 0, 0 }; 
        DWORD cCharsWritten; 
        CONSOLE_SCREEN_BUFFER_INFO csbi; 
        DWORD dwConSize; 
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
        FillConsoleOutputCharacter(hConsole, TEXT(' '),
                dwConSize, 
                coordScreen,
                &cCharsWritten); 
        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        FillConsoleOutputAttribute(hConsole,
                csbi.wAttributes,
                dwConSize,
                coordScreen,
                &cCharsWritten); 
        SetConsoleCursorPosition(hConsole, coordScreen); 

}
void init()
{
    srand (time(0));
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    if (hIn == err || hOut == err) {
        puts ("handle failed");
        getch ();
        exit (1);
    }
    drawList (" �z","�w","�{", N);   
    drawList (" �x","  ","�x", N, N-2);
    drawList (" �|","�w","�}", N);

    gotoxy (0,0);
    for (int i=0; i<N; i++) cout << room[i];
    put_cookie ();
   
    body[0].set ((x2-x1)/2, (y2-y1)/2);
    body[1].set (body[0].x+1, body[0].y);
}

void Leaderboard(char c[][NAME_LEN],int s[]){
	FILE *fin,*fout;
    //Ū�� 
	fin = fopen("score.txt", "r");
    if (!fin) {
        printf("T_T\n");
        return ;
    }
    fscanf(fin, "%s%d%s%d%s%d%s%d",c[0],&s[0],c[1],&s[1],c[2],&s[2],c[3],&s[3]);
 
	fclose(fin);
	int temp[Leaderboard_num] = {0};
	char tmp[Leaderboard_num][NAME_LEN] = {0};
	for(int i = 0 ; i < Leaderboard_num ; i++){
		temp[i] = s[i];
		strcpy(tmp[i],c[i]);
	}
	for(int i = 0 ; i < Leaderboard_num ; i++){
		if( score >= s[i]){
			s[i] = score;
			strcpy(c[i],name);
			for(int j = i+1 ; j < Leaderboard_num ; j++){
				s[j] = temp[j-1];
				strcpy(c[j],tmp[j-1]);
			}
			break;
		}
		
	}
	//�g�� 
	fout = fopen("score.txt","w");
	fprintf(fout,"%s %d\n%s %d\n%s %d\n%s %d\n",c[0],s[0],c[1],s[1],c[2],s[2],c[3],s[3]);
	fclose(fout);
	fin = fopen("score.txt", "r");
    if (!fin) {
        printf("T_T\n");
        return ;
    }
    fscanf(fin, "%s%d%s%d%s%d%s%d",c[0],&s[0],c[1],&s[1],c[2],&s[2],c[3],&s[3]);    
	fclose(fin);
}

void gameover(){//�����C������ 
	char c[Leaderboard_num][NAME_LEN] = {0};
    int s[Leaderboard_num];
	Clr();
	Leaderboard(c,s);
	draw (14,7,"G a m e    O v e r");
	draw (14,10,"Score:");
    cout << score;
    draw (14,12,"LEADER BOARD");
    for(int i = 0 ; i < Leaderboard_num ; i++){
		draw (14,14+i*2,c[i]);
		draw (20,14+i*2,s[i]);	
	}
	getch(); 
	bExit = true;
}
void first_page(){//�Ĥ@�� 
	srand (time(0));
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    if (hIn == err || hOut == err) {
        puts ("handle failed");
        getch ();
        exit (1);
    }
	gotoxy (0,0);
	draw (14,10,"Snake");
	draw (14,20,"Enter your name:");
    cin.getline(name,101);
    Clr();
}


int main ()
{
	
    first_page();
    init();
    while (!bExit)
    {        
        Sleep (delay_time); if (kbhit()) key_control();//kbhit�ˬd�ϥΪ̬O�_��J�F��
        draw (cookie.x, cookie.y, "��");
        move_snack();
        Sleep (delay_time); if (kbhit()) key_control();            
        gotoxy (10,24);
    }
    return 0;
}
