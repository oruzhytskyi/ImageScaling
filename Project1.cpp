//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", MainForm);
USEFORM("Unit2.cpp", NearestVsBilinear);
USEFORM("Unit5.cpp", BilinearVSBicubic);
USEFORM("Unit7.cpp", NearestVSBicubic);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TNearestVsBilinear), &NearestVsBilinear);
                 Application->CreateForm(__classid(TBilinearVSBicubic), &BilinearVSBicubic);
                 Application->CreateForm(__classid(TNearestVSBicubic), &NearestVSBicubic);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
