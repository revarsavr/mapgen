#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Escribe la cabecera con datos de configuración en el fichero indicado */
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

/* Escribe una fila de 1s en el fichero indicado, el ancho se amplía en 2 para acomodar los lados izquierdo y derecho del marco */
void	fila_unos(int fd, int w)
{
	int i;

	i = 0;
	while (i++ < w + 2)
		write(fd, "1", 1);
	write(fd, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		d;
	int		s;
	int		w;
	int		h;
	int		posx;
	int		posy;
	int		fd;
	int		x;
	int		y;
    
	/* Valores por defecto de densidad, frecuencia de sprites, ancho y alto del mapa, respectivamente */
	d = 50;
	s = 5;
	w = 10;
	h = 10;

	/* Asignación de otros valores si se pasan como argumentos por la línea de comandos */
	if (argc > 4)
		return (0);
	else if (argc == 2)
		d = atoi(argv[1]);
	else if (argc == 3)
	{
		w = atoi(argv[1]) - 2;
		h = atoi(argv[2]) - 2;
	}
	else if (argc == 4)
	{
		d = atoi(argv[1]);
		w = atoi(argv[2]) - 2;
		h = atoi(argv[3]) - 2;
	}

	/* Generación de semilla para números aleatorios */
	srand(time(NULL));

	/* Posición del jugador, aleatoria dentro del mapa */
	posx = rand() % h;
	posy = rand() % w;

	/* Apertura del fichero rand.cub y escritura de la cabecera */
	fd = open("rand.cub", O_RDWR | O_CREAT | O_TRUNC, 0644);
	cabecera(fd);

	/* Escritura del mapa en rand.cub */
	fila_unos(fd, w);
	x = 0;
	while (x < h)
	{
		y = 0;
		/* Escribe un 1 en el lado izquierdo del marco para cerrar el mapa */
		write(fd, "1", 1);
		while (y < w)
		{
			/* Coloca al jugador en su posición, mirando en una de las cuatro direcciones, elegida al azar */
			if (x == posx && y == posy)
                write(fd, &"NESW"[rand() % 4], 1);

			/* Con probabilidad de un d%, coloca un obstáculo o sprite */
			else if (rand() % 100 < d)
			{
				/* Con probabilidad de un s%, coloca un sprite en lugar de un obstáculo */
				if (rand() % 100 < s)
					write(fd, "2", 1);
				else
					write(fd, "1", 1);				
			}
			/* En los demás casos, coloca un 0 */
			else
				write(fd, "0", 1);			
			y++;
		}
		/* Escribe un 1 en el lado derecho del marco para cerrar el mapa */
		write(fd, "1\n", 2);
		x++;
	}
	fila_unos(fd, w);

	/* Cierre del fichero rand.cub */
	close(fd);
}
