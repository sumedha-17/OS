Q) Write programs using the I/O system calls of UNIX/LINUX operating system (open, read, write,
close, fcntl, seek, stat, opendir, readdir)


1️⃣ open(), read(), write(), close()

Copy contents of one file to another

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char buf[100];
    int n;

    fd1 = open("source.txt", O_RDONLY);
    fd2 = open("dest.txt", O_WRONLY | O_CREAT, 0644);

    if (fd1 < 0 || fd2 < 0) {
        printf("File error\n");
        return 1;
    }

    while ((n = read(fd1, buf, sizeof(buf))) > 0) {
        write(fd2, buf, n);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");
    return 0;
}

2️⃣ lseek()

Move file pointer and read data

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buf[20];

    fd = open("file.txt", O_RDONLY);

    lseek(fd, 5, SEEK_SET);   // move 5 bytes from beginning
    read(fd, buf, 10);
    buf[10] = '\0';

    printf("Data: %s\n", buf);
    close(fd);

    return 0;
}

3️⃣ fcntl() – File Locking
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    struct flock fl;

    fd = open("lockfile.txt", O_WRONLY);

    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    fcntl(fd, F_SETLK, &fl);
    printf("File locked\n");

    sleep(10);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("File unlocked\n");

    close(fd);
    return 0;
}

4️⃣ stat()

Display file information

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat s;

    stat("file.txt", &s);

    printf("File size: %ld bytes\n", s.st_size);
    printf("Inode: %ld\n", s.st_ino);
    printf("Permissions: %o\n", s.st_mode & 0777);

    return 0;
}

5️⃣ opendir() and readdir()

List files in a directory

#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

    return 0;
}
