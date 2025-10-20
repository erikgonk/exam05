#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_map
{
    int lines;
    int width;
    char full;
    char obstacle;
    char empty;
    char *map;
} t_map;

typedef struct s_square
{
    int y;
    int x;
    int area;
} t_square;

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

t_square get_square(int y, int x, t_map *map)
{
    t_square sq;

    sq.y = y;
    sq.x = x;

    for (sq.area = 0; y + sq.area < map->lines && x + sq.area < map->width; sq.area++)
    {
        for (int j = 0; j <= sq.area; j++)
        {
            for (int i = 0; i <= sq.area; i++)
            {
                if (map->map[(y + j) * map->width + (x + i)] == map->obstacle)
                {
                    sq.area--;
                    return (sq);
                }
            }
        }
    }
    sq.area--;
    return (sq);
}

int do_bsq(t_map *map)
{
    t_square current;
    t_square best = {};

    for (int y = 0; y < map->lines; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            current = get_square(y, x, map);
            if (current.area > best.area)
                best = current;
        }
    }
    for (int y = 0; y < map->lines; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (y >= best.y && y < best.y + best.area && x >= best.x && x < best.x + best.area)
            {
                if (map->map[y * map->width + x] != map->obstacle)
                    fprintf(stdout, "%c", map->full);
                else
                    fprintf(stdout, "%c", map->map[y * map->width + x]);
            }
            else
                fprintf(stdout, "%c", map->map[y * map->width + x]);
        }
        fprintf(stdout, "\n");
    }
    return (0);
}

// Leer mapa + check 1a linea + guardar mapa + remove newline(s)
t_map* read_map(char *filename) {
    FILE *file = filename ? fopen(filename, "r") : stdin;
    if (!file)
        return NULL;
    // Leemos la primera linea y guardamos los valores correspondientes
    t_map *map = malloc(sizeof(t_map));
    if (fscanf(file, "%d %c %c %c\n", &map->lines, &map->empty, &map->obstacle, &map->full) != 4) {
        free(map);
        if (filename)
            fclose(file);
        return NULL;
    }
    map->width = 0;
    int i = 0;

    // Read first line to determine width
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, file) == -1) {
        free(map);
        if (filename)
            fclose(file);
        return NULL;
    }

    // Remove newline
    int line_len = ft_strlen(line);
    if (line[line_len - 1] == '\n')
        line[line_len - 1] = '\0';

    map->width = ft_strlen(line);
    map->map = malloc(map->lines * map->width * sizeof(char));

    // Copy first line
    int j = 0;
    while (j < map->width) {
        map->map[0 * map->width + j] = line[j];
        j++;
    }
    free(line);
    i = 1;

    // Recorremos linea por linea, guardandola en el mapa.
    while (i < map->lines) {
        line = NULL;
        len = 0;
        if (getline(&line, &len, file) == -1) {
            free(map->map);
            free(map);
            if (filename)
                fclose(file);
            return NULL;
        }

        // Remove newline
        line_len = ft_strlen(line);
        if (line[line_len - 1] == '\n')
            line[line_len - 1] = '\0';

        if (ft_strlen(line) != map->width) {
            free(line);
            free(map->map);
            free(map);
            if (filename)
                fclose(file);
            return NULL;
        }

        // Copy line to map->map
        j = 0;
        while (j < map->width) {
            map->map[i * map->width + j] = line[j];
            j++;
        }
        free(line);
        i++;
    }

    if (filename)
        fclose(file);

    return map;
}

int validate_map(t_map *map)
{
    int i = 0;

    // Comprobamos si hay map (estrucura mapa, proteccion) y si el mapa tiene contenido
    if (!map || map->lines <= 0 || map->width <= 0)
        return 0;

    // Comprobamos que los caracteres no sean duplicados
    if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
        return 0;

    // Check de que no haya caracteres diferentes a 'empty' y 'obst'
    while (i < map->lines) {
        int j = 0;
        while (j < map->width) {
            char c = map->map[i * map->width + j];
            if (c != map->empty && c != map->obstacle)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

void free_map(t_map *map) {
    if (!map)
        return;
    free(map->map);
    free(map);
}

void process_file(char *filename) {
    t_map *map = read_map(filename);
    if (!map || !validate_map(map)) {
        fprintf(stderr, "map error\n");
        if (map)
            free_map(map);
        return;
    }

    do_bsq(map);
    free_map(map);
}

int main(int argc, char **argv) {
    if (argc == 1)
        process_file(NULL); // stdin
    else {
        int i = 1;
        while (i < argc) {
            process_file(argv[i]);
            i++;
        }
    }
    return 0;
}