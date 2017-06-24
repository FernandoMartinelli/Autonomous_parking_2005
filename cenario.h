//cenario.h
#define LIMPAR 0   
#include "carro.h"

#ifndef CENARIO_H
#define CENARIO_H
class Cenario
{
   private:
      int wx;           //largura da janela
      int wy;           //altura da janela
      int tamVaga;        //tamanho da vaga
  
   public:
      Cenario(Carro);

      void SetTamanhoVaga(int x)    {tamVaga=x;}
      
      int GetTamanhoVaga(void)      {return tamVaga;}
      int GetWindowX(void)             {return wx;}
      int GetWindowY(void)             {return wy;}

      void Janela();
   
      void Cor(int);
      void SetWindowSize(Carro);        //largura e altura da janela
      void AlteraTamJanela(int, int);  

 //     void DesenhaCarrosVermelhos(int d, int l , int t, int v);
      void Introducao(void);

      void DesenhaCarro(int t, int l, int flagEscolhido);

      void DesenhaRodasTraseiras(int t, int l);

      void DesenhaRodaDianteira(int t, int l);

      void DesenhaFaixaPontilhada();

      void DesenhaFaixaContinua();

      void Comandos();

};

#endif //CENARIO.H
