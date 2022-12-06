#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strchr(char *str, char c);
char	*ft_free_str(char *str);
char	*ft_cat(char *str, char *buf);
char	*ft_copy(const char *str);
char	*ft_read(int fd, char *str);
char	*ft_free(char *str);
#endif