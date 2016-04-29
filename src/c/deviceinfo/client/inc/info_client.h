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

// for linux socket
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

// should read from config store later
#define SERVERADDR "192.168.9.65"
#define SERVERPORT 5012

#define MAXSENDCOUNT 2048

static int clentsockfd;
static struct sockaddr_in serveraddr;
static char sendbuf[MAXSENDCOUNT];

// bytes read from recorder
static int readcount = 0;
// bytes send to server
static int sendcount = 0;

bool infoclient_init();
bool infoclient_startloop();
bool infoclient_term();
