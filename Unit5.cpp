//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit2.h"
#include "Unit6.cpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBilinearVSBicubic *BilinearVSBicubic;
//---------------------------------------------------------------------------
__fastcall TBilinearVSBicubic::TBilinearVSBicubic(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBilinearVSBicubic::FormActivate(TObject *Sender)
{
   int in=MainForm->Image1->Picture->Height;
   int im=MainForm->Image1->Picture->Width;
   int on=MainForm->Image1->Picture->Height*2;
   int om=MainForm->Image1->Picture->Width*2;

   Image1->Picture=0;
   Image2->Picture=0;

  Image1->Height=on;
  Image1->Width=om;

  Label1->Left=floor((om-Label1->Width)/2.0);
  Label2->Left=floor((om-Label1->Width)/2.0)+om;

  Button1->Left=floor((om-Button1->Width)/2.0);
  Button2->Left=floor((om-Button2->Width)/2.0)+om;
  Button1->Top=Image1->Height+Button1->Height+10;
  Button2->Top=Button2->Height +Image1->Height+10;


  Image2->Height=on;
  Image2->Width=om;
  Image2->Left=om+20;

   arr=new int*[in];
   for(int i=0;i<in;i++)
      arr[i]=new int[im];

   resarr=new int*[on];
   for(int i=0;i<on;i++)
      resarr[i]=new int[om];

   inp_r= new double*[in];
   for(int i=0;i<in;i++)
      inp_r[i]=new double[im];

   out_r= new double*[on];
   for(int i=0;i<on;i++)
      out_r[i]=new double[om];

   inp_g= new double*[in];
   for(int i=0;i<in;i++)
      inp_g[i]=new double[im];

   out_g= new double*[on];
   for(int i=0;i<on;i++)
      out_g[i]=new double[om];

   inp_b= new double*[in];
   for(int i=0;i<in;i++)
      inp_b[i]=new double[im];

   out_b= new double*[on];
   for(int i=0;i<on;i++)
      out_b[i]=new double[om];

   MainForm->formPictureArray(arr);

  for(int i=0;i<in;i++)
     for(int j=0;j<im;j++) {
        inp_r[i][j]=GetRValue(arr[i][j]);
        inp_g[i][j]=GetGValue(arr[i][j]);
        inp_b[i][j]=GetBValue(arr[i][j]);
     };

/*  interpolateBilin(inp_r,n,m,out_r);
  interpolateBilin(inp_g,n,m,out_g);
  interpolateBilin(inp_b,n,m,out_b);
  */
/*  interpolateBicub(inp_r,n,m,out_r);
  interpolateBicub(inp_g,n,m,out_g);
  interpolateBicub(inp_b,n,m,out_b);
  */
  bilinInterpolate(inp_r,in,im,out_r);
  bilinInterpolate(inp_g,in,im,out_g);
  bilinInterpolate(inp_b,in,im,out_b);

  for(int i=0;i<on;i++)
     for(int j=0;j<om;j++) {
        int r,g,b;
        r=floor(out_r[i][j]);
        g=floor(out_g[i][j]);
        b=floor(out_b[i][j]);

        if(floor(out_r[i][j])>255) { r=255;}
        if(floor(out_g[i][j])>255) { g=255;}
        if(floor(out_b[i][j])>255) { b=255;}

        if(floor(out_r[i][j])<0) { r=0;}
        if(floor(out_g[i][j])<0) { g=0;}
        if(floor(out_b[i][j])<0) { b=0;}

        resarr[i][j] = RGB(r,g,b);
     };

  for(int i=0;i<on;i++)
     for(int j=0;j<om;j++) {
        Image1->Canvas->Pixels[j][i] = (TColor)resarr[i][j];
     };


  bicubInterpolate(inp_r,in,im,out_r);
  bicubInterpolate(inp_g,in,im,out_g);
  bicubInterpolate(inp_b,in,im,out_b);


  for(int i=0;i<on;i++)
     for(int j=0;j<om;j++) {
        int r,g,b;
        r=floor(out_r[i][j]);
        g=floor(out_g[i][j]);
        b=floor(out_b[i][j]);

        if(floor(out_r[i][j])>255) { r=255;}
        if(floor(out_g[i][j])>255) { g=255;}
        if(floor(out_b[i][j])>255) { b=255;}

        if(floor(out_r[i][j])<0) { r=0;}
        if(floor(out_g[i][j])<0) { g=0;}
        if(floor(out_b[i][j])<0) { b=0;}

        resarr[i][j] = RGB(r,g,b);
     };

  for(int i=0;i<on;i++)
     for(int j=0;j<om;j++) {
        Image2->Canvas->Pixels[j][i] = (TColor)resarr[i][j];
     };

}
//---------------------------------------------------------------------------
void __fastcall TBilinearVSBicubic::Button1Click(TObject *Sender)
{
        SavePictureDialog1->Execute();
        Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TBilinearVSBicubic::Button2Click(TObject *Sender)
{
        SavePictureDialog1->Execute();
        Image2->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------

