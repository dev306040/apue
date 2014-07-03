CPPFLAGS = -I $(top_builddir) -I $(top_srcdir)/src
lib_LIBRARIES = libapue.a
libapue_a_SOURCES = \
	$(top_builddir)/config.h \
	$(top_srcdir)/src/lib.c \
	$(top_srcdir)/src/lib/error.c \
	$(top_srcdir)/src/lib/pathalloc.c \
	$(top_srcdir)/src/lib/openmax.c \
	$(top_srcdir)/src/lib/setfl.c \
	$(top_srcdir)/src/lib/prexit.c \
	$(top_srcdir)/src/proc/system1.c \
	$(top_srcdir)/src/lib/tellwait.c \
	$(top_srcdir)/src/signals/system2.c \
	$(top_srcdir)/src/signals/sleep1.c \
	$(top_srcdir)/src/signals/sleep2.c \
	$(top_srcdir)/src/signals/setops.c \
	$(top_srcdir)/src/lib/prmask.c \
	$(top_srcdir)/src/lib/signal1.c \
	$(top_srcdir)/src/lib/signalintr.c \
	$(top_srcdir)/src/signals/abort.c \
	$(top_srcdir)/src/lib/sleep3.c \
	$(top_srcdir)/src/datafiles/getpwnam1.c 


bin_PROGRAMS = apue
apue_SOURCES = \
	$(top_builddir)/config.h \
	$(top_srcdir)/src/apue.h \
	$(top_srcdir)/src/main.c \
	\
	$(top_srcdir)/src/file/ls1.c \
	$(top_srcdir)/src/mycat/mycat.c \
	$(top_srcdir)/src/mycat/getcputc.c \
	$(top_srcdir)/src/file/hello.c \
	$(top_srcdir)/src/proc/shell1.c \
	$(top_srcdir)/src/file/testerror.c \
	$(top_srcdir)/src/file/uidgid.c \
	$(top_srcdir)/src/proc/shell2.c \
	\
	$(top_srcdir)/src/std/conf.c \
	\
	$(top_srcdir)/src/file/seek.c \
	$(top_srcdir)/src/file/hole.c \
	$(top_srcdir)/src/file/fileflags.c \
	\
	$(top_srcdir)/src/file/filetype.c \
	$(top_srcdir)/src/file/access.c \
	$(top_srcdir)/src/file/umask.c \
	$(top_srcdir)/src/file/changemod.c \
	$(top_srcdir)/src/file/unlink.c \
	$(top_srcdir)/src/file/zap.c \
	$(top_srcdir)/src/file/ftw4.c \
	$(top_srcdir)/src/file/mycd.c \
	$(top_srcdir)/src/file/cdpwd.c \
	$(top_srcdir)/src/file/devrdev.c \
	\
	$(top_srcdir)/src/mycat/fgetsfputs.c \
	$(top_srcdir)/src/stdio/buf.c \
	$(top_srcdir)/src/stdio/tempfiles.c \
	$(top_srcdir)/src/stdio/tempnam.c \
	\
	$(top_srcdir)/src/environ/hello1.c \
	$(top_srcdir)/src/environ/doatexit.c \
	$(top_srcdir)/src/proc/echoarg.c \
	$(top_srcdir)/src/environ/testjmp.c \
	$(top_srcdir)/src/environ/getrlimit.c \
	\
	$(top_srcdir)/src/proc/fork1.c \
	$(top_srcdir)/src/proc/vfork1.c \
	$(top_srcdir)/src/proc/wait1.c \
	$(top_srcdir)/src/proc/fork2.c \
	$(top_srcdir)/src/proc/tellwait1.c \
	$(top_srcdir)/src/proc/tellwait2.c \
	$(top_srcdir)/src/proc/exec1.c \
	$(top_srcdir)/src/proc/echoall.c \
	$(top_srcdir)/src/proc/exec2.c \
	$(top_srcdir)/src/proc/systest1.c \
	$(top_srcdir)/src/proc/systest3.c \
	$(top_srcdir)/src/proc/pruids.c \
	$(top_srcdir)/src/proc/test1.c \
	$(top_srcdir)/src/proc/pracct.c \
	$(top_srcdir)/src/proc/times1.c \
	\
	$(top_srcdir)/src/sess/orphan3.c \
	\
	$(top_srcdir)/src/signals/sigusr.c \
	$(top_srcdir)/src/signals/reenter.c \
	$(top_srcdir)/src/signals/child.c \
	$(top_srcdir)/src/signals/tsleep2.c \
	$(top_srcdir)/src/signals/read1.c \
	$(top_srcdir)/src/signals/read2.c \
	$(top_srcdir)/src/signals/critical.c \
	$(top_srcdir)/src/signals/mask.c \
	$(top_srcdir)/src/signals/suspend1.c \
	$(top_srcdir)/src/signals/suspend2.c \
	$(top_srcdir)/src/proc/systest2.c \
	$(top_srcdir)/src/signals/sigtstp.c \
	\
	$(top_srcdir)/src/threads/threadid.c \
	$(top_srcdir)/src/threads/exitstatus.c \
	$(top_srcdir)/src/threads/badexit2.c \
	$(top_srcdir)/src/threads/cleanup.c

apue_LDADD = $(top_builddir)/libapue.a -lpthread

