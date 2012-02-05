//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "unit1.h"
#include <ExtCtrls.hpp>
#include "AlgCollection.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TNearestVsBilinear : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
        int **arr,**resarr;
        double **inp_r,**inp_g,**inp_b;
        double **out_r,**out_g,**out_b;
public:		// User declarations
        __fastcall TNearestVsBilinear(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNearestVsBilinear *NearestVsBilinear;
//---------------------------------------------------------------------------
#endif
