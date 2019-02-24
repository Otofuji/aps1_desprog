#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {
  
  
  //Inicialização de variáveis.

  double da; //variaçåo percentual da área que delimita a aresta entre a e b.
  double dx; //diferença em módulo dos pontos a e b no eixo x.
  double dy; //diferença em módulo dos pontos a e b no eixo y.
  double xmin; //menor valor do eixo x entre os pontos a e b.
  double ymin; //menor valor do eixo y entre os pontos a e b. 
  double dp; //diferença em módulo axial do ponto p e do menor valor axial dos pontos a e b.
  double dyda; //valor no eixo y que contém a aresta para um dado valor no eixo x. 


  //Verifica o módulo da diferença dos pontos a e b.
  //Também, verifica o menor x e o menor y. Isso será usado na verificação da distância axial percentual mais adiante.

  if (a.x > b.x) {
    dx = a.x - b.x;
    xmin = b.x;
    }
  else {
    dx = b.x - a.x;
    xmin = a.x;
    }

  if (a.y > b.y) {
    dy = a.y - b.y;
    ymin = b.y;
    }
  else {
    dy = b.y - a.y;
    ymin = a.y;
    }

  
  //Verifica se o ponto p está contido na área que delimita a aresta entre a e b.

  if (p.x >= a.x && p.x <= b.x) {
    if (p.y >= a.y && p.y <= b.y) {

      //Verifica a distância do ponto p no eixo x percentualmente em relação ao trajeto axial inteiro.
      //Por exemplo, se o menor valor de x é 10, o maior é 20 e o ponto p possui valor em x de 15, a distância percentual é de 50%.
      
      dp = p.x - xmin;
      da = dp / dx;
      dp = p.y - ymin;
      dyda = dy*da;

      //Verifica se valor percentual axial aplicado ao eixo y corresponde ao valor de p no eixo y.
      //Se isso for verdade, o ponto p com certeza está exatamente em cima da aresta.

      
      if (dyda - dp < 0.00001) {
        return 2;
      }

      //Verifica se raio disparado para a direita cruza a aresta contida entre os pontos a e b.
      //Chamamos de partícula i cada parte infinitesimal desse raio disparado para a direita.
      //Verifica se partícula i cruza aresta em algum momento a mesma lógica para esta verificação com o ponto p.

      for (int i = xmin, i < xmin+dx, i+=0.00001) {
        
        dp = i - xmin;

        //Tratativa de caso especial para não haver divisão por zero.
        if (dp - 0 < 0.00001) {
          dp = 0.00001;
        }

        da = dp / dx;
        dp = p.y - ymin;

        if (dyda - dp < 0.00001) {
         return 1;
      }


      }





    }
  }

  
  
  
  
  
  
  
  
  //Repete a verificação do raio disparado na hipótese do ponto p não estar contido na área delimitada pela aresta.
  for (int i = xmin, i < xmin+dx, i+=0.00001) {
        
    dp = i - xmin;

    //Tratativa de caso especial para não haver divisão por zero.
   if (dp - 0 < 0.00001) {
      dp = 0.00001;
     }

     da = dp / dx;
     dp = p.y - ymin;

     if (dyda - dp < 0.00001) {
       return 1;
      }


  return 0;
}



  
int inside(point p, point poly[], int n) {
  return 0;
}
