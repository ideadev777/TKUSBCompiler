#ifndef TKPROTECT_H
#define TKPROTECT_H

#include <QtWidgets/QMainWindow>
#include "ui_tkprotect.h"
#include <QProcess>


#include <windows.h>
#include <ioapiset.h>
#include <iostream>
#include <string>

using namespace std ;

class TKProtect : public QMainWindow
{
	Q_OBJECT

public:
	TKProtect(QWidget *parent = 0);
	~TKProtect();
private slots :
	void onFinished(int exitCode, QProcess::ExitStatus exitStatus) ;
	void onTest() ;
protected:
	void closeEvent(QCloseEvent *event) ;
private:
	bool isInvalidKey(QString key) ;
	QString getSerial( QString drive ) ;
	QString decrypt(const QString &password) ;
	QString encrypt(const QString &password) ;
	QString GetSerialNumberUSB(char d) ;

	Ui::TKProtectClass ui;
	QProcess* m_process ;
	bool m_isRunning ;
	QString m_extractName ;
};

#endif // TKPROTECT_H
