#include "tkprotect.h"
#include <QProcess>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <QDir>
#include "winioctl.h"
#include "fileapi.h"

#define CONFIG "stickconfig.dat"
#define PROTECTRESULT "stickbin.data"

TKProtect::TKProtect(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	hide() ;
	m_extractName = "temporarystick.dll" ;

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint );

	QFile styleSheet(QString(":/res/qss/%1.qss").arg(3));
	if (styleSheet.open(QIODevice::ReadOnly)) {
		setStyleSheet(styleSheet.readAll());
		styleSheet.close() ;
	}

	if( !QFile(CONFIG).exists() )
	{
		QMessageBox::information(NULL,"", "This is not protected software." ) ;
		exit(1) ;
		return ;
	}
	m_process = new QProcess(this) ;
	connect( m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onFinished(int,QProcess::ExitStatus))) ;

	QFile file(CONFIG) ;
	QDataStream in(&file) ;
	file.open(QIODevice::ReadOnly) ;
	QString hashKey ;
	int cnt ;
	QString oriPath ;
	bool valid = false ;
	if( !in.atEnd() ) {
		in >> oriPath >> hashKey >> cnt ;
		for( int i = 0; i < cnt; i++ )
		{
			QString key ;
			in >> key ;
			if( !isInvalidKey(key) ) valid = true ;
		}
	}
	file.close() ;

	if( !valid ) 
	{
		QMessageBox::information(NULL,"", "This protected software cannot run on this drive." ) ;
		exit(1) ;
		return ;
	}

	QFile tempFile(m_extractName) ;
	if( tempFile.exists() )
	{
		m_process->start(m_extractName) ;
		return ;
	}
	
	file.setFileName(PROTECTRESULT) ;
	file.open(QIODevice::ReadOnly) ;
//	show() ;
	QByteArray ba = QByteArray::fromBase64(file.readAll()) ;

	file.close() ;
	tempFile.open(QIODevice::WriteOnly) ;
	tempFile.write(ba) ;
//	hide() ;
	tempFile.close() ;
	SetFileAttributes( (TCHAR*)m_extractName.utf16() ,FILE_ATTRIBUTE_HIDDEN) ;
	m_process->start(m_extractName) ;
}


TKProtect::~TKProtect()
{

}

void TKProtect::closeEvent(QCloseEvent* event)
{
	event->accept() ;
}

bool TKProtect::isInvalidKey(QString key)
{
	for( int i = 0; i < 26; i++ )
	{
		char d = 'A'+i ;
		QString serial = GetSerialNumberUSB(d) ;
		if( !serial.length() ) continue ;
		if( serial == key ) return false ;
		//		if( serial == hdA)
	}
	return true ;
}

void TKProtect::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	QFile(m_extractName).remove() ;
	close() ;
}


QString TKProtect::getSerial( QString drive ) 
{
	return GetSerialNumberUSB(drive.at(0).toLatin1()) ;
}

QString TKProtect::decrypt(const QString &password)
{
	return password;
}

QString TKProtect::encrypt(const QString &password)
{
	return password ;
}

QString TKProtect::GetSerialNumberUSB( char d ) {
	//	QMessageBox::information(NULL,"",getSerialNumberOfUSB('E')) ;
	string strSerialNumber ;
	char cmd[5]  ;
	cmd[0] = d, cmd[1] = ':', cmd[2] = 0 ;
	char text[100] = "\\\\.\\" ;
	strcat(text,cmd) ;
	QString str = text ;
	//	QMessageBox::information(NULL,"Running Drive", str) ;
	wchar_t wtext[30];
	mbstowcs(wtext, text, strlen(text)+1);//Plus null
	LPCWSTR sDriveName = wtext ;


	HANDLE hVolume = CreateFileW(
		sDriveName,                            // lpFileName
		0,                          // dwDesiredAccess
		FILE_SHARE_READ || FILE_SHARE_WRITE,   // dwShareMode
		NULL,                                  // lpSecurityAttributes
		OPEN_EXISTING,                         // dwCreationDisposition
		0,                 // dwFlagsAndAttributes
		NULL                                   // hTemplateFile
		);
	if (hVolume == INVALID_HANDLE_VALUE) {
		// print GetLastError()
		//		QMessageBox::information(NULL,"GET LAST ERROR", str) ;
		return "";
	}

	// set the STORAGE_PROPERTY_QUERY input
	STORAGE_PROPERTY_QUERY PropertyQuery;
	ZeroMemory(&PropertyQuery, sizeof(STORAGE_PROPERTY_QUERY));
	PropertyQuery.PropertyId = StorageDeviceProperty;
	PropertyQuery.QueryType = PropertyStandardQuery;

	// first call to DeviceIocontrol to get the size of the output
	STORAGE_DEVICE_DESCRIPTOR  DeviceDescriptor = { 0 };
	DWORD nBytesDeviceDescriptor = 0;
	if ( !DeviceIoControl(
		hVolume,                              // hDevice
		IOCTL_STORAGE_QUERY_PROPERTY,         // dwIoControlCode
		&PropertyQuery,                       // lpInBuffer
		sizeof(STORAGE_PROPERTY_QUERY),       // nInBufferSize
		&DeviceDescriptor,                    // lpOutBuffer
		sizeof(STORAGE_DESCRIPTOR_HEADER),    // nOutBufferSize
		&nBytesDeviceDescriptor,              // lpBytesReturned
		NULL                                  // lpOverlapped
		)) {
			// print GetLastError()
			CloseHandle(hVolume);
//			QMessageBox::information(NULL,"","GET LAST ERROR1") ;
			return "" ;
			//			return FALSE;
	}

	// allocate the output
	const DWORD dwOutBufferSize = DeviceDescriptor.Size;
	char* pOutBuffer = new char[dwOutBufferSize];
	ZeroMemory(pOutBuffer, dwOutBufferSize);
	STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer);

	// second call to DeviceIocontrol to get the actual output STORAGE_DEVICE_DESCRIPTOR
	if (!DeviceIoControl(
		hVolume,
		IOCTL_STORAGE_QUERY_PROPERTY,
		&PropertyQuery,
		sizeof(PropertyQuery),
		pDeviceDescriptor,
		dwOutBufferSize,
		&nBytesDeviceDescriptor,
		NULL
		)) {
			// print GetLastError()
			delete[] pOutBuffer;
			CloseHandle(hVolume);
//			QMessageBox::information(NULL,"","GET LAST ERROR3") ;
			//			return FALSE;
			return "" ;
	}

	const DWORD nSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
	if (nSerialNumberOffset == 0) {
		// print GetLastError()
		delete[] pOutBuffer;
		CloseHandle(hVolume);
		//		return FALSE;
//		QMessageBox::information(NULL,"","GET LAST ERROR4") ;
		return "" ;
	}
	strSerialNumber = static_cast<std::string>(pOutBuffer + nSerialNumberOffset);

	delete[] pOutBuffer;
	CloseHandle(hVolume);
	return QString::fromStdString(strSerialNumber) ;
	//	return (strSerialNumber.empty()) ? FALSE : TRUE;
}


void TKProtect::onTest()
{
}