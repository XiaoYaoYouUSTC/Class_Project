unit Login;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, DB, ADODB;

type
  TLoginForm = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    ADOConnection1: TADOConnection;
    ADOQuery1: TADOQuery;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  LoginForm: TLoginForm;

implementation

uses Manager, User;

{$R *.dfm}

procedure TLoginForm.Button1Click(Sender: TObject);
var
s:string;
begin
  adoquery1.Close;
  adoquery1.sql.Clear ;
  s:='select * from PB18000051student where ѧ����=''';
  s:=s+edit1.text;
  s:=s+''' and ����=''';
  s:=s+edit2.text;
  s:=s+'''';
  adoquery1.sql.Add(s) ;
  adoquery1.open;
  if(adoquery1.RecordCount =0)then
    showmessage('��½ʧ��');
  if(adoquery1.FieldByName('����').AsString='����Ա') then
    begin
      ManagerForm.show;
      LoginForm.hide;
    end;
  if(adoquery1.FieldByName('����').AsString='��ͨ�û�')then
    begin
      UserForm.show;
      LoginForm.hide;
    end;
end;

end.
