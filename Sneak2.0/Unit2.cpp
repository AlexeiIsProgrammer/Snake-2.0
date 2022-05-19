//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit15.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

 extern int number;
 extern int apples;
 extern int winner;

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if(Edit1->Text!="" && number==0)
	{
		Form1->ADOQuery1->Insert();
		Form1->ADOQuery1->Fields->FieldByName("Имя")->AsString=Edit1->Text;
		Form1->ADOQuery1->Fields->FieldByName("Яблок")->AsString=apples;
		Form1->ADOQuery1->Fields->FieldByName("Дата")->AsString=Now().DateString()+" "+Now().TimeString();
		Form1->ADOQuery1->Post();
		Edit1->Text="";
	}

	Form15->MediaPlayer1->Stop();
	apples=-1;
	Form2->Close();
	Form1->Show();
	Edit1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	if(Edit1->Text!="")
	{
		if(number==0)
		{
			Form15->Timer1->Enabled=true;
		}
		if(number==1)
		{
			Form15->Timer1->Enabled=true;
			Form15->Timer2->Enabled=true;
		}
		Form2->Close();
		Form15->Show();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{
    Label3->Color=clYellow;
	if(number==1)
	{
		Edit1->Visible=false;
	}
	if(winner == 5)
	{
        Label3->Caption="Поздравляю, вы дошли до конца змейки, Вы Гений!!";
	}
	if(winner==-1)
	{
		Label3->Caption="Ничья!";
	}
	if(winner==0)
	{
		Label3->Caption="Вы проиграли!";
	}
	if(winner==1)
	{
		Label3->Caption="Игрок 1 выиграл!";
	}
	if(winner==2)
	{
		Label3->Caption="Игрок 2 выиграл!";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Edit1->Text.Length()<7 || Key==VK_BACK)
	{
	  return;
	}
    Key=0;
}
//---------------------------------------------------------------------------

