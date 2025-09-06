#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd = open("input.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    close(fd);
    return 0;
}

