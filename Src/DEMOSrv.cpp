#include "DEMOSrv.h"
#include <unistd.h>
#include <RFPSDTypes.h>

DEMOSrv::DEMOSrv(const int iPortNum)
                : m_pcSock(NULL), m_pusAmp(NULL)
{

    connect (this, SIGNAL (newConnection ()), this, SLOT (SlotNewConn ()));

    if (listen(QHostAddress::Any, iPortNum) == false) {

       qDebug (" Server failed to listen ");
    }
    else {
      qDebug ("server listening on %d client to connect\n", iPortNum);
    }
}

void DEMOSrv::SlotNewConn () {
    qDebug ("Client connected");
    if (m_pcSock != NULL)
      { delete m_pcSock; m_pcSock = NULL; }

    m_pcSock = nextPendingConnection ();

    QFile *pcFlData;
    bool bStatus;

    Int32  iAmpRawData = 0;

    // Open the file for reading
    pcFlData = new QFile ("Large_Trig_Data.dat");

    QTextStream ocDatFile (pcFlData);

    bStatus = pcFlData->open (QFile::ReadOnly);

    if (bStatus == false)
      { qDebug ()<<"Unable to Open File "; exit (1); }


    unsigned long int ulCount = 0;

    bool flag = false;
    while (!ocDatFile.atEnd()) {

      m_pusAmp = (Int16*) realloc (m_pusAmp, sizeof (Int16) * (ulCount + 1));

      if (flag == false) {
        qDebug () << ocDatFile.readLine().toInt ();
        flag = true;
      } else {
          iAmpRawData = ocDatFile.readLine().toInt ();
          m_pusAmp[ulCount] = iAmpRawData + 2048;
          ulCount++;
      }

      if (ulCount == (1024*24)) {
          this->SendData(m_pusAmp, ulCount);
          usleep (50000);
          ulCount = 0;
      }
    }

    if (ulCount > 0) {
        this->SendData(m_pusAmp, ulCount);
    }
}

int DEMOSrv::SendData (Int16 *pusAmp, UInt64 ulCount)
{

  int iBytes = 0;
  if ((m_pcSock != NULL) &&
      (m_pcSock->state () == QAbstractSocket::ConnectedState)) {

    iBytes = m_pcSock->write ((char*)pusAmp, ulCount*sizeof(Int16));
    m_pcSock->waitForBytesWritten (1000);
  }
  free (m_pusAmp); m_pusAmp = NULL;
  return iBytes;
}
