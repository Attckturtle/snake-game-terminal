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
Pos fruit;
int8_t snakeLength = 0;

char lastKey = 0;

bool fruitEaten = false;
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

	if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
		fruitEaten = true;
	}

	if (fruitEaten) {
		int fruitX = rand() % 49 + 0;
		int fruitY = rand() % 49 + 0;

		fruit = { fruitX, fruitY };
		snakeLength++;
		fruitEaten = false;
	}
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
			}
			else if (fruit.x == j && fruit.y == i) {
				std::cout << "FF";
			}
			else std::cout<<"  ";
		}
		std::cout << "||";
	}

	std::cout << "\n";
	for (int j = 0; j < boxWidth; j++)
		std::cout << "||";
}

int main() {
	int startSnakeX = rand() % boxWidth;
	int startSnakeY = rand() % boxHeight;
	snake.push_back({ startSnakeY, startSnakeX });
	
	while (1) {
		draw();
		update();
		Sleep(300);
	}
}