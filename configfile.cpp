/***************************************************************************
                          configfile.cpp  -  description
                             -------------------
    begin                : Son Aug 17 2003
    copyright            : (C) 2003 by Andreas Lindenau
    email                : DL4JAL@darc.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <qdir.h>
#include <QtDebug>
 
#include "configfile.h"

//#define ldebug

configfile::configfile(){
  sl.clear(); // Liste vorsichthalber noch loeschen
  speichern=false;
}

configfile::~configfile(){
  close();
}

void configfile::open( const QString &name ){
  QString qs;
  bool binsert = true;
  QFile *f1;

  //qDebug("open");
  //qDebug()<<sl.count();
  fname = name;
  f1 = new QFile(fname);
  if(f1->open(QIODevice::ReadOnly)){
    QTextStream ts( f1);
    while(!ts.atEnd()){
      qs = ts.readLine();
      if(qs.isEmpty())binsert = false;
      if(!qs.contains("="))binsert = false;
      if(binsert)sl.append(qs);
      //qDebug()<<sl.count();
    }
    f1->close();
    delete(f1);
    sl.sort();
    //qDebug()<<sl.count();
  }
}

void configfile::close(){
  QString qs;
  QStringList::Iterator it;
  QFile *f1;
  
  //qDebug("close");
  //qDebug()<<sl.count();
  if(speichern){
    sl.sort();
    f1 = new QFile(fname);
    if(f1->open(QIODevice::WriteOnly)){
      QTextStream ts(f1);
      for(it = sl.begin() ; it != sl.end(); it++){
        qs = (*it).toLocal8Bit().constData();
	//qDebug(qPrintable(qs));
        ts << qs << endl;
      }
      f1->close();
      delete(f1);
    }
  }
  speichern = FALSE;
}

bool configfile::clearItem(const QString &name){
  QString qs1;
  QStringList::Iterator it;
  
  //qDebug("clearItem");
  //qDebug()<<sl.count();
  speichern = true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    //qDebug(qPrintable(qs1));
    if(qs1.contains(name)){
      //qDebug()<<sl.count();
      sl.removeOne(qs1);
      //qDebug()<<sl.count();
      return true;
    }
  }
  return false;
}

double configfile::readDouble(const QString &name, double def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readDouble");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      //qDebug(name);
      //qDebug(qs1);
      qs1.remove(0, name.length()+1);
      return qs1.toDouble();
    }
  }
  return def;
}

int configfile::readInteger(const QString &name, int def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readInteger");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      qs1.remove(0, name.length()+1);
      return qs1.toInt();
    }
  }
  return def;
}

long configfile::readLong(const QString &name, long def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readLong");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      qs1.remove(0, name.length()+1);
      return qs1.toLong();
    }
  }
  return def;
}

qlonglong configfile::readLongLong(const QString &name, qlonglong def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readLong");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      qs1.remove(0, name.length()+1);
      return qs1.toLongLong();
    }
  }
  return def;
}

QString configfile::readString(const QString &name, const QString &def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readString");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      qs1.remove(0, name.length()+1);
      return qs1;
    }
  }
  return def;
}

bool configfile::readBool(const QString &name, bool def){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("readBool");
  //qDebug()<<sl.count();
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      qs1.remove(0, name.length()+1);
      return bool(qs1.toInt());
    }
  }
  return def;
}

void configfile::writeDouble(const QString &name, double wert){
  QString qs1, qs2;
  QStringList::Iterator it;

  //qDebug("writeDouble");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = name + "=";
  qs2.setNum(wert,'g',10);
  qs1.append(qs2);
  sl.append(qs1);
  return;
}

void configfile::writeInteger(const QString &name, int wert){
  QString qs1, qs2;
  QStringList::Iterator it;

  //qDebug("writeInteger");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = name + "=";
  qs2.setNum(wert);
  qs1.append(qs2);
  sl.append(qs1);
  return;
}

void configfile::writeLong(const QString &name, long wert){
  QString qs1, qs2;
  QStringList::Iterator it;

  //qDebug("writeLong");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = name + "=";
  qs2.setNum(wert);
  qs1.append(qs2);
  sl.append(qs1);
  return;
}

void configfile::writeLongLong(const QString &name, qlonglong wert){
  QString qs1, qs2;
  QStringList::Iterator it;

  //qDebug("writeLongLong");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = name + "=";
  qs2.setNum(wert);
  //qDebug()<<qs2;

  qs1.append(qs2);
  sl.append(qs1);
  return;
}

void configfile::writeString(const QString &name, const QString &wert){
  QString qs1;
  QStringList::Iterator it;

  //qDebug("writeString");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = (name + "=" + wert);
  sl.append(qs1);
  return;
}

void configfile::writeBool(const QString &name, bool wert){
  QString qs1, qs2;
  QStringList::Iterator it;

  //qDebug("writeBool");
  //qDebug()<<sl.count();
  speichern=true;
  for(it = sl.begin() ; it < sl.end(); it++){
    qs1 = (*it).toLocal8Bit().constData();
    if(qs1.indexOf(name+"=",0)==0){
      sl.erase(it);
      break;
    }
  }
  qs1 = name + "=";
  qs2.setNum(wert);
  qs1.append(qs2);
  sl.append(qs1);
  return;
}
