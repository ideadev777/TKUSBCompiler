#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QCloseEvent>
#include <QFileInfo>
#include <QFile>
#include <QProcess>
#include "common.h"
#include "setupapi.h"

#pragma comment(lib,"Setupapi.lib")

#define CONFIG "stickconfig.dat"
#define PROTECTRESULT "stickbin.data"
#define TITLEHEIGHT 50

#define PROTECTBIN "TKProtect.exe"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this) ;
	initUI() ;
	initConnection() ;
//	chooseFile("E://ColorSPY/TKProtect.exe") ;
	m_isPressing = false ;
	onRefresh() ;
} 

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
	qApp->setStyleSheet("QToolTip { color: #EB2D3D; background-color: #c3c3c3; border: 1px solid white; }");

	//	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint );
//	setFi
//	setFixedWidth(800,300) ;
	setFixedSize(523,540) ;
	int id = 2 ;
	QFile styleSheet(QString(":/res/qss/%1.qss").arg(3));
	if (styleSheet.open(QIODevice::ReadOnly)) {
		setStyleSheet(styleSheet.readAll());
	}
	
	ui.tb_protect->setVisible(false) ;
	ui.tb_unprotect->setVisible(false) ;
//	ui.w_main->setVisible(false) ;
	setMainWidgetEnabled(false) ;
	ui.tb_choose->setToolTip("<h1><p style='white-space:pre'>SELECT TARGET.EXE FILE</p></h1>");
	ui.lb_path_hint->setToolTip("<h1><p style='white-space:pre'>SELECT TARGET.EXE FILE</p></h1>");
}

void MainWindow::initConnection()
{
	connect( ui.tb_choose, SIGNAL(clicked()), this, SLOT(onChoose())) ;
	connect( ui.tb_protect, SIGNAL(clicked()), this, SLOT(onProtect())) ;
	connect( ui.tb_unprotect, SIGNAL(clicked()), this, SLOT(onUnProtect())) ;
	connect( ui.tb_add, SIGNAL(clicked()), this, SLOT(onAdd())) ;
//	connect( ui.tb_remove, SIGNAL(clicked()), this, SLOT(onRemove())) ;
//	connect( ui.tb_minimize, SIGNAL(clicked()), this, SLOT(showMinimized())) ;
//	connect( ui.tb_close, SIGNAL(clicked()), this, SLOT(close())) ;
	connect( ui.tb_refresh, SIGNAL(clicked()), this, SLOT(onRefresh())) ;
}
void MainWindow::onTest()
{
	static GUID GUID_DEVINTERFACE_USB_DEVICE = { 0xA5DCBF10L, 0x6530, 0x11D2, 
	{ 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } };

	HANDLE hInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_USB_DEVICE,NULL,NULL,
		DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);

	if ( hInfo == INVALID_HANDLE_VALUE )    
	{    
		QMessageBox::information(NULL,"","Invalid") ;
//		qDebug ()<<"invalid";   
	}    
	else    
	{        
//		qDebug ()<<"valid handle";    

		SP_DEVINFO_DATA DeviceInfoData;
		DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

		SP_INTERFACE_DEVICE_DATA Interface_Info;    
		Interface_Info.cbSize = sizeof(Interface_Info);

		BYTE Buf[1024];
		DWORD i;
		DWORD InterfaceNumber= 0;

		PSP_DEVICE_INTERFACE_DETAIL_DATA pspdidd = 
			(PSP_DEVICE_INTERFACE_DETAIL_DATA) Buf;

		for (i=0;SetupDiEnumDeviceInfo(hInfo,i,&DeviceInfoData);i++)
		{
			DWORD DataT;
			LPTSTR buffer = NULL;
			DWORD buffersize = 0;

			while (!SetupDiGetDeviceRegistryProperty( hInfo,
				&DeviceInfoData,
				SPDRP_DEVICEDESC,
				&DataT,
				(PBYTE)buffer,
				buffersize,
				&buffersize))    
			{
				if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
				{
					// Change the buffer size.
					if (buffer) LocalFree(buffer);
					buffer = (LPTSTR)LocalAlloc(LPTR,buffersize);
				}
				else
				{
					// Insert error handling here.
					break;
				}
				QString str = QString::fromWCharArray(buffer) ;
				QMessageBox::information(NULL,"device number is",str) ;
//				qDebug ()<<(TEXT("Device Number %i is: %s\n"),i, buffer);

				if (buffer) LocalFree(buffer);

				if ( GetLastError() != NO_ERROR 
					&& GetLastError() != ERROR_NO_MORE_ITEMS )    
				{
					// Insert error handling here.
					QMessageBox::information(NULL,"","Hehe") ;
//					qDebug ()<<"return false";
				}

				InterfaceNumber = 0; // this just returns the first one, you can iterate on this

				if (SetupDiEnumDeviceInterfaces(hInfo,
					NULL, 
					&GUID_DEVINTERFACE_USB_DEVICE,
					InterfaceNumber,
					&Interface_Info))
				{
					printf("Got interface");
					DWORD needed;
					pspdidd->cbSize = sizeof(*pspdidd);    
					SP_DEVICE_INTERFACE_DETAIL_DATA *pDetData = NULL;

					DWORD dwDetDataSize = sizeof (SP_DEVICE_INTERFACE_DETAIL_DATA) + 256;
					pDetData = (SP_DEVICE_INTERFACE_DETAIL_DATA*) malloc (dwDetDataSize);
					pDetData->cbSize = sizeof (SP_DEVICE_INTERFACE_DETAIL_DATA);


					SetupDiGetDeviceInterfaceDetail(hInfo, 
						&Interface_Info, pDetData,dwDetDataSize, NULL,
						&DeviceInfoData);

					QMessageBox::information(NULL,"Device Path",QString::fromWCharArray(pDetData->DevicePath)) ;
//					qDebug ()<<pDetData->DevicePath;
					//qDebug ()<<QString::fromWCharArray(pDetData->DevicePath);
					free(pDetData);
				}
				else
				{    
					printf("\nNo interface");

					//ErrorExit((LPTSTR) "SetupDiEnumDeviceInterfaces");

					if ( GetLastError() == ERROR_NO_MORE_ITEMS) 
						printf(", since there are no more items found.");
					else 
						printf(", unknown reason.");

				}
				// Cleanup

				SetupDiDestroyDeviceInfoList(hInfo);
//				qDebug ()<<"return true";
			}
		}
	}
}

bool MainWindow::isRunning(QString filePath)
{
	QString dir = QFileInfo(filePath).absolutePath() ;
	QString temp = dir + "/" + createSimpleUuid() + ".dat" ;
	if( !QFile(filePath).copy(temp) )
	{
		return true ;
	}
	if( !QFile(filePath).remove() ) return true ;
	QFile(temp).rename(filePath) ;
	return false ;
}

void MainWindow::onAdd()
{
	int cnt = ui.lw_1->count() ;
	if( !cnt )
	{
		QMessageBox::information(this, "", "Please insert USB first.") ;
		return ;
	}
	/*
	int cur = ui.lw_1->currentRow() ;
	if( cur < 0 || cur >= cnt )
	{
		QMessageBox::information(this, "", "Please select USB first.") ;
		return ;
	}
	QListWidgetItem* item = ui.lw_1->currentItem() ;
	if( ui.lw_2->findItem(item) )
	{
		QMessageBox::information(this, "", "Software is already protected with this USB") ;
		return ;
	}
	ui.lw_2->addMyItem(item->data(Qt::EditRole+1).toString(),item->data(Qt::EditRole+2).toInt()) ;
	*/
	saveCurrentState() ;
	QMessageBox::information(this, "Compile", "Success!") ;
	return ;
}

void MainWindow::onRemove()
{
	/*
	int cnt = ui.lw_2->count() ;
	if( !cnt )
	{
		QMessageBox::information(this, "", "No USB to unprotect.") ;
		return ;
	}
	int cur = ui.lw_2->currentRow() ;
	if( cur < 0 || cur >= cnt )
	{
		QMessageBox::information(this, "", "Please select protected USB first.") ;
		return ;
	}
	ui.lw_2->takeItem(cur) ;
	saveCurrentState() ;
	return ;
	*/
}

void MainWindow::onProtect()
{
	if( isRunning(m_curEXEpath) )
	{
		QMessageBox::information(this,"", QString("%1 is running currently. Please stop it first.").arg(m_curEXEpath)) ;
		return ;
	}
	QApplication::setOverrideCursor(Qt::WaitCursor) ;
/*	QString serial = getSerial(m_curEXEpath) ;
	if( !serial.length() )
	{
		QApplication::restoreOverrideCursor() ;
		QMessageBox::information( NULL,"","Can not recognize current drive." ) ;
		return ;
	}
	*/
	QStringList arg ;
	arg << "x" << "-y" << "env.rar" << "*.*" << m_curDir ;
	QProcess::execute( "rar",arg ) ;

	
	QFile file(m_configPath) ;
	QDataStream out(&file) ;
	file.open(QIODevice::WriteOnly) ;
	out << m_curEXEpath ;
//	out << encrypt(serial) ;
	file.close() ;

	file.setFileName(m_curEXEpath) ;
	file.open(QIODevice::ReadOnly) ;
	QByteArray ba = file.readAll().toBase64() ;
	file.close() ;

	file.setFileName(m_curDir+"/"+PROTECTRESULT) ;
	file.open(QIODevice::WriteOnly) ;
	file.write(ba) ;
	file.close() ;
	ui.tb_protect->hide() ;
	ui.tb_unprotect->show() ;
	QFile(m_curEXEpath).remove() ;
	QFile(PROTECTBIN).copy(m_curEXEpath) ;
//	ui.w_main->setVisible(true) ;
	setMainWidgetEnabled(true) ;
	loadConfigFile() ;
	QApplication::restoreOverrideCursor() ;
	QMessageBox::information(this,"","Success.") ;	
}

void MainWindow::onUnProtect()
{
	QApplication::setOverrideCursor(Qt::WaitCursor) ;

	QFile file(m_configPath) ;
	QDataStream in(&file) ;
	QString name  ;
	if( file.open(QIODevice::ReadOnly) )
	{
		in >> name ;
		file.close() ;
	}
	else
	{
		QApplication::restoreOverrideCursor() ;
		QMessageBox::information(this,"","Invalid format") ;
		return ;
	}
	QFile(m_curEXEpath).remove() ;
	file.setFileName(m_curDir+"/"+QFileInfo(name).fileName()) ;
	file.open(QIODevice::WriteOnly) ;
	QFile protectedFile(m_curDir+"/"+PROTECTRESULT) ;
	protectedFile.open(QIODevice::ReadOnly) ;
	QByteArray ba = QByteArray::fromBase64(protectedFile.readAll()) ;
	file.write(ba) ;
	file.close(), protectedFile.close() ;
 	QApplication::restoreOverrideCursor() ;
	protectedFile.remove() ;
	QFile(m_configPath).remove() ;
	QMessageBox::information(this,"","Successfully unprotect.") ;
	ui.tb_protect->show() ;
	ui.tb_unprotect->hide() ;
//	ui.w_main->setVisible(false) ;
	setMainWidgetEnabled(false) ;
//	ui.lw_2->clearMe() ;
}

void MainWindow::setMainWidgetEnabled(bool on)
{
	ui.w_available->setEnabled(on) ;
	ui.w_control->setEnabled(on) ;
//	ui.w_protected->setEnabled(on) ;
}
void MainWindow::onChoose()
{
//	onTest() ;
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("exe files (*.exe)"));
	if( fileName.length() == 0 ) return ;
	chooseFile(fileName) ;
}

void MainWindow::chooseFile( QString fileName )
{
	if( !QFile(fileName).exists() ) return ;
	QString tooltip = QString("<h1><p style='white-space:pre'>PATH NAME : %1</p></h1>").arg(QFileInfo(fileName).baseName()); 
	ui.tb_choose->setToolTip(tooltip);
	ui.lb_path_hint->setToolTip(tooltip) ;

	
	//	ui.lbl_path->setText(fileName) ;
	m_curEXEpath = fileName ;
	m_curDir = QFileInfo(fileName).absolutePath() ;
	m_configPath = m_curDir+"/"+CONFIG ;
	bool isProtected = QFile(m_configPath).exists() ;

//	ui.tb_protect->setEnabled(true) ;
	ui.tb_protect->setVisible(!isProtected) ;
	ui.tb_unprotect->setVisible(isProtected) ;
//	ui.w_main->setVisible(isProtected) ;
	setMainWidgetEnabled(isProtected) ;
	if( isProtected ) loadConfigFile() ;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	m_oriRect = geometry() ;
	m_oriPnt = event->globalPos() ;
	if( event->pos().y() < 0 || event->pos().y() > TITLEHEIGHT ) return ;
	m_isPressing = true ;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	if( !m_isPressing ) return ;
	QPoint tmp = event->globalPos()-m_oriPnt ;
	QRect geo = m_oriRect.translated(tmp.x(),tmp.y()) ;
	setGeometry(geo);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressing = false ;
}

void MainWindow::onRefresh()
{
	QString hdaddress = GetSerialNumberUSB('C') ;
	ui.lw_1->clearMe() ;
//	ui.lw_2->clearMe() ;

	for( int i = 0; i < 26; i++ )
	{
		char d = 'A'+i ;
		QString serial = GetSerialNumberUSB(d) ;
		if( !serial.length() ) continue ;
		if( serial == hdaddress ) continue ;
		ui.lw_1->addMyItem(serial,i) ;
		//		if( serial == hdA)
	}
	loadConfigFile() ;
}

void MainWindow::saveCurrentState()
{
	QFile file(m_curDir+"/"+CONFIG) ;
	QDataStream out(&file) ;
	file.open(QIODevice::WriteOnly) ;
	QString hashkey = "tom" ;
	out << m_curEXEpath ;
	out << hashkey ;
	int cnt = 0 ;
	for( int i = ui.lw_1->count()-1; i >= 0; i-- )
		if( ui.lw_1->item(i)->isSelected() ) cnt++ ;
	out << cnt ;
	for( int i = ui.lw_1->count()-1; i >= 0; i-- )
		if( ui.lw_1->item(i)->isSelected() ) 
		{
			out << encrypt(ui.lw_1->item(i)->data(Qt::EditRole+1).toString()) ;
		}
	/*
	out << ui.lw_2->count() ;
	for( int i = 0; i < ui.lw_2->count(); i++ )
	{
		out << encrypt(ui.lw_2->item(i)->data(Qt::EditRole+1).toString()) ;
	}
	*/
	file.close() ;
}

void MainWindow::loadConfigFile()
{
	/*
	ui.lw_2->clearMe() ;
	QFile file(m_curDir+"/"+CONFIG) ;
	QDataStream in(&file) ;
	file.open(QIODevice::ReadOnly) ;
	QString path, hashkey ;
	int cnt ;
	in >> path ;
	in >> hashkey ;
	in >> cnt ;
	for( int i = 0; i < cnt; i++ )
	{
		QString key ;
		in >> key ;
		key = decrypt(key) ;
		ui.lw_2->addMyItem(key) ;
	}
	*/
}