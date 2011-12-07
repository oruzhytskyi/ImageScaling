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
#include <unit2.h>
#include <AlgCollection.h>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TOpenDialog *OpenDialog1;
        TButton *LoadPictureButton;
        TMemo *Memo1;
        TButton *Button1;
        void __fastcall LoadPictureButtonClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        void formPictureArray(Array<long>* arr);
};
//---------------------------------------------------------------------------

extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif


