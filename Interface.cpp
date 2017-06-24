#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "carro.h"
#include "cenario.h"
#include "simManobra.h"
#include "ctrlManobra.h"

Carro carro(10, 100,0,16+50); // Carro (Distancia do meio fio, Tamanho do carro, x, y)    
Cenario cenario(carro);
Carro carroA;
Carro carroB;
SimManobra simManobra;
CtrlManobra ctrlManobra;
 
//==============================================================================

void Desenha(void) 
{
   int a=65, b=200, c=-100;   
   int d=carro.GetDistanciaMeioFio();
   int l=carro.GetLargCarro();
   int t=carro.GetTamCarro();
   int v=cenario.GetTamanhoVaga();

   simManobra.tecla=0;                                //
   if (carro.GetTecla()!=0)                            //
        simManobra.tecla=carro.GetTecla();            //Para evitar o BUG da colisao repetitiva da OPENGL
   if (carroA.GetTecla()!=0)                           //
        simManobra.tecla=carroA.GetTecla();           //
   if (carroB.GetTecla()!=0)                           //
        simManobra.tecla=carroB.GetTecla();
   if ((simManobra.colisao==1) && (simManobra.penultimoEscolhido==simManobra.escolhido)&& (simManobra.penultimaTecla==simManobra.tecla));
  
   else
   {
      simManobra.colisao= 0;
      cenario.Cor(LIMPAR); 

      cenario.DesenhaFaixaContinua();
      glTranslatef(0.0f,a, 0.0f);
      cenario.DesenhaFaixaContinua();
      glTranslatef(0.0f,b, 0.0f);
      cenario.DesenhaFaixaContinua();
      glTranslatef(0.0f,c, 0.0f);
      cenario.DesenhaFaixaPontilhada();
      glTranslatef(0.0f,-(a+b+c), 0.0f); 
      carro.AtualizaPosicao(t, l, d); //desenha carro que estaciona (simManobra.escolhido 1) 

      if (simManobra.VerificaColisao(carro, carroA, carroB)==0)  //se nao bateu
      {  
         if (simManobra.escolhido==1)                     //desenha carro na cor certa
            cenario.DesenhaCarro(t, l, 1);     //azul se selecionado
         else cenario.DesenhaCarro(t, l, 0);   //verde se nao selecionado
 
         cenario.DesenhaRodasTraseiras(t, l);
         carro.GiraRodasDianteiras(t, l);
         cenario.DesenhaRodaDianteira/*Direita*/(t, l);
         carro.CopiaRodaDianteira(l);
         cenario.DesenhaRodaDianteira/*Esquerda*/(t, l);
      
         //carro.CopiaRodaDianteira(l);*
         glRotatef(-carro.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f);   
         glTranslatef(0,.86*l, 0.0f);
         glRotatef(+carro.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f);
 
         //carro.GiraRodasDianteiras(t, l);*
         glRotatef(-carro.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f); 
         glTranslatef(-.6*t,-.43*l, 0.0f);

         glRotatef(-carro.rotaciona, 0.0f, 0.0f, 1.0f);
         glTranslatef(-carro.transladax,-carro.transladay, 0.0f); 

         carro.SetTecla(0); 
      }
      else if(carro.GetTecla()==1)  //se colidiu e tava indo pra frente
      {  
         simManobra.colisao=1;              //flag que diz que colidiu
         carro.ColidiuFrente(t,l,d); //faz voltar 
         carro.SetTecla(0);      
      }
      else if(carro.GetTecla()==2)  //se colidiu e tava indo pra tras
      {
         simManobra.colisao=1;       //flag que diz que colidiu
         carro.ColidiuTras(t,l,d);  //faz voltar
         carro.SetTecla(0);
      } 
   
      //Desenha o segundo carro (carroA) simManobra.escolhido 2

      carroA.AtualizaPosicao(t, l, d);   

      if (simManobra.VerificaColisao(carro,carroA,carroB)==0&&!simManobra.colisao) //se nao bateu
      {        
         if (simManobra.escolhido==2)          //desenha carro na cor certa
            cenario.DesenhaCarro(t, l, 1);   //azul se eh o selecionado
         else cenario.DesenhaCarro(t, l, 0);  //verde se nao eh o selecionado      

         cenario.DesenhaRodasTraseiras(t, l);
         carroA.GiraRodasDianteiras(t, l);
         cenario.DesenhaRodaDianteira/*Direita*/(t, l);
         carroA.CopiaRodaDianteira(l);
         cenario.DesenhaRodaDianteira/*Esquerda*/(t, l);
         
         //carro.CopiaRodaDianteira(l);*
         glRotatef(-carroA.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f);   
         glTranslatef(0,.86*l, 0.0f);
         glRotatef(+carroA.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f);
 
         //carro.GiraRodasDianteiras(t, l);*
         glRotatef(-carroA.GetAnguloVolante()*15, 0.0f, 0.0f, 1.0f); 
         glTranslatef(-.6*t,-.43*l, 0.0f);

         glRotatef(-carroA.rotaciona, 0.0f, 0.0f, 1.0f);
         glTranslatef(-carroA.transladax,-carroA.transladay, 0.0f); 

         carro.SetTecla(0); 
         carroA.SetTecla(0);
      }
      else if(carroA.GetTecla()==1) //se colidiu e tava indo pra frente
      {  
         simManobra.colisao=1;    //flag que diz que colidiu
         carroA.ColidiuFrente(t,l,d);   //faz voltar
         carroA.SetTecla(0); 
      }
      else if(carroA.GetTecla()==2)   //se colidiu e tava indo pra tras
      {  
         simManobra.colisao=1;       //flag que diz que colidiu
         carroA.ColidiuTras(t,l,d);
         carroA.SetTecla(0); 
      } 

      //Desenha o terceiro carro (carroB) simManobra.escolhido 3

      carroB.AtualizaPosicao(t, l, d);   

      if (simManobra.VerificaColisao(carro,carroA,carroB)==0&&!simManobra.colisao) //se nao colidiu
      {            
         if (simManobra.escolhido==3)       //desenha carro na cor certa
            cenario.DesenhaCarro(t, l, 1);  //azul se é o selecionado
         else cenario.DesenhaCarro(t, l, 0);    //verde se nao eh o selecionado
        
         cenario.DesenhaRodasTraseiras(t, l);
         carroB.GiraRodasDianteiras(t, l);
         cenario.DesenhaRodaDianteira/*Direita*/(t, l);
         carroB.CopiaRodaDianteira(l);
         cenario.DesenhaRodaDianteira/*Esquerda*/(t, l);
         carro.SetTecla(0); 
         carroA.SetTecla(0);
         carroB.SetTecla(0);
      }
      else if(carroB.GetTecla()==1) //se colidiu e tava indo pra frente
      {  
         simManobra.colisao=1;       //flag que indica colisao
         carroB.ColidiuFrente(t,l,d); 
         carroB.SetTecla(0);        
      }
      else if(carroB.GetTecla()==2) //se colidiu e tava indo pra tras
      {  
         simManobra.colisao=1; //flag que indica colisao
         carroB.ColidiuTras(t,l,d);  
         carroB.SetTecla(0);      
      }
      if (!simManobra.colisao)  //se nao bateu, desenha os carros
         glFlush();// Executa os comandos OpenGL
   }
   simManobra.penultimoEscolhido=simManobra.escolhido;
   simManobra.penultimaTecla=simManobra.tecla;
}

                     
//=================================================================

void Posiciona()
{
   float d = 18;         //deslocamento para consertar para angulo zero

   if (carro.rotaciona !=0 || carro.transladay !=carro.GetDistanciaMeioFio()+1.5*carro.GetLargCarro()+.16*carro.GetTamCarro()) // Pronto para estacionar, pra pular toda a posiciona
   {

   //Gira até 45graus em tres casos
   //caso 1  frente esquerda
   if ((int(carro.rotaciona)+36000)%360<45)
   {  
      float p=((45-((int(carro.rotaciona)+36000)%360))/1.8);
      for(int i=0; i<p; i++)
      {  
         
         carro.GrauVolante(6);
         carro.SetTecla(1);  // diz que eh pra frente    
         carro.SetPasso(2);  // diz que eh pra frente   
         //carro.rotaciona = carro.rotaciona + carro.GetAnguloVolante();  // frente => +;      
         ctrlManobra.Espera(1);
         Desenha();
      }
      carro.SetRotaciona(45);
   }
   //caso 2          
   if ((int(carro.rotaciona)+36000)%360>180)
   {  
      // re direita
      float p=(360-((int(carro.rotaciona)+36000)%360))/1.8;
      for(int i=0; i<p; i++)
      {  
         carro.GrauVolante(-6);
         carro.SetTecla(2); // diz que eh pra tras
         carro.SetPasso(-2); // diz que eh pra tras
         //carro.rotaciona = carro.rotaciona - carro.GetAnguloVolante(); 
         ctrlManobra.Espera(1);
         Desenha();
      }
      carro.SetRotaciona(0);
      // frente esquerda 
      for(int i=0; i<25; i++)  // Gira até 45 graus
      { 
         carro.GrauVolante(6);
         carro.SetTecla(1); // diz que eh pra frente
         carro.SetPasso(2); // diz que eh pra frente
         //carro.rotaciona = carro.rotaciona + carro.GetAnguloVolante();   
         ctrlManobra.Espera(1);
         Desenha();
      }
   }
   //caso 3
   if ((int(carro.rotaciona)+36000)%360!=45)
   {  
      // frente direita
     float p=((((int(carro.rotaciona)+36000)%360)-45)/1.8);
      for(int i=0; i<p; i++)
      {  
         carro.GrauVolante(-6);
         carro.SetTecla(1); // diz que eh pra frente
         carro.SetPasso(2);
         //carro.rotaciona = carro.rotaciona + carro.GetAnguloVolante();     
         ctrlManobra.Espera(1);
         Desenha();
      }
   }
   
  // posiciona ate a distancia d da linha ideal
   float p=((carro.transladay-(carro.GetDistanciaMeioFio()+1.5*carro.GetLargCarro()+.16*carro.GetTamCarro())-d)*sqrt(2)/2);
   for(int i=0; i<fabs(p); i++)
   {  
      carro.GrauVolante(0);
      carro.SetTecla(2);  // diz que eh pra tras    
      carro.SetPasso(-2*fabs(p)/p);      
      ctrlManobra.Espera(4);
      Desenha();
   }   

   // gira até angulo 0
   for(int i=0; i<25; i++)
   {
      carro.GrauVolante(6);
      carro.SetTecla(2);  // diz que eh pra tras    
      carro.SetPasso(-2);
      //carro.rotaciona = carro.rotaciona - carro.GetAnguloVolante();
      ctrlManobra.Espera(1);
      Desenha();
   }
   carro.SetRotaciona(0);
   carro.GrauVolante(0);
   } // final primeiro if
} 

void Estaciona() //soh estaciona o carro simManobra.escolhido 1
{         
   //anda pra frente
   float p=(((carro.GetTamCarro()+cenario.GetTamanhoVaga())-.3*carro.GetTamCarro()+2)-carro.transladax+.2*carro.GetTamCarro());
   for(int i=0; i<p; i++)
   {  

      carro.GrauVolante(0);
      carro.SetTecla(1); // diz que eh pra frente
      carro.SetPasso(1);     
      ctrlManobra.Espera(1);
      Desenha();
   }
   // curva pra direita
   for(int i=0; i<34; i++)
   {
      carro.GrauVolante(-6);
      carro.SetTecla(2);  // diz que eh pra tras    
      carro.SetPasso(-2);
      ctrlManobra.Espera(1);
      Desenha();
   }   
   // curva pra esquerda
   for(int i=0; i<34; i++)
   {
      carro.GrauVolante(6);
      carro.SetTecla(2);  // diz que eh pra tras    
      carro.SetPasso(-2);
      ctrlManobra.Espera(1);
      Desenha();                  
   }   
   // poe no meio
 
   for(int i=0; i<(fabs((1.8*carro.GetTamCarro()-cenario.GetTamanhoVaga())/2)); i++)
   {  
      carro.GrauVolante(0);
      carro.SetTecla(1); // diz que eh pra frente
      carro.SetPasso(((1.8*carro.GetTamCarro()-cenario.GetTamanhoVaga())/2)/fabs((1.8*carro.GetTamCarro()-cenario.GetTamanhoVaga())/2));     
      ctrlManobra.Espera(1);
      Desenha();
   }
}

//===========================================================================

void Arrow_keys ( int a_keys, int x, int y )  
{  
   switch (simManobra.escolhido)
   {
	case 1:
      carro.Direcao(a_keys);
      break;
   case 2:
      carroA.Direcao(a_keys);
      break;
   case 3: 
      carroB.Direcao(a_keys);
      break;
   default:
      break;
   }
}
//=================================================================

void Teclado(unsigned char key, int x, int y)  //captura comandos do teclado
{
   if (key=='1'||key=='2'||key=='3')
   {simManobra.escolhido = key-48;
      cout<<simManobra.escolhido<<endl;}
  
   switch (key)
   {
      case 'c':
         cenario.Comandos();
         break;
      case 'o':            //volta para a origem
         carro.ZerarPosicao(1,0);
         carroA.ZerarPosicao(2,0);
         carroB.ZerarPosicao(3,cenario.GetTamanhoVaga());
         break;
      case 'v':
         simManobra.VerificaPossibilidadeDeManobra(cenario.GetTamanhoVaga());         
         break;
      case 'e':           //estaciona automaticamente
      if(simManobra.VerificaPossibilidadeDeManobra(cenario.GetTamanhoVaga()))
      {
         Posiciona();
         Estaciona();
      }   
         break;
      case 'p':           //posiciona automaticamente
         Posiciona();
         break;
      case 27:
         exit(0);
         break;
      case 'f':
         glutFullScreen();
         break;
      case 'g':
         glutReshapeWindow ( 640, 480 );
         break;
      default:
         break;
   }
   glutPostRedisplay();    
}

//===========================================================================

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{  
   cenario.AlteraTamJanela(w, h);
}                                                                   
//=========================================================================

void Inicializa (void)
{  
   cenario.Comandos();
   cenario.Janela(); 
   glutReshapeFunc(AlteraTamanhoJanela);
   glutKeyboardFunc(Teclado);     //Habilita a captura dos eventos de carro.GetTecla()do
   glutSpecialFunc (Arrow_keys);
   glutDisplayFunc(Desenha);
   glutMainLoop();  //loop de execucao
                      
}
//=================================================================

// Programa Principal 
int main()
{              
   
   carroA.Inicializa(10, 100,0,0);
   carroB.Inicializa(10, 100,100+cenario.GetTamanhoVaga(),0);
   Inicializa();

   system("PAUSE");
   return 0;
}
