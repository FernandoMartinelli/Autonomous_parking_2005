//cenario.cpp
#include <time.h> 

#include <iostream>
#include <stdlib.h>
#include "cenario.h"

#define VERMELHO 1
#define AZUL 2
#define AZULCLARO 3
#define VERDE 4
#define BRANCO 5
#define AMARELO 6

using namespace std;

Cenario::Cenario(Carro carro)
{
   Introducao();    

   wx=1000;
   wy=1000;

   do
     {
      cout<<"Tamanho da vaga (2-35): ";
      cin >> tamVaga;
      tamVaga = 10*int(tamVaga);
     }while (!(tamVaga>20 && tamVaga<350));

   SetWindowSize(carro);   
}

void Cenario::SetWindowSize(Carro carro)
{
   wx=2*carro.tamCarro+tamVaga+3;
   wy=3*carro.largCarro;   
   
} 

void Cenario::Janela(void)
{
   glutInitWindowSize(wx,wy);
   glutInitWindowPosition(300,200);
   
   glutCreateWindow("AutoParking");
   glClearColor (0.0, 0.0, 0.0, 0.0);//Seleciona a cor de fundo para limpeza da tela
   glMatrixMode(GL_PROJECTION);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
}

void Cenario::Introducao(void)
{
   cout<<"    UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC     "<<endl;
   cout<<"     DEPARTAMENTO DE AUTOMACAO E SISTEMAS - DAS       "<<endl;
   cout<<"         ENGENHARIA DE CONTROLE E AUTOMACAO           "<<endl;
   cout<<"METODOLOGIA PARA DESENVOLVIMENTO DE SISTEMAS - DAS5312"<<endl;
   cout<<""<<endl;   
   cout<<"Desenvolvimento de um sistema automotivo de manobra automatica em balizas"<<endl;
   cout<<"                     ---> PROJETO AUTOPARKING <---                       "<<endl;
   cout<<""<<endl;
   cout<<"Alexandre Keunecke Hardt"<<endl;
   cout<<"Daniel Mayer"<<endl;
   cout<<"Fernando Cervigni Martinelli"<<endl;
   cout<<""<<endl;
   cout<<""<<endl;
}

void Cenario::AlteraTamJanela (int w, int h)
{
   // Especifica as dimensões da Viewport
   glViewport(0, 0, w, h);

   // Estabelece a janela de seleção (left, right, bottom, top)     
   gluOrtho2D(0.0f, wx, 0.0f, wy*2);
}

void Cenario::Cor (int color)
{
   if (color==0)
   {
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
   }

   if (color==1)       //vermelho
      glColor3f(1.0f, 0.0f, 0.0f);
   if (color==2)       //azul
      glColor3f(0.0f, 0.0f, 1.0f);
   if (color==3)       //azul claro
      glColor3f(0.0f, 1.0f, 1.0f);
   if (color==4)       //verde
      glColor3f(0.0f, 1.0f, 0.0f);
   if (color==5)       //branco
      glColor3f(1.0f, 1.0f, 1.0f);  
   if (color==6)       //amarela
      glColor3f(1.0f, 1.0f, 0.0f);
}

void Cenario::DesenhaCarro(int t, int l, int flagEscolhido)
{
   if (flagEscolhido)
      Cor(AZUL);
   else Cor(VERDE);

   // Desenha o carro com a origem sobre o meio do eixo de rodas traseiro
   glBegin(GL_QUADS);
      glVertex2d(-.2*t,-.5*l);
      glVertex2d(-.2*t,.5*l);
      glVertex2d(t-.2*t,.5*l);
      glVertex2d(t-.2*t,-.5*l);
   glEnd();
}
   
void Cenario::DesenhaRodasTraseiras(int t, int l)
{
   Cor(AZULCLARO);
      
   glBegin(GL_QUADS);  //direita
      glVertex2d(-.1*t,-.5*l);
      glVertex2d(-.1*t,-.36*l);
      glVertex2d(.1*t,-.36*l);
      glVertex2d(.1*t,-.5*l);
   glEnd();

   glBegin(GL_QUADS);  //esquerda
      glVertex2d(-.1*t,.5*l);
      glVertex2d(-.1*t,.36*l);
      glVertex2d(.1*t,.36*l);
      glVertex2d(.1*t,.5*l);
   glEnd();
}

void Cenario::DesenhaRodaDianteira(int t, int l)
{
   glBegin(GL_QUADS);
      glVertex2d(.1*t,-.07*l);
      glVertex2d(.1*t,.07*l);
      glVertex2d(-.1*t,.07*l);
      glVertex2d(-.1*t,-.07*l);
   glEnd();
}

void Cenario::DesenhaFaixaContinua()
{  
   Cor(BRANCO);
   glBegin(GL_QUADS);
      glVertex2d(0,0);
      glVertex2d(0,3);
      glVertex2d(1000,3);
      glVertex2d(1000,0);
   glEnd();
}

void Cenario::DesenhaFaixaPontilhada()
{
   Cor(AMARELO);
   for (int i=0; i<10; i++)
   {
   glBegin(GL_QUADS);
      glVertex2d(50*(2*i),0);
      glVertex2d(50*(2*i),5);
      glVertex2d(50*(2*i+1),5);
      glVertex2d(50*(2*i+1),0);
   glEnd();
   }
}

void Cenario::Comandos()
{
   system("CLS");
   cout<<"Comandos do teclado:"<<endl<<endl;
   cout<<"c      Exibir comandos"<<endl;
   cout<<"f      FullScreen"<<endl;
   cout<<"g      640x480"<<endl;
   cout<<"v      Verificar Possibilidade de Estacionar"<<endl;
   cout<<"e      Estacionar"<<endl;
   cout<<"p      Posicionar na pista"<<endl;
   cout<<"o      Voltar carro para a origem"<<endl;
   cout<<"1,2,3  Escolher carros para dirigir"<<endl;
   cout<<"Esc    Sair do programa"<<endl<<endl;
   cout<<"Pressione Alt+Tab"<<endl;
}
