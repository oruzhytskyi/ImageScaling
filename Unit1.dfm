object MainForm: TMainForm
  Left = 654
  Top = 266
  Width = 645
  Height = 381
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
    Left = 0
    Top = 8
    Width = 353
    Height = 321
  end
  object LoadPictureButton: TButton
    Left = 400
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Load picture'
    TabOrder = 0
    OnClick = LoadPictureButtonClick
  end
  object Button1: TButton
    Left = 400
    Top = 56
    Width = 217
    Height = 25
    Caption = 'Nearest Neighbor vs Bilinear Interpolation'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 400
    Top = 96
    Width = 217
    Height = 25
    Caption = 'Nearest Neighbor vs Bicubic Interpolation'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 400
    Top = 136
    Width = 217
    Height = 25
    Caption = 'Bilinear Interpolation vs Bicubic Interpolation'
    TabOrder = 3
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Left = 568
    Top = 320
  end
end
