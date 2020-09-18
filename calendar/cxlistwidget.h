#ifndef CXLISTWIDGET_H
#define CXLISTWIDGET_H

#include <QListWidget>
#include "ui_w_list_piece.h"

class PieceWidget : public QWidget
{
	Q_OBJECT
public:
	PieceWidget(QWidget* parent = 0 ) ;
	Ui::Form_PieceWidget form(){ return ui ; }
	void setSelected( bool on ) ;
private:
	Ui::Form_PieceWidget ui ;
};
class CxListWidget : public QListWidget
{
	Q_OBJECT

public:
	CxListWidget(QWidget *parent);
	~CxListWidget();
	void addMyItem( QString str, int driveLetter=-1 ) ;
	bool findItem(QListWidgetItem* item) ;
	void clearMe() ;
public slots:
	void onSelectionChanged() ;

protected:
	void resizeEvent(QResizeEvent *e) ;
	void showEvent(QShowEvent *e) ;
private:
	void fit() ;
};

#endif // CXLISTWIDGET_H
