#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	fn(void)
{
	char *line;
	int fd2;

	fd2 = open("test2", O_RDONLY);
	(get_next_line(fd2, &line));
	{	
		printf("%s\n", line);
		free(line);
	}
	close(fd2);
}

int main()
{
	char *line;
	int fd; 
	int fd2;

	while (get_next_line(0, &line))
	{
		//printf("%s\n", line);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	fd = open("test1", O_RDONLY);
	 (get_next_line(fd, &line));
	{	
		printf("%s\n", line);
		free(line);
	}
	fd2 = open("test2", O_RDONLY);
	(get_next_line(fd2, &line));
	{	
		printf("%s\n", line);
		free(line);
	}
	(get_next_line(fd, &line));
	{	
		printf("%s\n", line);
		free(line);
	}
	(get_next_line(fd2, &line));
	{	
		printf("%s\n", line);
		free(line);
	}
	fn();
	close(fd);
	close(fd2);
	return (0);
}
