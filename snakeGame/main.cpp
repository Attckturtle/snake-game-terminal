#include<iostream>
#include<vector>

constexpr int boxHeight = 50, boxWidth = 5;

struct Pos {
	int snakeX, snakeY;
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

constexpr Pos *snake;

Cell box[boxHeight][boxWidth];
/*
do u want a fixed size or a dynamic allocation?
want to do it yourself or use std::vector?
know pointers?

lets do it like this
when the length reaches the end the length gets extended by 10 cells
you always keep trach of the length anyways
first u declare a pointer and u allocate a 10 Pos
we cant call malloc in the global scope

aight i left in the main the malloc thing
remember to 
free the memory befor lengthening and pass the old stuff to it
good luck bye
thx
bye
ok 

	chinese worksheet cause my chinese is quite bad
i have to go alr
parents want me to do some work sry
how do we do that though


after this i need to go though



*/

void update() {
	system("cls");
	switch (getch()) {
	case UP:
    
		break;
	case DOWN:

		break;
	case LEFT:

		break;
	case RIGHT:

		break;
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
				std::cout << "X";
				break;
			}
		}
		std::cout << "|\n";
	}
	for (int j = 0; j < boxWidth; j++)
		std::cout << "--";
}

int main() {

	snake = malloc(10*sizeof(Pos));




 }

/*

how do we represent the snake?
we cant just get the box and discover the snake everytime

ok













*/
