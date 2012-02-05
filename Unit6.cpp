//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit6.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

double cubicInterpolate (double p[4], double x) {
	return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}

double linInterpolate (double p[2], double x) {
	return p[0]+(p[1]-p[0])*x;
}

double bicubicInterpolateBase (double p[4][4], double x, double y) {
	double arr[4];
	arr[0] = cubicInterpolate(p[0], y);
	arr[1] = cubicInterpolate(p[1], y);
	arr[2] = cubicInterpolate(p[2], y);
	arr[3] = cubicInterpolate(p[3], y);
	return cubicInterpolate(arr, x);
}

double bilinInterpolateBase (double p[2][2], double x, double y) {
	double arr[2];
	arr[0] = linInterpolate(p[0], y);
	arr[1] = linInterpolate(p[1], y);
	return linInterpolate(arr, x);
}

void bicubInterpolate(double** in, long n, long m, double** out) {
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         out[i*2][j*2]=in[i][j];

   double p[4][4];

   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) {
         for(int ii=0;ii<4;ii++)
            for(int jj=0;jj<4;jj++) {
               int a,b;
               a=i+ii-1;
               b=j+jj-1;
               if(i+ii-1<0) {a=i;}
               if(j+jj-1<0) {b=j;}
               if(i+ii-1>n-1) {a=n-1;}
               if(j+jj-1>m-1) {b=m-1;}
               p[ii][jj]=in[a][b];
            };
         out[i*2+1][j*2+1]=bicubicInterpolateBase(p,0.5,0.5);
         out[i*2][j*2+1]=bicubicInterpolateBase(p,0.0,0.5);
         out[i*2+1][j*2]=bicubicInterpolateBase(p,0.5,0.0);
      };
};

void bilinInterpolate(double** in, long n, long m, double** out) {
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         out[i*2][j*2]=in[i][j];

   double p[2][2];

   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) {
         for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++) {
               int a,b;
               a=i+ii;
               b=j+jj;
               if(i+ii>n-1) {a=n-1;}
               if(j+jj>m-1) {b=m-1;}
               p[ii][jj]=in[a][b];
            };
         out[i*2+1][j*2+1]=bilinInterpolateBase(p,0.5,0.5);
         out[i*2][j*2+1]=bilinInterpolateBase(p,0.0,0.5);
         out[i*2+1][j*2]=bilinInterpolateBase(p,0.5,0.0);
      };
};

void nearestNeighborInterpolate(double** in, long n, long m, double** out) {

   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) {
         out[i*2][j*2]=in[i][j];
         out[i*2+1][j*2]=in[i][j];
         out[i*2][j*2+1]=in[i][j];
         out[i*2+1][j*2+1]=in[i][j];
      };
};



