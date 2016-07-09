#include "HeapSort.h"

void peneira( int p, int m, int v[])
{ 
   int f = 2*p, x = v[p];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])
          ++f;
      if (x >= v[f])
          break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}

void restoreHup(int *a,int i)
{
        int v=a[i];

        while((i>1)&&(a[i/2]<v))
        {
                a[i]=a[i/2];
                i=i/2;
        }
        a[i]=v;
}

void restoreHdown(int *a,int i,int n)
{
        int v= a[i];
        int j=i*2;
        while(j<=n)
        {
                if((j<n)&&(a[j]<a[j+1]))
                        j++;
                if(a[j]<a[j/2]) 
                    break;
                a[j/2]=a[j];
                j=j*2;
        }
        a[j/2]=v;
}


void heapsort(int a[], int n)
{
   int i = n/2, pai, filho, t;
 
   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = a[i];
      }
      else
      {
          n--;
          if (n == 0)
             return;
          t = a[n];
          a[n] = a[0];
      }
 
      pai = i;
 
      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;
 
      while (filho < n)
      {
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t)
          {
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
   }
}