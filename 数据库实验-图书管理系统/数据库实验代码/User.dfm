object UserForm: TUserForm
  Left = 327
  Top = 200
  Width = 1305
  Height = 838
  Caption = #29992#25143#30028#38754
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 119
  TextHeight = 16
  object SearchPage: TPageControl
    Left = 120
    Top = 48
    Width = 953
    Height = 89
    ActivePage = TabSheet3
    TabOrder = 0
    Visible = False
    object TabSheet1: TTabSheet
      Caption = #22270#20070#20449#24687
      object Label1: TLabel
        Left = 80
        Top = 16
        Width = 33
        Height = 16
        AutoSize = False
        Caption = #39034#24207
      end
      object Label2: TLabel
        Left = 216
        Top = 16
        Width = 81
        Height = 16
        AutoSize = False
        Caption = #25490#24207#20851#38190#35789
      end
      object Order1: TComboBox
        Left = 120
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 0
        Text = #21319#24207
        Items.Strings = (
          #21319#24207
          #38477#24207)
      end
      object ComboBox1: TComboBox
        Left = 304
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 1
        Text = 'IBSN'
        Items.Strings = (
          'IBSN'
          #32034#20070#21495
          #20070#21517
          #31867#22411
          #20316#32773
          #20986#29256#31038
          #20986#29256#24180#20221
          #20215#26684
          #24211#23384#25968#37327
          #21097#20313#25968#37327)
      end
      object Button1: TButton
        Left = 416
        Top = 8
        Width = 57
        Height = 33
        Caption = #26597#35810
        TabOrder = 2
        OnClick = Button1Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = #20010#20154#20449#24687
      ImageIndex = 2
      object Button2: TButton
        Left = 416
        Top = 8
        Width = 57
        Height = 33
        Caption = #26597#35810
        TabOrder = 0
        OnClick = Button2Click
      end
    end
    object TabSheet13: TTabSheet
      Caption = #22270#20070#25628#32034
      ImageIndex = 5
      object Label17: TLabel
        Left = 0
        Top = 8
        Width = 41
        Height = 25
        AutoSize = False
        Caption = #20070#21517
      end
      object Label18: TLabel
        Left = 328
        Top = 16
        Width = 56
        Height = 25
        AutoSize = False
        Caption = #20316#32773
      end
      object Edit1: TEdit
        Left = 48
        Top = 16
        Width = 217
        Height = 24
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 400
        Top = 16
        Width = 193
        Height = 24
        TabOrder = 1
      end
      object Button9: TButton
        Left = 656
        Top = 16
        Width = 65
        Height = 25
        Caption = #26597#35810
        TabOrder = 2
        OnClick = Button9Click
      end
    end
  end
  object CountPage: TPageControl
    Left = 120
    Top = 48
    Width = 953
    Height = 89
    ActivePage = TabSheet9
    TabOrder = 1
    Visible = False
    object TabSheet9: TTabSheet
      Caption = #20511#38405#24773#20917#32479#35745
      object Label11: TLabel
        Left = 56
        Top = 16
        Width = 40
        Height = 16
        AutoSize = False
        Caption = #39034#24207
      end
      object Label12: TLabel
        Left = 216
        Top = 16
        Width = 81
        Height = 16
        AutoSize = False
        Caption = #25490#24207#20851#38190#35789
      end
      object ComboBox10: TComboBox
        Left = 120
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 0
        Text = #21319#24207
        Items.Strings = (
          #21319#24207
          #38477#24207)
      end
      object ComboBox11: TComboBox
        Left = 304
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        TabOrder = 1
        Text = 'IBSN'
        Items.Strings = (
          'IBSN'
          #20070#21517
          #24211#23384#25968#37327
          #21097#20313#25968#37327)
      end
      object Button5: TButton
        Left = 416
        Top = 8
        Width = 57
        Height = 33
        Caption = #32479#35745
        TabOrder = 2
        OnClick = Button5Click
      end
    end
    object TabSheet10: TTabSheet
      Caption = #36817#26399#37319#36141#24773#20917#32479#35745
      ImageIndex = 1
      object Label13: TLabel
        Left = 56
        Top = 16
        Width = 40
        Height = 16
        AutoSize = False
        Caption = #39034#24207
      end
      object Label14: TLabel
        Left = 216
        Top = 16
        Width = 81
        Height = 16
        AutoSize = False
        Caption = #25490#24207#20851#38190#35789
      end
      object ComboBox12: TComboBox
        Left = 120
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 0
        Text = #21319#24207
        Items.Strings = (
          #21319#24207
          #38477#24207)
      end
      object ComboBox13: TComboBox
        Left = 304
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        TabOrder = 1
        Text = 'IBSN'
        Items.Strings = (
          'IBSN'
          #37319#36141#25968#37327)
      end
      object Button7: TButton
        Left = 416
        Top = 8
        Width = 57
        Height = 33
        Caption = #32479#35745
        TabOrder = 2
        OnClick = Button7Click
      end
    end
    object TabSheet11: TTabSheet
      Caption = #36817#26399#28120#27760#24773#20917#32479#35745
      ImageIndex = 2
      object Label15: TLabel
        Left = 56
        Top = 16
        Width = 40
        Height = 16
        AutoSize = False
        Caption = #39034#24207
      end
      object Label16: TLabel
        Left = 216
        Top = 16
        Width = 89
        Height = 16
        AutoSize = False
        Caption = #25490#24207#20851#38190#35789
      end
      object ComboBox14: TComboBox
        Left = 120
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 0
        Text = #21319#24207
        Items.Strings = (
          #21319#24207
          #38477#24207)
      end
      object ComboBox15: TComboBox
        Left = 304
        Top = 16
        Width = 81
        Height = 24
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 1
        Text = 'IBSN'
        Items.Strings = (
          'IBSN'
          #28120#27760#25968#37327)
      end
      object Button8: TButton
        Left = 416
        Top = 8
        Width = 57
        Height = 33
        Caption = #32479#35745
        TabOrder = 2
        OnClick = Button8Click
      end
    end
  end
  object DBGrid1: TDBGrid
    Left = 120
    Top = 136
    Width = 953
    Height = 361
    DataSource = DataSource1
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Visible = False
  end
  object ActionPage: TPageControl
    Left = 120
    Top = 48
    Width = 953
    Height = 241
    ActivePage = TabSheet15
    TabOrder = 3
    Visible = False
    object TabSheet6: TTabSheet
      Caption = #20511#38405
      object Label21: TLabel
        Left = 296
        Top = 56
        Width = 65
        Height = 16
        AutoSize = False
        Caption = #26465#30721#21495
      end
      object Label22: TLabel
        Left = 224
        Top = 16
        Width = 393
        Height = 25
        AutoSize = False
        Caption = #35831#36755#20837#24744#30340#26465#30721#21495#65292#30830#35748#20934#30830#26080#35823#21518#65292#25353#19979#20511#38405#38190
      end
      object Edit3: TEdit
        Left = 392
        Top = 56
        Width = 161
        Height = 24
        TabOrder = 0
      end
      object Button11: TButton
        Left = 608
        Top = 96
        Width = 81
        Height = 41
        Caption = #20511#38405
        TabOrder = 1
        OnClick = Button11Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = #24402#36824
      ImageIndex = 1
      object Label23: TLabel
        Left = 296
        Top = 56
        Width = 57
        Height = 16
        AutoSize = False
        Caption = #26465#30721#21495
      end
      object Label24: TLabel
        Left = 224
        Top = 16
        Width = 393
        Height = 25
        AutoSize = False
        Caption = #35831#36755#20837#24744#30340#26465#30721#21495#65292#30830#35748#20934#30830#26080#35823#21518#65292#25353#19979#24402#36824#38190
      end
      object Edit4: TEdit
        Left = 392
        Top = 56
        Width = 161
        Height = 24
        TabOrder = 0
      end
      object Button12: TButton
        Left = 608
        Top = 96
        Width = 81
        Height = 41
        Caption = #24402#36824
        TabOrder = 1
        OnClick = Button12Click
      end
    end
    object TabSheet15: TTabSheet
      Caption = #26597#35810#20010#20154#26410#36824#20070#31821
      ImageIndex = 4
      object DBGrid2: TDBGrid
        Left = 64
        Top = 96
        Width = 793
        Height = 89
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -13
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object Button13: TButton
        Left = 352
        Top = 24
        Width = 97
        Height = 41
        Caption = #26597#35810
        TabOrder = 1
        OnClick = Button13Click
      end
    end
  end
  object Button14: TButton
    Left = 1080
    Top = 616
    Width = 145
    Height = 65
    Caption = #36864#20986#30331#24405
    TabOrder = 4
    OnClick = Button14Click
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 56
    object N1: TMenuItem
      Caption = #26597#35810
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #25805#20316
      OnClick = N2Click
    end
    object N3: TMenuItem
      Caption = #32479#35745
      OnClick = N3Click
    end
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=student;Persist Security Info=True;' +
      'User ID=student;Initial Catalog=student;Data Source=202.38.88.99' +
      ',1434'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 24
    Top = 104
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 24
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 64
    Top = 136
  end
end
