#pragma once

#include <iostream>
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
#endif

using namespace std;
