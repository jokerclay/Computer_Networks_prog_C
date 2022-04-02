# 00 
### Network Porgraming 
  - Also known as Socket Porgraming because the Network programing itsellf is
  base on sockets.
  - Definition: building a program that receives and transmits data between two
  or more computers by means of a network.


### A simple understanding of socket
  - Provided  by operating system within devices.
  - socket provides a high level of abstruction for programmers so that we don't
  have to worry about underlying physical & software details of networking


### 5 "must-know" fundamental details of socket programing in C
1. **creating a socket (a socket descriptor)**
    * TCP Socket can be compared to a phone 
      [we need a device to call someone or accept their phone calls] 
    * To perform network I/O, the first thing a process must do is:
      call a socket function to create a specific type of socket by specifying
      the type of communication protocol  desired, protocol family etc.

```C
#include<sys/socket.h>

int socket(int domain, int type, int protocol);

```

2. **binding the socket**
    * it liking registering a phone number to the phone (to conect to other phone)
    * sockets do not have compelete address in the begining to start transfering data,
    so we bind socket to a port (phone do not have a phone number at the begining 
    to make phone calls, so we register a phone number)
    * The process of allocating a port number to a socket called "binding"

```C
#include <sys/socket.h>
int bind(int sockfd struct sockaddr *myaddr, socklen_t addrlen);
```

**Blinding a request to TCP/IP indicating that it is ready to receive/send information**

3. **listen**
    * listening for connection requests
    * identifying a bound, unconnected socket: means "identifying the connection request"
    * The process of coverting an unconnected socket into a passive socket
    indicating that the kernel should accept incoming connection  requests directed to this socket

```C
#include <sys/socket.h>
int listen(int sockfd, int backlog);
```



















