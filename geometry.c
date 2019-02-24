#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {

  //Inicializando Variáveis
  double m = (a.x - b.x) / (a.y - b.y);        // Coeficiente angular da reta ab
  double pontoXReta = ((a.y - p.y) / m) - a.x; //Achando o valor de X que cruza com a reta na altura p.y
  if (p.y < a.y && p.y > b.y || p.y > a.y && p.y < b.y) {

    if (abs(pontoXReta - p.x) < 0.000001) {
      return 2;

    } else if (p.x < pontoXReta) {
      return 1;
    }
  }
  return 0;
}

int inside(point p, point poly[], int n) {
  return 0;
}
