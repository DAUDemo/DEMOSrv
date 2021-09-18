#ifndef DEMOSRV_H
#define DEMOSRV_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <RFPSDTypes.h>
class DEMOSrv :QTcpServer
{
Q_OBJECT
public:

    DEMOSrv(const int iPortNum);

    int SendData (Int16 *pusAmp, UInt64 ulCount);

    Int16         *m_pusAmp = NULL;
private slots:

  /* This function is used to create the new SCD Client connection */
  void SlotNewConn ();

private:
  QTcpSocket           *m_pcSock;     // holds the Server Connection
};

#endif // DEMOSRV_H
