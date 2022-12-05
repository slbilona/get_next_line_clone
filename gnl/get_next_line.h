#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int ft_strlen(char *str);
char *ft_read(int fd, char *str);

#endif