//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit4.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace kurswork {
  //MatrixHelper definition
  int MatrixHelper::multMatr(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b, std::vector<std::vector<double> >& res)
  {
     //TODO add verification for input matrixes (must be rectangularr)
     //TODO add resizing for output matrix
     for(int i=0;i<res.size();i++)
       for(int j=0;j<res[i].size();j++)
       {
         double el=0;
         for(int k=0;k<a[i].size();k++)
         {
           el=el+a[i][k]*b[k][j];
         };
         res[i][j]=el;
       };
     return 0;

   };
   int MatrixHelper::invMatr(const std::vector<std::vector<double> >& a, std::vector<std::vector<double> >& inv)
   {
   //TODO set aproppriate sizes for inv matrix

    //Gauss-Jordan method is used in this method to invert matrix a.
    //Form working matrix
    std::vector<std::vector<double> > w;
    w.resize(a.size());
    for(int i=0;i<a.size();i++)
      w[i].resize(a[0].size()*2,0);

    int n=w.size();
    int m=w[0].size();
    //   T mas[3][3]; //for debugging

    for(int i=0;i<a.size();i++)
      for(int j=0;j<a[0].size();j++)
      {
        w[i][j]=a[i][j];
        if (i==j) w[i][a[0].size()+j]=1; else w[i][a[0].size()+j]=0;
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
          if (w[i][j]!=0.0)
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
      if (w[ci][wj]==0.0)
      {
        //find string with non zero value in this column
        for(int i=ci;i<n;i++)
          if (w[i][wj]!=0.0) {wi=i; break;};
        //replace rows
        for(int j=cj;j<m;j++)
        {
          double elem=w[ci][j];
          w[ci][j]=w[wi][j];
          w[wi][j]=elem;
        };
      };
      //Step 3: divide all elements of first row on first element of chosen column
      double elem=w[ci][wj];
      for(int j=cj;j<m;j++)
        w[ci][j]=w[ci][j]/elem;

      //Step 4: subtruct first row multiplied on appropriate element of other rows
      //from other rows
      for(int i=ci+1;i<n;i++)
      {
        double elem=w[i][wj];
        for(int j=cj;j<m;j++)
          w[i][j]=w[i][j]-w[ci][j]*elem;
       };
    };

    //Step 6: subtructing last row multiplied to appropriate element of column
    //from other rows in order to make ones on main diagonal
    for(int k=n-1;k>-1;k--)
      for(int i=k-1;i>-1;i--)
      {
        double elem=w[i][k];
        for(int j=0;j<m;j++)
          w[i][j]=w[i][j]-w[k][j]*elem;
      };


    //Form output matrix inv
    for(int i=0;i<inv.size();i++)
      for(int j=0;j<inv[0].size();j++)
        inv[i][j]=w[i][j+inv[0].size()];

     return 0;
   };

  //Interpolator definition
  Interpolator::Interpolator()
  {
     Calc=MatrixHelper();
  };
  void Interpolator::linInterp(const std::vector<double>& in, std::vector<double>& out)
  {

  };
  void Interpolator::bilinInterp(const std::vector<std::vector<double> >& in, std::vector<std::vector<double> >& out)
  {
     //intBase(in,out);
  };
  void Interpolator::cubInterp(const std::vector<double>& in, std::vector<double>& out)
  {
     double matr[4];
     for(int i=0;i<4;i++)
        matr[i]=in[i];
     matr[0]=matr[0];

     out.resize(in.size()*2,0);
     std::vector<double> in_base(4,0);
     std::vector<double> out_base(4*2,0);
     for(int i=0;i<in.size();i=i+4)
     {
        for(int j=0;j<4;j++)
           if(i+j<in.size()) {in_base[j]=in[i+j];}
        intBase(in_base,out_base);
        for(int j=0;j<4*2;j++)
           out[i*2+j]=out_base[j];
     };
  };
  void Interpolator::bicubInterp(const std::vector<std::vector<double> >& in, std::vector<std::vector<double> >& out)
  {
     out.resize(in.size()*2,std::vector<double>(in[0].size()*2,0));
     std::vector<double> out_row(out[0].size(),0);
     std::vector<double> out_column(out.size(),0);
     std::vector<double> in_column(in.size(),0);

     for(int i=0;i<in.size();i++)
     {
        cubInterp(in[i],out_row);
        out[i*2]=out_row;
     }
     for(int j=0;j<out[0].size();j++)
     {
        for(int i=0;i<in.size();i++)
        {
           in_column[i]=out[i*2][j];
        }

        cubInterp(in_column,out_column);
        for(int i=0;i<in.size()-1;i++)
        {
           out[i*2+1][j]=out_column[i*2+1];
        }
     };
  };
  double Interpolator::intBase(const std::vector<double>& in, std::vector<double>& out)
  {

     int in_s=in.size();
     int out_s=in_s*2;
     out.resize(out_s,0);
     std::vector<std::vector<double> > X;
     X.resize(in_s);
     for(int i=0;i<in_s;i++)
        X[i].resize(in_s,0);

     std::vector<std::vector<double> > Xinv(in_s);
     Xinv.resize(in_s);
     for(int i=0;i<in_s;i++)
        Xinv[i].resize(in_s,0);

     std::vector<std::vector<double> > A(in_s);
     A.resize(in_s);
     for(int i=0;i<in_s;i++)
        A[i].resize(1,0);

     std::vector<std::vector<double> > Y;
     Y = std::vector<std::vector<double> >(in_s,std::vector<double>(1,0));

     for(int i=0; i<in_s; i++)
        for(int j=0; j<in_s; j++)
        {
           if(j==0.0) { X[i][j]= 1;}
              else
              {X[i][j]=pow(i*2,j);}
        };

     for(int i=0; i<in_s;i++)
        Y[i][0]=in[i];

     Calc.invMatr(X,Xinv);
     Calc.multMatr(Xinv,Y,A);

     for(int i=0;i<out_s;i++)
     {
        double elem=0;
        for(int j=0;j<in_s;j++)
        {
           if (j==0) {elem=elem+A[j][0];}
              else
              {elem=elem+A[j][0]*pow(i,j);}
        };
        out[i]=elem;
     };
     return 0;
  };
};
