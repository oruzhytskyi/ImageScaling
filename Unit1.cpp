//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"

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
    arr->setel(i,j,(long)ColorToRGB(Image1->Canvas->Pixels[j][i]));
}


void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  ResForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
   std::vector<std::vector<double> > in;
   in.resize(4);
   for(int i=0;i<4;i++)
      in[i].resize(4,0);
   std::vector<std::vector<double> > out;
   out.resize(4);
   for(int i=0;i<4;i++)
      out[i].resize(4,0);

   in[0][0]=1;
   in[1][0]=1;
   in[2][0]=4;
   in[3][0]=4;
   in[0][1]=9;
   in[1][1]=3;
   in[2][1]=4;
   in[3][1]=4;
   in[0][2]=5;
   in[1][2]=2;
   in[2][2]=1;
   in[3][2]=2;
   in[0][3]=5;
   in[1][3]=1;
   in[2][3]=2;
   in[3][3]=1;

   kurswork::Interpolator interp =kurswork::Interpolator();
   interp.bicubInterp(in,out);
   for(int i=0;i<out.size();i++)
      for(int j=0;j<out.size();j++)
         Memo1->Lines->Add("["+IntToStr(i)+"]"+"["+IntToStr(j)+"]="+FloatToStr(out[i][j]));

}
//---------------------------------------------------------------------------

