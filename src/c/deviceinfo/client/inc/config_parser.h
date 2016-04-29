/********************************************************************************************/
/* Copyright (c) 2014 Montage Technology Group Limited and its affiliated companies         */
/* Montage Proprietary and Confidential                                                     */
/* Montage Technology (Shanghai) Co., Ltd.                                                  */
/********************************************************************************************/
/********************************************************************************************/
/* Copyright (c) 2015 Montage Technology Group Limited and its affiliated
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

#ifdef USE_JSMN_CONFIG
#include "jsmn.h"
#endif

// config parser implement parse the config files
// and return the key/value pairs to call module to determine the config

// current deviceinfo_collect module will use json files to handle config.
// see http://www.json.org for json file format.

// folder store the config files
#define DEVINFO_CONFIG_PATH "/data/misc/deviceinfo"

// folder store the record files
// NOTE we use same folder as config file and maybe change later for some temp
// storage.
#define DEVINFO_RECORD_PATH "/data/misc/deviceinfo"

// config file name
#define CONFIG_FILTER "loginfo_filter.json"
#define CONFIG_RECORD "record.json"
#define CONFIG_CLIENT "client.json"
