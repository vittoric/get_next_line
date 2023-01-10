#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 


//#define BUFFER_SIZE 4096

int check_file_descriptor(int fd) {
    if (fd < 0 || BUFFER_SIZE <= 0) {
        return -1;
    }
    return 0;
}

char *read_data(int fd, int *eof) {
    static char stash[BUFFER_SIZE] = {0};
    static int stash_len = 0;
    char buffer[BUFFER_SIZE] = {0};
    int buffer_len;
    int line_len = 0;
    char *result;

    while (1) {
        buffer_len = read(fd, buffer, BUFFER_SIZE);
        if (buffer_len == 0) {
            if (stash_len == 0) {
                *eof = 1;
                return NULL;
            } else {
                break;
            }
        } else if (buffer_len < 0) {
            return NULL; // read error
        }

        int i;
        for (i = 0; i < buffer_len; i++) {
            if (buffer[i] == '\n') {
                break;
            }
        }

        if (i < buffer_len) {
            line_len = stash_len + i + 1;
            result = (char *)malloc(line_len + 1);
            if (!result) {
                return NULL;
            }
            memcpy(result, stash, stash_len);
            memcpy(result + stash_len, buffer, i + 1);
            result[line_len] = 0;
            *eof = 0;
            stash_len = buffer_len - i - 1;
            memcpy(stash, buffer + i + 1, stash_len);
            return result;
        } else {
            stash_len += buffer_len;
            memcpy(stash + stash_len - buffer_len, buffer, buffer_len);
        }
    }

    line_len = stash_len;
    result = (char *)malloc(line_len + 1);
    if (!result) {
        return NULL;
    }
    memcpy(result, stash, line_len);
    result[line_len] = 0;
    *eof = 0;
    stash_len = 0;

    return result;
}

char* get_next_line(int fd) {
    int eof = 0;
    if (check_file_descriptor(fd) != 0) {
        return NULL;
    }

    return read_data(fd, &eof);
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf ("%s", line); 
    line = get_next_line(fd);
    printf ("%s", line);
    line = get_next_line(fd);
    printf ("%s", line);
	free(line);
	close(fd);
	return (0);
}
