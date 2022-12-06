#include "get_next_line.h"

int main()
{
	int fd = open("test", O_RDONLY);
	char *str;
	int i = 0;
	if(fd >= 0)
	{
		while(i < 7)
		{
			str = get_next_line(fd);
			printf("str = %s", str);
			i++;
			free(str);
		}
	}
	close(fd);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;

	if (fd < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	ligne = ft_copy(str);
	if (!ligne)
		return (NULL);
	str = ft_free_str(str);
	return (ligne);
}

char	*ft_cat(char *str, char *buf)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0;
	}
	if (buf[0] == 0 && str[0] == 0)
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (buf[j])
		new[i++] = buf[j++];
	new[i] = 0;
	free(str);
	return (new);
}

char	*ft_copy(const char *str)
{
	char	*ligne;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ligne = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if(!ligne)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		ligne[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ligne[i] = str[i];
		i++;
	}
	ligne[i] = 0;
	return (ligne);
}

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		i;

	i = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
		return (NULL);
	while (i && !ft_strchr(str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		str = ft_cat(str, buf);
		if (!str)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (str);
}