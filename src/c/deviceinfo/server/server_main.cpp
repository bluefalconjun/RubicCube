/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
/*server main process*/

#include "server_main.h"

int main(int argc, char** argv) {
  InfoRecorder* curInfoRecorder = new InfoRecorder;
  curInfoRecorder->init();
  curInfoRecorder->startloop();

  printf("Will Never See This !!\n");
  return 0;
}
