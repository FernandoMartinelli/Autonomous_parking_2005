//carro.cpp

#include "carro.h"
#include <iostream>
#include <stdlib.h>
 
using namespace std;

void Carro::Inicializa(int distanciaMeioFioInicial,int tamCarroInicial,int transladaxInicial,int transladayInicial)
{
   tamCarro=tamCarroInicial;
   largCarro=tamCarro/2;
   passo=2;
   anguloMaximo=2;
   anguloVolante=0;
   tecla=0;
   distanciaMeioFio=distanciaMeioFioInicial;
   transladax= 0.2*tamCarro+transladaxInicial;
   transladay= 0.5*largCarro+transladayInicial+distanciaMeioFio;

      float a = 32.015;
      float b = 83.815;
      float alpha = 0.6747;
      float beta = 0.3029; 
      vertices[0][0] = transladax+a*cos(PI/2+alpha+rotaciona*PI/180);
      vertices[1][0] = transladax+a*cos(3*PI/2-alpha+rotaciona*PI/180);
      vertices[2][0] = transladax+b*cos(2*PI-beta+rotaciona*PI/180);
      vertices[3][0] = transladax+b*cos(beta+rotaciona*PI/180);
      transladay+=passo*sin(rotaciona*PI/180);
      //Define os pontos y's dos vertices
      vertices[0][1] = transladay+a*sin(PI/2+alpha+rotaciona*PI/180);
      vertices[1][1] = transladay+a*sin(3*PI/2-alpha+rotaciona*PI/180);
      vertices[2][1] = transladay+b*sin(2*PI-beta+rotaciona*PI/180);
      vertices[3][1] = transladay+b*sin(beta+rotaciona*PI/180);
}

void Carro::GrauVolante(int nivelVolanteaux)
{  
   nivelVolante=nivelVolanteaux;
   passo=2;
   switch (nivelVolanteaux)
   {
      case 1:
         anguloVolante = .1*anguloMaximo;                          
         break;
      case 2:
         anguloVolante = .3*anguloMaximo; 
         break;
      case 3:
         anguloVolante = .4*anguloMaximo;               
         break;
      case 4:
         anguloVolante = .5*anguloMaximo;             
         break;
      case 5:                                 
         anguloVolante = .7*anguloMaximo;             
         break;
      case 6:
         anguloVolante = .9*anguloMaximo;             
         break;
      case 7:                                  //volante mais a esquerda
         anguloVolante = 1*anguloMaximo;               
         break;
      case -1:
         anguloVolante = -.1*anguloMaximo;           
         break;
      case -2:
         anguloVolante = -.3*anguloMaximo;             
         break;
      case -3:
         anguloVolante = -.4*anguloMaximo;             
         break;
      case -4:
         anguloVolante = -.5*anguloMaximo;           
         break;
      case -5:                               
         anguloVolante = -.7*anguloMaximo;            
         break;
      case -6:
         anguloVolante = -.9*anguloMaximo;             
         break;
      case -7:                                  //volante mais a direita
         anguloVolante = -1*anguloMaximo;              
         break;
      case 0:                                   //volante ao centro
         anguloVolante = 0;          
         break;
     }
}

void Carro::ZerarPosicao(int escolhido, int tamanhoVaga)
{
   float a = 32.015;
   float b = 83.815;
   float alpha = 0.6747;
   float beta = 0.3029;rotaciona = 0;
   anguloVolante=0;
   nivelVolante=0;
   switch(escolhido)
   {
      case 1:
         transladax=.2*tamCarro;// 100 = tamanho carro
         transladay=tamCarro*.16+1.5*largCarro+distanciaMeioFio; 
         vertices[0][0] = transladax+a*cos(PI/2+alpha+rotaciona*PI/180);
         vertices[1][0] = transladax+a*cos(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][0] = transladax+b*cos(2*PI-beta+rotaciona*PI/180);
         vertices[3][0] = transladax+b*cos(beta+rotaciona*PI/180);
         transladay+=passo*sin(rotaciona*PI/180);
         //Define os pontos y's dos vertices
         vertices[0][1] = transladay+a*sin(PI/2+alpha+rotaciona*PI/180);
         vertices[1][1] = transladay+a*sin(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][1] = transladay+b*sin(2*PI-beta+rotaciona*PI/180);
         vertices[3][1] = transladay+b*sin(beta+rotaciona*PI/180);
         break;
      case 2:  
         transladax=.2*tamCarro;// 100 = tamanho carro
         transladay=.5*largCarro+distanciaMeioFio; 
         vertices[0][0] = transladax+a*cos(PI/2+alpha+rotaciona*PI/180);
         vertices[1][0] = transladax+a*cos(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][0] = transladax+b*cos(2*PI-beta+rotaciona*PI/180);
         vertices[3][0] = transladax+b*cos(beta+rotaciona*PI/180);
         transladay+=passo*sin(rotaciona*PI/180);
         //Define os pontos y's dos vertices
         vertices[0][1] = transladay+a*sin(PI/2+alpha+rotaciona*PI/180);
         vertices[1][1] = transladay+a*sin(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][1] = transladay+b*sin(2*PI-beta+rotaciona*PI/180);
         vertices[3][1] = transladay+b*sin(beta+rotaciona*PI/180);
         break;
      case 3:  
         transladax=.2*tamCarro+100+tamanhoVaga;// 100 = tamanho carro
         transladay=.5*largCarro+distanciaMeioFio;

         vertices[0][0] = transladax+a*cos(PI/2+alpha+rotaciona*PI/180);
         vertices[1][0] = transladax+a*cos(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][0] = transladax+b*cos(2*PI-beta+rotaciona*PI/180);
         vertices[3][0] = transladax+b*cos(beta+rotaciona*PI/180);
         transladay+=passo*sin(rotaciona*PI/180);
         //Define os pontos y's dos vertices
         vertices[0][1] = transladay+a*sin(PI/2+alpha+rotaciona*PI/180);
         vertices[1][1] = transladay+a*sin(3*PI/2-alpha+rotaciona*PI/180);
         vertices[2][1] = transladay+b*sin(2*PI-beta+rotaciona*PI/180);
         vertices[3][1] = transladay+b*sin(beta+rotaciona*PI/180);
         break;
      default:
         break;
   }
   
}

void Carro::Direcao(int a_keys)
{
   switch ( a_keys ) 
	{
      case GLUT_KEY_LEFT:         // Rotaciona anti-horario
         tecla=0;
         nivelVolante++;
         if (nivelVolante>7)
            nivelVolante=7;
         GrauVolante(nivelVolante);
   	   break;
   
      case GLUT_KEY_RIGHT:     // Rotaciona horario
         tecla=0;
         nivelVolante--;
         if (nivelVolante<-7)
            nivelVolante=-7;
         GrauVolante(nivelVolante);
			break;

		case GLUT_KEY_UP:     // Desloca para a frente
         //rotaciona = rotaciona + anguloVolante;
         passo=fabs(passo);
         tecla = 1;  
		   break;

	   case GLUT_KEY_DOWN:         // Desloca pra trás
         //rotaciona = rotaciona - anguloVolante;
         passo=-fabs(passo);
         tecla = 2;
			break;
      
		default:
			break;
	}
   glutPostRedisplay();
}

void Carro::AtualizaPosicao(int t, int l, int d)
{
   glTranslatef(transladax,transladay, 0.0f);      

   if (tecla==1)
   rotaciona = rotaciona + anguloVolante;
   if (tecla==2)
   rotaciona = rotaciona - anguloVolante;

   /* Efetua a operação de rotação em Z */
   glRotatef(rotaciona, 0.0f, 0.0f, 1.0f);
   if (tecla==1||tecla==2)
   {  
      

      float a = 32.015;
      float b = 83.815;
      float alpha = 0.6747;
      float beta = 0.3029; 
      glTranslatef(passo, 0.0f, 0.0f);
      transladax+=passo*cos(rotaciona*PI/180);
      //Define os pontos x's dos vertices
      vertices[0][0] = transladax+a*cos(PI/2+alpha+rotaciona*PI/180);
      vertices[1][0] = transladax+a*cos(3*PI/2-alpha+rotaciona*PI/180);
      vertices[2][0] = transladax+b*cos(2*PI-beta+rotaciona*PI/180);
      vertices[3][0] = transladax+b*cos(beta+rotaciona*PI/180);
      transladay+=passo*sin(rotaciona*PI/180);
      //Define os pontos y's dos vertices
      vertices[0][1] = transladay+a*sin(PI/2+alpha+rotaciona*PI/180);
      vertices[1][1] = transladay+a*sin(3*PI/2-alpha+rotaciona*PI/180);
      vertices[2][1] = transladay+b*sin(2*PI-beta+rotaciona*PI/180);
      vertices[3][1] = transladay+b*sin(beta+rotaciona*PI/180);

   }
}

void Carro::GiraRodasDianteiras(int t, int l)
{
   glTranslatef(.6*t,.43*l, 0.0f);
   glRotatef(anguloVolante*15, 0.0f, 0.0f, 1.0f);  
}

void Carro::CopiaRodaDianteira(int l)
{
   glRotatef(-anguloVolante*15, 0.0f, 0.0f, 1.0f);
   glTranslatef(0,-.86*l, 0.0f);
   glRotatef(anguloVolante*15, 0.0f, 0.0f, 1.0f);
}     

void Carro::ColidiuFrente(int t, int l, int d)
{
   tecla=2;  // diz que eh pra tras    
   passo=-2;      
   AtualizaPosicao(t, l, d);
   //rotaciona = rotaciona - anguloVolante;
}

void Carro::ColidiuTras(int t, int l, int d)
{
   tecla=1;  // diz que eh pra Frente   
   passo=2;
   AtualizaPosicao(t, l, d); 
   //rotaciona = rotaciona + anguloVolante;
}


