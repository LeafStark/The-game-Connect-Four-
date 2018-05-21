#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED
#include <Windows.h>
#include <string>
#include <iostream>
#include <exception>


using namespace std;

enum color {default_color, blue, yellow, red, green, white, black, dark_blue, dark_yellow, dark_red, dark_green};

class console{
public:
console();
~console();

bool set_dimensions(unsigned int width, unsigned int height);
void set_cursor_position(unsigned int x, unsigned int y);
void set_pen_color(color c);
void clear(unsigned int x, unsigned int y);
void clear();
void put_char(char c, unsigned int x, unsigned int y);
void put_string(const string& s, unsigned int x, unsigned int y);

private:
HANDLE hScreenBuffer;
CONSOLE_SCREEN_BUFFER_INFO screenInfo;
};


class console_exception{
string info;
public:
console_exception(const string& s):info(s){}
virtual const char* what() const throw();
};



#endif // CONSOLE_H_INCLUDED
