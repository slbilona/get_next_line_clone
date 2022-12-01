#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	char *buf = malloc(sizeof(char) * 218);
	if(!buf)
		return NULL;
	int size;
	size = read(fd, buf, 217);
	buf[size] = 0;
	return (buf);
}

char *test(int fd)
{
	printf("\n\ntest\n");
	char *buf;
	static int i = 0;
	if(i == 0)
		buf = get_next_line(fd);
	int j = 0;
	int k = i;
	int o = 0;
//	if(buf[i] == '\n')
//		i++;
	while(buf[i] != '\n' && buf[i] != 0)
	{
	//	printf("\nencore un printf ?\n");
		i++;
		j++;
	}
	//printf("%d", i);
	char *test = malloc(sizeof(char) * (j + 1));
	if(!test)
	{
		printf("\nnope\n");
		return NULL;
	}
	test[j] = 0;
	while(j != 0)
	{
		test[o] = buf[k];
		k++;
		o++;
		j--;
	}
	//printf("%s\n", test);
	if(buf[i] == 0)
		return (NULL);
	i++;
	//free(buf);
	return (test);
}

int main()
{
	int fd;
	int i = 0;
	fd = open("test.txt", O_RDONLY);
	if(!fd)
	{
		printf("123");
		return (1);
	}
	char *buf;
	while(i < 8)
	{
		buf = test(fd);
		printf("%d, %s", i, buf);
		free(buf);
		i++;
	}
	//printf("%s", buf);
	/*int i = 0;
	while(buf[i] != '\n' && buf[i] != 0)
		printf("%c", buf[i++]);
	printf("\ni2 = %d\n", i);
	*/
	/*
	int i = 0;
	while(buf[i] != 0 && buf[i] != '\n')
	{
		write(1, &buf[i], 218);
		i++;
	}*/
	close(fd);
}
