#include <math.h>

#include "geometry.h"


int verify(point p, point a, point b) {

  //Inicializando Variáveis
  double encontroX, encontroY, m1, m2, m2y, m2x;   //m sendo coeficiente angular (O segundo teve que ser quebrado em 3 partes para cuidar do caso de m2x == 0 
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
       encontroX = a.x;
    }
    else{
      encontroX = ( ((p.y-(p.x*m1)) - (a.y-(a.x*m2)) )/(m2-m1)   );
    }
    encontroY = p.y-(m1*(p.x-encontroX));
    if( ((encontroY<a.y+difMinima && encontroY>b.y-difMinima) || (encontroY>a.y-difMinima && encontroY<b.y+difMinima)) && ((a.x-difMinima<encontroX&&b.x+difMinima>encontroX)||(a.x+difMinima>encontroX&&b.x-difMinima<encontroX)) ){                   // Verifica se o ponto de encontro das 2 retas esta dentro dos eixos xy do segmento de reta
      if(encontroX>p.x-difMinima){
        if(encontroX<difMinima+p.x&&((a.x-difMinima<encontroX&&b.x+difMinima>encontroX)||(a.x+difMinima>encontroX&&b.x-difMinima<encontroX))){
          return 2;
        }
        else{
          return 1;
        }
      }
      else if(encontroX<p.x+difMinima){
        if(p.x <difMinima+encontroX){
          return 2;
        }
      }
    
    }

  }
  return 0; // caso a reta não se encontre a direita ou emcima de p, retorna zero
}

int inside(point p, point poly[], int n) {
  int sum = 0;   //Inicializando variaveis
  int boolLado;
  for(int i = 0;i<n;i++){ //Rodando para todos os lados
    if(i==n-1){           //Verificar se é o lado composto pelo 1° e ultimo ponto
      boolLado = verify(p,poly[i],poly[0]);
    }
    else{
      boolLado = verify(p, poly[i], poly[i+1]);
    }
    if(boolLado==2){           //Verifica se está acima da linha
      return 1;
      break;
    }
    sum+=boolLado;             //Soma das saidas de verify
  }
  if(sum%2==0){           //Se a soma for par o ponto p está fora da imagem
    return 0;
  }
  return 1;
}
