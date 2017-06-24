//carro.h

#include <gl/glut.h>
#include <time.h>
#define PI 3.1415926535897

#ifndef CARRO_H
#define CARRO_H
class Carro
{
   private:
      int tamCarro;    //comprimento do carro
      int largCarro;     //largura do carro
      float anguloVolante;
      float anguloMaximo;
      int nivelVolante;
      float passo;
      int tecla;
      int distanciaMeioFio;

   public:
      float  vertices[4][2];  //tentamos deixar essa matriz privada, mas não 
                           //conseguimos fazer a funçao GetVertices() funcionar
//     float ** GetVertices()      {return vertices;}
      int GetTamCarro()      {return tamCarro;} 
      int GetLargCarro()     {return largCarro;}
      Carro()
      {
      }

      Carro(int distanciaMeioFioInicial,int tamCarroInicial,int transladaxInicial,int transladayInicial)
      {
         Inicializa(distanciaMeioFioInicial, tamCarroInicial, transladaxInicial, transladayInicial);
      }
      
      void Inicializa(int distanciaMeioFioInicial,int tamCarroInicial,int transladaxInicial,int transladayInicial);

      friend class Cenario;
      friend class CtrlManobra;

      void SetPasso (float x)    {passo=x;}
      float GetPasso (void)      {return passo;}

      void GrauVolante (int);

      float GetAnguloVolante()   {return anguloVolante;}

      void ZerarPosicao(int escolhido, int tamanhoVaga);

      void Comandos(unsigned char);

      void Direcao(int);

      void SetTecla(int x)       {tecla=x;}
      int GetTecla()             {return tecla;}

      int GetDistanciaMeioFio()  {return distanciaMeioFio;}

      GLfloat transladax;
      GLfloat transladay;
      GLfloat rotaciona;   

      void SetRotaciona (float x)    {rotaciona=x;}
      float SetRotaciona (void)      {return rotaciona;}

      void AtualizaPosicao(int t, int l, int d);
      void GiraRodasDianteiras(int t, int l);
      void CopiaRodaDianteira(int l);

      void Espera(float);

      void ColidiuFrente(int t, int l, int d);
      void ColidiuTras(int t, int l, int d);

};

#endif //CARRO_H
   
