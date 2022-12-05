#include "get_next_line.h"
#include <stdio.h>

char *ft_cat(char *str, char *buf)
{
    char *new;
    int i;
    int j;
    
    i = 0;
    j = 0;
    if (!str)
    {
        str = malloc(sizeof(char));
        if(!str)
            return (NULL);
        str[0] = 0;
    }
    new = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
    if(!new)
        return (NULL);
    while(str)
    {
        new[i] = str[i];
        i++;
    }
    while(buf)
    {
        new[i] = buf[j];
        i++;
        j++;
    }
    return (new);

}

char *ft_read(int fd, char *str)
{
    int i;
    char *buf;

    i = 1;
    while(i)
    {
        i = read(fd, buf, BUFFER_SIZE);
        buf = malloc(sizeof(char) * i + 1);
        if(!buf)
            return (NULL);
        buf[i+1] = 0;
        str = ft_cat(str, buf);
        if(!str)
            return (NULL);
    }
    return (str);
}

char *get_next_line(int fd)
{
	static char *str;

    if (fd == -1)
        return (NULL);
    if(!ft_read(fd, str))
        return (NULL);
    return (str);
}

int main()
{
    int fd = open("test", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
}
