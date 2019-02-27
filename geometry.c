#include <math.h>

#include "geometry.h"


int verify(point p, point a, point b) {

  //Inicializando Variáveis
  double ex, ey, m1, m2, m2y, m2x;
  double difMinima = 0.000001;
  if ((p.y < (a.y+difMinima) && p.y > (b.y-difMinima)) || (p.y > (a.y-difMinima) && p.y < (b.y+difMinima))) {     //Verifica se p se encontra dentro do intervalo da reta no eixo y
    m2y = (a.y-b.y);                                                                                              //Achando o coeficiente angular do segmento AB   
    m2x = (a.x-b.x);
    m2 = m2y/m2x;             
 
    if ( ( (a.y-p.y)<difMinima && (a.y-p.y)>(-difMinima) ) || ((p.y-b.y) < difMinima && (p.y-b.y) > (-difMinima))) {         //Verifica se precisa aplicar uma perturbação no ray cast     
      m1 = -0.1;                                                                                                             //Coeficiente angular de ray cast perturbado
    }
    else {
      m1 = 0;
    }



    if(m2x<difMinima && m2x >(-difMinima)){                                                                 //Verifica um caso do coeficiente angular infinito, para tratar separadamente
       ex = a.x;
    }
    else{
      ex = ( ((p.y-(p.x*m1)) - (a.y-(a.x*m2)) )/(m2-m1)   );
    }
    ey = p.y-(m1*(p.x-ex));
    if( ((ey<a.y+difMinima && ey>b.y-difMinima) || (ey>a.y-difMinima && ey<b.y+difMinima)) && ((a.x-difMinima<ex&&b.x+difMinima>ex)||(a.x+difMinima>ex&&b.x-difMinima<ex)) ){                   // Verifica se o ponto de encontro das 2 retas esta dentro dos eixos xy do segmento de reta
      if(ex>p.x-difMinima){
        if(ex<difMinima+p.x&&((a.x-difMinima<ex&&b.x+difMinima>ex)||(a.x+difMinima>ex&&b.x-difMinima<ex))){
          return 2;
        }
        else{
          return 1;
        }
      }
      else if(ex<p.x+difMinima){
        if(p.x <difMinima+ex){
          return 2;
        }
      }
    
    }

  }
  return 0; // caso a reta não se encontre a direita ou emcima de p, retorna zero
}

int inside(point p, point poly[], int n) {
  int sum = 0;   //Inicializando variaveis
  int ret;
  for(int i = 0;i<n;i++){ //Rodando para todos os lados
    if(i==n-1){           //Verificar se é o lado composto pelo 1° e ultimo ponto
      ret = verify(p,poly[i],poly[0]);
    }
    else{
      ret = verify(p, poly[i], poly[i+1]);
    }
    if(ret==2){           //Verifica se está acima da linha
      return 1;
      break;
    }
    sum+=ret;             //Soma das saidas de verify
  }
  if(sum%2==0){           //Se a soma for par o ponto p está fora da imagem
    return 0;
  }
  return 1;
}
