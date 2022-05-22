#ifndef OPTIONDLG_H
#define OPTIONDLG_H

#include <qdialog.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qgroupbox.h>
#include <qcombobox.h>
#include <q3listbox.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qstring.h>
#include <QPen>
#include <QTabWidget>
#include <QSpinBox>

#include "konstdef.h"

class odlg : public QDialog
{
    Q_OBJECT

public:
  odlg(QWidget* parent=0, const char* name=0, bool modal=false);

  void setdaten(TGrunddaten agrunddaten);
  TGrunddaten getdaten();
  void tip(bool);
  void setsavcal(const TSavcalarray &);
  TSavcalarray getsavcal();

public slots:
  void psetfontsize(int);
  void setkalibrierarray(const TKalibrierarray&);

private slots:
  void setColor1();
  void setColor2();
  void setColorh();
  void setStandart();
  void checkboxsastatus_checked(bool);
  void checkboxschrittkorr_checked(bool);
  void sacal();
  void sacalreset();
  void setspinwtime(int);

private:
  TGrunddaten ogrunddaten;
  TKalibrierarray okalibrierarray;
  TSavcalarray osavcalarray;
  
  double getkalibrierwert(double afrequenz);
  
  QTabWidget *tabwidget;
  QWidget *wwobbel;
  QWidget *wspectrum;
  QWidget *wspectrum2;
  QWidget *wallgemein;
  
  //
  QPushButton *ok;
  QPushButton *cancel;
  QGroupBox *kalibrierfrequ;
  QLabel *labelanfang;
  QLabel *labelende;
  QLineEdit *eanfang;
  QLineEdit *eende;
  QGroupBox *ddstakt;
  QLabel *labelddstakt;
  QLineEdit *eddstakt;
  QGroupBox *gtty;
  QComboBox *ctty;
  QLabel *labelctty;
  QGroupBox *gkalibrier;
  QCheckBox *daempfungfa;
  QGroupBox *geinkanalig;
  QCheckBox *boxeinkanalig;
  QGroupBox *fname;
  QGroupBox *fgrenzen;
  QLineEdit *wobmax;
  QLabel *labelwobmax;
  QComboBox *cbfrqfaktor;
  QLabel *labelfrqfaktor;
  QLabel *labelsonde1;
  QLabel *labelsonde2;
  QLineEdit *econfig;
  QLineEdit *esonde1;
  QLineEdit *esonde2;
  QLabel *labelesonde1lin;
  QLineEdit *esonde1lin;
  QLabel *labelcpll;
  QComboBox *cpll;
  QGroupBox *gswriteration;
  QCheckBox *boxiteration;
//SA
  QGroupBox *gallgemein;
  QCheckBox *boxsastatus;
  QCheckBox *boxschrittkorr;
  
  QGroupBox *gsakw;
  QLineEdit *efrqa1;
  QLabel *labelfrqa1;
  QLineEdit *efrqb1;
  QLabel *labelfrqb1;
  QLineEdit *efrqzf1;
  QLabel *labelfrqzf1;
  QLineEdit *efrqshift;
  QLabel *labelfrqshift;
  
  QGroupBox *gsaukw;
  QLineEdit *efrqa2;
  QLabel *labelfrqa2;
  QLineEdit *efrqb2;
  QLabel *labelfrqb2;
  QLineEdit *efrqzf2;
  QLabel *labelfrqzf2;
  
  QGroupBox *gpegelkorr;
  QLineEdit *eabsolut1;
  QLabel *labelabsolut1;
  QLineEdit *eabsolut2;
  QLabel *labelabsolut2;
  QLineEdit *eabsolut3;
  QLabel *labelabsolut3;
  QLineEdit *eb300;
  QLabel *labelb300;
  QLineEdit *eb7k;
  QLabel *labelb7k;
  QLineEdit *eb30k;
  QLabel *labelb30k;
  
  QGroupBox *groupsavfehler;
  QLineEdit *esafehlermax;
  QLabel *labelsafehlermax;
  QLineEdit *esafehlermin;
  QLabel *labelsafehlermin;
  QLineEdit *esaminschritte;
  QLabel *labelsaminschritte;
  
  QGroupBox *groupsavgrenzen;
  QLabel *labelgsabmin;
  QLabel *labelgsabmax;
  QLineEdit *egsab300max;
  QLineEdit *egsab300min;
  QLabel *labelgsab300;
  QLineEdit *egsab7kmax;
  QLineEdit *egsab7kmin;
  QLabel *labelgsab7k;
  QLineEdit *egsab30kmax;
  QLineEdit *egsab30kmin;
  QLabel *labelgsab30k;
  
  QGroupBox *groupsavinfo;
  QCheckBox *savdbm;
  QCheckBox *savuv;
  QCheckBox *savwatt;
  QCheckBox *savdbuv;
  
  QGroupBox *groupsawarnung;
  QCheckBox *boxwarnsavbw;     //Warnung EIN/AUS bei SAV keine auto. Schrittkorr
  QCheckBox *boxwarnsavbwmax;  //Warnung EIN/AUS bei SAV keine auto. Schrittkorr
  
  QPushButton *sastandart;
  QPushButton *buttonsacal;
  QPushButton *buttonsacalreset;
  
  //Allgemein
  
  QGroupBox *grouppen;
  QPushButton *buttoncolor1;
  QPushButton *buttoncolor2;
  QPushButton *buttoncolorh;
  QSpinBox *spwidth;
  QLabel *labelspwidth;
  
  QGroupBox *groupfocus;
  QCheckBox *fwobbeln;
  QCheckBox *feinmal;
  QCheckBox *fstop;
  
  QGroupBox *groupspinpfsize;
  QSpinBox *spinpfsize;
  QLabel *labelspinpfsize;

  QGroupBox *groupwmprezision;
  QCheckBox *wmprezision;

  QGroupBox *groupnwtruhe;
  QCheckBox *chset0hz;

  QGroupBox *groupwdarstellung;
  QCheckBox *chsetfliessend;

  QGroupBox *groupaudio;
  QSpinBox *spinwtime;
  QLabel *labelspinwtime;
  QSpinBox *spinwsens;
  QLabel *labelspinwsens;
};

#endif // OPTIONDLG_H
