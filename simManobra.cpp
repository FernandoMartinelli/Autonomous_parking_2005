//simManobra.cpp
#include "simManobra.h"
#include "carro.h"
#include <math.h>
#include <iostream.h>
using namespace std;

SimManobra::SimManobra()
{
   distanciaMeioFio=10;  
   colisao=0;
   tecla=0;
   escolhido=1;             //Carro escolhido para andar (1,2,3)
   penultimoEscolhido=1;             //Carro escolhido para andar (1,2,3)
   quadradoMeioFio[0][0] = -200;
   quadradoMeioFio[0][1] = -100;
   quadradoMeioFio[1][0] = -200;
   quadradoMeioFio[1][1] = 0 ;
   quadradoMeioFio[2][0] = 1000;
   quadradoMeioFio[2][1] = 0;
   quadradoMeioFio[3][0] = 1000;
   quadradoMeioFio[3][1] = -100;
               
}

int SimManobra::VerificaPossibilidadeDeManobra(float tamanhoVaga)
{
   if (!(tamanhoVaga<140)) 
   {
      cout<<"Estacionamento possivel"<<endl;
      return 1;
   }
   else 
   {
      cout<<"A vaga eh pequena demais para estacionar"<<endl;
      return 0;
   }
}

float SimManobra::CalculaDistancia (float *vet1, float *vet2)
{
   
   return sqrt((vet1[0]-vet2[0])*(vet1[0]-vet2[0]) + (vet1[1]-vet2[1])*(vet1[1]-vet2[1]));
}

float SimManobra::ObtemAngulo (float *vet1, float *vet2, float *vet3)
{
   float a=CalculaDistancia(vet2,vet3);   
   float b=CalculaDistancia(vet1,vet2);
   float c=CalculaDistancia(vet1,vet3);
   return acos ((-(a*a)+b*b+c*c)/(2*b*c));

}
//----------------------------------------------
int SimManobra::VerificaPol(float * vet1, float * pto1, float * pto2, float * pto3, float * pto4)
{
	float Delta=0.001; // Um valor pequeno para que as aproximacoes do computador nao ocasionem em resultados falsos
	float aux=ObtemAngulo(vet1,pto1,pto2) + ObtemAngulo(vet1,pto2,pto3) + ObtemAngulo(vet1,pto3,pto4) + ObtemAngulo(vet1,pto4,pto1);
   if(aux > (2*PI - Delta)) 
   	return 1;
	else
	  return 0;
}

int SimManobra::VerificaColisao(Carro carro, Carro carroA, Carro carroB)
{
   return VerificaColisaoGlobal(carro.vertices,carroA.vertices,carroB.vertices,quadradoMeioFio);   
}

int SimManobra::VerificaColisaoGlobal(float pol1[][2], float pol2[][2], float pol3[][2], float pol4[][2])
{
	for(int i=0;i<4;i++) //testa cada ponto do primeiro poligono (carro 1) em relacao aos outros poligonos (carros 2 e 3)
		{
		if (VerificaPol(pol1[i], pol2[0], pol2[1], pol2[2], pol2[3])==1)
			{cout<<"ATENCAO: Carro 1 colidiu com carro 2, esta ocorreu no vertice "<<i+1<<" do carro 1"<<endl;
         return 1;
         }
		if (VerificaPol(pol1[i], pol3[0], pol3[1], pol3[2], pol3[3])==1)
			{cout<<"ATENCAO: Carro 1 colidiu com carro 3, esta ocorreu no vertice "<<i+1<<" do carro 1"<<endl;
         return 1;
         }
		if (VerificaPol(pol1[i], pol4[0], pol4[1], pol4[2], pol4[3])==1)
			{cout<<"ATENCAO: Carro 1 colidiu com o meio fio, esta ocorreu no vertice "<<i+1<<" do carro 1"<<endl;
         return 1;
         }
		}      
     
   for(int i=0;i<4;i++) //testa cada ponto do segundo poligono (carro 2) em relacao aos outros poligonos (carros 1 e 3)
		{
		if (VerificaPol(pol2[i], pol1[0], pol1[1], pol1[2], pol1[3])==1)
			{cout<<"ATENCAO: Carro 2 colidiu com o carro 1, esta ocorreu no vertice "<<i+1<<" do carro 2"<<endl;
         return 1;
         }
		if (VerificaPol(pol2[i], pol3[0], pol3[1], pol3[2], pol3[3])==1)
			{cout<<"ATENCAO: Carro 2 colidiu com o carro 3, esta ocorreu no vertice "<<i+1<<" do carro 2"<<endl;
         return 1;
         }
		if (VerificaPol(pol2[i], pol4[0], pol4[1], pol4[2], pol4[3])==1)
			{cout<<"ATENCAO: Carro 2 colidiu com o meio fio, esta ocorreu no vertice "<<i+1<<" do carro 2"<<endl;
         return 1;
         }
		}
	for(int i=0;i<4;i++) //testa cada ponto do terceiro poligono (carro 3) em relacao aos outros poligonos (carros 1 e 2)
		{
		if (VerificaPol(pol3[i], pol2[0], pol2[1], pol2[2], pol2[3])==1)
			{cout<<"ATENCAO: Carro 3 colidiu com o carro 2, esta ocorreu no vertice "<<i+1<<" do carro 3"<<endl;
         return 1;
         }
		if (VerificaPol(pol3[i], pol1[0], pol1[1], pol1[2], pol1[3])==1)
			{cout<<"ATENCAO: Carro 3 colidiu com o carro 1, esta ocorreu no vertice "<<i+1<<" do carro 3"<<endl;
         return 1;
         } 
		if (VerificaPol(pol3[i], pol4[0], pol4[1], pol4[2], pol4[3])==1)
			{cout<<"ATENCAO: Carro 3 colidiu com o meio fio, esta ocorreu no vertice "<<i+1<<" do carro 3"<<endl;
         return 1;
         }
		}

	for(int i=0;i<4;i++)           //testa cada ponto do quarto poligono (meiofio) em relacao aos outros poligonos (carros)
		{
		if (VerificaPol(pol4[i], pol2[0], pol2[1], pol2[2], pol2[3])==1)
			return 1;
		if (VerificaPol(pol4[i], pol3[0], pol3[1], pol3[2], pol3[3])==1)
			return 1;
		if (VerificaPol(pol4[i], pol1[0], pol1[1], pol1[2], pol1[3])==1)
			return 1;
		}
	return 0;
}

