#include <iostream>
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
	for (int i = 0; i < width; ++i)
		cout <<"@";
	cout <<endl;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width + 2; ++j)
		{
			if (j == 0)
				cout <<"@";
			if (i== y && j == x)
			{
				cout << "O";
			}
			else if (i == fruitx && j == fruity )
			{
				cout << "y";
			}

			else 
				cout << " ";
			if (j == width-1)
			{
				cout <<"@";
			}
			cout <<endl;
		}
	}





	for (int i = 0; i < width; ++i)
		cout <<"@";
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