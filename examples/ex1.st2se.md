# recvmsg, called 8 time(s)
## Group: INTEGER type masked invocations
```
recvmsg(5, *, *, 68)
recvmsg(5, *, *, 161)
recvmsg(5, *, *, 16)
recvmsg(5, *, *, 155)
recvmsg(5, *, *, 75)
```

## Group: CONSTANT type masked invocations
```
recvmsg(*, *, MSG_CMSG_CLOEXEC, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
recvmsg(5, *, MSG_CMSG_CLOEXEC, 161)
recvmsg(5, *, MSG_CMSG_CLOEXEC, 68)
recvmsg(5, *, MSG_CMSG_CLOEXEC, 155)
recvmsg(5, *, MSG_CMSG_CLOEXEC, 16)
recvmsg(5, *, MSG_CMSG_CLOEXEC, 75)
```
---

# madvise, called 1 time(s)
## Group: INTEGER type masked invocations
```
madvise(*, 8368128, *, 0)
```

## Group: CONSTANT type masked invocations
```
madvise(*, *, MADV_DONTNEED, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
madvise(*, 8368128, MADV_DONTNEED, 0)
```
---

# sendmsg, called 3 time(s)
## Group: INTEGER type masked invocations
```
sendmsg(5, *, *, 168)
sendmsg(5, *, *, 1)
sendmsg(5, *, *, 128)
```

## Group: CONSTANT type masked invocations
```
sendmsg(*, *, MSG_NOSIGNAL, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
sendmsg(5, *, MSG_NOSIGNAL, 128)
sendmsg(5, *, MSG_NOSIGNAL, 1)
sendmsg(5, *, MSG_NOSIGNAL, 168)
```
---

# getegid, called 2 time(s)
## Group: INTEGER type masked invocations
```
getegid(1000)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
getegid(1000)
```
---

# recvfrom, called 55 time(s)
## Group: INTEGER type masked invocations
```
recvfrom(5, *, 4096, 0, *, *, 15)
recvfrom(5, *, 4096, 0, *, *, 37)
recvfrom(11, *, 12328, *, *, *, -1)
recvfrom(5, *, 4096, 0, *, *, 46)
recvfrom(11, *, 12328, *, *, *, 12328)
```

## Group: CONSTANT type masked invocations
```
recvfrom(*, *, *, *, NULL, NULL, *)
recvfrom(*, *, *, MSG_WAITALL|MSG_NOSIGNAL, NULL, NULL, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
recvfrom(11, *, 12328, MSG_WAITALL|MSG_NOSIGNAL, NULL, NULL, -1)
recvfrom(5, *, 4096, 0, NULL, NULL, 15)
recvfrom(5, *, 4096, 0, NULL, NULL, 37)
recvfrom(11, *, 12328, MSG_WAITALL|MSG_NOSIGNAL, NULL, NULL, 12328)
recvfrom(5, *, 4096, 0, NULL, NULL, 46)
```
---

# connect, called 28 time(s)
## Group: INTEGER type masked invocations
```
connect(11, *, 110, 0)
connect(5, *, 23, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
connect(5, *, 23, 0)
connect(11, *, 110, 0)
```
---

# socket, called 28 time(s)
## Group: INTEGER type masked invocations
```
socket(*, *, 0, 5)
socket(*, *, 0, 11)
```

## Group: CONSTANT type masked invocations
```
socket(PF_LOCAL, SOCK_STREAM, *, *)
socket(PF_LOCAL, SOCK_STREAM|SOCK_CLOEXEC, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
socket(PF_LOCAL, SOCK_STREAM|SOCK_CLOEXEC, 0, 5)
socket(PF_LOCAL, SOCK_STREAM, 0, 11)
```
---

# epoll_ctl, called 2 time(s)
## Group: INTEGER type masked invocations
```
epoll_ctl(8, *, 7, *, 0)
epoll_ctl(8, *, 9, *, 0)
```

## Group: CONSTANT type masked invocations
```
epoll_ctl(*, EPOLL_CTL_ADD, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
epoll_ctl(8, EPOLL_CTL_ADD, 7, *, 0)
epoll_ctl(8, EPOLL_CTL_ADD, 9, *, 0)
```
---

# pipe, called 1 time(s)
## Group: INTEGER type masked invocations
```
pipe(*, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
pipe(*, 0)
```
---

# clock_getres, called 1 time(s)
## Group: INTEGER type masked invocations
```
clock_getres(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
clock_getres(CLOCK_MONOTONIC, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
clock_getres(CLOCK_MONOTONIC, *, 0)
```
---

# prctl, called 3 time(s)
## Group: INTEGER type masked invocations
```
prctl(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
prctl(PR_SET_NAME, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
prctl(PR_SET_NAME, *, 0)
```
---

# clock_gettime, called 83 time(s)
## Group: INTEGER type masked invocations
```
clock_gettime(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
clock_gettime(CLOCK_MONOTONIC, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
clock_gettime(CLOCK_MONOTONIC, *, 0)
```
---

# clone, called 4 time(s)
## Group: INTEGER type masked invocations
```
clone(*, *, *, *, *, 25456)
clone(*, *, *, *, *, 25454)
clone(*, *, *, *, *, 25455)
clone(*, *, *, *, *, 25457)
```

## Group: CONSTANT type masked invocations
```
clone(*, CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, *, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
clone(*, CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, *, *, *, 25456)
clone(*, CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, *, *, *, 25455)
clone(*, CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, *, *, *, 25457)
clone(*, CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, *, *, *, 25454)
```
---

# geteuid, called 2 time(s)
## Group: INTEGER type masked invocations
```
geteuid(1000)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
geteuid(1000)
```
---

# setsockopt, called 54 time(s)
## Group: INTEGER type masked invocations
```
setsockopt(11, *, *, *, 4, 0)
```

## Group: CONSTANT type masked invocations
```
setsockopt(*, SOL_SOCKET, SO_PASSCRED, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
setsockopt(11, SOL_SOCKET, SO_PASSCRED, *, 4, 0)
```
---

# write, called 19 time(s)
## Group: INTEGER type masked invocations
```
write(7, *, 8, 8)
write(3, *, 8, 8)
write(6, *, 8, 8)
write(4, *, 8, 8)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
write(7, *, 8, 8)
write(3, *, 8, 8)
write(6, *, 8, 8)
write(4, *, 8, 8)
```
---

# arch_prctl, called 1 time(s)
## Group: INTEGER type masked invocations
```
arch_prctl(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
arch_prctl(ARCH_SET_FS, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
arch_prctl(ARCH_SET_FS, *, 0)
```
---

# read, called 51 time(s)
## Group: INTEGER type masked invocations
```
read(6, *, 16, -1)
read(3, *, 1024, 0)
read(3, *, 832, 832)
read(6, *, 16, 8)
read(7, *, 16, 8)
read(3, *, 1024, 330)
read(3, *, 16, -1)
read(4, *, 16, 8)
read(3, *, 16, 8)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
read(6, *, 16, -1)
read(3, *, 1024, 0)
read(3, *, 16, 8)
read(3, *, 1024, 330)
read(3, *, 832, 832)
read(4, *, 16, 8)
read(3, *, 16, -1)
read(6, *, 16, 8)
read(7, *, 16, 8)
```
---

# open, called 105 time(s)
## Group: INTEGER type masked invocations
```
open(*, *, -1)
open(*, *, 3)
```

## Group: CONSTANT type masked invocations
```
open(*, O_RDONLY, *)
open(*, O_RDONLY|O_CLOEXEC, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
open(*, O_RDONLY|O_CLOEXEC, -1)
open(*, O_RDONLY|O_CLOEXEC, 3)
open(*, O_RDONLY, 3)
```
---

# mprotect, called 74 time(s)
## Group: INTEGER type masked invocations
```
mprotect(*, 139264, *, 0)
mprotect(*, 2097152, *, 0)
mprotect(*, 57344, *, 0)
mprotect(*, 16384, *, 0)
mprotect(*, 40960, *, 0)
mprotect(*, 4096, *, 0)
mprotect(*, 135168, *, 0)
mprotect(*, 2093056, *, 0)
mprotect(*, 8192, *, 0)
mprotect(*, 12288, *, 0)
mprotect(*, 24576, *, 0)
```

## Group: CONSTANT type masked invocations
```
mprotect(*, *, PROT_READ|PROT_WRITE, *)
mprotect(*, *, PROT_READ, *)
mprotect(*, *, PROT_NONE, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
mprotect(*, 139264, PROT_READ|PROT_WRITE, 0)
mprotect(*, 135168, PROT_READ|PROT_WRITE, 0)
mprotect(*, 40960, PROT_READ, 0)
mprotect(*, 16384, PROT_READ, 0)
mprotect(*, 4096, PROT_NONE, 0)
mprotect(*, 2097152, PROT_NONE, 0)
mprotect(*, 4096, PROT_READ, 0)
mprotect(*, 12288, PROT_READ, 0)
mprotect(*, 24576, PROT_READ, 0)
mprotect(*, 57344, PROT_READ, 0)
mprotect(*, 2093056, PROT_NONE, 0)
mprotect(*, 8192, PROT_READ, 0)
```
---

# shutdown, called 27 time(s)
## Group: INTEGER type masked invocations
```
shutdown(11, *, 0)
```

## Group: CONSTANT type masked invocations
```
shutdown(*, SHUT_RDWR, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
shutdown(11, SHUT_RDWR, 0)
```
---

# sendto, called 31 time(s)
## Group: INTEGER type masked invocations
```
sendto(5, *, 6, *, *, 0, 6)
sendto(5, *, 19, *, *, 0, 19)
sendto(11, *, 24, *, *, 0, 24)
sendto(5, *, 24, *, *, 0, 24)
sendto(5, *, 7, *, *, 0, 7)
```

## Group: CONSTANT type masked invocations
```
sendto(*, *, *, MSG_NOSIGNAL, NULL, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
sendto(5, *, 7, MSG_NOSIGNAL, NULL, 0, 7)
sendto(5, *, 24, MSG_NOSIGNAL, NULL, 0, 24)
sendto(5, *, 6, MSG_NOSIGNAL, NULL, 0, 6)
sendto(11, *, 24, MSG_NOSIGNAL, NULL, 0, 24)
sendto(5, *, 19, MSG_NOSIGNAL, NULL, 0, 19)
```
---

# execve, called 1 time(s)
## Group: INTEGER type masked invocations
```
execve(*, *, *, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
execve(*, *, *, 0)
```
---

# gettimeofday, called 2 time(s)
## Group: INTEGER type masked invocations
```
gettimeofday(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
gettimeofday(*, NULL, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
gettimeofday(*, NULL, 0)
```
---

# brk, called 5 time(s)
## Group: INTEGER type masked invocations
```
```

## Group: CONSTANT type masked invocations
```
brk(NULL, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
brk(NULL, *)
```
---

# getrlimit, called 2 time(s)
## Group: INTEGER type masked invocations
```
getrlimit(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
getrlimit(RLIMIT_NOFILE, *, *)
getrlimit(RLIMIT_STACK, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
getrlimit(RLIMIT_STACK, *, 0)
getrlimit(RLIMIT_NOFILE, *, 0)
```
---

# close, called 63 time(s)
## Group: INTEGER type masked invocations
```
close(3, 0)
close(7, 0)
close(11, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
close(3, 0)
close(11, 0)
close(7, 0)
```
---

# munmap, called 7 time(s)
## Group: INTEGER type masked invocations
```
munmap(*, 67108864, 0)
munmap(*, 58716160, 0)
munmap(*, 4096, 0)
munmap(*, 104783, 0)
munmap(*, 66256896, 0)
munmap(*, 8392704, 0)
munmap(*, 851968, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
munmap(*, 67108864, 0)
munmap(*, 58716160, 0)
munmap(*, 8392704, 0)
munmap(*, 4096, 0)
munmap(*, 104783, 0)
munmap(*, 66256896, 0)
munmap(*, 851968, 0)
```
---

# access, called 3 time(s)
## Group: INTEGER type masked invocations
```
access(*, *, -1)
access(*, *, 0)
```

## Group: CONSTANT type masked invocations
```
access(*, R_OK, *)
access(*, F_OK, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
access(*, F_OK, 0)
access(*, R_OK, -1)
access(*, F_OK, -1)
```
---

# epoll_wait, called 1 time(s)
## Group: INTEGER type masked invocations
```
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
```
---

# fstat, called 35 time(s)
## Group: INTEGER type masked invocations
```
fstat(3, *, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
fstat(3, *, 0)
```
---

# set_tid_address, called 1 time(s)
## Group: INTEGER type masked invocations
```
set_tid_address(*, 25453)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
set_tid_address(*, 25453)
```
---

# exit, called 1 time(s)
## Group: INTEGER type masked invocations
```
exit(0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
exit(0)
```
---

# set_robust_list, called 5 time(s)
## Group: INTEGER type masked invocations
```
set_robust_list(*, 24, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
set_robust_list(*, 24, 0)
```
---

# poll, called 88 time(s)
## Group: INTEGER type masked invocations
```
poll(*, 2, 0, 0)
poll(*, 1, 0, 0)
poll(*, 1, 993)
poll(*, 2, 0, 1)
poll(*, 1, 991, 0)
poll(*, 1, 963, 0)
poll(*, 2, -1, 1)
poll(*, 1, 993, 0)
poll(*, 1, -1, 1)
poll(*, 1, 994, 0)
poll(*, 1, 0, 1)
poll(*, 1, 25000, 1)
poll(*, 1, 995, 0)
poll(*, 1, 992, 0)
poll(*, 1, 989, 0)
poll(*, 1, 990, 0)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
poll(*, 2, -1, 1)
poll(*, 2, 0, 0)
poll(*, 2, 0, 1)
poll(*, 1, 0, 0)
poll(*, 1, 0, 1)
poll(*, 1, 993)
poll(*, 1, 963, 0)
poll(*, 1, 994, 0)
poll(*, 1, -1, 1)
poll(*, 1, 25000, 1)
poll(*, 1, 991, 0)
poll(*, 1, 990, 0)
poll(*, 1, 993, 0)
poll(*, 1, 995, 0)
poll(*, 1, 992, 0)
poll(*, 1, 989, 0)
```
---

# statfs, called 2 time(s)
## Group: INTEGER type masked invocations
```
statfs(*, *, -1)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
statfs(*, *, -1)
```
---

# rt_sigaction, called 3 time(s)
## Group: INTEGER type masked invocations
```
rt_sigaction(*, *, *, 8, 0)
```

## Group: CONSTANT type masked invocations
```
rt_sigaction(SIGRTMIN, *, NULL, *, *)
rt_sigaction(SIGRT_1, *, NULL, *, *)
rt_sigaction(SIGPIPE, *, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
rt_sigaction(SIGRTMIN, *, NULL, 8, 0)
rt_sigaction(SIGRT_1, *, NULL, 8, 0)
rt_sigaction(SIGPIPE, *, *, 8, 0)
```
---

# rt_sigprocmask, called 3 time(s)
## Group: INTEGER type masked invocations
```
rt_sigprocmask(*, *, *, 8, 0)
```

## Group: CONSTANT type masked invocations
```
rt_sigprocmask(SIG_UNBLOCK, *, NULL, *, *)
rt_sigprocmask(SIG_SETMASK, *, NULL, *, *)
rt_sigprocmask(SIG_SETMASK, *, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
rt_sigprocmask(SIG_UNBLOCK, *, NULL, 8, 0)
rt_sigprocmask(SIG_SETMASK, *, NULL, 8, 0)
rt_sigprocmask(SIG_SETMASK, *, *, 8, 0)
```
---

# stat, called 11 time(s)
## Group: INTEGER type masked invocations
```
stat(*, *, 0)
stat(*, *, -1)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
stat(*, *, -1)
stat(*, *, 0)
```
---

# futex, called 108 time(s)
## Group: INTEGER type masked invocations
```
futex(*, *, 0, *, -1)
futex(*, *, 1, 0)
futex(*, *, 2147483647, 0)
futex(*, *, 2, *, 0)
futex(*, *, 2, *, -1)
futex(*, *, 1, 1)
```

## Group: CONSTANT type masked invocations
```
futex(*, FUTEX_WAIT_PRIVATE, *, NULL, *)
futex(*, FUTEX_WAKE_PRIVATE, *, *)
futex(*, FUTEX_WAIT_PRIVATE, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
futex(*, FUTEX_WAIT_PRIVATE, 0, *, -1)
futex(*, FUTEX_WAKE_PRIVATE, 2147483647, 0)
futex(*, FUTEX_WAKE_PRIVATE, 1, 0)
futex(*, FUTEX_WAIT_PRIVATE, 2, NULL, -1)
futex(*, FUTEX_WAKE_PRIVATE, 1, 1)
futex(*, FUTEX_WAIT_PRIVATE, 2, NULL, 0)
```
---

# epoll_create1, called 1 time(s)
## Group: INTEGER type masked invocations
```
epoll_create1(*, 8)
```

## Group: CONSTANT type masked invocations
```
epoll_create1(EPOLL_CLOEXEC, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
epoll_create1(EPOLL_CLOEXEC, 8)
```
---

# getrandom, called 2 time(s)
## Group: INTEGER type masked invocations
```
getrandom(*, 16, 0, 16)
```

## Group: CONSTANT type masked invocations
```
```

## Group: CONSTANT & INTEGER type masked invocations
```
getrandom(*, 16, 0, 16)
```
---

# fcntl, called 89 time(s)
## Group: INTEGER type masked invocations
```
fcntl(5, *, *, 0)
fcntl(5, *, *)
fcntl(11, *, *, 0)
fcntl(9, *, *, 0)
fcntl(9, *, 0)
fcntl(10, *, *, 0)
fcntl(10, *, 0)
fcntl(11, *, 0)
```

## Group: CONSTANT type masked invocations
```
fcntl(*, F_SETFL, O_RDWR|O_NONBLOCK, *)
fcntl(*, F_GETFL, *)
fcntl(*, F_SETFL, O_RDONLY|O_NONBLOCK, *)
fcntl(*, F_SETFD, FD_CLOEXEC, *)
fcntl(*, F_GETFD, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
fcntl(5, F_GETFL, *)
fcntl(11, F_SETFL, O_RDONLY|O_NONBLOCK, 0)
fcntl(10, F_GETFD, 0)
fcntl(9, F_SETFL, O_RDONLY|O_NONBLOCK, 0)
fcntl(9, F_SETFD, FD_CLOEXEC, 0)
fcntl(11, F_GETFD, 0)
fcntl(9, F_GETFD, 0)
fcntl(10, F_SETFD, FD_CLOEXEC, 0)
fcntl(10, F_SETFL, O_RDONLY|O_NONBLOCK, 0)
fcntl(5, F_SETFL, O_RDWR|O_NONBLOCK, 0)
fcntl(11, F_SETFD, FD_CLOEXEC, 0)
```
---

# mmap, called 106 time(s)
## Group: INTEGER type masked invocations
```
mmap(*, 8192, *, *, -1, 0, *)
mmap(*, 2175096, *, *, 3, 0, *)
mmap(*, 16, *, *, -1, 0, *)
mmap(*, 8, *, *, -1, 0, *)
mmap(*, 2248712, *, *, 3, 0, *)
mmap(*, 2191376, *, *, 3, 0, *)
mmap(*, 4096, *, *, 3, *, *)
mmap(*, 2552072, *, *, 3, 0, *)
mmap(*, 2127048, *, *, 3, 0, *)
mmap(*, 2183272, *, *, 3, 0, *)
mmap(*, 134217728, *, *, -1, 0, *)
mmap(*, 2109528, *, *, 3, 0, *)
mmap(*, 4, *, *, -1, 0, *)
mmap(*, 16384, *, *, 3, *, *)
mmap(*, 552964, *, *, 3, 0, *)
mmap(*, 2113840, *, *, 3, 0, *)
mmap(*, 2237248, *, *, 3, 0, *)
mmap(*, 14912, *, *, -1, 0, *)
mmap(*, 40960, *, *, 3, *, *)
mmap(*, 3031840, *, *, 3, 0, *)
mmap(*, 10152, *, *, -1, 0, *)
mmap(*, 13504, *, *, -1, 0, *)
mmap(*, 3150104, *, *, 3, 0, *)
mmap(*, 2431880, *, *, 3, 0, *)
mmap(*, 8392704, *, *, -1, 0, *)
mmap(*, 12288, *, *, 3, *, *)
mmap(*, 36864, *, *, 3, *, *)
mmap(*, 800, *, *, -1, 0, *)
mmap(*, 2161672, *, *, 3, 0, *)
mmap(*, 134624, *, *, 3, 0, *)
mmap(*, 104783, *, *, 3, 0, *)
mmap(*, 3635112, *, *, 3, 0, *)
mmap(*, 263552, *, *, -1, 0, *)
mmap(*, 13488, *, *, -1, 0, *)
mmap(*, 2109712, *, *, 3, 0, *)
mmap(*, 28672, *, *, 3, *, *)
mmap(*, 2128800, *, *, 3, 0, *)
mmap(*, 2213040, *, *, 3, 0, *)
mmap(*, 2512256, *, *, 3, 0, *)
mmap(*, 2269560, *, *, 3, 0, *)
mmap(*, 2421456, *, *, 3, 0, *)
mmap(*, 4928, *, *, -1, 0, *)
mmap(*, 2206280, *, *, 3, 0, *)
mmap(*, 3669960, *, *, 3, 0, *)
mmap(*, 6728, *, *, -1, 0, *)
mmap(*, 4040, *, *, -1, 0, *)
mmap(*, 49152, *, *, 3, *, *)
mmap(*, 3379024, *, *, 3, 0, *)
mmap(*, 61440, *, *, 3, *, *)
mmap(*, 2117648, *, *, 3, 0, *)
mmap(*, 2273296, *, *, 3, 0, *)
mmap(*, 8192, *, *, 3, *, *)
mmap(*, 2117640, *, *, 3, 0, *)
mmap(*, 3934784, *, *, 3, 0, *)
mmap(*, 3675328, *, *, 3, 0, *)
mmap(*, 2397128, *, *, 3, 0, *)
mmap(*, 4096, *, *, -1, 0, *)
mmap(*, 2188320, *, *, 3, 0, *)
mmap(*, 2450056, *, *, 3, 0, *)
mmap(*, 24576, *, *, 3, *, *)
```

## Group: CONSTANT type masked invocations
```
mmap(NULL, *, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, *, *, *)
mmap(NULL, *, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE, *, *, *)
mmap(NULL, *, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, *, *, *)
mmap(NULL, *, PROT_READ, MAP_PRIVATE, *, *, *)
mmap(*, *, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, *, *, *)
mmap(*, *, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, *, *, *)
mmap(NULL, *, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, *, *, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
mmap(NULL, 8392704, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0, *)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2175096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 3031840, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2161672, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 8, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(*, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2127048, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 16, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2183272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(*, 16384, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2113840, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 6728, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2206280, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 4928, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2237248, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 14912, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(*, 40960, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2450056, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 13488, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(*, 10152, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2128800, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 134217728, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE, -1, 0, *)
mmap(*, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2273296, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2397128, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2109712, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2213040, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 134624, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 3675328, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2431880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 104783, PROT_READ, MAP_PRIVATE, 3, 0, *)
mmap(NULL, 3669960, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 3635112, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 36864, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2109528, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 3150104, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2248712, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 263552, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2191376, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 3379024, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 4040, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(*, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2512256, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2552072, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 552964, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 61440, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2421456, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 28672, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2117648, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 13504, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0, *)
mmap(NULL, 2117640, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 49152, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
mmap(NULL, 2269560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 2188320, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(NULL, 3934784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0, *)
mmap(*, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, *, *)
```
---

# eventfd2, called 5 time(s)
## Group: INTEGER type masked invocations
```
eventfd2(0, *, 7)
eventfd2(0, *, 6)
eventfd2(0, 0, 7)
eventfd2(0, *, 3)
eventfd2(0, *, 4)
```

## Group: CONSTANT type masked invocations
```
eventfd2(*, EFD_CLOEXEC|EFD_NONBLOCK, *)
```

## Group: CONSTANT & INTEGER type masked invocations
```
eventfd2(0, EFD_CLOEXEC|EFD_NONBLOCK, 7)
eventfd2(0, EFD_CLOEXEC|EFD_NONBLOCK, 3)
eventfd2(0, EFD_CLOEXEC|EFD_NONBLOCK, 6)
eventfd2(0, 0, 7)
eventfd2(0, EFD_CLOEXEC|EFD_NONBLOCK, 4)
```
---

