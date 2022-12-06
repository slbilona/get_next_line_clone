#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_free_str(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
		return (ft_free(str));
	new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (str[i])
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = 0;
	free(str);
	return (new);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}
