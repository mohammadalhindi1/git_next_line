#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("hindi.txt", O_RDONLY);
	int i = 0 ; 
	char *line;
	
	while((line = get_next_line(fd)) != NULL && i < 99)
	{
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return(0);
}