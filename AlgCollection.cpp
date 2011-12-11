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
//debugging
long matr[4][1];
//debugging
  int n=iarr->getn();
  int m=iarr->getm();
  long si=0,sj=0;
  int size=2;
  Array<long>* y=new Array<long>(size*size,1);
  Array<long>* x=new Array<long>(size*size,1);
  Array<double>* b=new Array<double>(size*size,1);

  for(int i=1;i<n-2;i++)
  for(int j=1;j<m-2;j++)
  {
    bicubicNearestMatrCoords(i,j,n,m,size,si,sj);

    for(int k=0;k<size;k++)
      for(int z=0;z<size;z++)
      {
        y->setel(z+k*size,0,iarr->getel(si+k,sj+z));
        x->setel(z+k*size,0,2*((sj+z)+(k+si)*size));
      };

//    bicubicNearestPointsMatr(a,c,size,f,iarr);

    bicubicGetCoeficients(x,y,b);
 //   oarr->setel(i*2,j*2,bicubicFunction(j*2+i*2*size,b));
    oarr->setel(i*2,j*2,iarr->getel(i,j));
    long el2=oarr->getel(i*2,j*2);
    //oarr->setel(i*2+1,j*2,bicubicFunction(j*2+(i*2+1)*size,b));
    long ell=  bicubicFunction((j*2+1)+i*2*size,b);
    oarr->setel(i*2,j*2+1,bicubicFunction((j*2+1)+i*2*size,b));
    //oarr->setel(i*2+1,j*2+1,bicubicFunction((j*2+1)+(i*2+1)*size,b));

/*    bicubicGetCoeficients(i-a,j-c+1,b);
    oarr->setel(i*2,j*2+1,(TColor)bicubicFunction(b,f));

    bicubicGetCoeficients(i-a+1,j-c+1,b);
    oarr->setel(i*2+1,j*2+1,(TColor)bicubicFunction(b,f));
*/
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
  a=x;
  b=y;
/*  if(x<(long)size/2) {a=0;};
  if(y<(long)size/2) {b=0;};
  if(x>n-(long)size/2-1) {a=n-(long)size/2-1;};
  if(y>m-(long)size/2-1) {b=m-(long)size/2-1;};
*/
};

long AlgCollection::bicubicFunction(long x, Array<double>* b)
{
  double result=0;
  for(int i=0;i<b->getn();i++)
    result=result+b->getel(i,0)*powl(x,i);
  if (div(result,1).rem>0.5) result=(long)div(result,1).quot+1; else result=(long)div(result,1).quot;
  return result;
};

void AlgCollection::bicubicGetCoeficients(Array<long>* x, Array<long>* y, Array<double>* b)
{
  double matr[4][1];
  for(int i=0;i<x->getn();i++)
    for(int j=0;j<x->getm();j++)
      matr[i][j]=x->getel(i,j);

  Array<double>* yy=new Array<double>(y->getn(),y->getm());
  for(int i=0;i<y->getn();i++)
    for(int j=0;j<y->getm();j++)
      yy->setel(i,j,(double)y->getel(i,j));

  Array<double>* xx=new Array<double>(x->getn(),x->getn());
  for(int i=0;i<xx->getn();i++)
    for(int j=0;j<xx->getm();j++)
      if((x->getel(i,0)==0)&&(j==0)) xx->setel(i,j,1);
        else xx->setel(i,j,pow(x->getel(i,0),j));

  Algorithms* Algs=new Algorithms();
  Array<double>* inv=new Array<double>(x->getn(),x->getn());
  Algs->invMatr<double>(xx, inv);
  Algs->multMatr<double>(inv,yy,b);

  double matr1[4][4];
  for(int i=0;i<xx->getn();i++)
    for(int j=0;j<xx->getm();j++)
      matr1[i][j]=xx->getel(i,j);

  double matr2[4][4];
  for(int i=0;i<inv->getn();i++)
    for(int j=0;j<inv->getm();j++)
      matr2[i][j]=inv->getel(i,j);

  double matr3[4][1];
  for(int i=0;i<yy->getn();i++)
    for(int j=0;j<yy->getm();j++)
      matr3[i][j]=yy->getel(i,j);

  double matr4[4][4];
  for(int i=0;i<b->getn();i++)
    for(int j=0;j<b->getm();j++)
      matr4[i][j]=b->getel(i,j);

  double matr5[4][1];
  for(int i=0;i<b->getn();i++)
    for(int j=0;j<b->getm();j++)
      matr4[i][j]=b->getel(i,j);

  for(int i=0;i<1;i++);

};


