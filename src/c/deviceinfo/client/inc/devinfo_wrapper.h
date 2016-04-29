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

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// for include specify method to get platform device info
// in android we use libcutils
#ifdef ANDROID
#include "cutils/properties.h"
#endif

// need to add struct define for DeviceInfo.
typedef struct {
  char *key;
  char *value
} MT_DeviceInfo;

int Get_DeviceInfo(MT_DeviceInfo *devinfo);
