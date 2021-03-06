#include "filedesc.h"
#include "file.h"

/*
 * Following macros are not defined in newlib, but are needed for build some
 * legacy code used in Lua RTOS
 *
 */
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#define MALLOC(space, cast, size) \
    (space) = (cast)malloc((u_long)(size))

#define FREE(addr) free(addr)

#define FFLAGS(oflags)  ((oflags) + 1)
#define OFLAGS(fflags)  ((fflags) - 1)
#define FFSYNC FSYNC
#define FNONBLOCK FNONBIO
#define FIONBIO FNONBIO
#define FMASK       (FREAD|FWRITE|FAPPEND|FASYNC|FFSYNC|FNONBLOCK)
#define FCNTLFLAGS  (FAPPEND|FASYNC|FFSYNC|FNONBLOCK)

/*
 * File system types
 */
#define FS_TTY    1
#define FS_SPIFFS 2
#define FS_FAT    3

/*
 * Function prototypes provided
 */
int falloc(struct file **resultfp, int *resultfd);
int closef(register struct file *fp);
int fcntl(int fd, int cmd, ... );
struct file *get_file(int fd);
int getdents (int fd, void *buff, int size);
