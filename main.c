/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:33:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/24 14:59:03 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	int m = 3;
    char *line;
	fd = open("test.txt" , O_RDONLY);
	while (m-- > 0)
	if (get_next_line(fd, &line) != 0)
	ft_putendl(line);
	return (0);
}
