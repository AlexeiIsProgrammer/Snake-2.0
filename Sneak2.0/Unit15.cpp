//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit15.h"
#include "Unit2.h"
#include "Unit1.h"
#include <ctime>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm15 *Form15;
//---------------------------------------------------------------------------

__fastcall TForm15::TForm15(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

extern int mode;
extern int number;
extern int bars;
extern int apples=-1;
extern int winner=-1;
extern bool onoff;

int out=0;

bool Start=true;

int global=4;
int global1=4;

int sw=1;
int sw1=2;

struct now
{
	float n_x;
	float n_y;
	float n_x1;
	float n_y1;
};

now Part[576];
now Sneak[576];

int randx;
int randy;
int randx1;
int randy1;

void go(now Part[256], int global, bool color)
{
	for(int i=global;i>0;i--)
	{
		if(color)
		  Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
		  Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
	  Part[i].n_x=Part[i-1].n_x;
	  Part[i].n_x1=Part[i-1].n_x1;
	  Part[i].n_y=Part[i-1].n_y;
	  Part[i].n_y1=Part[i-1].n_y1;
	  Form15->Image1->Canvas->Rectangle(Part[i].n_x,Part[i].n_y,Part[i].n_x1,Part[i].n_y1);
	}
}

void spawn_music()
{
	Form15->MediaPlayer1->FileName="sound.wav";
	Form15->MediaPlayer1->Open();
	Form15->MediaPlayer1->Play();
}
void Obnul()
{
	Form15->Image1->Canvas->Brush->Color=clGray;
	Form15->Image1->Canvas->Pen->Color=clGray;
	Form15->Image1->Canvas->Rectangle(0,0,Form15->Image1->Width,Form15->Image1->Height);
	onoff=false;
	Form1->MediaPlayer1->Stop();
	Form15->Timer1->Enabled=false;
	Form15->Timer2->Enabled=false;

	spawn_music();

	Start=true;

	global=4;
	global1=4;
	sw=1;
	sw1=2;
	 for(int i=1;i<=global;i++)
	{
		Part[i].n_x=0;
		Part[i].n_y=0;
		Part[i].n_x1=0;
		Part[i].n_y1=0;
	}

   if(number==1)
   {
		for(int i=1;i<=global1;i++)
		{
			Sneak[i].n_x=1;
			Sneak[i].n_y=1;
			Sneak[i].n_x1=1;
			Sneak[i].n_y1=1;
		}
	}
	Form2->Label2->Caption=IntToStr(apples);
	Form2->Show();
	Form15->Hide();
}

void add_tale(float x, float y, float x1, float y1, now Part[256], int & global)
{
	++global;
	Part[global].n_x+=x;
	Part[global].n_y+=y;
	Part[global].n_x1+=x1;
	Part[global].n_y1+=y1;
}

void spawn_apple(now Part[256], int & global)
{
	int s;
	if(number==0)
	{
		s=12;
	}
	if(number==1)
	{
		s=24;
	}
	bool a = true;
	srand(time(0));
	while(true){
		a = true;

		randx1 = rand()%s+1;
		randx1=randx1*25;

		randy1 =rand()%s+1;
		randy1=randy1*25;

		randx = randx1-25;

		randy=randy1-25;

		for(int i=0;i<=global;i++)
		{
			if(global==144 && number == 0)
			{
				winner = 5;
				Obnul();
			   return;
			}
			if(randx == Part[i].n_x && randy==Part[i].n_y &&randx1==Part[i].n_x1 &&randy1==Part[i].n_y1)
			{

				a = false;
			}
			if(bars==1)
			{
				if((randx >=50 && randx1<=75 && randy>=25 && randy1<=200)
				||(randx >=175 && randx1<=200 && randy>=0 && randy1<=50)
				||(randx >=175 && randx1<=200 && randy>=75 && randy1<=125)
				||(randx >=150 && randx1<=225 && randy>=125 && randy1<=175)
				||(randx >=150 && randx1<=175 && randy>=300 && randy1<=450)
				||(randx >=200 && randx1<=175 && randy>=450 && randy1<=475)
				||(randx >=50 && randx1<=150 && randy>=425 && randy1<=450)
				||(randx >=150 && randx1<=275 && randy>=450 && randy1<=475)
				||(randx >=250 && randx1<=300 &&randy>=475 && randy1<=500)
				||(randx >=275 && randx1<=325 && randy>=500 && randy1<=525)
				||(randx >=300 && randx1<=325 && randy>=250 && randy1<=275)
				||(randx >=325 && randx1<=350 && randy>=275 && randy1<=300)
				||(randx >=350 && randx1<=375 &&randy>=300 && randy1<=325)
				||(randx >=375 && randx1<=400 && randy>=325 && randy1<=350)
				||(randx >=400 && randx1<=600 && randy>=150 && randy1<=175)
				||(randx >=400 && randx1<=425 && randy>=100 && randy1<=150)
				||(randx >=500 && randx1<=525 && randy>=500 && randy1<=600))
				{
				   a=false;
				}
			}
		}
		if (a)
		{
				Graphics::TBitmap *bitmap=new Graphics::TBitmap;
				bitmap->LoadFromFile("apple.bmp");
				apples++;
				Form15->Image1->Canvas->Brush->Color=clGray;
				Form15->Image1->Canvas->Pen->Color=clGray;
				bitmap->Canvas->StretchDraw(Rect(0,0,25,25),bitmap);
				bitmap->Width=25;
				bitmap->Height=25;
				Form15->Image1->Canvas->Draw(randx,randy,bitmap);
				delete bitmap;
				return;

		}
	}

}

	void ad(now Part[256], int & global)
   {
	   if(Part[0].n_x ==randx && Part[0].n_x1==randx1  && Part[0].n_y ==randy&&Part[0].n_y1==randy1)
	  {
			switch(sw)
			{
				case 1:
				add_tale(25,0,25,0,Part,global);
				break;
				case 2:
				add_tale(-25,0,-25,0,Part,global);
				break;
				case 3:
				add_tale(0,25,0,25,Part,global);
				break;
				case 4:
				add_tale(0,-25,0,-25,Part,global);
				break;
			}
			spawn_apple(Part, global);
	  }
   }

void otrisovka_up(now Part[256], int global, bool color)
{
	if(mode==0)
	{
		if(Part[0].n_y-25>=0)
		{
			Part[0].n_y-=25;
			Part[0].n_y1-=25;
			Form15->Image1->Canvas->Brush->Color=clGray;
			Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
			if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
			else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		}
		else
		{
			if(color)
			{
				if(number==1)
					winner = 2;
				else
					winner = 0;
			}
			else
				winner = 1;
			Obnul();
		}
	}
	if(mode==1)
	{
	   if(Part[0].n_y-25>=0)
	   {
		Part[0].n_y-=25;
		Part[0].n_y1-=25;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
		if(color)
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
	   }
	   else
	   {
		Part[0].n_y=Form15->Image1->ClientHeight-25;
		Part[0].n_y1=Form15->Image1->ClientHeight;
		if(color)
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Pen->Color=clGray;
		Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
	   }
	}

}

void otrisovka_down(now Part[256], int global, bool color)
{
	if(mode==0)
	{
		if(Part[0].n_y1+25<=Form15->Image1->ClientHeight)
		{
			Part[0].n_y+=25;
			Part[0].n_y1+=25;

			Form15->Image1->Canvas->Brush->Color=clGray;
			Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
			if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
			else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		}
		else
		{
			if(color)
			{
				if(number==1)
					winner = 2;
				else
					winner = 0;
			}
			else
				winner = 1;
			Obnul();
		}
	}
	if(mode==1)
	{
	   if(Part[0].n_y1+25<=Form15->Image1->ClientHeight)
	   {
		Part[0].n_y+=25;
		Part[0].n_y1+=25;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
		if(color)
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
	   }
	   else
	   {
		   Part[0].n_y=0;
		   Part[0].n_y1=25;
		   if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		   else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		   Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		   Form15->Image1->Canvas->Brush->Color=clGray;
		   Form15->Image1->Canvas->Pen->Color=clGray;
		   Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
	   }
	}
}

void otrisovka_left(now Part[256], int global, bool color)
{
	if(mode==0)
	{
		if(Part[0].n_x-25>=0)
		{
			Part[0].n_x-=25;
			Part[0].n_x1-=25;

			Form15->Image1->Canvas->Brush->Color=clGray;
			Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
			if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
			else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		}
		else
		{
			if(color)
			{
					if(number==1)
						winner = 2;
					else
						winner = 0;
			}
			else
				winner = 1;
			Obnul();
		}
	}
	if(mode==1)
	{
	   if(Part[0].n_x-25>=0){
		Part[0].n_x-=25;
		Part[0].n_x1-=25;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
		if(color)
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
	   }
	   else
	   {
		   Part[0].n_x=Form15->Image1->ClientWidth-25;
		   Part[0].n_x1=Form15->Image1->ClientWidth;
		   if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		   else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		   Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		   Form15->Image1->Canvas->Brush->Color=clGray;
		   Form15->Image1->Canvas->Pen->Color=clGray;
		   Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
	   }
	}
}

void otrisovka_right(now Part[256], int global, bool color)
{
	if(mode==0)
	{
		if(Part[0].n_x1+25<=Form15->Image1->ClientWidth)
		{
			Part[0].n_x+=25;
			Part[0].n_x1+=25;

			Form15->Image1->Canvas->Brush->Color=clGray;
			Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
			if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
			else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		}
		else
		{
			if(color)
			{
				if(number==1)
					winner = 2;
				else
					winner = 0;
			}
			else
				winner = 1;
			Obnul();
		}
	}
	if(mode==1)
	{
	   if(Part[0].n_x1+25<=Form15->Image1->ClientWidth)
	   {
		Part[0].n_x+=25;
		Part[0].n_x1+=25;
		Form15->Image1->Canvas->Brush->Color=clGray;
		Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
		if(color)
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		else
			Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
	   }
	   else
	   {
		   Part[0].n_x=0;
		   Part[0].n_x1=25;
		   if(color)
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		   else
				Form15->Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		   Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		   Form15->Image1->Canvas->Brush->Color=clGray;
		   Form15->Image1->Canvas->Pen->Color=clGray;
		   Form15->Image1->Canvas->Rectangle(Part[global].n_x,Part[global].n_y,Part[global].n_x1,Part[global].n_y1);
	   }
	}
}

void otrisovka_face(now Part[256], int global, int sw)
{
	if(sw==1)
	{
		Form15->Image1->Canvas->Brush->Color=clBlack;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y+5,Part[0].n_x1-15,Part[0].n_y1-15);
		Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y+15,Part[0].n_x1-15,Part[0].n_y1-5);
		Form15->Image1->Canvas->Brush->Color=clRed;
		Form15->Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y+5,Part[0].n_x1-20,Part[0].n_y1-5);
	}
	else
		if(sw==2)
		{
			Form15->Image1->Canvas->Brush->Color=clBlack;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x+15,Part[0].n_y+5,Part[0].n_x1-5,Part[0].n_y1-15);
			Form15->Image1->Canvas->Rectangle(Part[0].n_x+15,Part[0].n_y+15,Part[0].n_x1-5,Part[0].n_y1-5);
			Form15->Image1->Canvas->Brush->Color=clRed;
			Form15->Image1->Canvas->Rectangle(Part[0].n_x+20,Part[0].n_y+5,Part[0].n_x1,Part[0].n_y1-5);
		}
		else
			if(sw==3)
			{
				Form15->Image1->Canvas->Brush->Color=clBlack;
				Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y+5,Part[0].n_x1-15,Part[0].n_y1-15);
				Form15->Image1->Canvas->Rectangle(Part[0].n_x+15,Part[0].n_y+5,Part[0].n_x1-5,Part[0].n_y1-15);
				Form15->Image1->Canvas->Brush->Color=clRed;
				Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y,Part[0].n_x1-5,Part[0].n_y1-20);
			}
			else
				if(sw==4)
				{
						Form15->Image1->Canvas->Brush->Color=clBlack;
						Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y+15,Part[0].n_x1-15,Part[0].n_y1-5);
						Form15->Image1->Canvas->Rectangle(Part[0].n_x+15,Part[0].n_y+15,Part[0].n_x1-5,Part[0].n_y1-5);
						Form15->Image1->Canvas->Brush->Color=clRed;
						Form15->Image1->Canvas->Rectangle(Part[0].n_x+5,Part[0].n_y+20,Part[0].n_x1-5,Part[0].n_y1);
				}
}

void check_bareers(now sneak[256], bool who)
{
		if((sneak[0].n_x >=50 && sneak[0].n_x1<=75 && sneak[0].n_y>=25 && sneak[0].n_y1<=200)
		||(sneak[0].n_x >=175 && sneak[0].n_x1<=200 && sneak[0].n_y>=0 && sneak[0].n_y1<=50)
		||(sneak[0].n_x >=175 && sneak[0].n_x1<=200 && sneak[0].n_y>=75 && sneak[0].n_y1<=125)
		||(sneak[0].n_x >=150 && sneak[0].n_x1<=225 && sneak[0].n_y>=125 && sneak[0].n_y1<=175)
		||(sneak[0].n_x >=150 && sneak[0].n_x1<=175 && sneak[0].n_y>=300 && sneak[0].n_y1<=450)
		||(sneak[0].n_x >=200 && sneak[0].n_x1<=175 && sneak[0].n_y>=450 && sneak[0].n_y1<=475)
		||(sneak[0].n_x >=50 && sneak[0].n_x1<=150 && sneak[0].n_y>=425 && sneak[0].n_y1<=450)
		||(sneak[0].n_x >=150 && sneak[0].n_x1<=275 && sneak[0].n_y>=450 && sneak[0].n_y1<=475)
		||(sneak[0].n_x >=250 && sneak[0].n_x1<=300 &&sneak[0].n_y>=475 && sneak[0].n_y1<=500)
		||(sneak[0].n_x >=275 && sneak[0].n_x1<=325 && sneak[0].n_y>=500 && sneak[0].n_y1<=525)
		||(sneak[0].n_x >=300 && sneak[0].n_x1<=325 && sneak[0].n_y>=250 && sneak[0].n_y1<=275)
		||(sneak[0].n_x >=325 && sneak[0].n_x1<=350 && sneak[0].n_y>=275 && sneak[0].n_y1<=300)
		||(sneak[0].n_x >=350 && sneak[0].n_x1<=375 && sneak[0].n_y>=300 && sneak[0].n_y1<=325)
		||(sneak[0].n_x >=375 && sneak[0].n_x1<=400 && sneak[0].n_y>=325 && sneak[0].n_y1<=350)
		||(sneak[0].n_x >=400 && sneak[0].n_x1<=600 && sneak[0].n_y>=150 && sneak[0].n_y1<=175)
		||(sneak[0].n_x >=400 && sneak[0].n_x1<=425 && sneak[0].n_y>=100 && sneak[0].n_y1<=150)
		||(sneak[0].n_x >=500 && sneak[0].n_x1<=525 && sneak[0].n_y>=500 && sneak[0].n_y1<=600))
		{
		   if(who)
			winner = 2;
		   else
			winner = 1;
			Obnul();
		}


}

void prov(now Part[256], now Sneak[256],int global, int global1, bool who)
{
  if(number ==1)
  {
		if(bars==1)
			check_bareers(Part,who);
		for(int j=1;j<global1;j++)
		{
			   if(Part[0].n_x == Sneak[j].n_x && Part[0].n_y == Sneak[j].n_y &&Part[0].n_x1 == Sneak[j].n_x1 &&Part[0].n_y1 == Sneak[j].n_y1)
			   {
				if(who)
					winner = 2;
				else
					winner = 1;
				Obnul();
				return;
			   }
		}
		if(Part[0].n_x == Sneak[0].n_x &&Part[0].n_y == Sneak[0].n_y&&Part[0].n_x1 == Sneak[0].n_x1&&Part[0].n_y1 == Sneak[0].n_y1)
		{
			winner = -1;
			Obnul();
			return;
		}
  }
  if(global>4)
  {
	  for(int i=1;i<global;i++)
	  {
		  if(Part[0].n_x ==Part[i].n_x && Part[0].n_x1==Part[i].n_x1  && Part[0].n_y ==Part[i].n_y&&Part[0].n_y1==Part[i].n_y1)
		  {
				if(who)
				{
				  if(number==1)
					winner = 2;
				  else
					winner = 0;
				}
				else
				  winner = 1;
				Obnul();
				return;
		  }
	  }
  }
}

bool change=true;
bool change1=true;

void __fastcall TForm15::Timer1Timer(TObject *Sender)
{
	if(Start)
	{
		Start=!Start;
		if(bars==0)
		{
			Form15->Image1->Canvas->Brush->Color=clGray;
			Form15->Image1->Canvas->Pen->Color=clGray;
			Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
		}

		Image1->Canvas->Brush->Color=Form1->ColorBox1->Selected;
		Image1->Canvas->Rectangle(Part[0].n_x,Part[0].n_y,Part[0].n_x1,Part[0].n_y1);
		if(number==1)
		{
			Image1->Canvas->Brush->Color=Form1->ColorBox2->Selected;
		   	Image1->Canvas->Rectangle(Sneak[0].n_x,Sneak[0].n_y,Sneak[0].n_x1,Sneak[0].n_y1);
		}
		spawn_apple(Part, global);
	}
	prov(Part,Sneak,global,global1,true);
  if(number==0)
  {
	for(int i=1;i<global;i++)
	{
		if(Part[0].n_x ==Part[i].n_x && Part[0].n_x1==Part[i].n_x1  && Part[0].n_y ==Part[i].n_y&&Part[0].n_y1==Part[i].n_y1)
		{
			winner = 0;
			Obnul();
			return;
		}
	}
  }
  ad(Part,global);
  if(change)
	 {
		go(Part, global, true);

		switch (sw) {

		case 1:

		otrisovka_left(Part, global, true);

		break;

		case 2:

		otrisovka_right(Part, global, true);

		break;

		case 3:

		otrisovka_up(Part, global, true);

		break;

		case 4:

		otrisovka_down(Part, global, true);

		break;
		}
		otrisovka_face(Part, global,sw);
	 }
	 else
		change =true;


}
//---------------------------------------------------------------------------

void __fastcall TForm15::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_LEFT && (sw!=1 && sw!=2))
	{
		if(change)
			change=!change;
		sw= 1;
		prov(Part,Sneak,global,global1,true);
		ad(Part,global);
		go(Part, global, true);
		otrisovka_left(Part, global, true);
		otrisovka_face(Part, global,sw);
	}
	else
	{
		if(Key == VK_RIGHT && (sw!=1 && sw!=2))
		{
			if(change)
				change=!change;
			sw=2;
			prov(Part,Sneak,global,global1,true);
			ad(Part,global);
			go(Part, global, true);
			otrisovka_right(Part, global, true);
			otrisovka_face(Part, global,sw);
		}
		else
		{
			if(Key == VK_UP && (sw!=3 && sw!=4))
			{
				if(change)
				{
					change=!change;
				}
				sw = 3;
				prov(Part,Sneak,global,global1,true);
				ad(Part,global);
				go(Part, global, true);
				otrisovka_up(Part, global, true);
				otrisovka_face(Part, global,sw);
			}
			else
			{
				if(Key == VK_DOWN && (sw!=3 && sw!=4))
				{
					if(change)
						change=!change;
					sw = 4;
					prov(Part,Sneak,global,global1,true);
					ad(Part,global);
					go(Part, global, true);
					otrisovka_down(Part, global, true);
					otrisovka_face(Part, global,sw);
				}
			}
		}
	}
	if(number == 1)
	{
		if(Key==65&& (sw1!=1 && sw1!=2))
		{
			if(change1)
			change1=!change1;

			sw1= 1;
			prov(Sneak,Part,global1,global,false);
			ad(Sneak,global1);
			go(Sneak, global1, false);
			otrisovka_left(Sneak, global1, false);
			otrisovka_face(Sneak, global1,sw1);
		}
		else
		{
			if(Key==68&& (sw1!=1 && sw1!=2))
			{
			if(change1)
				change1=!change1;
			sw1= 2;
			prov(Sneak,Part,global1,global,false);
			ad(Sneak,global1);
			go(Sneak, global1, false);
			otrisovka_right(Sneak, global1, false);
			otrisovka_face(Sneak, global1,sw1);
			}
			else
			{
				if(Key==87&& (sw1!=3 && sw1!=4))
				{
				if(change1)
					change1=!change1;
				sw1 = 3;
				prov(Sneak,Part,global1,global,false);
				ad(Sneak,global1);
				go(Sneak, global1, false);
				otrisovka_up(Sneak, global1, false);
				otrisovka_face(Sneak, global1,sw1);
				}
				else
				{
					if(Key==83&& (sw1!=3 && sw1!=4))
					{
						if(change1)
							change1=!change1;
						sw1 = 4;
						prov(Sneak,Part,global1,global,false);
						ad(Sneak,global1);
						go(Sneak, global1, false);
						otrisovka_down(Sneak, global1, false);
						otrisovka_face(Sneak, global1,sw1);
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm15::Timer2Timer(TObject *Sender)
{

	prov(Sneak,Part,global1,global,false);
	ad(Sneak,global1);
	if(change1)
	{
			go(Sneak, global1, false);

			switch (sw1)
			{

				case 1:

				otrisovka_left(Sneak, global1, false);

				break;

				case 2:

				otrisovka_right(Sneak, global1, false);

				break;

				case 3:

				otrisovka_up(Sneak, global1, false);

				break;

				case 4:

				otrisovka_down(Sneak, global1, false);

				break;
			}
			otrisovka_face(Sneak, global1,sw1);
	}
	else
		change1 =true;

}
//---------------------------------------------------------------------------



 void Bareers()
{
	Form15->Image1->Canvas->Brush->Color=clBlack;
	Form15->Image1->Canvas->Pen->Color=clBlack;
	Form15->Image1->Canvas->Rectangle(50,25,75,200);
	Form15->Image1->Canvas->Rectangle(175,0,200,50);
	Form15->Image1->Canvas->Rectangle(175,75,200,125);
	Form15->Image1->Canvas->Rectangle(150,125,225,175);
	Form15->Image1->Canvas->Rectangle(150,300,175,450);
	Form15->Image1->Canvas->Rectangle(200,450,175,475);
	Form15->Image1->Canvas->Rectangle(50,425,150,450);
	Form15->Image1->Canvas->Rectangle(150,450,275,475);
	Form15->Image1->Canvas->Rectangle(250,475,300,500);
	Form15->Image1->Canvas->Rectangle(275,500,325,525);
	Form15->Image1->Canvas->Rectangle(300,250,325,275);
	Form15->Image1->Canvas->Rectangle(325,275,350,300);
	Form15->Image1->Canvas->Rectangle(350,300,375,325);
	Form15->Image1->Canvas->Rectangle(375,325,400,350);
	Form15->Image1->Canvas->Rectangle(400,150,600,175);
	Form15->Image1->Canvas->Rectangle(400,100,425,150);
	Form15->Image1->Canvas->Rectangle(500,500,525,600);
	Form15->Image1->Canvas->Pen->Color=clGray;
}

bool y=true;
void __fastcall TForm15::FormActivate(TObject *Sender)
{
		  //Form15->Image1->Canvas->Brush->Color=clGray;
		//Form15->Image1->Canvas->Pen->Color=clGray;
		//Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

		Part[0].n_x=Image1->ClientWidth-25;
		Part[0].n_y = Image1->ClientHeight/2;
		Part[0].n_x1 = Image1->ClientWidth;
		Part[0].n_y1 = Image1->ClientHeight/2+25;
		if(number==1)
		{
			Sneak[0].n_x=0;
			Sneak[0].n_y = Image1->ClientHeight/2;
			Sneak[0].n_x1 = 25;
			Sneak[0].n_y1 = Image1->ClientHeight/2+25;
		}
		 Form15->Timer1->Enabled=true;
	 if(number==1)
		 Form15->Timer2->Enabled=true;
		//Form15->Image1->Canvas->Brush->Color=clGray;
		//Form15->Image1->Canvas->Pen->Color=clGray;
		//Form15->Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

		onoff=true;
		Form1->MediaPlayer1->Open();
		Form1->MediaPlayer1->Notify=true;
		Form1->MediaPlayer1->Play();

	if(number==1 && bars==1)
		Bareers();



}
//---------------------------------------------------------------------------
