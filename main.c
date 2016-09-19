#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd1 = open("read.txt", O_RDONLY);
    if(fd1 == -1)
    {
        perror("fd1");
        return -1;
    }
    int fd2 = open("write.txt", O_WRONLY | O_CREAT, 0644);
    if(fd2 == -1)
    {
        perror("fd2");
        return -1;
    }
    int count = 0;
    char c[1024];
    int i;
    while( (count = read(fd1, c, sizeof(c) ) )> 0 )
    {
        for(i = 0; i <= count; ++i)
        {
            if( c[i] >= 'a' && c[i] <= 'z')
            {
                c[i] = c[i] - 'a' + 'A';
            }
        }
        if( write(fd2, c, count) == -1)
        {
            perror("write");
            return -1;
        }
    }
    if(count == -1)
    {
        perror("read");
        return -1;
    }
    close(fd1);
    close(fd2);
    printf("Hello world!\n");
    return 0;
}
