/*
 *  serial_port_linux.c
 *
 *  Copyright 2013-2024 Michael Zillgith
 *
 *  This file is part of Platform Abstraction Layer (libpal)
 *  for libiec61850, libmms, and lib60870.
 */

#include "lib_memory.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "hal_serial.h"
#include "hal_time.h"

struct sSerialPort {
    char interfaceName[100];
    int fd;
    int baudRate;
    uint8_t dataBits;
    char parity;
    uint8_t stopBits;
    uint64_t lastSentTime;
    int timeout;
    SerialPortError lastError;
};

SerialPort
SerialPort_create(const char* interfaceName, int baudRate, uint8_t dataBits, char parity, uint8_t stopBits)
{
    SerialPort self = (SerialPort) GLOBAL_MALLOC(sizeof(struct sSerialPort));

    if (self != NULL) {
        self->fd = -1;
        self->baudRate = baudRate;
        self->dataBits = dataBits;
        self->stopBits = stopBits;
        self->parity = parity;
        self->lastSentTime = 0;
        self->timeout = 100; /* 100 ms */
        strncpy(self->interfaceName, interfaceName, 99);
        self->lastError = SERIAL_PORT_ERROR_NONE;
    }

    return self;
}

void
SerialPort_destroy(SerialPort self)
{
    if (self != NULL) {
        GLOBAL_FREEMEM(self);
    }
}

bool
SerialPort_open(SerialPort self)
{
    return true;
}

void
SerialPort_close(SerialPort self)
{
    
}

int
SerialPort_getBaudRate(SerialPort self)
{
    return self->baudRate;
}

void
SerialPort_discardInBuffer(SerialPort self)
{
    
}

void
SerialPort_setTimeout(SerialPort self, int timeout)
{
    self->timeout = timeout;
}

SerialPortError
SerialPort_getLastError(SerialPort self)
{
    return self->lastError;
}

int
SerialPort_readByte(SerialPort self)
{
    return -1;
}

int
SerialPort_write(SerialPort self, uint8_t* buffer, int startPos, int bufSize)
{
    return -1;
}
