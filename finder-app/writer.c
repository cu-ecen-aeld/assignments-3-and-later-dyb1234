#include<syslog.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "%s\n", "paremeters are not specified.");
        return 1;
    }
    int fd = open(argv[1], O_CREAT | O_RDWR, 0755);
    if (fd == -1) {
        syslog(LOG_ERR, "%s\n", "open file failed.");
    }
    char * content = argv[2];
    int len = strlen(argv[2]);
    ssize_t ret;
    while (len != 0 && (ret = write(fd, content, len)) != 0) {
        if (ret == -1) {
            syslog(LOG_ERR, "%s\n", "write error.");
        }
        len -= ret;
        content += ret;
    }
    write(fd, "\n", 1);
    syslog(LOG_DEBUG, "Writing %s to %s.", argv[2], argv[1]);
    close(fd);
    return 0;
}