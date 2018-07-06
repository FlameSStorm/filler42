/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:11:28 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/02/22 18:35:40 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft.h"
# define MCH(x) if (!(x)) return (-1);
# define RET_TRUE(x) if (x) return (1);
# define BUFF_SIZE 2
# define ENDL '\n'
# define END '\0'

int				get_next_line(const int fd, char **line);

#endif
