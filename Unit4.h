//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#endif

#include <vector>
#include <map>
#include <math>

namespace kurswork {
  class MatrixHelper {
    public:
      int multMatr(const std::vector<std::vector<double> >& a, const std::vector<std::vector<double> >& b, std::vector<std::vector<double> >& res);
      int invMatr(const std::vector<std::vector<double> >& a, std::vector<std::vector<double> >& inv);
  };

  class Interpolator {
    public:
      Interpolator();
      void linInterp(const std::vector<double>& in, std::vector<double>& out);
      void bilinInterp(const std::vector<std::vector<double> >& in, std::vector<std::vector<double> >& out);
      void cubInterp(const std::vector<double>& in, std::vector<double>& out);
      void bicubInterp(const std::vector<std::vector<double> >& in, std::vector<std::vector<double> >& out);
      double intBase(const std::vector<double>& in, std::vector<double>& out);

    private:
      MatrixHelper Calc;
  };
};

