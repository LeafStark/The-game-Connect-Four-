#include <conio.h>
#include "connect4.h"
#include "info.h"

int connect4::C4Welcome(void)
{
int i=(6*Board_Vertical+2)/2-20;
int mode;
conso.set_pen_color(white);
conso.set_cursor_position(i,3);
cout << "*****************************************"<< endl;
conso.set_cursor_position(i,4);
cout << "* *" <<endl;
conso.set_cursor_position(i,5);
cout << "* *" <<endl;
conso.set_cursor_position(i,6);
cout << "* *" <<endl;
conso.set_cursor_position(i,7);
cout << "* *" <<endl;
conso.set_cursor_position(i,8);
cout << "* *" <<endl;
conso.set_cursor_position(i,9);
cout << "* *" <<endl;
conso.set_cursor_position(i,10);
cout << "* *" <<endl;
conso.set_cursor_position(i,11);
cout << "* *" <<endl;
conso.set_cursor_position(i,12);
cout << "* *" <<endl;
conso.set_cursor_position(i,13);
cout << "*****************************************"<< endl;


conso.set_pen_color(red);
conso.set_cursor_position(i+1,5);
cout << " Welcome to play Connect Four " <<endl;
conso.set_pen_color(yellow);
conso.set_cursor_position(i+1,6);
cout << " 1.Player VS Computer " <<endl;
conso.set_cursor_position(i+1,7);
cout << " 2.Player VS Player " <<endl;
conso.set_cursor_position(i+1,8);
cout << " 3.Computer VS Computer " <<endl;

conso.set_pen_color(green);
conso.set_cursor_position(i+1,11);
cout << " Please Choose " <<endl;
conso.set_cursor_position((6*Board_Vertical+2)/2,13);

mode=getch();
conso.clear();

switch(mode)
{
case 49:

conso.set_pen_color(white);
conso.set_cursor_position(i,3);
cout << "*****************************************"<< endl;
conso.set_cursor_position(i,4);
cout << "* *" <<endl;
conso.set_cursor_position(i,5);
cout << "* *" <<endl;
conso.set_cursor_position(i,6);
cout << "* *" <<endl;
conso.set_cursor_position(i,7);
cout << "* *" <<endl;
conso.set_cursor_position(i,8);
cout << "* *" <<endl;
conso.set_cursor_position(i,9);
cout << "* *" <<endl;
conso.set_cursor_position(i,10);
cout << "* *" <<endl;
conso.set_cursor_position(i,11);
cout << "* *" <<endl;
conso.set_cursor_position(i,12);
cout << "* *" <<endl;
conso.set_cursor_position(i,13);
cout << "*****************************************"<< endl;
conso.set_pen_color(yellow);
conso.set_cursor_position(i+1,5);

cout << " Level of difficulty£º " <<endl;
conso.set_pen_color(white);
conso.set_cursor_position(i+1,6);
cout << " 1.Easy" <<endl;
conso.set_cursor_position(i+1,7);
cout << " 2.Normal" <<endl;
conso.set_cursor_position(i+1,8);
cout << " 3.Hard" <<endl;
conso.set_pen_color(red);
conso.set_cursor_position(i+1,9);
cout << " 4.GOD" <<endl;

conso.set_pen_color(green);
conso.set_cursor_position(i+1,11);
cout << " Please choose " <<endl;
conso.set_cursor_position((6*Board_Vertical+2)/2,13);
do{
mode=getch();
}while(mode>52||mode<49);
switch(mode)
{
case 49:
return 49;
case 50:
return 50;
case 51:
return 51;
case 52:
return 52;
}
case 50:
return 53;
case 51:
return 54;
}
}
void connect4::C4Player(int Player)
{
for(int i=0;i<15;i++)
conso.clear(20+i, 3*Board_Horizontal+3);
conso.set_cursor_position(21,3*Board_Horizontal+3);
if(Player==Player1)
{
conso.set_pen_color(red);
cout << "Red";
}
else {
conso.set_pen_color(yellow);
cout << "Yellow";
}


}
void connect4::C4Point(int who_turn,unsigned int x, unsigned int y)
{
color col;
if(who_turn==Player1)
col=red;
else if(who_turn == Player2)
col=yellow;
conso.set_pen_color(col);
conso.set_cursor_position((y-1)*6+2,(x-1)*3+1);
cout <<"¡ö¡ö" ;
conso.set_cursor_position((y-1)*6+2,(x-1)*3+2);
cout <<"¡ö¡ö" ;
}

void connect4::superprint(int n,int m,char *p){
    for(int i=0;i<n;cout << ' ',i++);
    cout.write(p,m);
    cout << endl;
}


void connect4::C4Point_delete(unsigned int x, unsigned int y){
conso.set_cursor_position((y-1)*6+2,(x-1)*3+1);
cout <<"    " ;
conso.set_cursor_position((y-1)*6+2,(x-1)*3+2);
cout <<"    " ;
}


void connect4::C4Board(int Horizontal,int Vertical)
{
conso.set_pen_color(blue);
conso.set_cursor_position(0,0);
for(int i=0;i<(Horizontal+1);i++)
for(int j=0;j<(3*Vertical+1);j++)
{
conso.set_cursor_position(j*2, i*3);
cout << "¡ö" ;
}
for(int i=0;i<(Vertical+1);i++)
for(int j=0;j<(3*Horizontal+1);j++)
{
conso.set_cursor_position(i*6, j) ;
cout << "¡ö" ;
}
conso.set_pen_color(default_color);
for(int i=1;i<(Board_Vertical+1);i++)
{
conso.set_cursor_position(6*(i-1)+4,(3*Horizontal+1));
cout << i;
}
conso.set_cursor_position(0,(3*Horizontal+2));
conso.set_pen_color(green);
for(unsigned int i=0;i<(3*Vertical+1);i++)
cout << "¡ö" ;
conso.set_pen_color(white);
cout << "Player£º" << endl;
cout << "Column£º" << endl << endl;
cout << "Your choice (";
for(int i=1;i<(Vertical+1);i++)
cout << i << " ";
cout <<")?" << endl<<endl<<endl;
cout<<"If you enter 0, you can cheat once!" <<endl;
cout<<"If you enter 666, you can withdraw once!"<<endl;
conso.set_pen_color(green);
for(unsigned int i=0;i<(3*Vertical+1);i++)
cout << "¡ö" ;
}

