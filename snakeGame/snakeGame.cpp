#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>

constexpr int boxHeight = 20, boxWidth = 20;

struct Pos {
	int x, y;
};

std::vector<Pos> snake = {};
Pos fruit;
int8_t snakeLength = 1;

char lastKey = 0;

void clearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}


void update() {
	clearScreen();
	if (_kbhit()) {
		switch (_getch()) {
			if (lastKey != 's') {
		case 'w':
		case 'W':
			lastKey = 'w';
			break;
			}
			if (lastKey != 'w') {
		case 's':
		case 'S':
			lastKey = 's';
			break;
			}
			if (lastKey != 'd') {
		case 'a':
		case 'A':
			lastKey = 'a';
			break;
			}
			if (lastKey != 'a') {
		case 'd':
		case 'D':
			lastKey = 'd';
			break;
			}
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
	snake.push_back({ snake[0].x, snake[0].y});

	if (snake.size() > 1) {
		for (int i = 2; i < snake.size(); i++) {
			snake[i] = snake[i - 1];
		}
		snake[1] = head;
	}

	if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
		int fruitX = rand() % 49 + 0;
		int fruitY = rand() % 49 + 0;

		fruit = { fruitX, fruitY };
		snakeLength++;
	}
}

void draw() {
	clearScreen();
	for (int j = 0; j < boxWidth; j++)
		std::cout << "||";

	for (int k = 0; k < snakeLength; k++) {
		for (int i = 0; i < boxHeight; i++) {
			std::cout << "\n||";
			for (int j = 0; j < boxWidth; j++) {
				if (snake[0].x == j && snake[0].y == i) {
					std::cout << "HH";
				}
				else if (fruit.x == j && fruit.y == i) {
					std::cout << "FF";
				}
				else if (snake[k].x == j && snake[k].y == i) {
					std::cout << "BB";
				}
				else std::cout << "  ";
			}
			std::cout << "||";
		}
	}

	std::cout << "\n";
	for (int j = 0; j < boxWidth; j++)
		std::cout << "||";
}

int main() {
	int startSnakeX = rand() % boxWidth;
	int startSnakeY = rand() % boxHeight;
	snake.push_back({ startSnakeY, startSnakeX });
	
	while (true) {
		draw();
		update();

		if (snake[0].x == boxWidth + 1 || snake[0].x == -1 || snake[0].y == boxHeight + 1 || snake[0].y == -1) {
			clearScreen();
			std::cout << "You lose\n";
			std::cout << "Your score was: " << snakeLength;
			break;
		}

		Sleep(100);
	}
}