//simManobra.h

#ifndef SIMMANOBRA_H
#define SIMMANOBRA_H

class SimManobra
{
   private:
      //Por enquanto, depois serao outros objetos carros
      float carrovermelho1[4][2];
      float carrovermelho2[4][2];
      float quadradoMeioFio[4][2];
      int distanciaMeioFio;
      
   public:
      int colisao;
      int tecla;
      int penultimaTecla;
      int escolhido;           //Carro escolhido para andar (1,2,3)
      int penultimoEscolhido;            //Penultimo arro escolhido para andar (1,2,3)
      friend class Carro;

      SimManobra();     

      int VerificaPossibilidadeDeManobra(float tamanhoVaga);

      float CalculaDistancia (float *vet1, float *vet2);

      float ObtemAngulo (float *vet1, float *vet2, float *vet3);

      int VerificaPol(float * vet1, float * pto1, float * pto2, float * pto3, float * pto4);

      int VerificaColisaoGlobal(float pol1[][2], float pol2[][2], float pol3[][2], float pol4[][2]) ;
      
      int VerificaColisao(Carro carro, Carro carroA, Carro carroB);
};
#endif //SIMMANOBRA_H
