#include<iostream>
#include<vector>
#include<conio.h>

constexpr int boxHeight = 50, boxWidth = 50;

struct Pos {
	int x, y;
};

enum Cell {
	EMPTY,
	BODY,
	HEAD,
	FRUIT
};

enum Button {
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd'
};

std::vector<Pos> snake = {};

Cell box[boxHeight][boxWidth];

Button lastKey;
void update() {
	system("cls");
	if (_kbhit()) {
		switch (_getch()) {
		case UP:
			lastKey = UP;
			break;
		case DOWN:
			lastKey = DOWN;
			break;
		case LEFT:
			lastKey = LEFT;
			break;
		case RIGHT:
			lastKey = RIGHT;
			break;
		}
	}

	Pos head = snake[0];

	switch (lastKey) {
	case UP:
		snake[0].y -= 1;
		break;
	case DOWN:
		snake[0].y += 1;
		break;
	case LEFT:
		snake[0].x += 1;
		break;
	case RIGHT:
		snake[0].y -= 1;
		break;
	}

	if (snake.size() > 1) {
		for (int i = 2; i < snake.size(); i++) {
			snake[i] = snake[i - 1];
		}
		snake[1] = head;
	}
}

void draw() {
	for (int j = 0; j < boxWidth; j++)
		std::cout << "--\n";

	for (int i = 0; i < boxHeight; i++) {
		std::cout << "|";
		for (int j = 0; j < boxWidth; j++) {
			switch (box[i][j]) {
			case HEAD:
				std::cout << "S ";
				break;
			case BODY:
				std::cout << "O ";
				break;
			case EMPTY:
				std::cout << "  ";
				break;
			case FRUIT:
				std::cout << "X ";
				break;
			}
		}
		std::cout << "|\n";
	}
	for (int j = 0; j < boxWidth; j++)
		std::cout << "--";
}

int main() {
	snake.push_back({ 5, 5 });

	while (1) {
		draw();
		update();
		_sleep(100);
	}
}

/*
lets read the errors and solve them one by one
(53,12): error C2039: 'y': is not a member of 'Pos'
(7): message : see declaration of 'Pos'
there are more amazing go ahead u still havent compiled

*/