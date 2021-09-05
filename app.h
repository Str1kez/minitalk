/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:28:20 by tnessrou          #+#    #+#             */
/*   Updated: 2021/09/05 17:07:12 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_bin
{
	int	data;
	int	pow;
}				t_bin;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	raise_error(char *err);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif
