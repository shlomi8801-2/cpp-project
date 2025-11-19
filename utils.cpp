#ifndef utils
#define utils

#include "console.h"
using std::cout;
void DrawAt(int x,int y,char c){
    gotoxy(x,y);
    cout<<c;   
}
#endif