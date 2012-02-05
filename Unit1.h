//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include "unit2.h"
#include "AlgCollection.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TOpenDialog *OpenDialog1;
        TButton *LoadPictureButton;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall LoadPictureButtonClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        void formPictureArray(int** arr);
};
//---------------------------------------------------------------------------

extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif


