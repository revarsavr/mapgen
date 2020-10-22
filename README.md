# cub3D

mapgen es un generador de mapas válidos aleatorios. Genera un mapa (en el directorio actual) llamado "rand.cub", que va a ser siempre válido, y como mínimo de dimensiones 10x10.

Uso: 

1) gcc -Wall -Werror -Wextra mapgen.c -o mapgen

2) ./mapgen

3) ./cub3D rand.cub

cub3D debería ser el nombre de tu programa para visualizar mapas (mediante RayCasting).

Nota: 

si tu cub3D ya visualiza texturas, asegúrate de cambiar "./path_to_the..." en mapgen.c a sus directorios correspondientes.
