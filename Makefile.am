bin_PROGRAMS=\
	strace2seccomp

strace2seccomp_SOURCES=\
	src/main.cpp \
	src/grammar.hpp \
	src/collect.hpp \
	src/collect.cpp \
	src/analyze.hpp \
	src/analyze.cpp \
	src/Syscall.hpp \
	src/Syscall.cpp

strace2seccomp_CPPFLAGS=\
	-I$(top_srcdir)/src/PEGTL

EXTRA_DIST=\
	src/PEGTL

