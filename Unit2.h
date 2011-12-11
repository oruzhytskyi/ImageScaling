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
//---------------------------------------------------------------------------
class TResForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResForm *ResForm;
//---------------------------------------------------------------------------
#endif
