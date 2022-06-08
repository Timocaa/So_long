/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:39:59 by tlafont           #+#    #+#             */
/*   Updated: 2022/06/08 13:21:58 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_check_args(t_chk *item, int ac, char **av)
{
	if (ac < 2)
		return (ft_print_error("Error\n     Too few arguments !\n"), 0);
	else if (ac > 2)
		return (ft_print_error("Error\n     Too many arguments !\n"), 0);
	if (av[1][0] == '\0')
		return (ft_print_error("Error\n     Map name missing !\n"), 0);
	if (ft_strcmp((av[1] + (ft_strlen(av[1]) - 4)), ".ber") != 0)
		return (ft_print_error("Error\n     Wrong file type !\n"), 0);
	if (!ft_parsing_map(item, av[1]))
		return (0);
	return (1);
}

int	ft_parsing_map(t_chk *item, char *map)
{
	int		fd;
	int		i;

	i = ft_read_map(map);
	if (i <= 0)
		return (ft_print_error("Error\n     Map not compliant !\n"), 0);
	fd = open(map, O_RDONLY);
	if (!ft_check_map(item, i, fd))
		return (ft_print_error("Error\n     Map not compliant !\n"), 0);
	close(fd);
	return (1);
}

int	ft_check_map(t_chk *item, int i, int fd)
{
	int		max;
	char	*line;
	size_t	len1;

	max = i;
	len1 = 0;
	while (i)
	{
		line = get_next_line(fd);
		if (len1 == 0)
			len1 = ft_strlen(line);
		else if (len1 != ft_strlen(line))
			return (free(line), 0);
		if (!ft_check_line(item, i, max, line))
			return (free(line), 0);
		free(line);
		i--;
	}
	if (item->e != 1 || item->p != 1 || item->c < 1 || item->i != 1)
		return (0);
	return (1);
}

int	ft_read_map(char *map)
{
	int		fd;
	int		rd;
	char	buff[2];
	int		count;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Error\n     Permission denied !\n"), 0);
	rd = 1;
	buff[0] = '\0';
	count = 0;
	while (rd != 0)
	{
		rd = read(fd, buff, 1);
		if (buff[0] == '\n')
			count++;
	}
	close(fd);
	return (count - 1);
}

int	ft_check_line(t_chk *item, int i, int max, char *line)
{
	int		j;

	j = 0;
	if (i == max || i == 1)
		while (line[j] != '\n')
			if (line[j++] != '1')
				return (0);
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		return (0);
	if (!ft_pars_line(line, item))
		return (0);
	return (1);
}
