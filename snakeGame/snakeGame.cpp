#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include <cstdlib>

constexpr int boxHeight = 20, boxWidth = 20;

struct Pos {
	int x, y;
};

std::vector<Pos> snake = {};
int8_t snakeLength = 0;

Pos fruitPos;

char lastKey = 0;

void update() {
	system("cls");
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
		case 'W':
			lastKey = 'w';
			break;
		case 's':
		case 'S':
			lastKey = 's';
			break;
		case 'a':
		case 'A':
			lastKey = 'a';
			break;
		case 'd':
		case 'D':
			lastKey = 'd';
			break;
		}
	}

	Pos head = snake[0];

	switch (lastKey) {
	case 'w':
		snake[0].y -= 1;
		break;
	case 's':
		snake[0].y += 1;
		break;
	case 'a':
		snake[0].x -= 1;
		break;
	case 'd':
		snake[0].x += 1;
		break;
	}

	if (snake.size() > 1) {
		for (int i = 2; i < snake.size(); i++) {
			snake[i] = snake[i - 1];
		}
		snake[1] = head;
	}

	/*if (fruitEaten) {
		int fruitX = rand() % 49 + 0;
		int fruitY = rand() % 49 + 0;
		box[fruitX][fruitY] = Cell::FRUIT;

		fruitPos = { fruitX, fruitY };
		snakeLength++;
		fruitEaten = false;
	}*/

}

void draw() {
	system("CLS"); 
	for (int j = 0; j < boxWidth; j++)
		std::cout << "||";

	for (int i = 0; i < boxHeight; i++) {
		std::cout << "\n||";
		for (int j = 0; j < boxWidth; j++) {
			if (snake[0].x == j && snake[0].y == i) {
				std::cout << "HH";
			} else std::cout<<"  ";
		}
		std::cout << "||";
	}

	std::cout << "\n";
	for (int j = 0; j < boxWidth; j++)
		std::cout << "||";
}//trial and error is good enough
//sry i have to go now its getting late here
/// i know . bye
//k bye
int main() {
	int startSnakeX = rand() % boxWidth;
	int startSnakeY = rand() % boxHeight;
	snake.push_back({ startSnakeY, startSnakeX });
	
	while (1) {
		draw();
		update();
		Sleep(100);
	}
}

/*



what do u mean they are lol
this is not a matter or padding and marging like in css lol
you just count the number of || here and you see there is a lack of them

yeah but they are the length they should be tho

lol you are right in some way
so lets say there are two ways to fix it
make them longer or add empty space in the front lol
ok

i would lenghten them lol
*/