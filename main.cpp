#include<Windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include"game.h"
#define coluna 40
#define linha 40
#define tempo 8


extern short direcao;
bool fimjogo=false;
int score=0;
void time_callback(int);
void keybord_callback(int,int,int );

int index=0;

void desenhar(){
glClear(GL_COLOR_BUFFER_BIT);
drawGrid();
drawGame();
drawFood();
glutSwapBuffers();

if(fimjogo){
    MessageBox(NULL,"your score : ","FIM DO JOGO",0);
    exit(0);
}

}

// para que serve esta função.
void reshape_callbach(int w,int h){
 glViewport(0,0,(GLsizei)w,(GLsizei)h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,coluna,0.0,linha,-1.0,1.0);
 glMatrixMode(GL_MODELVIEW);

}
// Função que permite dar cor na minha tela de jogo.
void init(){
glClearColor(0.0,0.0,0.0,1.0);
initGrid(coluna,linha);
}

int main(int argc,char **argv){

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);
glutInitWindowSize(500,500);
glutInitWindowPosition(250,150);
glutCreateWindow("jogo da cobra");
glutDisplayFunc(desenhar);
glutReshapeFunc(reshape_callbach);
glutTimerFunc(0,time_callback,0);
glutSpecialFunc(keybord_callback);
init();
glutMainLoop();
return 0;
}


void time_callback(int){
glutPostRedisplay();
glutTimerFunc(1000/tempo,time_callback,0);

}

void keybord_callback(int key,int,int ){

switch(key){

case GLUT_KEY_UP:
    if(direcao!=dow)
        direcao=up;
    break;
case GLUT_KEY_DOWN:
    if(direcao!=up)
        direcao=dow;
    break;

case GLUT_KEY_RIGHT:
    if(direcao!=esquerda)
        direcao=altura;
    break;
case GLUT_KEY_LEFT:
    if(direcao!=altura)
        direcao=esquerda;
    break;
}

}
