#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QProcess>
#include <QMouseEvent>
#include <QProcess>

#include "ui_mainwindow.h"
#include <QTimeLine>


class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0 );
	~MainWindow();
private slots:
	void onTest() ;
	void onChoose() ;
	void onProtect() ;
	void onUnProtect() ;
	void onRefresh() ;
	void onAdd() ;
	void onRemove() ;
protected:
	void mouseMoveEvent(QMouseEvent *) ;
	void mousePressEvent(QMouseEvent *) ;
	void mouseReleaseEvent(QMouseEvent *) ;
private:
	void initUI() ;
	void setMainWidgetEnabled(bool on) ;
	void initConnection() ;
	void chooseFile( QString str ) ;
	bool isRunning(QString filePath) ;
	void saveCurrentState() ;
	void loadConfigFile() ;
	Ui::Form_MainWindow ui ;
	QString m_curEXEpath, m_configPath, m_curDir ;
	bool m_isPressing ;
	QRect m_oriRect;
	QPoint m_oriPnt ;
};

#endif // MAINWINDOW_H
