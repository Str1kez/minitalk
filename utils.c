/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:33:41 by tnessrou          #+#    #+#             */
/*   Updated: 2021/09/04 21:36:01 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	raise_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}

int	ft_isdigit(int c)
{
	if ((c < 58) && (c > 47))
		return (1);
	return (0);
}
