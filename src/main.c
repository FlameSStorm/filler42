#include "filler.h"


static void        save_map(t_meta *meta, int fd)
{
    char    **map;
    int     i;

    RET_VOID(map = (char**)malloc(sizeof(char*) * (meta->size_x + 5)));
    RET_VOID(meta->map = (char**)malloc(sizeof(char*) * (meta->size_x + 5)));
    i = -1;
    while (++i < meta->size_x)
    {
        RET_VOID(get_next_line(fd, &map[i]));
        RET_VOID(meta->map[i] = ft_strsub(map[i], 4, meta->size_y));
        ft_strdel(&map[i]);
    }
    meta->map[i] = NULL;
    free(map);
}

int save_piece(char *tmp, t_meta *meta, int fd)
{
    int i;

    meta->piece.size_x = ft_atoi(tmp + 6);
    meta->piece.size_y = ft_atoi(tmp + 6 + find_size(meta->piece.size_x));
    RET_CHECK(meta->piece.piece = (char**)malloc(sizeof(char*) * (meta->piece.size_x + 1)));
    i = 0;
    while (i < meta->piece.size_x)
        RET_CHECK(get_next_line(fd, &meta->piece.piece[i++]));
    meta->piece.piece[i] = NULL;
    return (1);
}

static void save_start_positions(t_meta *meta)
{
    int i;
    int j;

    i = 0;
    while (i < meta->size_x)
    {
        j = 0;
        while (j < meta->size_y)
        {
            if (meta->map[i][j] != '.')
            {
                if (meta->map[i][j] == meta->enemy)
                {
                    meta->enemy_x = i;
                    meta->enemy_y = j;
                }
            }
            j++;
        }
        i++;
    }
}

static int save_meta(char **tmp, t_meta *meta, int fd)
{
    RET_CHECK((get_next_line(fd, tmp)));
    meta->player = (char)(ft_strstr(*tmp, "$$$ exec p1") ? 'O' : 'X');
    meta->enemy =  (char)(meta->player == 'O' ? 'X' : 'O');
    ft_strdel(tmp);
    RET_CHECK((get_next_line(fd, tmp)));
    meta->size_x = ft_atoi(*tmp + 8);
    meta->size_y = ft_atoi(*tmp + 8 + find_size(meta->size_x));
    ft_strdel(tmp);
    RET_CHECK(get_next_line(fd, tmp));
    ft_strdel(tmp);
    save_map(meta, fd);
    RET_CHECK(get_next_line(fd, tmp));
    save_start_positions(meta);
    RET_CHECK(save_piece(*tmp, meta, fd));
    ft_strdel(tmp);
    return (1);
}


int main(int ac, char **av)
{
    char    *tmp;
    t_meta  meta;
    int     ret;

    tmp = NULL;
    RET_CHECK(save_meta(&tmp, &meta, 0));
    find_option(&meta);
    while ((ret = get_next_line(0, &tmp)) > 0)
    {
        free_meta(&meta, &tmp);
        while (ret > 0)
        {
            ret = get_next_line(0, &tmp);
            if (ft_strstr(tmp, "01234"))
                break;
            ft_strdel(&tmp);
        }
        ft_strdel(&tmp);
        save_map(&meta, 0);
        get_next_line(0, &tmp);
        save_piece(tmp, &meta, 0);
        find_option(&meta);
    }
    return (0);
}
