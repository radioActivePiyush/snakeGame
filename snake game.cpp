#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;
bool gameOver;
const int width = 20 ;
const int height = 20;
int x, y, fruitx, fruity,score;
int tailX[100], tailY[100];
int nTail;
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
	fruitx = rand() % width;
	fruity = rand() % height ;
	score = 0;

}
void draw()
{
	system("cls");//clear screan
	cout << x<<endl;
	cout << y<<endl;
	cout << fruitx<<endl;
	cout << fruity<<endl;

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
			else if (j == fruitx && i == fruity )//print the fruit
			{
				cout << "y";
			}

			else
			{
				bool print = false;
				for (int i = 0; i < nTail; i++)
				{
					if (tailX[i] == x && tailY[i] == y)
					{
						cout <<"o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}

			}
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
	int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
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
