#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
	int		x;
	int		y;
	int		i;
	char	c;
	int		w;
	int		h;
	int		fd;
	char	*dirs;
	int		posx;
	int		posy;

	dirs = "NESW";
	fd = open("rand.cub", O_RDWR | O_CREAT | O_TRUNC, 0644);
	srand(time(NULL));
	w = 10 + rand() % 10;
	h = 10 + rand() % 10;
	i = 0;
	write(fd, "R 1920 1080\nNO ./path_to_the_north_texture\nSO ./path_to_the_south_texture\nWE ./path_to_the_west_texture\nEA ./path_to_the_east_texture\nS ./path_to_the_sprite_texture\nF 25,25,25\nC 0,126,233\n\n", 189);
	while (i++ < w + 2)
		write(fd, "1", 1);
	write(fd, "\n", 1);
	posx = rand() % h;
	posy = rand() % w;
	x = 0;
	while (x < h)
	{
		y = 0;
		write(fd, "1", 1);
		while (y < w)
		{
			c = '0' + rand() % 2;
			if (x == posx && y == posy)
				c = dirs[rand() % 4];
			write(fd, &c, 1);
			y++;
		}
		write (fd, "1\n", 2);
		x++;
	}
	i = 0;
	while (i++ < w + 2)
		write(fd, "1", 1);
	write(fd, "\n", 1);
	close(fd);
}
