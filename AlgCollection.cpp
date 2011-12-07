//---------------------------------------------------------------------------


#pragma hdrstop

#include "AlgCollection.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void AlgCollection::nearestNeighbor(Array<long>* iarr, Array<long>* oarr)
{
  for(int i=0;i<iarr->getn();i++)
  for(int j=0;j<iarr->getm();j++)
  {
    oarr->setel(2*i,2*j,iarr->getel(i,j));
    oarr->setel(2*i,2*j+1,iarr->getel(i,j));
    oarr->setel(2*i+1,2*j,iarr->getel(i,j));
    oarr->setel(2*i+1,2*j+1,iarr->getel(i,j));
  }
};

void AlgCollection::bicubicInterpolation(Array<long>* iarr, Array<long>* oarr)
{
  int n=iarr->getn();
  int m=iarr->getm();
  long a=0,c=0;
  int size=4;

  long** f=new long*[size];
  for(int i=0;i<size;i++) f[i]=new long[size];

  long* b=new long[size*size];

  for(int i=0;i<n-2;i++)
  for(int j=0;j<m-2;j++)
  {
    bicubicNearestMatrCoords(i,j,n,m,size,a,c);
    for(int i=0;i<size;i++)
    {
      x->setel(i,0,i+a);
      y->setel(i,0,iarr->getel(i+a,j));
    };
//    bicubicNearestPointsMatr(a,c,size,f,iarr);

    bicubicGetCoeficients(x,y,b);
    oarr->setel(i*2+1,j*2,(TColor)bicubicFunction(b,f));

    bicubicGetCoeficients(i-a,j-c+1,b);
    oarr->setel(i*2,j*2+1,(TColor)bicubicFunction(b,f));

    bicubicGetCoeficients(i-a+1,j-c+1,b);
    oarr->setel(i*2+1,j*2+1,(TColor)bicubicFunction(b,f));
  };

};

void AlgCollection::bicubicNearestPointsMatr(long a, long b, int size, long** f, Array<long>* arr)
{
  for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
  f[i][j]=arr->getel(a+i,b+j);
};

void AlgCollection::bicubicNearestMatrCoords(long x, long y, long n, long m, int size, long& a, long& b)
{
  a=x-1;
  b=y-1;
  if(x<(long)size/2) {a=0;};
  if(y<(long)size/2) {b=0;};
  if(x>n-(long)size/2-1) {a=n-(long)size/2-1;};
  if(y>m-(long)size/2-1) {b=m-(long)size/2-1;};
};

long AlgCollection::bicubicFunction(long x, Array<float>* b, long f)
{
  long result=0;
  for(int i=0;i<b->getn();i++)
    result=result+b->getel(i,0)*pow(x,i);
  return result;
};

void AlgCollection::bicubicGetCoeficients(Array<long>* x, Array<long>* y, Array<float>* b)
{
  float matr[4][4];
  Array<float>* yy=new Array<float>(y->getn(),y->getm());
  for(int i=0;i<y->getn();i++)
    for(int j=0;j<y->getm();j++)
      yy->setel(i,j,(float)y->getel(i,j));

  for(int i=0;i<y->getn();i++)
    for(int j=0;j<y->getm();j++)
      matr[i][j]=yy->getel(i,j);

  Array<float>* xx=new Array<float>(x->getn(),x->getn());
  for(int i=0;i<xx->getn();i++)
    for(int j=0;i<xx-getm();j++)
      xx->setel(i,j,pow(x->getel(i,0),j));

  Algorithms* Algs=new Algorithms();
  Array<float>* inv=new Array<float>(x->getn(),x->getn());
  Algs->invMatr(xx, inv);
  Algs->multMatr(inv,y,b);
};


