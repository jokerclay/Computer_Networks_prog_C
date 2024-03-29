# Protocols, socket creation, data transmisstion

### Opeing / Closing and writing into files 

- Low-level file IO
    * Linux based on a low-level file input and output, and Socket I/O can be 
      compared to file operations because the socket is also considered as a
      file (Generally, considered as stream)

    * File Descriptor (fd)
      * Operating system files are created (and socket) simply as numbers
        (to be able easily distinguish them)
      * Low-level file input and output function requires a file descriptor 
        for the perpose of making I/O operations.
      * Both socket & file have input and output stream 
        (socket being more advanced than file)
        socket descriptor can be used simply as a file descriptor as well  

- File open and close
    * use open system call to read and write a file `open()`
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    
    int open(const char *path, int flag)
    
    ```
    * use close system call to close a file `close()`
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    
    int close(int fd);
    
    ```

- Writing data to a file

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>      // O_RDONLY ....

int main(void) {

    int fd;
    /*
     *--------------------------------
     *| fd   |                       |
     *--------------------------------
     *| 0    |stardand input         |
     *--------------------------------
     *| 1    |stardand output        |
     *--------------------------------
     *| 2    |stardand error         |
     *--------------------------------
     * */


    char buffer[] = "this is the data of this file.\n";


    fd = open("data.txt", O_RDONLY | O_WRONLY | O_TRUNC);



    if (fd == -1) {
        printf("ERROR: can not open data.txt\n");
    }

    printf("file descriptor is : %d \n", fd);

    /*
     *
     * write function call
     *
     */


    if (write(fd, &buffer, sizeof(buffer)) == -1) {

        printf("ERROR: can not write buffer to  data.txt\n");

    };


    close(fd);

    return 0;
}

```

- Read data From a file


```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>      // O_RDONLY ....

#define BUFFER_SIZE 225

int main(void) {

    int fd;
    const char *buffer[BUFFER_SIZE];

    fd = open("data.txt", O_RDONLY);

    if (fd == -1) {
        printf("ERROR: can not open data.txt\n");
    }

    printf("file descriptor is => %d \n", fd);

    /*
     *
     * read function call
     *
     */

    if (read(fd, &buffer, sizeof(buffer)) == -1) {
        printf("ERROR: can not read from data.txt\n");
    };

    printf("file data in data.txt => \n%s  ", buffer);

    close(fd);

    return 0;
}
```

- Other way to open a file to read and write

    * `fopen` is more user friendly, is an abstract of `open()`
    * read and write data using `fopen()`
* read data using fopen
```c
#include <stdio.h>

#define FILE_PATH "data.txt"

int main(void) 
{
    /*
     * in the "r" mode the file has to aleady existed
     * if the file you try you to read doesn't exist yet
     * you can not open file, aka "r" reading mode
     *
     */
    FILE *file = fopen(FILE_PATH, "r");

    if (file == NULL) {
        printf("can not open %s\n" , FILE_PATH);
    }

    /*
     * you can not write data to a file which is opned in read mode
     * it can't change the data in data.txt file 
     *
     */
    char sentence[] = "this is an example in the reading mode ";

    fwrite(sentence, sizeof(sentence), 1, file);

    
    fclose(file);

    return 0;
}


```

* write data using fopen
```c
#include <stdio.h>
#define FILE_PATH "data.txt"

int main(void) {

    /*
     * in the "w" mode the file don't have to be existed
     * if the file you try you to write doesn't exist yet
     * in writing mode, it will just create the file you trying to write
     *
     */
    FILE *file = fopen(FILE_PATH, "w");


    if (file == NULL) {
        printf("can not open %s\n" , FILE_PATH);
    }

    char sentence[] = "this is an example in the writing mode ";

    fwrite(sentence, sizeof(sentence), 1, file);

    fclose(file);

    return 0;
}
```

###File descriptor and socket
    * the simliarity between the file and socket 
      * Both socket and file descriptors are in the same number sequence
        this confirms that linux I/O considers socket and files the same

##Socket
```c

int socketfd = socket(domain, type, protocol)

```

### Protocols
    * What is Protocol ? 
      * Network protocol are formal stardands and policies comprised of rules
        procedures and formats that define communication between two or more 
        devices over network
      * it needs to be specified to create a socket
        (socket need to know the protocol type)
      * it's like a detailed deal between two people about communication 
        or understanding each other 
      * The both parties can communicate with each other using the agreed terms
        and conditions


```c
#include <sys/socket.h>
int socket(int domain, int type, int protocol)
                |           |           |
                V           V           V

```
    * Domain, Type, Protocol
      * Socket domain
        * PF_XXXX -> Protocol Family Internet
            * PF_INET = Protocol Family Internet(IPv4)
            * PF_INET6 = Protocol Family Internet(IPv6)
        * SF_XXXX -> Address Family 
         (each address family supports multiple protocol families)
            * AF_INET = Address Family Internet(IPv4)
            * AF_INET6 = Address Family Internet(IPv6)











