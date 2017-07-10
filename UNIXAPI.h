#pragma once
int errno;
int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;
char *basename(char *path);

#pragma region FileSys 
typedef int DIR;
DIR *opendir(const char *dirname);
struct dirent {
	const char* d_name;
};
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
#define O_RDONLY 1
#define O_WRONLY 2
#define O_RDWR 3
#define O_APPEND 4
#define O_CREAT 5
#define O_TRUNC 6
int open(const char* path, int oflag);

#pragma endregion

#pragma region NETWORK <sys/socket.h>

int socket(int domain, int type, int protocol);
#define PF_INET6 1
#define PF_UNIX 2
#define AF_UNIX 1
#define AF_INET 2
#define AF_INET6 3
#define AF_UNSPEC 4
#define SOCK_STREAM 1
#define SOCK_DGRAM 2

typedef long socklen_t;
int bind(int socket, const struct sockaddr *address, socklen_t address_len);
int listen(int socket, int backlog);
int accept(int socket, struct sockaddr *address, socklen_t * address_len);
int inet_pton(int af, const char *src, void *dst);
const char *inet_ntop(int af, const void *src, char *dst, size_t size);
int connect(int sock, struct sockaddr *address, socklen_t address_len);
int close(int fildes);
int shutdown(int socket, int how);
int getaddrinfo(const char *nodename, const char *servicename, const struct addrinfo *hint, struct addrinfo **res);
int freeaddrinfo(struct addrinfo * x);
struct addrinfo {
public:
	int ai_family;
	int ai_socktype;
	int ai_protocol;
	void* ai_addr;
	socklen_t ai_addrlen;
	addrinfo* ai_next;
};

#pragma endregion

#pragma region RW
typedef size_t ssize_t;
#pragma region read
#define EAGAIN 1//The file descriptor fd refers to a file other than a socket and has been marked nonblocking(O_NONBLOCK), and the read would block. OR The file descriptor fd refers to a socket and has been marked nonblocking(O_NONBLOCK), and the read would block.POSIX.1 - 2001 allows either error to be returned for this case, and does not require these constants to have the same value, so a portable application should check for both possibilities.
#define EWOULDBLOCK 2 //The file descriptor fd refers to a socket and has been marked nonblocking(O_NONBLOCK), and the read would block.POSIX.1 - 2001 allows either error to be returned for this case, and does not require these constants to have the same value, so a portable application should check for both possibilities.
#define EBADF 3 //fd is not a valid file descriptor or is not open for reading.
#define EFAULT 4//buf is outside your accessible address space.
#define EINTR 5//The call was interrupted by a signal before any data was read; see signal(7).
#define EINVAL 6//fd is attached to an object which is unsuitable for reading; or the file was opened with the O_DIRECT flag, and either the address specified in buf, the value specified in count, or the current file offset is not suitably aligned.
#define EINVAL 7//fd was created via a call to timerfd_create(2) and the wrong size buffer was given to read(); see timerfd_create(2) for further information.
#define EIO 8//I / O error.This will happen for example when the process is in a background process group, tries to read from its controlling terminal, and either it is ignoring or blocking SIGTTIN or its process group is orphaned.It may also occur when there is a low - level I / O error while reading from a disk or tape.
#define EISDIR  9 //fd refers to a directory.
ssize_t read(int fildes, void * buf, size_t nbyte);
#pragma  endregion 


ssize_t write(int fildes, const void * buf, size_t nbyte);

struct stat;

#define EACCES 1//A component of the path prefix denies search permission.
#define EIO 2//An error occurred while reading from the file system.
#define ELOOP 3//A loop exists in symbolic links encountered during resolution of the path argument.
#define ENAMETOOLONG 4//The length of a pathname exceeds{ PATH_MAX } or a pathname component is longer than{ NAME_MAX }.
#define ENOTDIR 5//A component of the path prefix is not a directory.
#define ENOENT 6//A component of path does not name an existing file or path is an empty string.
#define EOVERFLOW 7//The file size in bytes or the number of blocks allocated to the file or the file serial number cannot be represented correctly in the structure pointed to by buf.


[ELOOP] //More than{ SYMLOOP_MAX } symbolic links were encountered during resolution of the path argument.
[ENAMETOOLONG] //As a result of encountering a symbolic link in resolution of the path argument, the length of the substituted pathname string exceeded{ PATH_MAX }.
[EOVERFLOW] //One of the members is too large to store into the structure pointed to by the buf argument.

int lstat(const char *path, struct stat *buf); //#include <sys/stat.h>
#pragma endregion
