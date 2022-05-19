//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.MPlayer.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCGrids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TMediaPlayer *MediaPlayer1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TImage *Image12;
	TColorBox *ColorBox1;
	TDBGrid *DBGrid1;
	TColorBox *ColorBox2;
	TLabel *Label2;
	TLabel *Label3;
	TRadioGroup *RadioGroup1;
	TShape *Shape1;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TShape *Shape2;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TDBRichEdit *DBRichEdit1;
	TDBRichEdit *DBRichEdit2;
	TDBRichEdit *DBRichEdit3;
	TDBText *DBText1;
	TDBText *DBText2;
	TDBText *DBText3;
	TRadioGroup *RadioGroup2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Image2MouseEnter(TObject *Sender);
	void __fastcall Image2MouseLeave(TObject *Sender);
	void __fastcall Image3MouseEnter(TObject *Sender);
	void __fastcall Image3MouseLeave(TObject *Sender);
	void __fastcall Image4MouseEnter(TObject *Sender);
	void __fastcall Image4MouseLeave(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image5MouseEnter(TObject *Sender);
	void __fastcall Image5MouseLeave(TObject *Sender);
	void __fastcall Image6MouseEnter(TObject *Sender);
	void __fastcall Image6MouseLeave(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image7MouseEnter(TObject *Sender);
	void __fastcall Image7MouseLeave(TObject *Sender);
	void __fastcall Image8MouseEnter(TObject *Sender);
	void __fastcall Image8MouseLeave(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image10MouseLeave(TObject *Sender);
	void __fastcall Image9MouseLeave(TObject *Sender);
	void __fastcall Image9MouseEnter(TObject *Sender);
	void __fastcall Image10MouseEnter(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall MediaPlayer1Notify(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image12Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall RadioGroup2Click(TObject *Sender);
	void __fastcall Image12MouseEnter(TObject *Sender);
	void __fastcall Image12MouseLeave(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
