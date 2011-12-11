//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResForm *ResForm;
//---------------------------------------------------------------------------
__fastcall TResForm::TResForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TResForm::FormShow(TObject *Sender)
{
  int in=MainForm->Image1->Picture->Height;
  int im=MainForm->Image1->Picture->Width;
  int on=MainForm->Image1->Picture->Height*2;
  int om=MainForm->Image1->Picture->Width*2;
  AlgCollection* Algs;
  Array<long>* arr=new Array<long>(in,im);
  Array<long>* resarr=new Array<long>(on,om);
  for(int i=0;i<resarr->getn();i++)
    for(int j=0;j<resarr->getm();j++)
      resarr->setel(i,j,16777215);

  MainForm->formPictureArray(arr);
 // Algs->nearestNeighbor(arr,resarr);
  Algs->bicubicInterpolation(arr,resarr);

  Image1->Center=true;
  for(int i=0;i<resarr->getn();i++)
  for(int j=0;j<resarr->getm();j++)
  Image1->Canvas->Pixels[j][i] = (TColor)resarr->getel(i,j);
//  Image1->Canvas->Pixels[j][i] = (TColor)RGB(GetRValue(ColorToRGB(arr->getel(i,j))),GetGValue(ColorToRGB(arr->getel(i,j))),GetBValue(ColorToRGB(arr->getel(i,j))));
}
//---------------------------------------------------------------------------

