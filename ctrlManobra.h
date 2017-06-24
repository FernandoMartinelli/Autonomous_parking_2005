//ctrlManobra.h
#include <time.h>
#include <gl/glut.h>
#include "carro.h"
#ifndef CTRLMANOBRA_H
#define CTRLMANOBRA_H

class CtrlManobra
{
   private:
       
   public:
      CtrlManobra(){ }     
      
      void AndaPraFrente(Carro);
      void CurvaPraDireita(Carro);
      void CurvaPraEsquerda(Carro);
      void PoeNoMeio(Carro);

      void Espera(float);

};
#endif //CTRLMANOBRA_H
