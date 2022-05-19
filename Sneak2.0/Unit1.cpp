//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit15.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
extern int mode=0;
extern int number=0;
extern int bars=0;
int choose;
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	Form1->ClientHeight=438;
	Form1->ClientWidth=813;
	MediaPlayer1->FileName="xxx.wav";
	Image2->Canvas->Brush->Color=RGB(174, 163, 164);
	Image3->Canvas->Brush->Color=RGB(174, 163, 164);
	Image4->Canvas->Brush->Color=RGB(174, 163, 164);
	Image5->Canvas->Brush->Color=RGB(174, 163, 164);
	Image6->Canvas->Brush->Color=RGB(174, 163, 164);
	Image6->Canvas->FillRect(Rect(0,0,Image5->Width,Image5->Height));
	Image5->Canvas->FillRect(Rect(0,0,Image5->Width,Image5->Height));
	Image2->Canvas->FillRect(Rect(0,0,Image2->Width,Image2->Height));
	Image3->Canvas->FillRect(Rect(0,0,Image3->Width,Image3->Height));
	Image4->Canvas->FillRect(Rect(0,0,Image4->Width,Image4->Height));
	Image2->Canvas->Font->Size=28;
	Image2->Canvas->Font->Color=RGB (105, 105, 105);
	Image2->Canvas->Font->Name="Lilita One Rus";
	Image2->Canvas->TextOut(50,-5,"Play");
	Image4->Canvas->Font->Size=28;
	Image4->Canvas->Font->Color=RGB (105, 105, 105);
	Image4->Canvas->Font->Name="Lilita One Rus";
	Image4->Canvas->TextOut(13,-5,"Settings");
	Image3->Canvas->Font->Size=28;
	Image3->Canvas->Font->Color=RGB (105, 105, 105);
	Image3->Canvas->Font->Name="Lilita One Rus";
	Image3->Canvas->TextOut(15,-5,"Leaders");
	Image5->Canvas->Font->Size=28;
	Image5->Canvas->Font->Color=RGB(105, 105, 105);
	Image5->Canvas->Font->Name="Lilita One Rus";
	Image5->Canvas->TextOut(13,-5,"1 player");
	Image6->Canvas->Font->Size=28;
	Image6->Canvas->Font->Color=RGB(105, 105, 105);
	Image6->Canvas->Font->Name="Lilita One Rus";
	Image6->Canvas->TextOut(13,-5,"2 player");
	Image7->Canvas->Brush->Color=RGB(174, 163, 164);
	Image7->Canvas->FillRect(Rect(0,0,Image7->Width,Image7->Height));
	Image7->Canvas->Font->Size=28;
	Image7->Canvas->Font->Color=RGB(105, 105, 105);
	Image7->Canvas->Font->Name="Lilita One Rus";
	Image7->Canvas->TextOut(57,-5,"Box");
    Image8->Canvas->Brush->Color=RGB(174, 163, 164);
	Image8->Canvas->FillRect(Rect(0,0,Image8->Width,Image8->Height));
	Image8->Canvas->Font->Size=28;
	Image8->Canvas->Font->Color=RGB(105, 105, 105);
	Image8->Canvas->Font->Name="Lilita One Rus";
	Image8->Canvas->TextOut(15,-5,"Infinity");
	Image9->Canvas->Brush->Color=RGB(174, 163, 164);
	Image9->Canvas->FillRect(Rect(0,0,Image9->Width,Image9->Height));
	Image9->Canvas->Font->Size=28;
	Image9->Canvas->Font->Color=RGB(105, 105, 105);
	Image9->Canvas->Font->Name="Lilita One Rus";
	Image9->Canvas->TextOut(15,-5,"NO Bareers");
	Image10->Canvas->Brush->Color=RGB(174, 163, 164);
	Image10->Canvas->FillRect(Rect(0,0,Image10->Width,Image10->Height));
	Image10->Canvas->Font->Size=28;
	Image10->Canvas->Font->Color=RGB(105, 105, 105);
	Image10->Canvas->Font->Name="Lilita One Rus";
	Image10->Canvas->TextOut(60,-5,"Bareers");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseEnter(TObject *Sender)
{
	Image2->Canvas->Brush->Color=RGB(140, 125, 127);
	Image2->Canvas->FillRect(Rect(0,0,Image2->Width,Image2->Height));
	Image2->Canvas->Font->Size=28;
	Image2->Canvas->Font->Color=RGB (95, 83, 83);
	Image2->Canvas->Font->Name="Lilita One Rus";
	Image2->Canvas->TextOut(50,-5,"Play");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseLeave(TObject *Sender)
{
	Image2->Canvas->Brush->Color=RGB (174, 163, 164);
	Image2->Canvas->FillRect(Rect(0,0,Image2->Width,Image2->Height));
	Image2->Canvas->Font->Size=28;
	Image2->Canvas->Font->Color=RGB (105, 105, 105);
	Image2->Canvas->Font->Name="Lilita One Rus";
	Image2->Canvas->TextOut(50,-5,"Play");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseEnter(TObject *Sender)
{
	Image3->Canvas->Brush->Color=RGB(140, 125, 127);
	Image3->Canvas->FillRect(Rect(0,0,Image3->Width,Image3->Height));
	Image3->Canvas->Font->Size=28;
	Image3->Canvas->Font->Color=RGB (95, 83, 83);
	Image3->Canvas->Font->Name="Lilita One Rus";
	Image3->Canvas->TextOut(15,-5,"Leaders");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseLeave(TObject *Sender)
{
	Image3->Canvas->Brush->Color=RGB (174, 163, 164);
	Image3->Canvas->FillRect(Rect(0,0,Image3->Width,Image3->Height));
	Image3->Canvas->Font->Size=28;
	Image3->Canvas->Font->Color=RGB (105, 105, 105);
	Image3->Canvas->Font->Name="Lilita One Rus";
	Image3->Canvas->TextOut(15,-5,"Leaders");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseEnter(TObject *Sender)
{
	Image4->Canvas->Brush->Color=RGB(140, 125, 127);
	Image4->Canvas->FillRect(Rect(0,0,Image4->Width,Image4->Height));
	Image4->Canvas->Font->Size=28;
	Image4->Canvas->Font->Color=RGB (95, 83, 83);
	Image4->Canvas->Font->Name="Lilita One Rus";
	Image4->Canvas->TextOut(13,-5,"Settings");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseLeave(TObject *Sender)
{
	Image4->Canvas->Brush->Color=RGB (174, 163, 164);
	Image4->Canvas->FillRect(Rect(0,0,Image4->Width,Image4->Height));
	Image4->Canvas->Font->Size=28;
	Image4->Canvas->Font->Color=RGB (105, 105, 105);
	Image4->Canvas->Font->Name="Lilita One Rus";
	Image4->Canvas->TextOut(13,-5,"Settings");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
	Image2->Visible=false;
	Image3->Visible=false;
	Image4->Visible=false;
	Image5->Visible=true;
	Image6->Visible=true;
	Image12->Visible=true;
	choose = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
	number = 0;
	Form15->Image1->Canvas->Brush->Color=clGray;
	Form15->Image1->Canvas->Pen->Color=clGray;
	Form15->Image1->Canvas->Rectangle(0,0,Form15->Image1->ClientWidth,Form15->Image1->ClientHeight);
	Form15->ClientHeight=300;
	Form15->ClientWidth=300;
	Form15->Image1->ClientHeight=Form15->ClientHeight;
	Form15->Image1->ClientWidth=Form15->ClientWidth;
	Form15->Image1->Top=0;
	Form15->Image1->Left=0;
	Image5->Visible=false;
	Image6->Visible=false;
	Image7->Visible=true;
	Image8->Visible=true;
	choose=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseEnter(TObject *Sender)
{
	Image5->Canvas->Brush->Color=RGB(140, 125, 127);
	Image5->Canvas->FillRect(Rect(0,0,Image5->Width,Image5->Height));
	Image5->Canvas->Font->Size=28;
	Image5->Canvas->Font->Color=RGB(95, 83, 83);
	Image5->Canvas->Font->Name="Lilita One Rus";
	Image5->Canvas->TextOut(13,-5,"1 player");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseLeave(TObject *Sender)
{
	Image5->Canvas->Brush->Color=RGB(174, 163, 164);
	Image5->Canvas->FillRect(Rect(0,0,Image5->Width,Image5->Height));
	Image5->Canvas->Font->Size=28;
	Image5->Canvas->Font->Color=RGB(105, 105, 105);
	Image5->Canvas->Font->Name="Lilita One Rus";
	Image5->Canvas->TextOut(13,-5,"1 player");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6MouseEnter(TObject *Sender)
{
   Image6->Canvas->Brush->Color=RGB(140, 125, 127);
	Image6->Canvas->FillRect(Rect(0,0,Image6->Width,Image6->Height));
	Image6->Canvas->Font->Size=28;
	Image6->Canvas->Font->Color=RGB(95, 83, 83);
	Image6->Canvas->Font->Name="Lilita One Rus";
	Image6->Canvas->TextOut(13,-5,"2 player");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6MouseLeave(TObject *Sender)
{
Image6->Canvas->Brush->Color=RGB(174, 163, 164);
	Image6->Canvas->FillRect(Rect(0,0,Image6->Width,Image6->Height));
	Image6->Canvas->Font->Size=28;
	Image6->Canvas->Font->Color=RGB(105, 105, 105);
	Image6->Canvas->Font->Name="Lilita One Rus";
	Image6->Canvas->TextOut(13,-5,"2 player");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
    number = 1;
	Form15->Image1->Canvas->Brush->Color=clGray;
	Form15->Image1->Canvas->Pen->Color=clGray;
	Form15->Image1->Canvas->Rectangle(0,0,Form15->Image1->ClientWidth,Form15->Image1->ClientHeight);
	Form15->ClientHeight=600;
	Form15->ClientWidth=600;
	Form15->Image1->ClientHeight=Form15->ClientHeight;
	Form15->Image1->ClientWidth=Form15->ClientWidth;
	Form15->Image1->Top=0;
	Form15->Image1->Left=0;
	Image5->Visible=false;
	Image6->Visible=false;
	Image7->Visible=true;
	Image8->Visible=true;
	choose=3;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image7MouseEnter(TObject *Sender)
{
	Image7->Canvas->Brush->Color=RGB(140, 125, 127);
	Image7->Canvas->FillRect(Rect(0,0,Image7->Width,Image7->Height));
	Image7->Canvas->Font->Size=28;
	Image7->Canvas->Font->Color=RGB(95, 83, 83);
	Image7->Canvas->Font->Name="Lilita One Rus";
	Image7->Canvas->TextOut(57,-5,"Box");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7MouseLeave(TObject *Sender)
{
		Image7->Canvas->Brush->Color=RGB(174, 163, 164);
	Image7->Canvas->FillRect(Rect(0,0,Image7->Width,Image7->Height));
	Image7->Canvas->Font->Size=28;
	Image7->Canvas->Font->Color=RGB(105, 105, 105);
	Image7->Canvas->Font->Name="Lilita One Rus";
	Image7->Canvas->TextOut(57,-5,"Box");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8MouseEnter(TObject *Sender)
{
	Image8->Canvas->Brush->Color=RGB(140, 125, 127);
	Image8->Canvas->FillRect(Rect(0,0,Image8->Width,Image8->Height));
	Image8->Canvas->Font->Size=28;
	Image8->Canvas->Font->Color=RGB(95, 83, 83);
	Image8->Canvas->Font->Name="Lilita One Rus";
	Image8->Canvas->TextOut(15,-5,"Infinity");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8MouseLeave(TObject *Sender)
{
	Image8->Canvas->Brush->Color=RGB(174, 163, 164);
	Image8->Canvas->FillRect(Rect(0,0,Image8->Width,Image8->Height));
	Image8->Canvas->Font->Size=28;
	Image8->Canvas->Font->Color=RGB(105, 105, 105);
	Image8->Canvas->Font->Name="Lilita One Rus";
	Image8->Canvas->TextOut(15,-5,"Infinity");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
	 mode = 0;
	 Image7->Visible=false;
	Image8->Visible=false;
	if(number==1)
	{
		Image9->Visible=true;
		Image10->Visible=true;
	}
	if(number==0)
	{
		Image2->Visible=true;
		Image3->Visible=true;
		Image4->Visible=true;
		Image12->Visible=false;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Pen->Color=clGray;
		Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

		Form1->Hide();
		Form15->Show();
	}
	choose=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
	mode=1;

	Image7->Visible=false;
	Image8->Visible=false;
	if(number==1)
	{
		Image9->Visible=true;
		Image10->Visible=true;
	}
	if(number==0)
	{
		Image2->Visible=true;
		Image3->Visible=true;
		Image4->Visible=true;
		Image12->Visible=false;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Pen->Color=clGray;
		Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
		Form1->Hide();
		Form15->Show();
	}
	choose=4;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image10MouseLeave(TObject *Sender)
{
	Image10->Canvas->Brush->Color=RGB(174, 163, 164);
	Image10->Canvas->FillRect(Rect(0,0,Image10->Width,Image10->Height));
	Image10->Canvas->Font->Size=28;
	Image10->Canvas->Font->Color=RGB(105, 105, 105);
	Image10->Canvas->Font->Name="Lilita One Rus";
	Image10->Canvas->TextOut(60,-5,"Bareers");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9MouseLeave(TObject *Sender)
{
	Image9->Canvas->Brush->Color=RGB(174, 163, 164);
	Image9->Canvas->FillRect(Rect(0,0,Image9->Width,Image9->Height));
	Image9->Canvas->Font->Size=28;
	Image9->Canvas->Font->Color=RGB(105, 105, 105);
	Image9->Canvas->Font->Name="Lilita One Rus";
	Image9->Canvas->TextOut(15,-5,"NO Bareers");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9MouseEnter(TObject *Sender)
{
	Image9->Canvas->Brush->Color=RGB(140, 125, 127);
	Image9->Canvas->FillRect(Rect(0,0,Image9->Width,Image9->Height));
	Image9->Canvas->Font->Size=28;
	Image9->Canvas->Font->Color=RGB(95, 83, 83);
	Image9->Canvas->Font->Name="Lilita One Rus";
	Image9->Canvas->TextOut(15,-5,"NO Bareers");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10MouseEnter(TObject *Sender)
{
	Image10->Canvas->Brush->Color=RGB(140, 125, 127);
	Image10->Canvas->FillRect(Rect(0,0,Image10->Width,Image10->Height));
	Image10->Canvas->Font->Size=28;
	Image10->Canvas->Font->Color=RGB(95, 83, 83);
	Image10->Canvas->Font->Name="Lilita One Rus";
	Image10->Canvas->TextOut(60,-5,"Bareers");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
	bars=0;
	Image9->Visible=false;
	Image10->Visible=false;
	Image2->Visible=true;
	Image3->Visible=true;
	Image4->Visible=true;
	Image12->Visible=false;
	Form15->Image1->Canvas->Brush->Color=clGray;
	Form15->Image1->Canvas->Pen->Color=clGray;
	Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
	Form1->Hide();
	Form15->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
	bars=1;
	Image9->Visible=false;
	Image10->Visible=false;
	Image2->Visible=true;
	Image3->Visible=true;
	Image4->Visible=true;

	Image12->Visible=false;
	Form15->Image1->Canvas->Brush->Color=clGray;
	Form15->Image1->Canvas->Pen->Color=clGray;
	Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
	Form1->Hide();
	Form15->Show();
}
//---------------------------------------------------------------------------



extern bool onoff=false;

void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
	if(onoff)
		MediaPlayer1->Play();
	else
		MediaPlayer1->Stop();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image3Click(TObject *Sender)
{
	choose = 1;
	Image2->Visible=false;
	Image4->Visible=false;
	Image3->Visible=false;
	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="SELECT * FROM Recordi ORDER BY Яблок DESC";
	ADOQuery1->Active=true;
	Image13->Visible=true;
	Image14->Visible=true;
	Image15->Visible=true;
	DBEdit1->Visible=true;
	DBEdit2->Visible=true;
	DBEdit3->Visible=true;
	DBRichEdit1->Visible=true;
	DBRichEdit2->Visible=true;
	DBRichEdit3->Visible=true;
	DBText1->Visible=true;
	DBText2->Visible=true;
	DBText3->Visible=true;
	Label5->Visible=true;
	Label6->Visible=true;
	Label7->Visible=true;
	Label8->Visible=true;
	Shape1->Visible=true;
	Shape2->Visible=true;
	ADOQuery1->First();
	if(!ADOQuery1->Eof)
	{
		DBEdit1->Text=ADOQuery1->Fields->FieldByName("Имя")->AsString;
		DBText1->Caption=ADOQuery1->Fields->FieldByName("Яблок")->AsInteger;
		DBRichEdit1->Text=ADOQuery1->Fields->FieldByName("Дата")->AsString;
		ADOQuery1->Next();
		if(!ADOQuery1->Eof)
		{

			DBEdit2->Text=ADOQuery1->Fields->FieldByName("Имя")->AsString;
			DBText2->Caption=ADOQuery1->Fields->FieldByName("Яблок")->AsInteger;
			DBRichEdit2->Text=ADOQuery1->Fields->FieldByName("Дата")->AsString;
			ADOQuery1->Next();
			if(!ADOQuery1->Eof)
			{

				DBEdit3->Text=ADOQuery1->Fields->FieldByName("Имя")->AsString;
				DBText3->Caption=ADOQuery1->Fields->FieldByName("Яблок")->AsInteger;
				DBRichEdit3->Text=ADOQuery1->Fields->FieldByName("Дата")->AsString;
				DBEdit3->Visible=true;

			}

		}
	}
    Image12->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
	choose = 0;
	Image2->Visible=false;
	Image4->Visible=false;
	Image3->Visible=false;
	ColorBox1->Visible=true;
	ColorBox2->Visible=true;
	Label2->Visible=true;
	Label3->Visible=true;
	Image12->Visible=true;
	RadioGroup1->Visible=true;
	RadioGroup2->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12Click(TObject *Sender)
{

	if (choose==0)
	{
		Image2->Visible=true;
		Image4->Visible=true;
		Image3->Visible=true;
		ColorBox1->Visible=false;
		ColorBox2->Visible=false;
		Label2->Visible=false;
		Label3->Visible=false;
		Image12->Visible=false;
		RadioGroup1->Visible=false;
		RadioGroup2->Visible=false;
	}
		if (choose==1)
		{
			Image2->Visible=true;
			Image4->Visible=true;
			Image3->Visible=true;
			Image13->Visible=false;
			Image14->Visible=false;
			Image15->Visible=false;
			DBEdit1->Visible=false;
			DBEdit2->Visible=false;
			DBEdit3->Visible=false;
			DBRichEdit1->Visible=false;
			DBRichEdit2->Visible=false;
			DBRichEdit3->Visible=false;
			DBText1->Visible=false;
			DBText2->Visible=false;
			DBText3->Visible=false;
			Label5->Visible=false;
			Label6->Visible=false;
			Label7->Visible=false;
			Label8->Visible=false;
			Shape1->Visible=false;
			Shape2->Visible=false;
			Image12->Visible=false;
		}
		if(choose==2)
		{
			Image12->Visible=false;
			Image2->Visible=true;
			Image3->Visible=true;
			Image4->Visible=true;
			Image5->Visible=false;
			Image6->Visible=false;
		}
		if(choose==3)
		{
			choose=2;
			Image5->Visible=true;
			Image6->Visible=true;
			Image7->Visible=false;
			Image8->Visible=false;
		}
		if(choose==4)
		{
			choose=3;
			Image7->Visible=true;
			Image8->Visible=true;
			Image9->Visible=false;
			Image10->Visible=false;
		}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	if(RadioGroup1->ItemIndex==0)
	{
		Form15->Timer1->Interval=150;
		Form15->Timer2->Interval=150;
	}
	if(RadioGroup1->ItemIndex==1)
	{
		Form15->Timer1->Interval=100;
		Form15->Timer2->Interval=100;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
   if(RadioGroup2->ItemIndex==0)
   {
	MediaPlayer1->FileName="не от мира сего.wav";
	MediaPlayer1->Open();
   }
   else{
	   if(RadioGroup2->ItemIndex==1)
	   {
		MediaPlayer1->FileName="зеленые.wav";
		MediaPlayer1->Open();
	   }
	   else
	   {
		   if(RadioGroup2->ItemIndex==2)
		   {

			MediaPlayer1->FileName="xxx.wav";
			MediaPlayer1->Open();
		   }
		   else
		   {
			   if(RadioGroup2->ItemIndex==3)
			   {
				MediaPlayer1->FileName="сентябрь.wav";
				MediaPlayer1->Open();
			   }
			   else
			   {
				   if(RadioGroup2->ItemIndex==4)
				   {
					MediaPlayer1->FileName="фонк.wav";
					MediaPlayer1->Open();
				   }
				   else
				   {
					   if(RadioGroup2->ItemIndex==5)
					   {
						MediaPlayer1->FileName="жизнь.wav";
						MediaPlayer1->Open();
					   }
				   }
			   }
		   }
	   }
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image12MouseEnter(TObject *Sender)
{
	Image12->Picture->LoadFromFile("back1.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12MouseLeave(TObject *Sender)
{
   Image12->Picture->LoadFromFile("back.png");
}
//---------------------------------------------------------------------------

