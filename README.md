# mapgen

mapgen es un generador de mapas válidos aleatorios. Genera un mapa (en el directorio actual) llamado "rand.cub", que va a ser siempre válido.
Por defecto tendrá dimensiones de 10x10, un 50% de obstáculos (un 10% de los cuales serán sprites).

Uso: 

1) gcc -Wall -Werror -Wextra mapgen.c -o mapgen

2) ./mapgen [densidad] [ancho] [alto]

3) ./cub3D rand.cub

Notas: 

1) el parámetro opcional densidad es un número entre 0 y 100 que representa el % de 1s en el mapa, por defecto (si no pones nada) vale 50.

2) ambos parámetros ancho y alto deben estar presentes en la línea de comandos y ser mayores de 2.

3) cub3D debería ser el nombre de tu programa para visualizar mapas (mediante RayCasting).

4) si tu cub3D ya visualiza texturas, asegúrate de cambiar "./path_to_the..." en mapgen.c a sus directorios correspondientes, y de cambiar el número de bytes a escribir (el último argumento de la función write).

Ejemplos:

"./mapgen" genera un mapa de 10x10, con un 50% de obstáculos.

"./mapgen 30" genera un mapa con un 30% de obstáculos.

·./mapgen 40 20" genera un mapa de 40x20, con el 50% de obstáculos por defecto.

"./mapgen 60 10 15" genera un mapa de 10x15, con un 60% de obstáculos.
