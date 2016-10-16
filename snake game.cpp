#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameOver;
const int width = 20 ;
const int height = 20;
int x, y, fruitx, fruity,score;
enum direction{
	STOP = 0,LEFT,RIGHT,UP,DOWN
};

direction dir ;

void setup(){
	gameOver = false;
//snake init pos
	dir = STOP;
	x = width/2;
	y = height/2;
//fruit placement
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;

}
void draw(){
	system("cls");//clear screan
	for (int i = 0; i < width + 2; ++i)
    	cout << "@";// printing the upper border

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j == 0) //printing the left border
				cout <<"@"; 
			if (i== y && j == x)//print the init snake head
			{
				cout << "O";
			}
			else if (i == fruitx && j == fruity )//print the fruit
			{
				cout << "y";
			}

			else
				cout << " ";
			if (j == width-1)
			{
				cout <<"@";// printing the right border
			}

		}cout <<endl;
	}
    for (int i = 0; i < width +2; ++i){
		cout <<'@';
	}
    //Sleep(60);
	cout <<endl;
}
void input(){


}
void logic(){

}

int main()
{
	setup();
	while (!gameOver){
		draw();
		input();
		logic();
		//we can add sleep function
	}
	return 0;
}
