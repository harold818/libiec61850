/*
 *  file_provider_linux.c
 *
 *  Copyright 2014-2018 Michael Zillgith
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
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#include "hal_filesystem.h"
#include "lib_memory.h"

FileHandle
FileSystem_openFile(char* fileName, bool readWrite)
{
    return NULL;
}

int
FileSystem_readFile(FileHandle handle, uint8_t* buffer, int maxSize)
{
    return 0;
}

int
FileSystem_writeFile(FileHandle handle, uint8_t* buffer, int size)
{
    return 0;
}

void
FileSystem_closeFile(FileHandle handle)
{
    
}

bool
FileSystem_deleteFile(char* filename)
{
    return false;
}

bool
FileSystem_renameFile(char* oldFilename, char* newFilename)
{
    return false;
}


bool
FileSystem_getFileInfo(char* filename, uint32_t* fileSize, uint64_t* lastModificationTimestamp)
{
    return false;
}

DirectoryHandle
FileSystem_openDirectory(char* directoryName)
{
    return NULL;
}

char*
FileSystem_readDirectory(DirectoryHandle directory, bool* isDirectory)
{
    return NULL;
}

void
FileSystem_closeDirectory(DirectoryHandle directory)
{
    
}

