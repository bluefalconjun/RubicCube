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
