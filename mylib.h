#include<Windows.h>
#include<iostream>
#include<conio.h>
using namespace std;
void gotoXY(int x,int y){
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void nocusor(){
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}
void control(int x,int y){
    if(kbhit()){
        char key = getch();
        if(key == 'w') y--;
        if(key == 's') y++;
        if(key == 'a') x--;
        if(key == 'd') x++;
    }
}
void color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}