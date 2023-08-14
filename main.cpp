#include <iostream>
#include<conio.h>
#include<windows.h>


using namespace std;
bool game;
const int width = 30;
const int height = 20;
int x,y,fruitx,fruity,score= 1;
enum direction{ stop=0 , up , RIGHT , down , LEFT};
direction dir;
int speed = 100 ;

void setup (){
    game = false;
    dir = stop;
    x = width/2;
    y = height/2;
    fruitx = rand() % width;
    fruity = rand() % height;
}
void mapp(){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
     cout<<endl<<"Game by Aryan Khanna"<<endl<<endl;
    for(int i = 0;i<width+2;i++){
        cout<<"#";

    }
    cout<<endl;
    for(int i= 0;i<height;i++){
        for(int j = 0;j<width;j++){
            if(j ==0){
                cout<<"#";
            }
            if(i==y && j == x ){
                cout<<0;
            }

            else if(i== fruity && j == fruitx){

                cout<<"x";
            }
            else{cout<<" ";}

            if(j == width-1){
                cout<<"#";
            }

        }
        cout<<endl;

    }
     for(int i = 0;i<width+2;i++){
        cout<<"#";

    }
    cout<<endl;
    cout<<"LEVEL "<<score;
}

void input(){
    if(_kbhit()){
        switch(_getch())
        {

        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = down;
            break;
        case 'w':
            dir = up;
            break;
        case 'x':
            game = true;
            break;



        }
    }
}
void logic(){
    switch(dir){

    case LEFT:
        x--;
        break;
     case RIGHT:
        x++;
        break;
     case up:
        y--;
        break;
     case down:
        y++;
        break;
    }
    if(x==-1 ){
        x=width;
    }
    if(y==-1){
        y= height;
    }
    if(x==width +1 ){
        x=1;
    }
    if(y==height+1){
        y= 1;
    }
    if(x == fruitx && y== fruity){
        score += 1;
    fruitx = rand() % width;
    fruity = rand() % height;
    speed -=10;
    }
    if(speed == 0){
        cout<<endl<< "you won";
        game=true;
    }

}
int main()
{

    setup();
    while(!game){
        mapp();
        input();
        logic();
        _sleep(speed);

    }


}
