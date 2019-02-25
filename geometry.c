#include <math.h>
#include <stdio.h>

#include "geometry.h"

int verify(point p, point a, point b) {

  //Inicializando Variáveis
  double ex, ey, m1, m2, m2y, m2x;
  m2y = (a.y-b.y);
  m2x = (a.x-b.x);
  m2 = m2y/m2x;
               //Achando o valor de X que cruza com a reta na altura p.y
  if ((p.y < (a.y+0.000001) && p.y > (b.y-0.000001)) || (p.y > (a.y-0.000001) && p.y < (b.y+0.000001))) { //Verifica se p se encontra dentro do intervalo da reta no eixo y
    
  



    if ((p.y-a.y)<0.000001 || (a.y-p.y)< 0.000001 || (p.y-b.y)< 0.000001 || (b.y-p.y)<0.000001) {
      m1 = -0.1;
    }
    else {
      m1 = 0;
    }

    ex = ( ((p.y-(p.x*m1)) - (a.y-(a.x*m2)) )/(m2-m1)   );
    ey = p.y-(m1*(p.x-ex));

    if( (ey<a.y+0.000001 && ey>b.y-0.000001) || (ey>a.y-0.000001 && ey<b.y+0.000001) ){
      if(ex>p.x){
        if(ex-p.x<0.000001){
          return 2;
        }
        else{
          return 1;
        }
      }
      else if(ex<p.x){
        if(p.x-ex <0.000001){
          return 2;
        }
      }
    
    }

  }
  
  return 0; // caso a reta não se encontre a direita ou emcima de p, retorna zero
}

int inside(point p, point poly[], int n) {
  return 0;
}
