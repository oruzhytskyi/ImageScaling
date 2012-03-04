//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TBilinearVSBicubic : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        TButton *Button1;
        TSavePictureDialog *SavePictureDialog1;
        TButton *Button2;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        int **arr,**resarr;
        double **inp_r,**inp_g,**inp_b;
        double **out_r,**out_g,**out_b;
public:		// User declarations
        __fastcall TBilinearVSBicubic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBilinearVSBicubic *BilinearVSBicubic;
//---------------------------------------------------------------------------
#endif
 