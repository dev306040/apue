/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  apue_main.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */

/**
 * @file
 * @brief Entry of apue program
 */
#include "apue.h"
/*
 * program
 */
int ls1_main(int argc, char *argv[]);           /* Figure 1.3 */
int mycat_main(int argc, char *argv[]);         /* Figure 1.4 3.4 */
int getcputc_main(int argc, char *argv[]);      /* Figure 1.5 5.4*/
int hello_main(int argc, char *argv[]);         /* Figure 1.6 */
int shell1_main(int argc, char *argv[]);        /* Figure 1.7 */
int testerror_main(int argc, char *argv[]);     /* Figure 1.8 */
int uidgid_main(int argc, char *argv[]);        /* Figure 1.9 */
int shell2_main(int argc, char *argv[]);        /* Figure 1.10 */

int conf_main(int argc, char *argv[]);          /* Figure 2.13 */
int seek_main(int argc, char *argv[]);          /* Figure 3.1 */
int hole_main(int argc, char *argv[]);          /* Figure 3.2 */
int fileflags_main(int argc, char *argv[]);     /* Figure 3.10 */


int filetype_main(int argc, char *argv[]);      /* Figure 4.3 */
int access_main(int argc, char *argv[]);        /* Figure 4.8 */
int umask_main(int argc, char *argv[]);         /* Figure 4.9 */
int changemod_main(int argc, char *argv[]);     /* Figure 4.12 */
int unlink_main(int argc, char *argv[]);        /* Figure 4.16 */
int zap_main(int argc, char *argv[]);           /* Figure 4.21 */
int ftw4_main(int argc, char *argv[]);          /* Figure 4.22 */
int mycd_main(int argc, char *argv[]);          /* Figure 4.23 */
int cdpwd_main(int argc, char *argv[]);         /* Figure 4.24 */
int devrdev_main(int argc, char *argv[]);       /* Figure 4.25 */

int fgetsfputs_main(int argc , char *argv[]);   /* Figure 5.5 */
int buf_main(int argc, char *argv[]);           /* Figure 5.11 */
int tempfiles_main(int argc, char *argv[]);     /* Figure 5.12 */
int tempnam_main(int argc, char *argv[]);       /* Figure 5.13 */



int hello1_main(int argc, char *argv[]);        /* Figure 7.1 */
int doatexit_main(int argc, char *argv[]);      /* Figure 7.3 */
int echoarg_main(int argc, char *argv[]);       /* Figure 7.4 */
int testjmp_main(int argc, char *argv[]);       /* Figure 7.13 */
int getrlimit_main(int argc, char *argv[]);     /* Figure 7.16 */

int fork1_main(int argc, char *argv[]);         /* Figure 8.1 */
int vfork1_main(int argc, char *argv[]);        /* Figure 8.3 */
int wait1_main(int argc, char *argv[]);         /* Figure 8.6 */
int fork2_main(int argc, char *argv[]);         /* Figure 8.8 */
int tellwait1_main(int argc, char *argv[]);     /* Figure 8.12 */
int tellwait2_main(int argc, char *argv[]);     /* Figure 8.13 */
int exec1_main(int argc, char *argv[]);         /* Figure 8.16 */
int echoall_main(int argc, char *argv[]);       /* Figure 8.17 */
int exec2_main(int argc, char *argv[]);         /* Figure 8.20 */
int systest1_main(int argc, char *argv[]);      /* Figure 8.23 */
int systest3_main(int argc, char *argv[]);      /* Figure 8.24 */
int pruids_main(int argc, char *argv[]);        /* Figure 8.25 */
int test1_main(int argc, char *argv[]);         /* Figure 8.28 */
int pracct_main(int argc, char *argv[]);        /* Figure 8.29 */
int times1_main(int argc, char *argv[]);        /* Figure 8.30 */

int orphan3_main(int argc, char *argv[]);       /* Figure 9.11 */

int sigusr_main(int argc , char *argv[]);       /* Figure 10.2 */
int reenter_main(int argc, char *argv[]);       /* Figure 10.5 */
int child_main(int argc, char *argv[]);         /* Figure 10.6 */
int tsleep2_main(int argc, char *argv[]);       /* Figure 10.9 */
int read1_main(int argc, char *argv[]);         /* Figure 10.10 */
int read2_main(int argc, char *argv[]);         /* Figure 10.11 */
int critical_main(int argc, char *argv[]);      /* Figure 10.15 */
int mask_main(int argc, char *argv[]);          /* Figure 10.20 */
int suspend1_main(int argc, char *argv[]);      /* Figure 10.22 */
int suspend2_main(int argc, char *argv[]);      /* Figure 10.23 */
int systest2_main(int argc, char *argv[]);      /* Figure 10.26 */
int sigtstp_main(int argc, char *argv[]);       /* Figure 10.30 */



typedef struct {
  const char *figure;
  int (*fn) (int argc, char *argv[]);
  const char *name;
  const char *msg;
} item_t;

static item_t map[] = 
{
  { "1.3", ls1_main, "ls1" , "List all the files in a directory" },
  { "1.4", mycat_main, "mycat" , "Copy standard input to standard output"},
  { "1.5", getcputc_main, "getcputc", "Copy standard input to standard output, using standard I/O" },
  { "1.6", hello_main, "hello", "Print the process ID" },
  { "1.7", shell1_main, "shell1", "Read commands from standard input and execute them" },
  { "1.8", testerror_main, "testerror", "Demonstrate strerror and perror" },
  { "1.9", uidgid_main, "uidgid", "Print user ID and group ID" },
  { "1.10", shell2_main, "shell2", "Read commands from standard input and execute them" },
  { "2.13", conf_main, "conf", "Print all possible sysconf and pathconf values" },
  { "3.1", seek_main, "seek", "Test wheter standard input is capable of seeking"},
  { "3.2", hole_main, "hole", "Create a file with a hole in it"},
  { "3.4", mycat_main, "mycat", "Copy standard input to standard output"},
  { "3.10", fileflags_main, "fileflags", "Print file flags for specified descriptor"},
  { "4.3", filetype_main, "filetype", "Print type of file for each command-line argument"},
  { "4.8", access_main, "access", "Example of access function"},
  { "4.9", umask_main, "umask", "Example of umask function"},
  { "4.12", changemod_main, "changemod", "Example of chmod function"},
  { "4.16", unlink_main, "unlink", "Open a file and then unlink it"},
  { "4.21", zap_main, "zap", "Example of utime function"},
  { "4.22", ftw4_main, "ftw4", "Recursively descend a directory hierarchy, counting file types"},
  { "4.23", mycd_main, "mycd", "Example of chdir function"},
  { "4.24", cdpwd_main, "cdpwd", "Example of getcwd function"},
  { "4.25", devrdev_main, "devrdev", "Print st_dev and st_rdev values"},
  { "5.4", getcputc_main, "getcputc", "Copy standard input to standard output using getc and putc"},
  { "5.5", fgetsfputs_main, "fgetsfputs", "Copy standard input to standard output using fgets and fputs"},
  { "5.11", buf_main, "buf", "Print buffering for various standard I/O streams"},
  { "5.12", tempfiles_main, "tempfiles", "Demonstrate tmpnam and tmpfile functions"},
  { "5.13", tempnam_main, "tempnam", "Demonstrate tempnam function"},
  { "7.1", hello1_main, "hello1", "Classic C program"},
  { "7.3", doatexit_main, "doatexit", "Example of exit handlers"},
  { "7.4", echoarg_main, "echoarg", "Echo all command-line arguments to standard output"},
  { "7.13", testjmp_main, "testjmp", "Effect of longjmp on various types of variables"},
  { "7.16", getrlimit_main, "getrlimit", "Print the current resource limits"},
  { "8.1", fork1_main, "fork1", "Example of fork function"},
  { "8.3", vfork1_main, "vfork1", "Example of vfork function"},
  { "8.6", wait1_main, "wait1", "Demonstrate various exit statuses"},
  { "8.8", fork2_main, "fork2", "Avoid zombie processes by calling fork twice"},
  { "8.12", tellwait1_main, "tellwait1", "Program with a race condition"},
  { "8.13", tellwait2_main, "tellwait2", "Modification of Figure 8.12 to avoid race condition"},
  { "8.16", exec1_main, "exec1", "Example of exec functions"},
  { "8.17", echoall_main, "echoall", "Echo all command-line arguments and all environment strings"},
  { "8.20", exec2_main, "exec2", "A program that execs an interpreter file"},
  { "8.23", systest1_main, "systest1", "Calling the system function"},
  { "8.24", systest3_main, "systest3", "Execute the command-line argument using system"},
  { "8.25", pruids_main, "pruids", "Print real and effective user IDs"},
  { "8.28", test1_main, "test1", "Program to generate accounting data"},
  { "8.29", pracct_main, "pracct", "Print selected fields form system's accounting file"},
  { "8.30", times1_main, "times1", "Time and execute all command-line arguments"},
  { "9.11", orphan3_main, "orphan3", "Creating an orphaned process group"},
  { "10.2", sigusr_main, "sigusr", "Simple program to catch SIGUSR1 and SIGUSR2"},
  { "10.5", reenter_main, "reenter", "Call a nonreentrant function from a signal handler"},
  { "10.6", child_main, "child", "System V SIGCLD handler that doesnt' work"},
  { "10.9", tsleep2_main, "tsleep2", "Calling sleep2 from a program that catches other signals" },
  { "10.10", read1_main, "read1", "Calling read with a timeout" },
  { "10.11", read2_main, "read2", "Calling read with a timeout, using longjmp" },
  { "10.15", critical_main, "critical", "Example of signal sets and sigprocmask" },
  { "10.20", mask_main, "mask", "Example of signal masks, sigsetjmp, and siglongjmp"},
  { "10.22", suspend1_main, "suspend1", "Protecting a critical region from a signal"},
  { "10.23", suspend2_main, "suspend2", "Using sigsuspend to wait for a global variable to be set"},
  { "10.26", systest2_main, "systest2", "Using system to invoke the ed editor" },
  { "10.30", sigtstp_main, "sigtstp", "How to handler SIGTSTP" },




  { 0 , 0 , 0 }
};

typedef struct {
  const char *name;
  const char *figure;
  const char *msg;
} libitem_t;

static libitem_t libmap[] = {
  { "path_alloc", "2.15", "Dynamically allocate space for a pathname"}, 
  { "open_max", "2.16", "Determine the number of file descriptors" },
  { "set_fl", "3.11", "Turn on one or more of the file status flags for a descriptor"},
  { "# getpwnam", "6.2", "The getpwnam function" },
  { "pr_exit", "8.5", "Print a description of the exit status" },
  { "# system", "8.22", "The system function, without signal handling" },
  { "", "10.28", "Correct POSIX.1 implemetation of system function" },
  { "# sleep", "10.7", "Simple, incomplete implementation of sleep" },
  { "", "10.8", "Another (imperfect) implementation of sleep" },
  { "", "10.29", "Reliable implementation of sleep" },
  { "# sigaddset", "10.12", "An implementation of sigaddset, sigdelset, and sigismember"},
  { "# sigdelset", "", ""},
  { "# sigismember", "", ""},
  { "pr_mask", "10.14", "Print the signal mask for the process" },
  { "# signal", "10.18", "An implementation of signal using sigaction" },
  { "", "10.19", "signal_intr try to prevent any interrupted system calls from being started" },
  { "TELL_WAIT", "10.24", "Routines to allow a parent and child to synchronize" },
  { "TELL_PARENT", "", "" },
  { "WAIT_PARENT", "", "" },
  { "TELL_CHILD", "", "" },
  { "WAIT_CHILD", "", "" },
  { "# abort", "10.25", "Implementation of POSIX.1 abort" },

  { 0 , 0 , 0 }
};

const char *basename(const char *path)
{
  const char *p = strrchr(path , '/');
  if (!p) return path;
  return p + 1;
}
void showapp()
{
  item_t *p = map;
  printf("Programs:\n");
  while (p->figure) {
    printf(" %-15s %-6s %s\n" , p->name, p->figure, p->msg);
    p++;
  }
}

void showlib()
{
  libitem_t *p = libmap;
  printf("Functions:\n");
  while (p->name) {
    printf(" %-15s %-6s %s\n", p->name, p->figure, p->msg);
    p++;
  }
}

int main(int argc, char *argv[])
{
  item_t *p = map;
  const char *cmd = basename(argv[0]);
  char **arg = argv;
  if (strcmp(cmd , "apue") == 0) {
    arg ++;
    argc --;
    cmd = *arg;
  }

  if (argc > 0) {
    while (p->figure) {
      if (strcmp(cmd , p->figure) == 0 || strcmp(cmd , p->name) == 0) {
        setenv("figure", p->figure, 1);
        return p->fn(argc , arg);
      }
      p++;
    }
  }
  printf("Advanced Programming in the UNIX Environment 2e Demos\n");
  printf("http://www.libpix.org/apue\n\n");
  printf("Usage: e.g. $ ./apue ls1 .\n");
  printf("        or  $ ./ln -s apue ls1; ./ls1 .\n\n");

  showapp();
  printf("\n");
  showlib();

  return 0;
}
