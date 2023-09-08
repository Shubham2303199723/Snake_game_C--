#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int height = 20;
const int width = 20;
int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;

void Setup(){
	gameover=false;
	dir =STOP;
	x=width/2;
	y=height/2;
	fruitX = rand() %width;
	fruitY = rand() %height;
}
void Draw(){
	system("CLS");
	
	for (int i=0;i<width;i++){
		cout<<"#";
	}cout<<endl;
	
	for (int i=0;i<height;i++){
		for (int j=0;j<width;j++){
		if ( j==0 || j == width-1 ){
			cout<<"#";
			}
		else if (i == y && j == x){
					cout<<"O";
			}
		else if ( i == fruitY && j == fruitX ){
			cout<<"F";
		}
		else{
			cout<<" ";
		}
		}cout<<endl;
	}
	
	for (int i=0;i<width;i++){
		cout<<"#";
	}cout<<endl;
	cout<<"You Score is "<<score<<endl;
}
void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			default:
				break;
		}
	}
}
void Logic(){
	switch(dir){
		case UP:
			y--;
		break;
		case DOWN:
			y++;
		break;
		case LEFT:
			x--;
		break;
		case RIGHT:
			x++;
		break;
		default:
		break;
	}
	if (x<0 || x>width ||y<0 || y>height){
		gameover=true;
	}
	if (x==fruitX && y==fruitY){
		score=score+10;
		fruitX = rand() %width;
		fruitY = rand() %height;
	}
}

int main(){
	Setup();
	while(!gameover){
		Draw();
		Input();
		Logic();
		Sleep(40);
		
	}
	return 0;
}
