#ifndef TICTACTOE_H_
#define TICTACTOE_H_

void createPattern();
void startGame();
int isRunning();
void input();
void changePlayer();
void gameState();
void updatePattern(int i, int j, char current);
void drawPattern();
void winMsg();

#endif
