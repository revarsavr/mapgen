#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	cabecera(int fd)
{
    write(fd, "R 1920 1080 \n", 13);
    write(fd, "NO ./path_to_the_north_texture\n",31);
	write(fd, "SO ./path_to_the_south_texture\n",31);
	write(fd, "WE ./path_to_the_west_texture\n",30);
	write(fd, "EA ./path_to_the_east_texture\n",30);
	write(fd, "S ./path_to_the_sprite_texture\n",31);
	write(fd, "F 25,25,25\n",11);
	write(fd, "C 0,126,233\n\n", 13);
}

int		main(int argc, char **argv)
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
	int		d;
        
        
	if (argc > 2)
		return (0);
	d = 50;
	if (argc == 2)
		d = atoi(argv[1]);
	dirs = "NESW";
	fd = open("rand.cub", O_RDWR | O_CREAT | O_TRUNC, 0644);
	srand(time(NULL));
	w = 10 + rand() % 10;
	h = 10 + rand() % 10;
	i = 0;
	posx = rand() % h;
	posy = rand() % w;
	
	cabecera(fd);
	while (i++ < w + 2)
	write(fd, "1", 1);
	write(fd, "\n", 1);
	x = 0;
	while (x < h)
	{
		y = 0;
		write(fd, "1", 1);
		while (y < w)
		{
                        c = '0';
			if (rand() % 100 < d)
                            c = '1';
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
