/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:32:08 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/29 11:21:25 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	main()
{
	int fd;
	int fd2;
	char *line;
	char *line2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (get_next_line(fd,&line) > 0 && get_next_line(fd2,&line2) > 0)
	{
		ft_putendl(line);
		ft_putendl(line2);
		ft_strdel(&line);
		ft_strdel(&line2);
	}
	sleep(120);
	close(fd);
	close(fd2);
	return (0);
}
