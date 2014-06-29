/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  apue.h
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  header file of apue
 *
 * =============================================================
 */


/**
 * @file
 * @brief apue header
 *
 * Most programs in the text include the header apue.h (ourheader.h in the first edition)
 * It defines constatnts( such as MAXLINE ) and prototypes for apue functions.
 *
 * Most programs need to include the following headers: 
 * <stdio.h>, <stdilib.h> ( for the exit function prototype), 
 * <unistd.h> ( for all the standard UNIX function prototypes). 
 * So our header automatically includes these system headers, 
 * along with <string.h>. 
 * This also reduces the size of all the program listing in the text
 */


#ifndef _APUE_H
#define _APUE_H

/** Single UNIX Specification, Version 3 */
#define _XOPEN_SOURCE 600

#include <sys/types.h>                          /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>                        /* for winsize */
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif
#include <stdio.h>                              /* for convenience */
#include <stdlib.h>                             /* for convenience */
#include <stddef.h>                             /* for offsetof */
#include <string.h>                             /* for convenience */
#include <unistd.h>                             /* for convenience */
#include <signal.h>                             /* for SIG_ERR */

/** max line length */
#define MAXLINE 4096

/** Default file access permissions for new files. */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/** Default permissions for new directories. */
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)
/**
 * @brief for signal handlers
 */
typedef void Sigfunc(int);

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((Sigfunc *) -1)
#endif

#define min(a,b) ((a) < (b) ? (a) : (b) )
#define max(a,b) ((a) > (b) ? (a) : (b) )
char *path_alloc(int *);                        /* Figure 2.15 */
long open_max(void);                            /* Figure 2.16 */
void clr_fl(int, int);                          /* Figure 3.11 */
void set_fl(int, int);                          /* Figure 3.11 */
void pr_exit(int);                              /* Figure 8.5 */
void pr_mask(const char *);                     /* Figure 10.14 */
Sigfunc *signal_intr(int, Sigfunc *);           /* Figure 10.19 */

int tty_cbreak(int);                            /* Figure 18.20 */
int tty_raw(int);                               /* Figure 18.20 */
int tty_reset(int);                             /* Figure 18.20 */
void tty_atexit(void);                          /* Figure 18.20 */

#ifdef ECHO                                     /* Only if <termios.h> has been included */
struct termios *tty_termios(void);              /* Figure 18.20 */
#endif

void sleep_us(unsigned int);                    /* Exercise 14.6 */
ssize_t readn(int, void *, size_t);             /* Figure 14.29 */
ssize_t writen(int, const void *, size_t);      /* Figure 14.29 */
void daemonize(const char *);                   /* Figure 13.1 */
int s_pipe(int *);                              /* Figure 17.6 17.13 */

int recv_fd(int, ssize_t (*func) (int, const void *, size_t)); /* Figure 17.21 17.23 */

int send_fd(int, int);                          /* Figure 17.20 17.22 */

int send_err(int, int, const char *);           /* Figure 17.19 */

int serv_listen(const char *);                  /* Figure 17.10 17.15 */
int serv_accept(int, uid_t *);                  /* Figure 17.11 17.16 */
int cli_conn(const char *);                     /* Figure 17.12 17.17 */
int buf_args(char *, int (*func) (int, char **)); /* Figure 17.32 */

int ptym_open(char *, int);                     /* Figure 19.8 19.9 19.10 */
int ptys_open(char *);                          /* Figure 19.8 19.9 19.10 */

#ifdef TIOCGWINSZ
pid_t pty_fork(int *, char *, int, const struct termios *,
               const struct winsize *);         /* Figure 19.11 */
#endif

int lock_reg(int, int, int, off_t, int, off_t); /* Figure 14.5 */
#define read_lock(fd, offset, whence, len) \
            lock_reg((fd), F_SETLK, F_RDLCK, (offset), (whence), (len))
#define readw_lock(fd, offset, whence, len) \
            lock_reg((fd), F_SETLKW, F_RDLCK, (offset), (whence), (len))
#define write_lock(fd, offset, whence, len) \
            lock_reg((fd), F_SETLK, F_WRLCK, (offset), (whence), (len))
#define writew_lock(fd, offset, whence, len) \
            lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
#define un_lock(fd, offset, whence, len) \
            lock_reg((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))

pid_t lock_test(int, int, off_t, int, off_t);   /* Figure 14.6 */
#define is_read_lockable(fd, offset, whence, len) \
            (lock_test((fd), F_RDLCK, (offset), (whence), (len)) == 0)
#define is_write_lockable(fd, offset, whence, len) \
            (lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)
/**
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
void err_dump(const char *, ...);
/**
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 *
 */
void err_msg(const char *, ...);
/**
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char *, ...);
/**
 * Fatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and terminate.
 */
void err_exit(int, const char *, ...);
/**
 * Nonfatal error related to a system call.
 * Print a message and return.
 */
void err_ret(const char *, ...);
/**
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char *, ...);


/**
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void log_msg(const char *, ...);
/**
 * Initialize syslog(), if running as daemon.
 */
void log_open(const char *, int, int);
/**
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void log_quit(const char *, ...);
/**
 * Nonfatal error related to a system call.
 * Print a message with the system's errno value and return.
 */
void log_ret(const char *, ...);
/**
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void log_sys(const char *, ...);

/**
 * parent/child from Section 8.9 
 */
void TELL_WAIT(void);
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);
/*
 * libraries
 */
int system_lib(const char *cmdstring);
Sigfunc *signal_lib(int, Sigfunc *);
unsigned int sleep_lib(unsigned sec);





#endif        /* _APUE_H */


