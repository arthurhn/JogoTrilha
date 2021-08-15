#ifndef MOINHO_H
#define MOINHO_H


class Moinho{
   private:
      int direcao;               // 1 - Horizontal e 2 - Vertical
      int estado;                // 1 - Cheio e 0 - Vazio
      int pos_i;                 // Primeira linha (-1 para não posicionado)
      int pos_j;                 // Primeira coluna (-1 para não posicionado)
   public:
      Moinho();                  // Construtor padrão 

      // Sets
      void setDirecao(int d);
      void setEstado(int e);
      void setPos_i(int i);
      void setPos_j(int j);
      // Gets
      int getDirecao();
      int getEstado();
      int getPos_i();
      int getPos_j(); 

      void showMoinho();
};


#endif 