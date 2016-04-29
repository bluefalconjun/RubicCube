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

#include "info_client.h"
#include "info_recorder.h"

bool infoclient_init() {
  clentsockfd = -1;
  memset(sendbuf, 0, MAXSENDCOUNT);

  // prepare socket
  clentsockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == clentsockfd) {
    printf("Create Socket Fail!\n");
    exit(-1);
  }

  serveraddr.sin_addr.s_addr = inet_addr(SERVERADDR);
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(SERVERPORT);

  // Connect to remote server
  if (connect(clentsockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) <
      0) {
    printf("Connect To Server Fail!\n");
    exit(1);
  }

  return true;
}

bool infoclient_startloop() {
  while (1) {
    // read from info_recorder
    readcount = inforecorder_read(sendbuf, MAXSENDCOUNT);

    // send to server
    if (-1 != readcount) {
      sendcount = send(clentsockfd, sendbuf, readcount, 0);
    }
  }
  return true;
}

bool infoclient_term() { return true; }
