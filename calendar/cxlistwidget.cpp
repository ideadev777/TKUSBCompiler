#include "cxlistwidget.h"
#define ITEMH 40

PieceWidget::PieceWidget(QWidget* parent /* = 0 */ )
{
	ui.setupUi(this) ;
}

void PieceWidget::setSelected( bool on )
{
	QString path = "" ;
	if( on ) path = ":/res/icon/check.png" ;
	ui.lbl_pix->setPixmap(path) ; 
}
//////////////////////////////////////////////////////////////////////////

CxListWidget::CxListWidget(QWidget *parent)
	: QListWidget(parent)
{
	connect( this, SIGNAL(itemSelectionChanged()), this, SLOT(onSelectionChanged())) ;
	setSelectionMode(QAbstractItemView::MultiSelection) ;
}

CxListWidget::~CxListWidget()
{

}

void CxListWidget::addMyItem( QString str, int driveLetter )
{
	QListWidgetItem* item = new QListWidgetItem ;
	PieceWidget* w = new PieceWidget ;
	item->setData(Qt::EditRole+1,str) ;
	item->setData(Qt::EditRole+2,driveLetter) ;
	w->form().lbl_txt->setText(str) ;
	if( driveLetter != -1 ) w->form().lbl_drive->setText(QString("%1:").arg(QChar('A'+driveLetter))) ;
	addItem(item) ;
	w->setStyleSheet("QWidget{background:#B5F0B5;}") ;
	item->setSizeHint(QSize(viewport()->width(),ITEMH)) ;
	setItemWidget(item,w) ;
}
 
void CxListWidget::onSelectionChanged()
{
	int cnt = count() ;
	for( int i = 0; i < cnt; i++ )
	{
		QListWidgetItem* it = item(i) ;
		bool isSel = it->isSelected() ;
		PieceWidget* w = (PieceWidget*) itemWidget(it) ;
		if (!w ) continue ;
		w->setSelected(isSel) ;
	}
}

void CxListWidget::resizeEvent(QResizeEvent* event)
{
	QListWidget::resizeEvent(event) ;
	fit() ;
}

void CxListWidget::showEvent(QShowEvent *e)
{
	QListWidget::showEvent(e) ;
	fit() ;
}

void CxListWidget::fit()
{
	for( int i = count()-1; i >= 0; i-- )
	{
		QListWidgetItem* it = item(i) ;
		PieceWidget* w = (PieceWidget*) itemWidget(it) ;
		it->setSizeHint(QSize(viewport()->width(),ITEMH)) ;
		w->resize(QSize(viewport()->width(),ITEMH)) ;
	}
}

bool CxListWidget::findItem(QListWidgetItem* it)
{
	for( int i = count()-1; i >= 0; i-- )
	{
		if( item(i)->data(Qt::EditRole+1) == it->data(Qt::EditRole+1) ) return true ;
	}
	return false ;
}

void CxListWidget::clearMe()
{
	clearSelection() ;
	for( int i = count()-1; i >=0 ; i-- )
	{
		takeItem(i) ;
	}
}