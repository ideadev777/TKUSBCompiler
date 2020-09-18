#include "common.h"
#include <QUuid>
#include <QString>
#include <QProcess>

QString createUuid()
{
	return QUuid::createUuid().toString() ;
}

QString createSimpleUuid()
{
	QString ret = createUuid() ;
	ret.chop(1) ;
	ret = ret.right(ret.length()-1) ;
	return ret ;
}

int getMSec(QTime t) 
{
	int ret = t.hour()*3600 ;
	ret += t.minute()*60 ;
	ret += t.second() ;
	ret = ret*1000+t.msec() ;
	return ret ;
}

QTime getTime(qint64 msec) 
{
	int s = msec/1000 ;
	msec %= 1000 ;
	int h = s/3600 ;
	s %= 3600 ;
	int m = s/60 ;
	s%=60 ;
	return QTime(h,m,s,msec) ;
}

void runProcess( QObject* parent, QString path, QStringList arg )
{
	QProcess *myProcess = new QProcess(parent);
	myProcess->start(path,arg);
	if (myProcess->waitForStarted(-1)) {
		while(myProcess->waitForReadyRead(-1)) {
		}
	}
}

QString getSerial( QString drive ) 
{
	return GetSerialNumberUSB(drive.at(0).toLatin1()) ;
}


QString decrypt(const QString &password)
{
	return password;
	/*
	string plain;
	string encrypted = password.toStdString();
	// Hex decode symmetric key:
	HexDecoder decoder;
	decoder.Put( (byte *)PRIVATE_KEY,32*2 );
	decoder.MessageEnd();
	word64 size = decoder.MaxRetrievable();
	char *decodedKey = new char[size];
	decoder.Get((byte *)decodedKey, size);
	// Generate Cipher, Key, and CBC
	byte key[ AES::MAX_KEYLENGTH ], iv[ AES::BLOCKSIZE ];
	StringSource( reinterpret_cast<const char *>(decodedKey), true,
		new HashFilter(*(new SHA256), new ArraySink(key, AES::MAX_KEYLENGTH)) );
	memset( iv, 0x00, AES::BLOCKSIZE );
	try {
		CBC_Mode<AES>::Decryption Decryptor
			( key, sizeof(key), iv );
		StringSource( encrypted, true,
			new HexDecoder(new StreamTransformationFilter( Decryptor,
			new StringSink( plain ) ) ) );
	}
	catch (Exception &e) { // ...
	}
	catch (...) { // ...
	}
	return QString::fromStdString(plain);
	*/
}

QString encrypt(const QString &password)
{
	return password ;
	
	/*
	string plain = password.toStdString();
	string ciphertext;
	// Hex decode symmetric key:
	HexDecoder decoder;
	decoder.Put( (byte *)PRIVATE_KEY, 32*2 );
	decoder.MessageEnd();
	word64 size = decoder.MaxRetrievable();
	char *decodedKey = new char[size];
	decoder.Get((byte *)decodedKey, size);
	// Generate Cipher, Key, and CBC
	byte key[ AES::MAX_KEYLENGTH ], iv[ AES::BLOCKSIZE ];
	StringSource( reinterpret_cast<const char *>(decodedKey), true,
		new HashFilter(*(new SHA256), new ArraySink(key, AES::MAX_KEYLENGTH)) );
	memset( iv, 0x00, AES::BLOCKSIZE );
	CBC_Mode<AES>::Encryption Encryptor( key, sizeof(key), iv );
	StringSource( plain, true, new StreamTransformationFilter( Encryptor,
		new HexEncoder(new StringSink( ciphertext ) ) ) );
	return QString::fromStdString(ciphertext);
	*/
}

QString GetSerialNumberUSB( char d ) {
	//	QMessageBox::information(NULL,"",getSerialNumberOfUSB('E')) ;
	string strSerialNumber ;
	char cmd[5] ;
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


QString getSerialNumberOfUSB( char d ) {

	string strSerialNumber ;
	char cmd[5]  ;
	cmd[0] = d, cmd[1] = ':', cmd[2] = 0 ;
	char text[100] = "\\\\.\\" ;
	strcat(text,cmd) ;
	wchar_t wtext[30];
	mbstowcs(wtext, text, strlen(text)+1);//Plus null

	LPCWSTR sDriveName = wtext ;


	HANDLE hVolume = CreateFileW(
		sDriveName,                            // lpFileName
		GENERIC_READ,                          // dwDesiredAccess
		FILE_SHARE_READ || FILE_SHARE_WRITE,   // dwShareMode
		NULL,                                  // lpSecurityAttributes
		OPEN_EXISTING,                         // dwCreationDisposition
		FILE_ATTRIBUTE_NORMAL,                 // dwFlagsAndAttributes
		NULL                                   // hTemplateFile
		);
	if (hVolume == INVALID_HANDLE_VALUE) {
		// print GetLastError()
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
			return "" ;
			//FALSE;
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
			//FALSE;
			return "" ;
	}

	const DWORD nSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
	if (nSerialNumberOffset == 0) {
		// print GetLastError()
		delete[] pOutBuffer;
		CloseHandle(hVolume);
		//FALSE
		return "" ;
	}
	strSerialNumber = static_cast<std::string>(pOutBuffer + nSerialNumberOffset);

	delete[] pOutBuffer;
	CloseHandle(hVolume);
	return QString::fromStdString(strSerialNumber) ;
}