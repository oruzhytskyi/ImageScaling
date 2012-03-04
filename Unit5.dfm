object BilinearVSBicubic: TBilinearVSBicubic
  Left = 423
  Top = 225
  Width = 466
  Height = 243
  AutoSize = True
  Caption = 'Bilinear VS Bicubic interpolation'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 24
    Width = 225
    Height = 185
  end
  object Label1: TLabel
    Left = 64
    Top = 0
    Width = 121
    Height = 16
    Caption = 'Bilinear interpolation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Image2: TImage
    Left = 233
    Top = 24
    Width = 225
    Height = 185
  end
  object Label2: TLabel
    Left = 296
    Top = 0
    Width = 120
    Height = 16
    Caption = 'Bicubic Interpolation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 80
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Save Picture'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 320
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Save Picture'
    TabOrder = 1
    OnClick = Button2Click
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 416
    Top = 176
  end
end
