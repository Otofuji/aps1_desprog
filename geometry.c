#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {

  //Inicializando Variáveis
  double m = (a.x - b.x) / (a.y - b.y);        // Coeficiente angular da reta ab
  double pontoXReta = ((a.y - p.y) / m) - a.x; //Achando o valor de X que cruza com a reta na altura p.y
  if (p.y < a.y && p.y > b.y || p.y > a.y && p.y < b.y) { //Verifica se p se encontra dentro do intervalo da reta no eixo y

    if (abs(pontoXReta - p.x) < 0.000001) {     // verifica se p está emcima da reta
      return 2;

    } else if (p.x < pontoXReta) { // verifica se a reta está a esquerda de p
      return 1;
    }
  }
  return 0; // caso a reta não se encontre a direita ou emcima de p, retorna zero
}

int inside(point p, point poly[], int n) {
  return 0;
}
