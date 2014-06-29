CPPFLAGS = -I $(top_builddir)/src -I $(top_srcdir)/src
lib_LIBRARIES = libapue.a
libapue_a_SOURCES = \
										src/lib.c \
										src/lib/error.c \
										src/lib/pathalloc.c \
 										src/lib/openmax.c \
										src/lib/setfl.c \
							      src/lib/prexit.c \
										src/proc/system1.c \
										src/lib/tellwait.c \
										src/signals/system2.c \
										src/signals/sleep1.c \
										src/signals/sleep2.c \
										src/signals/setops.c \
										src/lib/prmask.c \
										src/lib/signal1.c \
										src/lib/signalintr.c \
										src/signals/abort.c \
										src/lib/sleep3.c \
										src/datafiles/getpwnam1.c 
	


bin_PROGRAMS = apue
apue_SOURCES = \
							 src/apue.h \
							 src/main.c \
							 \
							 src/file/ls1.c \
							 src/mycat/mycat.c \
							 src/mycat/getcputc.c \
							 src/file/hello.c \
							 src/proc/shell1.c \
							 src/file/testerror.c \
							 src/file/uidgid.c \
							 src/proc/shell2.c \
							 \
							 src/std/conf.c \
							 \
							 src/file/seek.c \
							 src/file/hole.c \
							 src/file/fileflags.c \
							 \
							 src/file/filetype.c \
							 src/file/access.c \
							 src/file/umask.c \
							 src/file/changemod.c \
							 src/file/unlink.c \
							 src/file/zap.c \
							 src/file/ftw4.c \
							 src/file/mycd.c \
							 src/file/cdpwd.c \
							 src/file/devrdev.c \
							 \
							 src/mycat/fgetsfputs.c \
							 src/stdio/buf.c \
							 src/stdio/tempfiles.c \
							 src/stdio/tempnam.c \
							 \
							 src/environ/hello1.c \
							 src/environ/doatexit.c \
							 src/proc/echoarg.c \
							 src/environ/testjmp.c \
							 src/environ/getrlimit.c \
							 \
							 src/proc/fork1.c \
							 src/proc/vfork1.c \
							 src/proc/wait1.c \
							 src/proc/fork2.c \
							 src/proc/tellwait1.c \
							 src/proc/tellwait2.c \
							 src/proc/exec1.c \
							 src/proc/echoall.c \
							 src/proc/exec2.c \
							 src/proc/systest1.c \
							 src/proc/systest3.c \
							 src/proc/pruids.c \
							 src/proc/test1.c \
							 src/proc/pracct.c \
							 src/proc/times1.c \
							 \
							 src/sess/orphan3.c \
							 \
							 src/signals/sigusr.c \
							 src/signals/reenter.c \
							 src/signals/child.c \
							 src/signals/tsleep2.c \
							 src/signals/read1.c \
							 src/signals/read2.c \
							 src/signals/critical.c \
							 src/signals/mask.c \
							 src/signals/suspend1.c \
							 src/signals/suspend2.c \
							 src/proc/systest2.c \
							 src/signals/sigtstp.c




apue_LDADD = $(top_builddir)/libapue.a


