typedef struct s_map
{
    int lines;
    char full;
    char obstacle;
    char empty;
    char **map;
} t_map;


typedef struct s_square
{
    int y;
    int x;
    int area;
} t_square;


t_square get_square(int y, int x, t_map *map)
{
    t_square sq;

    sq.y = y;
    sq.x = x;

    for (sq.area = 0; y + sq.area < map->lines && x + sq.area < ft_strlen(map[y]) - 1; sq.area++)
    {
        for (int j = 0; j <= sq.area; j++)
        {
            for (int i = 0; i <= sq.area; i++)
            {
                if (map[y + j][x + i] == map->obstacle)
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
        for (int x = 0; map[y][x] != '\n'; x++)
        {
            current = get_square(y, x, map);
            if (current.area > best.area)
                best = current;
        }
    }
    for (int y = 0; y < map->lines; y++)
    {
        for (int x = 0; map->map[y][x] != '\n'; x++)
        {
            if (y >= best.y && y <= y + best.area && x >= best.x && x <= x + best.area)
            {
                //caso mapa 1x1 en el que el caracter solo es 
                if (map->map[y][x] != map->obstacle)
                    fprintf(stdout, "%c", map->fill);
                else
                    fprintf(stdout, "%c", map->map[y][x]);
            else
                fprintf(stdout, "%c", map->map[y][x]);
            }
        }
        fprintf(stdout, "\n");
    }
    return (0);
}