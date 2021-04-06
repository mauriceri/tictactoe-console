#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"



const char playerX = 'x';
const char playerO = 'o';
char current_player = 'x';

char** pattern;

int status = 0;

void createPattern(){
	
	pattern = (char**)malloc(3 * sizeof(char));

	int i;
	for(i =0; i<3; i++){
		pattern[i] = (char*)malloc(3 * sizeof(char));

	}

	
	int j ;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			pattern[i][j] = '-';
		}
	}
	
	drawPattern();
}


void input(){
	int i = 0;
	int j = 0;
	char inputcheck;


	do{
		printf("Player %c turn\n", current_player);
		printf("Row: \n");
		scanf("%d", &i);
		printf("Column: \n");
		scanf("%d", &j);

		if( i > 3 || j > 3 || i < 1 || j < 1){
			printf("\n Wrong input! Please change input.\n");
			
		}else{
			inputcheck = pattern[i-1][j-1];
		}

		if(inputcheck == 'x' || inputcheck == 'o'){
			printf("(Field taken!) \n");

			j = 5;
		}

	}while(i > 3 || j > 3 || i < 1 || j < 1);
	
	updatePattern(i-1, j-1, current_player);
	
}


int isRunning(){

	if(status == 1){
		return 1;
	}else{
		return 0;
	}

}


void changePlayer(){
	if(current_player == 'x'){
		current_player = 'o';
	}else{
		current_player = 'x';
	}

}

void updatePattern(int i, int j, char current){
	
	pattern[i][j] = current;
	
	drawPattern();
	

}


void drawPattern(){

	printf("| %c | %c | %c | \n", pattern[0][0], pattern[0][1], pattern[0][2]);
	printf("| %c | %c | %c | \n", pattern[1][0], pattern[1][1], pattern[1][2]);	
	printf("| %c | %c | %c | \n", pattern[2][0], pattern[2][1], pattern[2][2]);
}


void gameState(){

	int i;
	for(i = 0; i < 3; i++){
		if(pattern[i][0] == current_player && pattern[i][1] == current_player && pattern[i][2] == current_player ){
			winMsg();
		}
	}

	for(i = 0; i < 3; i++){
		if(pattern[0][i] == current_player && pattern[1][i] == current_player && pattern[2][i] == current_player ){
			winMsg();
		}
	}

	if(pattern[0][0] == current_player && pattern[1][1] == current_player && pattern[2][2] == current_player){
		winMsg();
	}else if(pattern[0][2] == current_player && pattern[1][1] == current_player && pattern[2][0] == current_player){
		winMsg();
	}
}


void debugfunktion(){

	int i ;
	int j ;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			pattern[i][j] = 'x';
		}
	}
}

void winMsg(){
	printf("Player %c wins! \n", current_player);
	status = 0;
}
void startGame(){
	
	status = 1;

	createPattern();

	while(isRunning()){
		input();
		gameState();
		changePlayer();
	}
}

