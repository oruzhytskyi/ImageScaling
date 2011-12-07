//---------------------------------------------------------------------------

#ifndef MyAlgorithmsH
#define MyAlgorithmsH
//---------------------------------------------------------------------------

template<class T> class Array
{
  public:
     Array(long np, long mp)
     {
        n=np;
        m=mp;
        a=new T*[n];
        for(int i=0;i<n;i++) a[i]=new T[m];
     };
     T getel(long x, long y) {return a[x][y];};
     void setel(long x, long y, T elem) {a[x][y]=elem;};
     long getn() {return n;};
     long getm() {return m;};
  private:
     long n;
     long m;
     T** a;
};

class Algorithms
{
  public:
    template<class T> int multMatr(Array<T>* a, Array<T>* b, Array<T>* res);
    template<class T> int invMatr(Array<T>* a, Array<T>* inv);
};

template<class T> int Algorithms::multMatr(Array<T>* a, Array<T>* b, Array<T>* res)
{
   for(int i=0;i<res->getn();i++)
     for(int j=0;j<res->getm();j++)
     {
       T el=0;
       for(int k=0;k<a->getm();k++)
       {
         el=el+a->getel(i,k)*b->getel(k,j);
       };
       res->setel(i,j,el);
     };
   return 0;
};

template<class T> int Algorithms::invMatr(Array<T>* a, Array<T>* inv)
{
//Gauss-Jordan method is used in this method to invert matrix a.
//Form working matrix
   Array<T>* w = new Array<T>(a->getn(),a->getm()*2);
   int n=w->getn();
   int m=w->getm();
   T mas[3][3];

   for(int i=0;i<a->getn();i++)
     for(int j=0;j<a->getm();j++)
     {
       w->setel(i,j,a->getel(i,j));
       if (i==j) w->setel(i,a->getm()+j,1); else w->setel(i,a->getm()+j,0);
     };

//Step 5: iterating steps 1-4
   int cj=0;
   for(int ci=0;ci<n;ci++)
   {
     cj=ci;
//Step 1: choose non zero row
     int j=cj;
     int wj=0;
     bool found=false;

     do
     {
       for(int i=ci;i<n;i++)
         if (w->getel(i,j)!=0.0)
         {
           wj=j;
           found=true;
         };
       j++;
     }
     while(j<m && !found);
     if (!found) {return 1;};
//Step 2: switch rows in case first element of chosen columnt is zero
     int wi=ci;
     if (w->getel(ci,wj)==0.0)
     {
       //find string with non zero value in this column
       for(int i=ci;i<n;i++)
         if (w->getel(i,wj)!=0.0) {wi=i; break;};
       //replace rows
       for(int j=cj;j<m;j++)
       {
         T elem=w->getel(ci,j);
         w->setel(ci,j,w->getel(wi,j));
         w->setel(wi,j,elem);
       };
     };
//Step 3: divide all elements of first row on first element of chosen column
     T elem=w->getel(ci,wj);
     for(int j=cj;j<m;j++)
       w->setel(ci,j,w->getel(ci,j)/elem);

//Step 4: subtruct first row multiplied on appropriate element of other rows
//from other rows
     for(int i=ci+1;i<n;i++)
     {
       T elem=w->getel(i,wj);
       for(int j=cj;j<m;j++)
         w->setel(i,j,w->getel(i,j)-w->getel(ci,j)*elem);
      };
   };

//Step 6: subtructing last row multiplied to appropriate element of column
//from other rows in order to make ones on main diagonal
   for(int k=n-1;k>-1;k--)
     for(int i=k-1;i>-1;i--)
     {
       T elem=w->getel(i,k);
       for(int j=0;j<m;j++)
         w->setel(i,j,w->getel(i,j)-w->getel(k,j)*elem);
     };


//Form output matrix inv
   for(int i=0;i<inv->getn();i++)
     for(int j=0;j<inv->getm();j++)
       inv->setel(i,j,w->getel(i,j+inv->getm()));

    return 0;
};


#endif
