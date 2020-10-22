# cub3D

mapgen es un generador de mapas válidos aleatorios. Genera un mapa (en el directorio actual) llamado "rand.cub", que va a ser siempre válido, y como mínimo de dimensiones 10x10.

Uso: 

1) gcc -Wall -Werror -Wextra mapgen.c -o mapgen

2) ./mapgen [densidad]

3) ./cub3D rand.cub

Notas: 

1) el parámetro opcional densidad es un número entre 0 y 100 que representa el % de 1s en el mapa, por defecto (si no pones nada) vale 50.

2) cub3D debería ser el nombre de tu programa para visualizar mapas (mediante RayCasting).

3) si tu cub3D ya visualiza texturas, asegúrate de cambiar "./path_to_the..." en mapgen.c a sus directorios correspondientes, y de cambiar el número de bytes a escribir (el último argumento de la función write).
