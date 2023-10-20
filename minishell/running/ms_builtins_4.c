/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:31:51 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/15 07:12:16 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

int	fn_redirin(int argc, char **argv)
{
	int		fd;
	char	buffer[2];

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_print_2(argv[1], "No such file or directory", -1));
	while (read(fd, buffer, 1) > 0)
	{
		if ((write(1, buffer, 1)) < 0)
			return (-1);
	}
	close(fd);
	return (0);
}

int	fn_redirout(int argc, char **argv, int dbl)
{
	int		fd;
	char	buffer[2];

	(void)argc;
	if (dbl)
	{
		fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0)
			return (-1);
	}
	else
	{
		fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (-1);
	}
	while (read(0, buffer, 1) > 0)
	{
		if ((write(fd, buffer, 1)) < 0)
			return (-1);
	}
	close(fd);
	return (0);
}

int	fn_redirout1(int argc, char **argv)
{
	return (fn_redirout(argc, argv, 0));
}

int	fn_redirout2(int argc, char **argv)
{
	return (fn_redirout(argc, argv, 1));
}
