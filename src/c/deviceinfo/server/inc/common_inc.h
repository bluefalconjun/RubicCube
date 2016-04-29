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
#pragma once

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

// for different HOST_OS
//#define WINDOWS
#define LINUX

#ifdef WINDOWS
#include <winsock2.h>
typedef int socklen_t;
#endif

#ifdef LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#endif

using namespace std;
