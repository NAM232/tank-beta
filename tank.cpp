#include"mylib.h"
int health=0,health1=0;
void wall(){
    for(int i = 0;i != 120;i++){
        gotoXY(i,0);
        cout<<(char)219;
        gotoXY(i,28);
        cout<<(char)219;
    }
}
void walls(){
    for(int i = 0;i <5;i++){
        gotoXY(15,i);
        cout<<(char)219;
        gotoXY(90,i);
        cout<<(char)219;
    }
    for(int i = 24;i <28;i++){
        gotoXY(15,i);
        cout<<(char)219;
        gotoXY(90,i);
        cout<<(char)219;
    }
    
}
void healthb(int health,int health1){
    gotoXY(0,29);
    cout<<"Player 1:";
    color(4);
    for(int i = 0;i != health;i++) cout<<" "<<(char)219;
    color(7);
    gotoXY(100,29);
    cout<<"Player 2:";
    color(4);
    for(int i = 0;i != health1;i++) cout<<" "<<(char)219;
    color(7);
}
void setupshot(int check,int x1,int y1){
    if(check == 0){
        while (true){
            if(y1==-1){
                break;
                gotoXY(x1+1,y1);
            cout<<" ";
            }
            gotoXY(x1+1,y1);
            cout<<"|";
            gotoXY(x1+1,y1+1);
            cout<<" ";
            gotoXY(x1+1,y1-1);
            cout<<" ";
            y1--;
        }
    }
    if(check == 1){
        while (true){
            if(y1==29){
                break;
                gotoXY(x1+1,y1);
            cout<<" ";
            }
            gotoXY(x1+1,y1);
            cout<<"|";
            gotoXY(x1+1,y1+1);
            cout<<" ";
            gotoXY(x1+1,y1-1);
            cout<<" ";
            y1++;
        }
    }
    if(check == 2){
        while (true){
            if(x1==119){
                gotoXY(x1,y1+1);
                cout<<" ";
                break;
            }
            gotoXY(x1,y1+1);
            cout<<"-";
            gotoXY(x1+2,y1+1);
            cout<<" ";
            gotoXY(x1,y1+1);
            cout<<" ";
            x1++;
        }
    }
    if(check == 3){
        while (true){
            if(x1==0){
                gotoXY(x1,y1+1);
            cout<<" ";
                break;
            }
            gotoXY(x1,y1+1);
            cout<<"-";
            gotoXY(x1+2,y1+1);
            cout<<" ";
            gotoXY(x1,y1+1);
            cout<<" ";
            x1--;
        }
    }
}
void shot(int check,int x,int y,int xx,int yy,int h){
    int x1=x,y1 = y;
    setupshot(check,x,y);
    if((x==x1+1||x+1==x1+1||x+2==x1+1)&&(y==y1)) h++;
    if((x==x1+1||x+1==x1+1||x+2==x1+1)&&(y==y1+2)) h++;
    if((x==x1)&&(y==y1||y==y1+1||y==y1+2)) h++;
    if((x==x1+2)&&(y==y1||y==y1+1||y==y1+2)) h++;
}
void tank(int check,int x,int y){
    if(check == 0){
        gotoXY(x,y);
        cout<<"0^0";
        gotoXY(x,y+1);
        cout<<"0|0";
        gotoXY(x,y+2);
        cout<<"000";
    }
    if(check == 1){
        gotoXY(x,y);
        cout<<"000";
        gotoXY(x,y+1);
        cout<<"0|0";
        gotoXY(x,y+2);
        cout<<"0v0";
    }
    if(check == 2){
        gotoXY(x,y);
        cout<<"000";
        gotoXY(x,y+1);
        cout<<"0->";
        gotoXY(x,y+2);
        cout<<"000";
    }
    if(check == 3){
        gotoXY(x,y);
        cout<<"000";
        gotoXY(x,y+1);
        cout<<"<-0";
        gotoXY(x,y+2);
        cout<<"000";
    }
    gotoXY(x+3,y);
    cout<<" ";
    gotoXY(x+3,y+1);
    cout<<" ";
    gotoXY(x+3,y+2);
    cout<<" ";
    gotoXY(x-1,y);
    cout<<" ";
    gotoXY(x-1,y+1);
    cout<<" ";
    gotoXY(x-1,y+2);
    cout<<" ";
    gotoXY(x,y-1);
    cout<<" ";
    gotoXY(x+1,y-1);
    cout<<" ";
    gotoXY(x+2,y-1);
    cout<<" ";
    gotoXY(x,y+3);
    cout<<" ";
    gotoXY(x+1,y+3);
    cout<<" ";
    gotoXY(x+2,y+3);
    cout<<" ";
}
int main(){
    int x=5,y=5,check=0,check1=0,x1=80,y1=5,health=0,health1=0,shotx,shoty,shotx1,shoty1,checkl,checkk;
    nocusor();
    gotoXY(10,29);
    cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
    gotoXY(110,29);
    cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
    while(true){
        wall();
        if(kbhit()){
        char key = getch();
        if(key == 'w'&&y!=1) {
            y--; check = 0;
            }
        if(key == 's'&&y!=25) {
            y++; check = 1;
            }
        if(key == 'a'&&x!=0&&((x!=16||x!=91)&&(y!=1||y!=2||y!=3||y!=4))) {
            x--; check = 3;
            }
        if((key == 'd'&&x!=116)&&((x!=12||x!=87)&&(y!=1||y!=2))) {
            x++; check = 2;
            }
        if(key == 'e'){
            shot(check,x,y,x1,y1,health1);
            shotx = x;shoty = y;
            while(true){
                    if(check == 0) shoty--; 
                    if(check == 1) shoty++; 
                    if(check == 2) shotx++; 
                    if(check == 3) shotx--;
                    if((x1 == shotx+1||x1+1 == shotx+1||x1+2 == shotx+1)&&(y1-1==shoty||y1==shoty||y1+1==shoty)){health1++;
                    break;
                    }
                    if(shotx==119||shotx==0||shoty==29||shoty==0) break;
                }
                gotoXY(10,29);
                cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
                gotoXY(110,29);
                cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
        }
        if(key == 'i'&&y1!=1){
                y1--;
                check1=0;
            }
            if(key == 'k'&&y1!=25){
                y1++;
                check1=1;
            }
            if(key == 'l'&&x1!=116&&((x1!=14||x1!=89)&&(y1!=1||y1!=2||y1!=3||y1!=4))){
                x1++;
                check1=2;
            }
            if(key == 'j'&&x1!=0&&((x1!=16||x1!=91)&&(y1!=1||y1!=2||y1!=3||y1!=4))){
                x1--;
                check1=3;
            }
            if(key == 'o'){
                shot(check1,x1,y1,x,y,health);
                shotx1 =x1; shoty1=y1;
                while(true){
                    if(check1 == 0) shoty1--; 
                    if(check1 == 1) shoty1++; 
                    if(check1 == 2) shotx1++; 
                    if(check1 == 3) shotx1--;
                    if((x == shotx1+1||x+1 == shotx1+1||x+2 == shotx1+1)&&(y-1==shoty1||y==shoty1||y+1==shoty1)){
                        health++;
                        break;
                    }
                    if(shotx1==119||shotx1==0||shoty1==29||shoty1==0) break;
                }
                gotoXY(10,29);
                cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
                gotoXY(110,29);
                cout<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219<<" "<<(char)219;
            }
        }
        healthb(health,health1);
        tank(check,x,y);
        tank(check1,x1,y1);
        if(health==5||health1==5)break;
    }
    system("cls");
    if(health==5)cout<<"Player 2 win";
    if(health1==5)cout<<"Player 1 win";
    if(health==5&&health1==5)cout<<"TIE";
    cout<<endl;
    system("pause");    
    return 0;
}