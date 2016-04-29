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

#include "info_recorder.h"

InfoRecorder::InfoRecorder() { return; }

InfoRecorder::~InfoRecorder() { return; }

bool InfoRecorder::init() {
  // prepare the socket
  mServerSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == mServerSocket) {
    printf("Create Socket Fail!\n");
    exit(-1);
  }

  memset(&mServerAddr, 0, sizeof(mServerAddr));
  mServerAddr.sin_family = AF_INET;
  mServerAddr.sin_port = htons((u_short)SERVERPORT);
  mServerAddr.sin_addr.s_addr = htons(INADDR_ANY);

  if (-1 == bind(mServerSocket, (struct sockaddr *)&mServerAddr,
                 sizeof(struct sockaddr_in))) {
    printf("Bind Socket Fail!\n");
    exit(-1);
  }

  if (-1 == listen(mServerSocket, 200)) {
    printf("Listen Socket Fail!\n");
    exit(-1);
  }

  return true;
}

// need to make startloop as non-block call with create thread
bool InfoRecorder::startloop() {
  // recv from client
  mClientSocket = accept(mServerSocket, NULL, NULL);
  while (1) {
    mRecvBytes = read(mClientSocket, mRecvBuf, MAXRECVCOUNT);
    if (-1 != mRecvBytes) {
      printf("%s\n", mRecvBuf);
    }
  }
  // save();
  return true;
}

bool InfoRecorder::term() { return true; }
