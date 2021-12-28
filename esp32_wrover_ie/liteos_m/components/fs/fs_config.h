/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FS_CONFIG_H
#define _FS_CONFIG_H

#include "los_compiler.h"
#include "sys/socket.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

int *__errno_location(void);
#define errno (*__errno_location())
#define LFS_NO_ASSERT 1
#define FF_VOLUME_STRS "system", "inner", "update", "user"
#define FS_MAX_SS            512

#define FAT_MAX_OPEN_FILES   50
#define LITTLEFS_MAX_LFN_LEN 120

#define O_SEARCH             O_PATH
#define O_EXEC               O_PATH
#define O_TTY_INIT           0
#define ELIBBAD              80

#define O_ACCMODE            (03|O_SEARCH)
#define O_RDONLY             00
#define O_WRONLY             01
#define O_RDWR               02
#define O_CREAT              0100
#define O_EXCL               0200
#define O_NOCTTY             0400
#define O_TRUNC              01000
#define O_APPEND             02000
#define O_NONBLOCK           04000
#define O_DSYNC              010000
#define O_SYNC               04010000
#define O_RSYNC              04010000
#define O_DIRECTORY          040000
#define O_NOFOLLOW           0100000
#define O_CLOEXEC            02000000

#define O_ASYNC              020000
#define O_DIRECT             0200000
#define O_LARGEFILE          0400000
#define O_NOATIME            01000000
#define O_PATH               010000000
#define O_TMPFILE            020040000

#define _FNDELAY             O_NONBLOCK

#define F_OFD_GETLK          36
#define F_OFD_SETLK          37
#define F_OFD_SETLKW         38

#define F_DUPFD              0
#define F_GETFD              1
#define F_SETFD              2
#define F_GETFL              3
#define F_SETFL              4
#define F_GETLK              5
#define F_SETLK              6
#define F_SETLKW             7
#define F_SETOWN             8
#define F_GETOWN             9
#define F_SETSIG             10
#define F_GETSIG             11

#define F_SETOWN_EX          15
#define F_GETOWN_EX          16

#define F_GETOWNER_UIDS      17

#define F_DUPFD_CLOEXEC      1030

#define F_RDLCK              0
#define F_WRLCK              1
#define F_UNLCK              2

#define FD_CLOEXEC           1

#define AT_FDCWD             (-100)
#define AT_SYMLINK_NOFOLLOW  0x100
#define AT_REMOVEDIR         0x200
#define AT_SYMLINK_FOLLOW    0x400
#define AT_EACCESS           0x200

#define POSIX_FADV_NORMAL     0
#define POSIX_FADV_RANDOM     1
#define POSIX_FADV_SEQUENTIAL 2
#define POSIX_FADV_WILLNEED   3
#ifndef POSIX_FADV_DONTNEED
#define POSIX_FADV_DONTNEED   4
#define POSIX_FADV_NOREUSE    5
#endif

#undef SEEK_SET
#undef SEEK_CUR
#undef SEEK_END
#define SEEK_SET              0
#define SEEK_CUR              1
#define SEEK_END              2

#ifndef S_IRUSR
#define S_ISUID               04000
#define S_ISGID               02000
#define S_ISVTX               01000
#define S_IRUSR               0400
#define S_IWUSR               0200
#define S_IXUSR               0100
#define S_IRWXU               0700
#define S_IRGRP               0040
#define S_IWGRP               0020
#define S_IXGRP               0010
#define S_IRWXG               0070
#define S_IROTH               0004
#define S_IWOTH               0002
#define S_IXOTH               0001
#define S_IRWXO               0007
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define AT_NO_AUTOMOUNT 0x800
#define AT_EMPTY_PATH 0x1000
#define AT_STATX_SYNC_TYPE 0x6000
#define AT_STATX_SYNC_AS_STAT 0x0000
#define AT_STATX_FORCE_SYNC 0x2000
#define AT_STATX_DONT_SYNC 0x4000
#define AT_RECURSIVE 0x8000

#define FAPPEND O_APPEND
#define FFSYNC O_SYNC
#define FASYNC O_ASYNC
#define FNONBLOCK O_NONBLOCK
#define FNDELAY O_NDELAY

#define F_OK 0
#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_ULOCK 0
#define F_LOCK  1
#define F_TLOCK 2
#define F_TEST  3

#define F_SETLEASE	1024
#define F_GETLEASE	1025
#define F_NOTIFY	1026
#define F_CANCELLK	1029
#define F_SETPIPE_SZ	1031
#define F_GETPIPE_SZ	1032
#define F_ADD_SEALS	1033
#define F_GET_SEALS	1034

#define F_SEAL_SEAL	0x0001
#define F_SEAL_SHRINK	0x0002
#define F_SEAL_GROW	0x0004
#define F_SEAL_WRITE	0x0008
#define F_SEAL_FUTURE_WRITE	0x0010

#define F_GET_RW_HINT		1035
#define F_SET_RW_HINT		1036
#define F_GET_FILE_RW_HINT	1037
#define F_SET_FILE_RW_HINT	1038

#define RWF_WRITE_LIFE_NOT_SET	0
#define RWH_WRITE_LIFE_NONE	1
#define RWH_WRITE_LIFE_SHORT	2
#define RWH_WRITE_LIFE_MEDIUM	3
#define RWH_WRITE_LIFE_LONG	4
#define RWH_WRITE_LIFE_EXTREME	5

#define DN_ACCESS	0x00000001
#define DN_MODIFY	0x00000002
#define DN_CREATE	0x00000004
#define DN_DELETE	0x00000008
#define DN_RENAME	0x00000010
#define DN_ATTRIB	0x00000020
#define DN_MULTISHOT	0x80000000
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _FS_CONFIG_H */
