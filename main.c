#include "get_next_line.h"

int main()
{
	char	*str;
	int fd = open("test", O_RDONLY);
	int i = 0;

	if (fd >= 0)
	{
		while (i < 10)
		{
			str = get_next_line(fd);
			printf("str = %s", str);
			i++;
			free(str);
		}
	}
	close(fd);
}