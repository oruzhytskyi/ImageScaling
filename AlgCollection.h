//---------------------------------------------------------------------------

#ifndef AlgCollectionH
#define AlgCollectionH

#include <Controls.hpp>
#include <math>
#include "MyAlgorithms.h"
#include <float>
using namespace std;

class AlgCollection
{
  public:
        void bicubicInterpolation(Array<long>* iarr, Array<long>* oarr);
        void bilinearInterpolation(Array<long>* iarr, Array<long>* oarr);
        void nearestNeighbor(Array<long>* iarr, Array<long>* oarr);
  private:
        long bicubicFunction(long x, Array<double>* b);
        void bicubicGetCoeficients(Array<long>* x, Array<long>* y, Array<double>* b);
        void bicubicNearestMatrCoords(long x, long y, long n, long m, int size, long& a, long& b);
        void bicubicNearestPointsMatr(long a, long b,int size, long** f, Array<long>* arr);
};

//---------------------------------------------------------------------------
#endif
