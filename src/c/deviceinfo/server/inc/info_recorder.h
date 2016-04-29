/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated
 * companies         */
/* Montage Proprietary and Confidential */
/* Montage Technology (Shanghai) Co., Ltd. */
/********************************************************************************************/
/*recv and record the devinfo from client*/

#include "common_inc.h"

#define SERVERADDR "192.168.9.65"
#define SERVERPORT 5012

#define MAXRECVCOUNT 2048

// how to handle client list?
#define MAXCLIENTNUM 128

class InfoRecorder {
 private:
  int mServerSocket = -1;
  int mClientSocket = -1;
  struct sockaddr_in mServerAddr;

  char mRecvBuf[MAXRECVCOUNT];
  int mRecvBytes = -1;

  bool save();

 public:
  InfoRecorder();
  virtual ~InfoRecorder();
  bool init();
  bool startloop();
  bool term();
};
