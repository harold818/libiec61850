/*
 *  ethernet_linux.c
 *
 *  Copyright 2013-2026 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#include <string.h>

#include "hal_ethernet.h"
#include "lib_memory.h"

#ifndef DEBUG_SOCKET
#define DEBUG_SOCKET 0
#endif

EthernetHandleSet
EthernetHandleSet_new(void)
{
    return NULL;
}

void
EthernetHandleSet_addSocket(EthernetHandleSet self, const EthernetSocket sock)
{
    
}

void
EthernetHandleSet_removeSocket(EthernetHandleSet self, const EthernetSocket sock)
{
    
}

int
EthernetHandleSet_waitReady(EthernetHandleSet self, unsigned int timeoutMs)
{
    return -1;
}

void
EthernetHandleSet_destroy(EthernetHandleSet self)
{
    
}

static int
getInterfaceIndex(int sock, const char* deviceName)
{
    return -1;
}

void
Ethernet_getInterfaceMACAddress(const char* interfaceId, uint8_t* addr)
{
    
}

EthernetSocket
Ethernet_createSocket(const char* interfaceId, uint8_t* destAddress)
{
    return NULL;
}

void
Ethernet_setMode(EthernetSocket self, EthernetSocketMode mode)
{
    
}

void
Ethernet_addMulticastAddress(EthernetSocket self, const uint8_t* multicastAddress)
{
    
}

void
Ethernet_setProtocolFilter(EthernetSocket self, uint16_t etherType)
{
    
}

/* non-blocking receive */
int
Ethernet_receivePacket(EthernetSocket self, uint8_t* buffer, int bufferSize)
{
    return 0;
}

void
Ethernet_sendPacket(EthernetSocket self, uint8_t* buffer, int packetSize)
{
    
}

void
Ethernet_destroySocket(EthernetSocket self)
{
    
}

bool
Ethernet_isSupported()
{
    return false;
}
