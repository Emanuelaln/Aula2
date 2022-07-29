#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define up 1
#define dow -1
#define altura 2
#define esquerda -2
#define Maximo 50
void initGrid(int x,int y);
void drawGrid();
void drawGame();
void drawFood();
void random(int&,int& );
#endif // GAME_H_INCLUDED
