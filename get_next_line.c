#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	int size;
	static int i = 0;
	int j = 0;
	int k = i;
	int o = 0;
	char *str;
	if(i == 0)
	{
		size = read(fd, buf, BUFFER_SIZE - 1);
		//printf("%d", size);
		buf[size] = 0;
	}
	if(buf[0] == 0 || i == -1)
		return (NULL);
	while(buf[i] && buf[i] != '\n')
	{
		i++;
		j++;
	}
	str = malloc(sizeof(char) * (j + 2));
	while(j-- >= 0)
		str[o++] = buf[k++];
	str[o] = 0;
	i++;
	if(buf[i] == 0)
		i = -1;
	return (str);
}
/*
int main()
{
	int fd;
	fd = open("test", O_RDONLY);
	if(!fd)
		return (1);
	int i = 0;
	while(i < 9)
	{
		char *str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
}*/
