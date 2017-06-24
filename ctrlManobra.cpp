//ctrlManobra.cpp
#include "ctrlManobra.h"

#include <math.h>
#include <iostream.h>
using namespace std;

void CtrlManobra::AndaPraFrente(Carro carro)
{
   carro.GrauVolante(0);
   carro.SetTecla(1); // diz que eh pra frente
   carro.SetPasso(1);     
   Espera(1);
}

void CtrlManobra::CurvaPraDireita(Carro carro)
{
   carro.GrauVolante(-6);
   carro.SetTecla(2);  // diz que eh pra tras    
   carro.SetPasso(-2);
   Espera(1);
}

void CtrlManobra::CurvaPraEsquerda(Carro carro)
{
   carro.GrauVolante(6);
   carro.SetTecla(2);  // diz que eh pra tras    
   carro.SetPasso(-2);
   
}

void CtrlManobra::PoeNoMeio(Carro carro)
{
   carro.GrauVolante(0);
   Espera(1);
}

void CtrlManobra::Espera ( float milisegundos )
{
  clock_t endwait;
  endwait = clock () + static_cast<clock_t> (milisegundos * CLK_TCK / 1000) ;
  while (clock() < endwait) {}
}     
