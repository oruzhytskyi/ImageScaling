//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TNearestVSBicubic : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        TSavePictureDialog *SavePictureDialog1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        int **arr,**resarr;
        double **inp_r,**inp_g,**inp_b;
        double **out_r,**out_g,**out_b;
public:		// User declarations
        __fastcall TNearestVSBicubic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNearestVSBicubic *NearestVSBicubic;
//---------------------------------------------------------------------------
#endif
