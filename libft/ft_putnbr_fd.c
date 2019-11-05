/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:21:00 by lhuang            #+#    #+#             */
/*   Updated: 2019/10/13 15:42:31 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int a;

	if (n < 0)
	{
		a = -n;
		ft_putchar_fd1('-', fd);
	}
	else
		a = n;
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd1(a % 10 + 48, fd);
	}
	else
		ft_putchar_fd1(a % 10 + 48, fd);
}
