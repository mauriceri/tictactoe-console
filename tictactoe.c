#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"



const char playerX = 'x';
const char playerO = 'o';
char current_player = 'x';

char** raster;

int status = 0;

void createRaster(){
	
	
	

	raster = (char**)malloc(3 * sizeof(char));

	int i;
	for(i =0; i<3; i++){
		raster[i] = (char*)malloc(3 * sizeof(char));

	}

	
	int j ;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			raster[i][j] = '-';
		}
	}
	
	
	//debugfunktion();
	drawRaster();
}





void input(){
	int i = 0;
	int j = 0;
	char inputcheck;


	do{

		

		printf("Spieler %c ist am Zug \n", current_player);
		printf("Zeile angeben: \n");
		scanf("%d", &i);
		printf("Spalte angeben: \n");
		scanf("%d", &j);

		

		if( i > 3 || j > 3 || i < 1 || j < 1){
			printf("\nFalsche eingabe, neu eingeben!\n");
			
		}else{
			inputcheck = raster[i-1][j-1];
		}

		if(inputcheck == 'x' || inputcheck == 'o'){
			printf("(Feld bereits belegt!) \n");

			j = 5;
		}


		
		

	}while(i > 3 || j > 3 || i < 1 || j < 1);
	
	/*
	if( i > 3 || j > 3 || i < 1 || j < 1){
		printf("Falsche eingabe, neu eingeben!\n");
		input();
	}
	*/
	
	
	updateRaster(i-1, j-1, current_player);
	
	
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

void updateRaster(int i, int j, char current){
	
	raster[i][j] = current;
	
	drawRaster();
	

}


void drawRaster(){

	printf("| %c | %c | %c | \n", raster[0][0], raster[0][1], raster[0][2]);
	printf("| %c | %c | %c | \n", raster[1][0], raster[1][1], raster[1][2]);	
	printf("| %c | %c | %c | \n", raster[2][0], raster[2][1], raster[2][2]);
}


void gameState(){

	int i;
	for(i = 0; i < 3; i++){
		if(raster[i][0] == current_player && raster[i][1] == current_player && raster[i][2] == current_player ){
			winMsg();
		}
	}

	for(i = 0; i < 3; i++){
		if(raster[0][i] == current_player && raster[1][i] == current_player && raster[2][i] == current_player ){
			winMsg();
		}
	}

	if(raster[0][0] == current_player && raster[1][1] == current_player && raster[2][2] == current_player){
		winMsg();
	}else if(raster[0][2] == current_player && raster[1][1] == current_player && raster[2][0] == current_player){
		winMsg();
	}

	

}



void debugfunktion(){

	int i ;
	int j ;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			raster[i][j] = 'x';
		}
	}


}

void winMsg(){
	printf("Spieler %c hat gewonnen yaaay \n", current_player);
	status = 0;
}


void startGame(){
	
	status = 1;

	createRaster();

	
	while(isRunning()){
		input();
		gameState();
		changePlayer();
	}
		

}

