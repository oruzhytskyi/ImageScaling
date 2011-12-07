//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LoadPictureButtonClick(TObject *Sender)
{
  OpenDialog1->Execute();
  Image1->Picture->LoadFromFile(OpenDialog1->FileName);
  Image1->Center=true;
/*  for(int i=0;i<30;i++)
  for(int j=0;j<90;j++)
  Memo1->Lines->Add(GetRValue(ColorToRGB(Image1->Canvas->Pixels[i][j])));
*/}
//---------------------------------------------------------------------------
void TMainForm::formPictureArray(Array<long>* arr)
{
  int h=Image1->Picture->Height;
  int w=Image1->Picture->Width;

  for(int i=0;i<h;i++)
  for(int j=0;j<w;j++)
    arr->setel(i,j,(long)Image1->Canvas->Pixels[j][i]);
}


void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  ResForm->Show();
}
//---------------------------------------------------------------------------
