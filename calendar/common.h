#ifndef COMMON_H
#define COMMON_H

#define DEFAULTFRAMERATE 29.7

#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QTime>
#include <QPixmap>

#include <windows.h>
#include <ioapiset.h>
#include <iostream>
#include <string>

using namespace std ;

QString  createUuid() ;
QString createSimpleUuid() ;
int getMSec(QTime t) ;
QTime getTime(qint64 msec) ;

void runProcess( QObject* parent, QString path, QStringList arg ) ;

QString getSerial( QString drive ) ;

QString decrypt(const QString &password) ;

QString encrypt(const QString &password) ;

QString GetSerialNumberUSB(char d) ;
QString getSerialNumberOfUSB( char d ) ;

#endif // COMMON_H
