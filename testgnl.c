/*#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cat(char *str, char *buf)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		str = malloc(sizeof(char));
		str[0] = 0;
	}
	new = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (buf[j] != 0)
	{
		new[i] = buf[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
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
	}
	free(buf);
	return (str);
}

char	*ft_ligne(char *str)
{
	char	*ligne;
	int		i;

	i = 0;
	ligne = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i] && str[i] != '\n')
	{
		ligne[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ligne[i] = '\n';
		i++;
	}
	ligne[i] = 0;
	return (ligne);
}

char	*ft_new_str(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == 0)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (str[i])
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = 0;
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;

	str = ft_read(fd, str);
	ligne = ft_ligne(str);
	str = ft_new_str(str);
	return (ligne);
}

int main()
{
	int fd  = open("test", O_RDONLY);
	int i = 0;
	char *ligne;
	while(i < 5)
	{
		ligne = get_next_line(fd);
		printf("%s", ligne);
		i++;
		free(ligne);
	}
	
	close(fd);
}*/