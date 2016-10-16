#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;
bool gameOver;
const int width = 20 ;
const int height = 20;
int x, y, fruitx, fruity,score;
enum direction{
	STOP = 0,LEFT,RIGHT,UP,DOWN
};

direction dir ;

void setup()
{
	gameOver = false;
//snake init pos
	dir = STOP;
	x = width/2;
	y = height/2;
//fruit placement
	fruitx = (rand() % width) ;
	fruity = (rand() % height) ;
	score = 0;

}
void draw()
{
	system("cls");//clear screan
	for (int i = 0; i < width + 2; i++)
    	cout << "@";
    	cout << endl;// printing the upper border

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
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
    for (int i = 0; i < width +2; i++){
		cout <<'@';
	}
    cout <<endl;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch()){//this will handle the controlls
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;

		}
 	}
}
void logic()
{
	switch (dir){//this will handle the controlls
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++ ;
				break;
			case UP:
				y--;
				break;
			case DOWN:
				y++;
				break;
			}
	if (x>width || x<0 || y >height|| y<0)
		gameOver = true;

	if (x == fruitx && y == fruity)
	{
		score++;
		fruitx = rand() % width;
		fruity = rand() % height;
	}
}

int main(){
	setup();
	while (!gameOver){
		draw();
		input();
		logic();
		Sleep(60);//we can add sleep function
	}
	return 0;
}
