#ifndef FILLER_H
#define FILLER_H

# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"
# include <ncurses.h>
# define RET_CHECK(x) if (!(x)) return (0);
# define RET_VOID(x) if (!(x)) return ;
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct  s_piece
{
    int         size_x;
    int         size_y;
    char        **piece;


}               t_piece;

typedef struct  s_meta
{
    int         enemy_x;
    int         enemy_y;
    int         size_x;
    int         size_y;
    char        player;
    char        enemy;
    char        **map;
    t_piece     piece;
}               t_meta;

typedef struct  s_option
{
    int         distance;
    int         x;
    int         y;
}               t_option;

int     is_fit(t_meta *meta, int x, int y);
void    find_option(t_meta *meta);
void    free_meta(t_meta *meta, char **tmp);
int     find_size(intmax_t a);
int     save_piece(char *tmp, t_meta *meta, int fd);

#endif
