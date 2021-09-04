/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:25:52 by tnessrou          #+#    #+#             */
/*   Updated: 2021/09/04 21:43:50 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static int	num_len(int n)
{
	int				count;
	unsigned int	help;

	help = n;
	count = 1;
	while (help > 9)
	{
		help /= 10;
		count++;
	}
	return (count);
}

static int	num_on_iter(int n, int iter, int len)
{
	int				i;
	unsigned int	help;

	help = n;
	i = 0;
	while (i < len - iter - 1)
	{
		help /= 10;
		i++;
	}
	return (help % 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		iter;

	iter = 0;
	len = num_len(n);
	while (iter < len)
	{
		ft_putchar_fd(num_on_iter(n, iter, len) + 48, fd);
		iter++;
	}
}
