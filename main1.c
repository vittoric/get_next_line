//                      .---.     .---.
//                     ( -o- )---( -o- )
//                     ;-...-`   `-...-;
//  TEST              /                 \
//                   /                   \
//                  | /_               _\ |
//                  \`'.`'"--.....--"'`.'`/
//                   \  '.   `._.`   .'  /
//                _.-''.  `-.,,_,,.-`  .''-._
//               `--._  `'-.,_____,.-'`  _.--`
//                    /                 \
//                   /.-'`\   .'.   /`'-.\
//                  `      '.'   '.' 

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static void	write_ma_boy(char	*s, int file, int line);

int			main(int argc, char *const argv[])
{
	char	*s;
	
	if (argc == 1)
	{	
		printf("-- Estandar de entrada (stdin) --\n");
		do
		{
			s = get_next_line(0);
			write_ma_boy(s, 1, 1);
		} while (s != 0);
	}
	else
	{

		printf("-- Ficheros (%d) --\n", argc - 1);
		int	fd[argc - 1];
		int i = 0;
		int i2 = 1;
		int b;

		while (i < argc - 1)
		{
			fd[i] = open(argv[i + 1], O_RDONLY);
			i++;
		}
		do
		{
			b = 0;
			i = 0;
			while (i < argc - 1)
			{
				s = get_next_line(fd[i]);
				if (s != 0)
					b = 1;
				write_ma_boy(s, i + 1, i2);
				i++;
			}
			i2++;
		} while (b != 0);
		/*
		i = 0;
		while (i < argc - 1)
		{
			close(fd[i]);
			i++;
		}
		*/
	}
	system("leaks a.out");
	return (0);
}

static void	write_ma_boy(char	*s, int file, int line)
{
	if (s != 0)
	{
		printf("file \t%d line \t%d:|%s|\n", file, line, s);
		free(s);
	}
	else
		printf("file \t%d line \t%d: NULL\n", file, line);
}