object NearestVsBilinear: TNearestVsBilinear
  Left = 722
  Top = 205
  Width = 489
  Height = 251
  AutoSize = True
  Caption = 'Nearest neighbor VS Bilinear interpolation'
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
    Top = 32
    Width = 225
    Height = 185
  end
  object Label1: TLabel
    Left = 64
    Top = 0
    Width = 107
    Height = 16
    Caption = 'Nearest Neighbor'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Image2: TImage
    Left = 256
    Top = 32
    Width = 225
    Height = 185
  end
  object Label2: TLabel
    Left = 320
    Top = 0
    Width = 121
    Height = 16
    Caption = 'Bilinear Interpolation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
end
