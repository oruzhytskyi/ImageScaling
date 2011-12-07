object MainForm: TMainForm
  Left = 223
  Top = 190
  Width = 689
  Height = 394
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 481
    Height = 305
  end
  object LoadPictureButton: TButton
    Left = 584
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Load picture'
    TabOrder = 0
    OnClick = LoadPictureButtonClick
  end
  object Memo1: TMemo
    Left = 584
    Top = 56
    Width = 65
    Height = 129
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Button1: TButton
    Left = 584
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object OpenDialog1: TOpenDialog
    Left = 648
    Top = 304
  end
end
