#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include <cstdlib>

#define Board_Horizontal 6//棋盘的行数
#define Board_Vertical 7 //棋盘的列数
#define Board_Boundary 3 //表示棋盘边界的数值
#define Board_Empty 0 //表示棋盘空位的数值
#define Player1 1 //表示玩家1的数值
#define Player2 2 //表示玩家2的数值

#define Situation_Win 3000 //棋子连珠类型的分值（以下皆是）
#define Situation_DoubleThree 1800
#define Situation_Three 1000
#define Situation_DieThree 500
#define Situation_DiedThree 20
#define Situation_Two 20
#define Situation_DieTwo 10
#define Situation_DiedTwo 7
#define Situation_Lose -3000
#define Number 9 //总的棋子连珠类型的数量


#endif // INFO_H_INCLUDED
