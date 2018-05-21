#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "connect4.h"
#include "info.h"
#include <ctime>
#include <stdlib.h>
int** Board;
int Num[Number];
int Who_Turn = Player1;
int Level = 1;
int Max_Depth=7;
int Best_Move=0;
int temp=0;
int temp2=1;
int withdraw_x,withdraw_y;
void cheat(int a,int b);
void PrintBoard(int Horizontal,int Vertical);
int Move(int Vertical,int Player);
void UnMove(int Vertical);
void ChangePlayer(void);
void NumIinitialization(void);
void NumSet(void);
int CountScore(void);
int victory_judgment();
int Evaluate(int Player);
int AlphaBeta(int depth, int alpha, int beta);
int Random(int m, int n);//随机数程序，叶星宇专利
int** DefineBoard();


int main(int argc, char *argv[])
{
    Board=DefineBoard();
LPCTSTR str=_T("Connect Four V6.0");
connect4 connect4;
int position;
int x;
int Winner;
int mode;
int i=0;
char a[]="connect4  connect4  connect4 connect4 ";
    cout << "\n\n\n";
    connect4.superprint(39,21, "connect4    connect4 connect4  connect4 ");
    connect4.superprint(36,25,"connect4   connect4   connect4   connect4");
    connect4.superprint(34,29,"connect4 connect4 connect4");
    connect4.superprint(32,33,a);
    connect4.superprint(31,35,a);
    connect4.superprint(31,35,a);
    connect4.superprint(32,33,a);
    connect4.superprint(33,31,a);
    connect4.superprint(34,29,a);
    connect4.superprint(36,25,a);
    connect4.superprint(38,21,a);
    connect4.superprint(41,17,a);
    connect4.superprint(43,13,a);
    connect4.superprint(45,9,a);
    connect4.superprint(47,5,a);
    connect4.superprint(48,3,a);
    connect4.superprint(49,1,a);

system("pause");
connect4.set_dimensions((6*Board_Vertical+2),(3*Board_Horizontal+9)+4);
SetConsoleTitle(str);

connect4.clear();
mode=connect4.C4Welcome();
connect4.clear();
connect4.C4Board(Board_Horizontal,Board_Vertical);
if(mode==53)
{
while(1)
{
connect4.C4Player(Who_Turn);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >>position;
while(position>Board_Vertical||position<1)
{
MessageBox(NULL,_T("This column does not exist！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}
while(Board[1][position]!=Board_Empty)
{
MessageBox(NULL,_T("This column is full！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}
x=Move(position,Who_Turn);
connect4.C4Point(Who_Turn,x,position);
i=0;
while(Board[1][i+1]!=Board_Empty)
i++;
if(i>=Board_Vertical)
{
MessageBox(NULL,_T("Drawn game！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
i=0;
if((Winner=victory_judgment())!=0)
{
MessageBox(NULL,_T("Player1 wins！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
ChangePlayer();
connect4.C4Player(Who_Turn);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >>position;
while(position>Board_Vertical||position<1)
{
MessageBox(NULL,_T("This column does not exist！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}
while(Board[1][position]!=Board_Empty)
{
MessageBox(NULL,_T("This column is full！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}
x=Move(position,Who_Turn);
connect4.C4Point(Who_Turn,x,position);

i=0;
while(Board[1][i+1]!=Board_Empty)
i++;
if(i>=Board_Vertical)
{
MessageBox(NULL,_T("Drawn game！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
i=0;
if((Winner=victory_judgment())!=0)
{
if(Who_Turn==Player2)
{
MessageBox(NULL,_T("Player2 wins！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
else {
MessageBox(NULL,_T("Player1 wins！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
}
ChangePlayer();
connect4.C4Player(Who_Turn);

}
}




if(mode<53&&mode>48)
{
switch(mode)
{
case 49 :
Max_Depth=5;
break;
case 50:
Max_Depth=7;
break;
case 51:
Max_Depth=9;
break;
case 52:
 Max_Depth=10;
}

while(1)
{
connect4.C4Player(Who_Turn);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
if(position==0)
    {
        cheat(position,Best_Move);
        MessageBox(NULL,_T("You can eat the piece your opponent has just placed！"),_T("Oh"),MB_OK|MB_ICONWARNING);
    continue;

    }
    while(position==666)
{			UnMove(Best_Move);
	connect4.C4Point_delete(Move(Best_Move,Who_Turn), Best_Move);
	UnMove(Best_Move);


	ChangePlayer();
connect4.set_cursor_position(0,(3*Board_Horizontal+8));




UnMove(withdraw_y);
	connect4.C4Point_delete(Move(withdraw_y,Who_Turn), withdraw_y);
	UnMove(withdraw_y);
	MessageBox(NULL,_T("WithDraw！"),_T("Oh"),MB_OK|MB_ICONWARNING);


	ChangePlayer();
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;







}
withdraw_y=position;

while(position>Board_Vertical||(position<1&&position!=0))
{
MessageBox(NULL,_T("This column does not exist！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}
while(Board[1][position]!=Board_Empty)
{
MessageBox(NULL,_T("This column is full！"),_T("Error"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+8));
cin >> position;
}

x=Move(position,Who_Turn);
connect4.C4Point(Who_Turn,x,position);

if((Winner=victory_judgment())!=0)
{
MessageBox(NULL,_T("You win！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}

ChangePlayer();
connect4.C4Player(Who_Turn);
AlphaBeta(Max_Depth, -30000, 30000);
x=Move(Best_Move,Who_Turn);

connect4.C4Point(Who_Turn,x,Best_Move);
connect4.set_cursor_position(0,0);
while(Board[1][i+1]!=Board_Empty)
i++;
if(i>=Board_Vertical)
{
MessageBox(NULL,_T("Drawn game！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
i=0;
if((Winner=victory_judgment())!=0)
{
MessageBox(NULL,_T("Sorry，computer wins"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
ChangePlayer();
connect4.C4Player(Who_Turn);
}
}
if(mode==54)
{
while(1)
{_sleep(500);
connect4.C4Player(Who_Turn);

AlphaBeta(Max_Depth, -30000, 30000);
if(temp==0)
{
    srand(unsigned(time(0)));
Best_Move=Random(1,7);
temp+=1;
}
x=Move(Best_Move,Who_Turn);
connect4.C4Point(Who_Turn,x,Best_Move);
i=0;
while(Board[1][i+1]!=Board_Empty)
i++;
if(i>=Board_Vertical)
{
MessageBox(NULL,_T("Drawn game！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
i=0;
if((Winner=victory_judgment())!=0)
{if(temp2%2!=0)
MessageBox(NULL,_T("Player1 wins！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
else
MessageBox(NULL,_T("Player2 wins！"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}
ChangePlayer();
temp2++;
}
}
connect4.set_cursor_position(0,(3*Board_Horizontal+11));
return EXIT_SUCCESS;
}

int** DefineBoard()

{int i;
    int**a=new int*[Board_Horizontal+2];
    for(i=0;i<(Board_Horizontal+2);i++)
        a[i]=new int[Board_Vertical+2];
        for(int i=0;i<(Board_Vertical+2);i++)
{
a[0][i] = Board_Boundary;
a[Board_Horizontal+1][i] = Board_Boundary;
}
for( i=0;i< (Board_Horizontal+2);i++)
{
a[i][0] = Board_Boundary;
a[i][Board_Vertical+1] = Board_Boundary;
}
for( i=1;i<(Board_Horizontal+1);i++)
for(int j=1;j<(Board_Vertical+1);j++)
a[i][j] = Board_Empty;
    return a;
}


void PrintBoard(int Horizontal,int Vertical)
//显示棋盘的函数的具体实现,经调试确认无误
{
for(int i=0;i<(Horizontal+2);i++)
{
for(int j=0;j< (Vertical+2);j++)
cout << Board[i][j] << " ";
cout << endl;
}
}

int Move(int Vertical,int Player)
//落子函数的具体实现,经调试确认无误
{
int i=1;
while(Board[i][Vertical]==Board_Empty)
i++;
Board[i-1][Vertical] = Player;
return i-1;
}

void UnMove(int Vertical)
//撤销落子函数的具体实现,经调试确认无误
{
int i=1;
while(Board[i][Vertical]==0)
i++;
Board[i][Vertical] = Board_Empty;
}
void ChangePlayer(void)
//变换玩家函数的具体实现,经调试确认无误
{
if(Who_Turn == Player1)
Who_Turn = Player2;
else Who_Turn = Player1;
}
void NumIinitialization(void)
//初始化连珠类型数量统计的函数,将数组置零,经调试确认无误
{
for(int i=0;i<Number;i++)
Num[i] = 0;
}
void NumSet(void)
//将计算棋子连珠数量的数组进行调整的函数具体实现
{
Num[0] = Num[0]/4;
Num[2] = Num[2]/3;
Num[3] = Num[3]/3;
Num[4] = Num[4]/3;
Num[5] = Num[5]/2;
Num[6] = Num[6]/2;
Num[7] = Num[7]/2;
while(Num[2]>1)
{
Num[2]-=2;
Num[1]+=1;
}
}
int CountScore(void)
//计算分数的函数
{
int Score = 0;
//连珠类型的数量乘以其分数
Score+=(Num[0]*Situation_Win);
Score+=(Num[1]*Situation_DoubleThree);
Score+=(Num[2]*Situation_Three);
Score+=(Num[3]*Situation_DieThree);
Score+=(Num[4]*Situation_DiedThree);
Score+=(Num[5]*Situation_Two);
Score+=(Num[6]*Situation_DieTwo);
Score+=(Num[7]*Situation_DiedTwo);
Score+=(Num[8]*Situation_Lose);
return Score;
}
int AlphaBeta(int depth, int alpha, int beta)
//AlphaBeta搜索函数,递归
{
int val;
int Player;
if((Level%2)==1)
Player=Player2;
else Player=Player1;

if ((depth<= 0)||(victory_judgment()))
return Evaluate(Player);
for(int i=0;i<Board_Vertical;i++)
{
if(Board[1][i+1]!=Board_Empty)
continue;
Move(i+1,Player);
Level++;
val = -AlphaBeta(depth - 1, -beta, -alpha);
UnMove(i+1);
Level--;
if (val>=beta)
return beta;
if (val>alpha)
{
alpha = val;
if(depth==Max_Depth)
{
Best_Move = i+1;
}
}
}
return alpha;
}
int Random(int m, int n)
{
        int pos, dis;
        if(m == n)
        {
            return m;
        }
        else if(m > n)
        {
            pos = n;
            dis = m - n + 1;
            return rand() % dis + pos;
        }
        else
        {
            pos = m;
            dis = n - m + 1;
            return rand() % dis + pos;
        }
}

void cheat(int a,int b)
{
   int i=1;
while(Board[i][a]==0)
i++;
Board[i][a] = Board_Empty;
if(b!=0)
{i=1;
while(Board[i][b]==0)
i++;
Board[i][b] = Board_Empty;}
}

int Evaluate(int Player)
//打分函数
{
int Count_Left = 1;
int Count_Right = 1;

NumIinitialization();

//计算水平方向的连珠数量
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i][j-Count_Left] == Player)
Count_Left++;
while(Board[i][j+Count_Right] == Player)
Count_Right++;
if((j-Count_Left)<0||j+Count_Right+1>8)
    return CountScore();
if((Count_Left+Count_Right) == 3)
{
if((Board[i][j-Count_Left-1] != Board_Empty)&&(Board[i][j+Count_Right+1] != Board_Empty))
Num[7]++;
else if((Board[i][j-Count_Left-1] != Board_Empty)||(Board[i][j+Count_Right+1] != Board_Empty))
Num[6]++;
else Num[5]++;
}
else if((Count_Left+Count_Right) == 4)
{
if((Board[i][j-Count_Left-1] != Board_Empty)&&(Board[i][j+Count_Right+1] != Board_Empty))
Num[4]++;
else if((Board[i][j-Count_Left-1] != Board_Empty)||(Board[i][j+Count_Right+1] != Board_Empty))
Num[3]++;
else Num[2]++;
}
else if((Count_Left+Count_Right) >= 5)
Num[0]++;
Count_Left=1;
Count_Right=1;
}

//计算竖直
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j] == Player)
Count_Left++;
while(Board[i-Count_Right][j] == Player)
Count_Right++;
if((i+Count_Left+1)>7||i-Count_Right-1<0)
    return CountScore();
if((Count_Left+Count_Right) == 3)
{
if((Board[i+Count_Left+1][j] != Board_Empty)&&(Board[i-Count_Right-1][j] != Board_Empty))
Num[7]++;
else if((Board[i+Count_Left+1][j] != Board_Empty)||(Board[i-Count_Right-1][j] != Board_Empty))
Num[6]++;
else Num[5]++;
}
else if((Count_Left+Count_Right) == 4)
{
if((Board[i+Count_Left+1][j] != Board_Empty)&&(Board[i-Count_Right-1][j] != Board_Empty))
Num[4]++;
else if((Board[i+Count_Left+1][j] != Board_Empty)||(Board[i-Count_Right-1][j] != Board_Empty))
Num[3]++;
else Num[2]++;
}
else if((Count_Left+Count_Right) >= 5)
Num[0]++;
Count_Left=1;
Count_Right=1;
}

//计算右倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i-Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i+Count_Right][j+Count_Right] == Player)
Count_Right++;
if((Count_Left+Count_Right) == 3)
{
if((Board[i-Count_Left-1][j-Count_Left-1] != Board_Empty)&&(Board[i+Count_Right+1][j+Count_Right+1] != Board_Empty))
Num[7]++;
else if((Board[i-Count_Left-1][j-Count_Left-1] != Board_Empty)||(Board[i+Count_Right+1][j+Count_Right+1]!= Board_Empty))
Num[6]++;
else Num[5]++;
}
else if((Count_Left+Count_Right) == 4)
{
if((Board[i-Count_Left-1][j-Count_Left-1] != Board_Empty)&&(Board[i+Count_Right+1][j+Count_Right+1] != Board_Empty))
Num[4]++;
else if((Board[i-Count_Left-1][j-Count_Left-1] != Board_Empty)||(Board[i+Count_Right+1][j+Count_Right+1]!= Board_Empty))
Num[3]++;
else Num[2]++;
}
else if((Count_Left+Count_Right) >= 5)
Num[0]++;
Count_Left=1;
Count_Right=1;
}

//计算左倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i-Count_Right][j+Count_Right] == Player)
Count_Right++;
if((Count_Left+Count_Right) == 3)
{
if((Board[i+Count_Left+1][j-Count_Left-1] != Board_Empty)&&(Board[i-Count_Right-1][j+Count_Right+1] != Board_Empty))
Num[7]++;
else if((Board[i+Count_Left+1][j-Count_Left-1] != Board_Empty)||(Board[i-Count_Right-1][j+Count_Right+1] != Board_Empty))
Num[6]++;
else Num[5]++;
}
else if((Count_Left+Count_Right) == 4)
{
if((Board[i+Count_Left+1][j-Count_Left-1] != Board_Empty)&&(Board[i-Count_Right-1][j+Count_Right+1] != Board_Empty))
Num[4]++;
else if((Board[i+Count_Left+1][j-Count_Left-1] != Board_Empty)||(Board[i-Count_Right-1][j+Count_Right+1] != Board_Empty))
Num[3]++;
else Num[2]++;
}
else if((Count_Left+Count_Right) >= 5)
Num[0]++;
Count_Left=1;
Count_Right=1;
}




if(Player == Player2)
Player = Player1;
else Player =Player2;

for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i][j-Count_Left] == Player)
Count_Left++;
while(Board[i][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
Num[8]++;
Count_Left=1;
Count_Right=1;
}

//计算竖直
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j] == Player)
Count_Left++;
while(Board[i-Count_Right][j] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
Num[8]++;
Count_Left=1;
Count_Right=1;
}

//计算右倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i-Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i+Count_Right][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
Num[8]++;
Count_Left=1;
Count_Right=1;
}

//计算左倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i-Count_Right][j+Count_Right] == Player)
Count_Right++;
if((Count_Left+Count_Right) >= 5)
Num[8]++;
Count_Left=1;
Count_Right=1;
}
NumSet();
return CountScore();
}

int victory_judgment()
{
int Player= Player1;
int Count_Left = 1;
int Count_Right = 1;

for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i][j-Count_Left] == Player)
Count_Left++;
while(Board[i][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player1;
Count_Left=1;
Count_Right=1;
}

//计算竖直
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j] == Player)
Count_Left++;
while(Board[i-Count_Right][j] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player1;
Count_Left=1;
Count_Right=1;
}

//计算右倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i-Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i+Count_Right][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player1;
Count_Left=1;
Count_Right=1;
}

//计算左倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i-Count_Right][j+Count_Right] == Player)
Count_Right++;
if((Count_Left+Count_Right) >= 5)
return Player1;
Count_Left=1;
Count_Right=1;
}

Player = Player2;

for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i][j-Count_Left] == Player)
Count_Left++;
while(Board[i][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player2;
Count_Left=1;
Count_Right=1;
}

//计算竖直
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j<(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j] == Player)
Count_Left++;
while(Board[i-Count_Right][j] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player2;
Count_Left=1;
Count_Right=1;
}

//计算右倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i-Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i+Count_Right][j+Count_Right] == Player)
Count_Right++;

if((Count_Left+Count_Right) >= 5)
return Player2;
Count_Left=1;
Count_Right=1;
}

//计算左倾
for(int i = 1;i<(Board_Horizontal+1);i++)
for(int j = 1;j <(Board_Vertical+1);j++)
{
if(Board[i][j]!=Player)
continue;
while(Board[i+Count_Left][j-Count_Left] == Player)
Count_Left++;
while(Board[i-Count_Right][j+Count_Right] == Player)
Count_Right++;
if((Count_Left+Count_Right) >= 5)
return Player2;
Count_Left=1;
Count_Right=1;
}
return 0;
}
