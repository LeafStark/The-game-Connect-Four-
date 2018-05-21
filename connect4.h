#ifndef CONNECT_H_INCLUDED
#define CONNECT_H_INCLUDED
#include "console.h"


class connect4:public console
{
private:
console conso;

public:
int C4Welcome(void);
void C4Player(int Player);
void C4Point(int who_turn,unsigned int x, unsigned int y);
void C4Board(int Horizontal,int Vertical);
void C4Point_delete(unsigned int x, unsigned int y);
void superprint(int n,int m,char *p);
};


#endif // CONNECT_H_INCLUDED
